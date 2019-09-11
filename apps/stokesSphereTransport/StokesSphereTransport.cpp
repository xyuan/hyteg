#include <cmath>

#include "core/DataTypes.h"
#include "core/Environment.h"
#include "core/config/Config.h"
#include "core/mpi/MPIManager.h"

#include "hyteg/FunctionProperties.hpp"
#include "hyteg/VTKWriter.hpp"
#include "hyteg/composites/P1StokesFunction.hpp"
#include "hyteg/composites/P1StokesOperator.hpp"
#include "hyteg/composites/P1Transport.hpp"
#include "hyteg/gridtransferoperators/P1P1StokesToP1P1StokesProlongation.hpp"
#include "hyteg/gridtransferoperators/P1P1StokesToP1P1StokesRestriction.hpp"
#include "hyteg/gridtransferoperators/P1toP1LinearProlongation.hpp"
#include "hyteg/gridtransferoperators/P1toP1LinearRestriction.hpp"
#include "hyteg/mesh/MeshInfo.hpp"
#include "hyteg/petsc/PETScLUSolver.hpp"
#include "hyteg/petsc/PETScManager.hpp"
#include "hyteg/petsc/PETScWrapper.hpp"
#include "hyteg/primitivestorage/PrimitiveStorage.hpp"
#include "hyteg/primitivestorage/SetupPrimitiveStorage.hpp"
#include "hyteg/primitivestorage/Visualization.hpp"
#include "hyteg/primitivestorage/loadbalancing/DistributedBalancer.hpp"
#include "hyteg/primitivestorage/loadbalancing/SimpleBalancer.hpp"
#include "hyteg/solvers/CGSolver.hpp"
#include "hyteg/solvers/GeometricMultigridSolver.hpp"
#include "hyteg/solvers/MinresSolver.hpp"
#include "hyteg/solvers/UzawaSmoother.hpp"
#include "hyteg/solvers/preconditioners/StokesBlockDiagonalPreconditioner.hpp"
#include "hyteg/solvers/preconditioners/StokesPressureBlockPreconditioner.hpp"

using walberla::real_c;
using walberla::real_t;

int main( int argc, char* argv[] )
{
   walberla::Environment env( argc, argv );
   walberla::MPIManager::instance()->useWorldComm();

   //check if a config was given on command line or load default file otherwise
   auto cfg = std::make_shared< walberla::config::Config >();
   if( env.config() == nullptr )
   {
      auto defaultFile = "./StokesSphereTransport.prm";
      WALBERLA_LOG_INFO_ON_ROOT( "No Parameter file given loading default parameter file: " << defaultFile );
      cfg->readParameterFile( defaultFile );
   } else
   {
      cfg = env.config();
   }
   /////////////// Parameters ///////////////
   const walberla::Config::BlockHandle mainConf    = cfg->getBlock( "Parameters" );
   const walberla::Config::BlockHandle layersParam = cfg->getBlock( "Layers" );

   WALBERLA_ROOT_SECTION()
   {
      if( mainConf.getParameter< bool >( "printParameters" ) )
      {
         mainConf.listParameters();
      }
   }

   const uint_t          ntan = mainConf.getParameter< uint_t >( "ntan" );
   std::vector< double > layers;
   for( auto it : layersParam )
   {
      layers.push_back( layersParam.getParameter< double >( it.first ) );
   }

   const double rmin = layers.front();
   const double rmax = layers.back();

   const uint_t minLevel  = mainConf.getParameter< uint_t >( "minLevel" );
   const uint_t maxLevel  = mainConf.getParameter< uint_t >( "maxLevel" );
   const uint_t numVCycle = mainConf.getParameter< uint_t >( "numVCycle" );

   const real_t uzawaTolerance = mainConf.getParameter< double >( "uzawaTolerance" );
   const uint_t uzawaMaxIter   = mainConf.getParameter< uint_t >( "uzawaMaxIter" );

   const uint_t innerTimeSteps  = mainConf.getParameter< uint_t >( "innerTimeSteps" );
   const uint_t outerIterations = mainConf.getParameter< uint_t >( "outerIterations" );

   const real_t viscosity = mainConf.getParameter< real_t >( "viscosity" );
   const real_t dt        = mainConf.getParameter< real_t >( "dt" );

   const real_t rhsScaleFactor = mainConf.getParameter< real_t >( "rhsScaleFactor" );

   const uint_t VTKOutputFrequency = mainConf.getParameter< uint_t >( "VTKFrequency" );

   /////////////////// Mesh / Domain ///////////////////////

   hyteg::MeshInfo              meshInfo = hyteg::MeshInfo::meshSphericalShell( ntan, layers );
   hyteg::SetupPrimitiveStorage setupStorage( meshInfo, walberla::uint_c( walberla::mpi::MPIManager::instance()->numProcesses() ) );
   hyteg::loadbalancing::roundRobin( setupStorage );

   setupStorage.setMeshBoundaryFlagsOnBoundary( 1, 0, true );

   std::shared_ptr< walberla::WcTimingTree > timingTree( new walberla::WcTimingTree() );
   std::shared_ptr< hyteg::PrimitiveStorage > storage = std::make_shared< hyteg::PrimitiveStorage >( setupStorage, timingTree );

   if( mainConf.getParameter< bool >( "useParMETIS" ) )
   {
      hyteg::loadbalancing::distributed::parmetis( *storage );
   }

   if( mainConf.getParameter< bool >( "printGlobalStorageInfo" ) )
   {
      auto globalInfo = storage->getGlobalInfo();
      WALBERLA_LOG_INFO_ON_ROOT( globalInfo );
   }

   if( mainConf.getParameter< bool >( "writeDomainVTK" ) )
   {
      hyteg::writeDomainPartitioningVTK( storage, "./output", "StokesSphereTransport_domain" );
   }

   hyteg::P1StokesFunction< real_t > r( "r", storage, minLevel, maxLevel );
   hyteg::P1StokesFunction< real_t > f( "f", storage, minLevel, maxLevel );
   hyteg::P1StokesFunction< real_t > u( "u", storage, minLevel, maxLevel );
   hyteg::P1Function< real_t >       temp( "temperature", storage, minLevel, maxLevel );
   hyteg::P1Function< real_t >       normalX( "normalX", storage, minLevel, maxLevel );
   hyteg::P1Function< real_t >       normalY( "normalY", storage, minLevel, maxLevel );
   hyteg::P1Function< real_t >       normalZ( "normalZ", storage, minLevel, maxLevel );

   if( mainConf.getParameter< bool >( "printDoFCount" ) )
   {
      uint_t totalGlobalDofsStokes = 0;
      for( uint_t lvl = minLevel; lvl <= maxLevel; ++lvl )
      {
         uint_t tmpDofStokes = hyteg::numberOfGlobalDoFs< hyteg::P1StokesFunctionTag >( *storage, lvl );
         WALBERLA_LOG_INFO_ON_ROOT( "Stokes DoFs on level " << lvl << " : " << tmpDofStokes );
         totalGlobalDofsStokes += tmpDofStokes;
      }
      WALBERLA_LOG_INFO_ON_ROOT( "Total Stokes DoFs on all level :" << totalGlobalDofsStokes );
   }

   hyteg::VTKOutput vtkOutput("./output", "StokesSphereTransport", storage, VTKOutputFrequency);
   if( mainConf.getParameter< bool >( "VTKOutput" ) )
   {
      vtkOutput.add( u.u );
      vtkOutput.add( u.v );
      vtkOutput.add( u.w );
      //      vtkOutput.add( &u.p );
      //      vtkOutput.add( &f.u );
      //      vtkOutput.add( &f.v );
      //      vtkOutput.add( &f.w );
      //      vtkOutput.add( &f.p );
      vtkOutput.add( temp );
   }

   hyteg::P1StokesOperator L( storage, minLevel, maxLevel );
   hyteg::P1ConstantMassOperator M( storage, minLevel, maxLevel );

   std::function< real_t( const hyteg::Point3D& ) > temperature = [rmin, rmax]( const hyteg::Point3D& x ) {
      return std::pow( ( rmax - x.norm() ) / ( rmax - rmin ), 3.0 );
   };

   temp.interpolate( temperature, maxLevel );

   std::function< real_t( const hyteg::Point3D& ) > zero = []( const hyteg::Point3D& ) { return 0.0; };
   std::function< real_t( const hyteg::Point3D& ) > ones = []( const hyteg::Point3D& ) { return 1.0; };

   std::function< real_t( const hyteg::Point3D& ) > nX = []( const hyteg::Point3D& x ) { return x[0] / x.norm(); };
   std::function< real_t( const hyteg::Point3D& ) > nY = []( const hyteg::Point3D& x ) { return x[1] / x.norm(); };
   std::function< real_t( const hyteg::Point3D& ) > nZ = []( const hyteg::Point3D& x ) { return x[2] / x.norm(); };

   normalX.interpolate( nX, maxLevel );
   normalY.interpolate( nY, maxLevel );
   normalZ.interpolate( nZ, maxLevel );

   if( mainConf.getParameter< bool >( "VTKOutput" ) )
   {
      vtkOutput.write( maxLevel, 0 );
   }

   ///// MinRes coarse grid solver for UZAWA /////
//   typedef hyteg::StokesPressureBlockPreconditioner< hyteg::P1StokesFunction< real_t >, hyteg::P1LumpedInvMassOperator >
//       PressurePreconditioner_T;
//
//   hyteg::P1LumpedInvMassOperator  massOperator( storage, minLevel, minLevel );
//   PressurePreconditioner_T pressurePrec( massOperator, storage, minLevel, minLevel );
//
//   typedef hyteg::MinResSolver< hyteg::P1StokesFunction< real_t >, hyteg::P1StokesOperator, PressurePreconditioner_T >
//       PressurePreconditionedMinRes_T;
//
//   auto pressurePreconditionedMinResSolver = PressurePreconditionedMinRes_T( storage, minLevel, minLevel, pressurePrec );

   typedef hyteg::StokesPressureBlockPreconditioner< hyteg::P1StokesOperator, hyteg::P1LumpedInvMassOperator >
       PressurePreconditioner_T;
   auto pressurePrec = std::make_shared< PressurePreconditioner_T >( storage, minLevel, minLevel );
   typedef hyteg::MinResSolver< hyteg::P1StokesOperator > PressurePreconditionedMinRes_T;
   auto pressurePreconditionedMinResSolver = std::make_shared< PressurePreconditionedMinRes_T >(
       storage, minLevel, minLevel, uzawaMaxIter, uzawaTolerance, pressurePrec );

   ///// UZAWA solver /////
//   typedef hyteg::UzawaSolver< hyteg::P1StokesFunction< real_t >,
//                        hyteg::P1StokesOperator,
//                        PressurePreconditionedMinRes_T,
//                        hyteg::P1P1StokesToP1P1StokesRestriction,
//                        hyteg::P1P1StokesToP1P1StokesProlongation,
//                        false >
//       UzawaSolver_T;
//
//   hyteg::P1P1StokesToP1P1StokesRestriction  stokesRestriction{};
//   hyteg::P1P1StokesToP1P1StokesProlongation stokesProlongation{};
//
//   UzawaSolver_T uzawaSolver(
//       storage, pressurePreconditionedMinResSolver, stokesRestriction, stokesProlongation, minLevel, maxLevel, 2, 2, 2 );

   typedef hyteg::GeometricMultigridSolver< hyteg::P1StokesOperator > UzawaSolver_T;
   auto stokesRestriction  = std::make_shared< hyteg::P1P1StokesToP1P1StokesRestriction >();
   auto stokesProlongation = std::make_shared< hyteg::P1P1StokesToP1P1StokesProlongation >();
   auto uzawaSmoother =
       std::make_shared< hyteg::UzawaSmoother< hyteg::P1StokesOperator > >( storage, minLevel, maxLevel, 0.3 );

   UzawaSolver_T uzawaSolver( storage,
                              uzawaSmoother,
                              pressurePreconditionedMinResSolver,
                              stokesRestriction,
                              stokesProlongation,
                              minLevel,
                              maxLevel,
                              2,
                              2,
                              2 );

   auto count = hyteg::Function< hyteg::vertexdof::VertexDoFFunction< real_t > >::getLevelWiseFunctionCounter();
   if( mainConf.getParameter< bool >( "printFunctionCount" ) )
   {
      for( uint_t i = minLevel; i <= maxLevel; ++i )
      {
         WALBERLA_LOG_INFO_ON_ROOT( "Total number of P1 Functions on " << i << " : " << count[i] );
      }
   }

   hyteg::P1Transport transportOperator( storage, minLevel, maxLevel );
   real_t      time = 0.0;

   for( uint_t step = 0; step < outerIterations; ++step )
   {
      M.apply( temp, f.u, maxLevel, hyteg::All );
      M.apply( temp, f.v, maxLevel, hyteg::All );
      M.apply( temp, f.w, maxLevel, hyteg::All );

      f.u.multElementwise( {f.u, normalX}, maxLevel, hyteg::All );
      f.v.multElementwise( {f.v, normalY}, maxLevel, hyteg::All );
      f.w.multElementwise( {f.w, normalZ}, maxLevel, hyteg::All );

      f.u.assign( {rhsScaleFactor}, {f.u}, maxLevel, hyteg::All );
      f.v.assign( {rhsScaleFactor}, {f.v}, maxLevel, hyteg::All );
      f.w.assign( {rhsScaleFactor}, {f.w}, maxLevel, hyteg::All );

      L.apply( u, r, maxLevel, hyteg::Inner | hyteg::NeumannBoundary );
      r.assign( {1.0, -1.0}, {f, r}, maxLevel, hyteg::Inner | hyteg::NeumannBoundary );
      real_t currentResidualL2 = sqrt( r.dotGlobal( r, maxLevel, hyteg::Inner ) ) /
                                 real_c( hyteg::numberOfGlobalDoFs< hyteg::P1StokesFunctionTag >( *storage, maxLevel ) );
      real_t lastResidualL2 = currentResidualL2;
      WALBERLA_LOG_INFO_ON_ROOT( "[StokesSphere] iteration | residual (L2) | convergence rate " );
      WALBERLA_LOG_INFO_ON_ROOT( "[StokesSphere] ----------+---------------+------------------" );
      WALBERLA_LOG_INFO_ON_ROOT( "[StokesSphere] " << std::setw( 9 ) << 0 << " | " << std::setw( 13 ) << std::scientific
                                                   << currentResidualL2 << " | " << std::setw( 16 ) << std::scientific
                                                   << currentResidualL2 / lastResidualL2 );
      for( uint_t i = 0; i < numVCycle; i++ )
      {
         uzawaSolver.solve( L, u, f, maxLevel );

         lastResidualL2 = currentResidualL2;
         L.apply( u, r, maxLevel, hyteg::Inner | hyteg::NeumannBoundary );
         r.assign( {1.0, -1.0}, {f, r}, maxLevel, hyteg::Inner | hyteg::NeumannBoundary );
         currentResidualL2 = sqrt( r.dotGlobal( r, maxLevel, hyteg::Inner ) ) /
                             real_c( hyteg::numberOfGlobalDoFs< hyteg::P1StokesFunctionTag >( *storage, maxLevel ) );
         WALBERLA_LOG_INFO_ON_ROOT( "[StokesSphere] " << std::setw( 9 ) << i + 1 << " | " << std::setw( 13 ) << std::scientific
                                                      << currentResidualL2 << " | " << std::setw( 16 ) << std::scientific
                                                      << currentResidualL2 / lastResidualL2 )
         //WALBERLA_LOG_INFO_ON_ROOT( "after it " << i << ": " << std::scientific << residualMG );
      }

      for( uint_t innerSteps = 0; innerSteps < innerTimeSteps; ++innerSteps )
      {
         time += dt;
         WALBERLA_LOG_INFO_ON_ROOT( "time = " << time );

         transportOperator.step( temp, u.u, u.v, u.w, maxLevel, hyteg::Inner, dt, viscosity );
      }

      if( mainConf.getParameter< bool >( "VTKOutput" ) )
      {
         vtkOutput.write( maxLevel, step + 1 );
      }
   }

   if( mainConf.getParameter< bool >( "PrintTiming" ) )
   {
      auto tt = timingTree->getReduced();
      tt      = timingTree->getCopyWithRemainder();
      WALBERLA_LOG_INFO_ON_ROOT( tt );
   }

   return EXIT_SUCCESS;
}

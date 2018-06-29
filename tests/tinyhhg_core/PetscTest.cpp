#include <core/timing/Timer.h>

#include "core/Environment.h"
#include "core/logging/Logging.h"

#include "tinyhhg_core/mesh/MeshInfo.hpp"
#include "tinyhhg_core/p1functionspace/P1Function.hpp"
#include "tinyhhg_core/p1functionspace/P1ConstantOperator.hpp"
#include "tinyhhg_core/petsc/PETScLUSolver.hpp"
#include "tinyhhg_core/petsc/PETScManager.hpp"
#include "tinyhhg_core/primitivestorage/PrimitiveStorage.hpp"
#include "tinyhhg_core/primitivestorage/SetupPrimitiveStorage.hpp"
#include "tinyhhg_core/primitivestorage/loadbalancing/SimpleBalancer.hpp"

#ifndef HHG_BUILD_WITH_PETSC
#error "This test only works with PETSc enabled. Please enable it via -DHHG_BUILD_WITH_PETSC=ON"
#endif

using walberla::real_t;
using walberla::uint_c;
using walberla::uint_t;

using namespace hhg;

int main( int argc, char* argv[] )
{
   walberla::Environment walberlaEnv( argc, argv );
   walberla::logging::Logging::instance()->setLogLevel( walberla::logging::Logging::PROGRESS );
   walberla::MPIManager::instance()->useWorldComm();

   PETScManager petscManager;

   std::string meshFileName = "../../data/meshes/quad_4el.msh";

   MeshInfo              meshInfo = MeshInfo::fromGmshFile( meshFileName );
   SetupPrimitiveStorage setupStorage( meshInfo, uint_c( walberla::mpi::MPIManager::instance()->numProcesses() ) );

   hhg::loadbalancing::roundRobin( setupStorage );

   size_t Level = 2;

   std::shared_ptr< PrimitiveStorage > storage = std::make_shared< PrimitiveStorage >( setupStorage );

   hhg::P1Function< real_t > x( "x", storage, Level, Level );
   hhg::P1Function< real_t > x_exact( "x_exact", storage, Level, Level );
   hhg::P1Function< real_t > err( "err", storage, Level, Level );

   std::shared_ptr< hhg::P1Function< PetscInt > > numerator =
       std::make_shared< hhg::P1Function< PetscInt > >( "numerator", storage, Level, Level );

   hhg::P1ConstantLaplaceOperator A( storage, Level, Level );

   std::function< real_t( const hhg::Point3D& ) > exact = []( const hhg::Point3D& xx ) {
      return xx[0] * xx[0] - xx[1] * xx[1] + 10;
   };
   std::function< real_t( const hhg::Point3D& ) > rhs  = []( const hhg::Point3D& ) { return 0.0; };
   std::function< real_t( const hhg::Point3D& ) > ones = []( const hhg::Point3D& ) { return 1.0; };

   x.interpolate( exact, Level, hhg::DirichletBoundary );
   x_exact.interpolate( exact, Level );

   uint_t num        = 0;
   uint_t dofsOnRank = numerator->enumerate( Level, num );
   WALBERLA_LOG_INFO_ON_ROOT( "Num dofs = " << uint_c( num ) )

   PETScLUSolver< real_t, hhg::P1Function, hhg::P1ConstantLaplaceOperator > solver( numerator, dofsOnRank, num );

   WALBERLA_LOG_INFO_ON_ROOT( "Solving System" )
   walberla::WcTimer timer;
   solver.solve( A, x, x, x, Level, 0, 0 );
   timer.end();

   WALBERLA_LOG_INFO_ON_ROOT( "time was: " << timer.last() );
   err.assign( {1.0, -1.0}, {&x, &x_exact}, Level );

   real_t discr_l2_err = std::sqrt( err.dot( err, Level ) / (real_t) num );

   WALBERLA_LOG_INFO_ON_ROOT( "discrete L2 error = " << discr_l2_err );

   //  WALBERLA_LOG_INFO_ON_ROOT("Printing Solution")
   //  hhg::VTKWriter< P1Function >({ &x, &x_exact, &err }, Level, "../output", "exact_solver");

   return EXIT_SUCCESS;
}

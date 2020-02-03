/*
 * Copyright (c) 2017-2019 Daniel Drzisga, Dominik Thoennes, Nils Kohl.
 *
 * This file is part of HyTeG
 * (see https://i10git.cs.fau.de/hyteg/hyteg).
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include <core/Environment.h>
#include <core/math/Constants.h>
#include <core/timing/Timer.h>

#include "hyteg/composites/MMOCTransport.hpp"
#include "hyteg/dataexport/VTKOutput.hpp"
#include "hyteg/mesh/MeshInfo.hpp"
#include "hyteg/p1functionspace/P1ConstantOperator.hpp"
#include "hyteg/p1functionspace/P1Function.hpp"
#include "hyteg/p2functionspace/P2ConstantOperator.hpp"
#include "hyteg/p2functionspace/P2Function.hpp"
#include "hyteg/primitivestorage/PrimitiveStorage.hpp"
#include "hyteg/primitivestorage/SetupPrimitiveStorage.hpp"
#include "hyteg/primitivestorage/Visualization.hpp"
#include "hyteg/primitivestorage/loadbalancing/SimpleBalancer.hpp"

using walberla::real_t;
using walberla::uint_c;
using walberla::uint_t;

using namespace hyteg;

/// Setting from Kuzmin transport tutorial section 4.4.6.1

int main( int argc, char* argv[] )
{
   walberla::MPIManager::instance()->initializeMPI( &argc, &argv );
   walberla::MPIManager::instance()->useWorldComm();

   MeshInfo meshInfo = hyteg::MeshInfo::meshRectangle( Point2D( {0, 0} ), Point2D( {1, 1} ), MeshInfo::CRISS, 3, 3 );
   // MeshInfo meshInfo = MeshInfo::fromGmshFile( "../../data/meshes/tri_1el.msh" );
   SetupPrimitiveStorage setupStorage( meshInfo, walberla::uint_c( walberla::mpi::MPIManager::instance()->numProcesses() ) );

   const uint_t minLevel   = 2;
   const uint_t maxLevel   = 4;
   real_t       dt         = 1.0 * std::pow( 2.0, -walberla::real_c( maxLevel + 1 ) );
   const real_t dist       = 2 * walberla::math::pi * 0.25;
   const real_t velocity   = 0.25;
   const real_t tEnd       = dist / velocity;
   const uint_t stepsTotal = uint_c( tEnd / dt );

   const uint_t outerSteps = 1;
   const uint_t innerSteps = 201;

   WALBERLA_LOG_INFO_ON_ROOT( "Circular convection" )
   WALBERLA_LOG_INFO_ON_ROOT( " - dt:                                           " << dt )
   WALBERLA_LOG_INFO_ON_ROOT( " - level:                                        " << maxLevel )
   WALBERLA_LOG_INFO_ON_ROOT( " - inner time steps (no temperature evaluation): " << innerSteps )
   WALBERLA_LOG_INFO_ON_ROOT( " - outer time steps:                             " << outerSteps )
   WALBERLA_LOG_INFO_ON_ROOT( " - steps until circle completed:                 " << stepsTotal )
   WALBERLA_LOG_INFO_ON_ROOT( "" )

   auto r = []( const hyteg::Point3D& x, const hyteg::Point3D& x0, const real_t& r0 ) -> real_t {
      return ( 1 / r0 ) * std::sqrt( std::pow( x[0] - x0[0], 2 ) + std::pow( x[1] - x0[1], 2 ) );
   };

   std::function< real_t( const hyteg::Point3D& ) > conicalBody = [&]( const hyteg::Point3D& x ) -> real_t {
      const Point3D x0( {0.5, 0.25, 0.0} );
      const real_t  r0 = 0.15;
      if ( r( x, x0, r0 ) <= 1. )
         return 1 - r( x, x0, r0 );
      else
         return 0.0;
   };

   std::function< real_t( const hyteg::Point3D& ) > gaussianCone = [&]( const hyteg::Point3D& x ) -> real_t {
      const Point3D x0( {0.5, 0.25, 0.0} );
      const real_t  r0 = 0.15;
      if ( r( x, x0, r0 ) <= 1. )
         return ( 1 + std::cos( walberla::math::pi * r( x, x0, r0 ) ) ) * 0.25;
      else
         return 0.0;
   };

   auto vel_x = []( const hyteg::Point3D& x ) -> real_t {
      if ( ( x - Point3D( {0.5, 0.5, 0} ) ).norm() < 0.45 )
         return 0.5 - x[1];
      else
         return 0;
   };

   auto vel_y = []( const hyteg::Point3D& x ) -> real_t {
      if ( ( x - Point3D( {0.5, 0.5, 0} ) ).norm() < 0.45 )
         return x[0] - 0.5;
      else
         return 0;
   };

   std::shared_ptr< hyteg::PrimitiveStorage > storage = std::make_shared< hyteg::PrimitiveStorage >( setupStorage );

   writeDomainPartitioningVTK( storage, "../../output", "MMOC2DCircularConvectionTest_Domain" );

   typedef P2Function< real_t >   FunctionType;
   typedef P2ConstantMassOperator MassOperator;

   FunctionType c( "c", storage, minLevel, maxLevel );
   FunctionType cInitial( "cInitial", storage, minLevel, maxLevel );
   FunctionType cError( "cError", storage, minLevel, maxLevel );
   FunctionType cMass( "cError", storage, minLevel, maxLevel );
   FunctionType u( "u", storage, minLevel, maxLevel );
   FunctionType v( "v", storage, minLevel, maxLevel );
   FunctionType w( "w", storage, minLevel, maxLevel );

   MassOperator                  M( storage, minLevel, maxLevel );
   MMOCTransport< FunctionType > transport( storage, minLevel, maxLevel, TimeSteppingScheme::RK4 );

   u.interpolate( vel_x, maxLevel );
   v.interpolate( vel_y, maxLevel );
   c.interpolate( gaussianCone, maxLevel );
   cInitial.interpolate( gaussianCone, maxLevel );

   hyteg::VTKOutput vtkOutput( "../../output", "MMOC2DCircularConvectionTest", storage, innerSteps );

   vtkOutput.add( u );
   vtkOutput.add( v );
   vtkOutput.add( c );
   vtkOutput.add( cInitial );

   WALBERLA_LOG_INFO_ON_ROOT( " outer step | timestep | max temperature | total mass | mass lost since last outer step " )
   WALBERLA_LOG_INFO_ON_ROOT( "------------+----------+-----------------+------------+---------------------------------" )

   cError.assign( {1.0, -1.0}, {c, cInitial}, maxLevel, All );
   auto max_temp = c.getMaxMagnitude( maxLevel, All );
   M.apply( c, cMass, maxLevel, All );
   auto total_mass = cMass.sumGlobal( maxLevel );

   vtkOutput.write( maxLevel );

   WALBERLA_LOG_INFO_ON_ROOT( walberla::format( " %10d | %8d | %15.3e | %10.3e | %30.2f%% ", 0, 0, max_temp, total_mass, 0, 0. ) )

   for ( uint_t i = 1; i <= outerSteps; i++ )
   {
      transport.step( c, u, v, w, maxLevel, Inner, dt, innerSteps );

      cError.assign( {1.0, -1.0}, {c, cInitial}, maxLevel, All );
      max_temp = c.getMaxMagnitude( maxLevel, All );
      M.apply( c, cMass, maxLevel, All );
      auto total_mass_new  = cMass.sumGlobal( maxLevel );
      auto total_mass_lost = 1.0 - ( total_mass_new / total_mass );
      total_mass           = total_mass_new;

      WALBERLA_LOG_INFO_ON_ROOT( walberla::format(
          " %10d | %8d | %15.3e | %10.3e | %30.2f%% ", i, i * innerSteps, max_temp, total_mass, total_mass_lost * 100. ) )

      vtkOutput.write( maxLevel, i * innerSteps );

   }

   cError.assign( {1.0, -1.0}, {c, cInitial}, maxLevel, All );
   auto l2_error = cError.dotGlobal( cError, maxLevel, All );
   WALBERLA_LOG_INFO_ON_ROOT( "discrete L2 error: " << l2_error );
   WALBERLA_CHECK_LESS( l2_error, 1.1e-03 );

   return EXIT_SUCCESS;
}

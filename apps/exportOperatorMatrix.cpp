/*
 * Copyright (c) 2017-2019 Christoph Schwarzmeier, Dominik Thoennes, Marcus Mohr.
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
#include <sstream>
#include <string>
#include <core/timing/Timer.h>
#include <core/Environment.h>
#include <core/math/Constants.h>

// Primitive management
#include "hyteg/primitivestorage/SetupPrimitiveStorage.hpp"
#include "hyteg/primitivestorage/loadbalancing/SimpleBalancer.hpp"
#include "hyteg/primitivestorage/PrimitiveStorage.hpp"

// Function spaces
#include "hyteg/p1functionspace/P1Function.hpp"
#include "hyteg/p2functionspace/P2Function.hpp"
#include "hyteg/composites/P2P1TaylorHoodFunction.hpp"

// P1 Operators
#include "hyteg/p1functionspace/P1ConstantOperator.hpp"

// P2 Operators
#include "hyteg/p2functionspace/P2ConstantOperator.hpp"

// Mixed Operators
#include "hyteg/composites/P2P1TaylorHoodStokesOperator.hpp"

// PETSc interface
#include "hyteg/petsc/PETScManager.hpp"
#include "hyteg/petsc/PETScSparseMatrix.hpp"
#include "hyteg/petsc/PETScExportOperatorMatrix.hpp"

using walberla::real_t;
using walberla::uint_t;
using walberla::uint_c;
using walberla::math::pi;

using namespace hyteg;


typedef enum { P1MASS, P1LAPLACE, P2MASS, P2LAPLACE, P2P1STOKES } operatorTag;

typedef struct {
  operatorTag oprEnum;
  std::string matName;
  bool elimDirichletBC;
} oprInfo;

std::map<std::string, oprInfo> oprMap = {
  {  "P1Mass",     { P1MASS,     "MassOpP1",     false } },
  {  "P1Diff",     { P1LAPLACE,  "DiffOpP1",     true  } },
  {  "P2Mass",     { P2MASS,     "MassOpP2",     false } },
  {  "P2Diff",     { P2LAPLACE,  "DiffOpP2",     true  } },
  {  "P2P1Stokes", { P2P1STOKES, "StokesOpP2P1", true  } }
};


void showUsage() {

  std::stringstream mesg;

  mesg << "Please specify the following two parameters in the given order:\n\n"
       << "  <level>      on which level do you want the operator to be set up?\n"
       << "  <operator>   which operator do you want to export?\n\n"
       << " Choices available for <operator> are\n";

  for( auto it = oprMap.begin(); it != oprMap.end(); ++it ) {
    mesg << " - " << it->first << "\n";
  }

  WALBERLA_LOG_INFO_ON_ROOT( "" << mesg.str() );
}


int main( int argc, char* argv[] ) {

  walberla::MPIManager::instance()->initializeMPI( &argc, &argv );
  walberla::MPIManager::instance()->useWorldComm();
  walberla::logging::Logging::instance()->setLogLevel( walberla::logging::Logging::PROGRESS );

  WALBERLA_LOG_DEVEL_ON_ROOT( "" );
  WALBERLA_LOG_DEVEL_ON_ROOT( "----------------------------------------------" );
  WALBERLA_LOG_DEVEL_ON_ROOT( "--------- Matrix Export of Operators ---------" );
  WALBERLA_LOG_DEVEL_ON_ROOT( "----------------------------------------------" );
  WALBERLA_LOG_DEVEL_ON_ROOT( "" );

  // Process command-line
  if( argc < 3 || argc > 3 ) {
    showUsage();
    WALBERLA_ABORT( "\n" );
  }

  uint_t level = static_cast<uint_t>( std::stoul( argv[1] ) );
  std::string oprName  = ( argv[2] );
  operatorTag oprTag   = oprMap[ oprName ].oprEnum;
  std::string matName  = oprMap[ oprName ].matName;
  std::string fileName = oprName + ".m";
  bool elim = oprMap[ oprName ].elimDirichletBC;

  // Mesh generation
  WALBERLA_LOG_INFO_ON_ROOT( "Generating criss mesh on unit square" );
  MeshInfo meshInfo = MeshInfo::emptyMeshInfo();
  Point2D cornerLL( { 0.0, 0.0 } );
  Point2D cornerUR( { 1.0, 1.0 } );
  meshInfo = MeshInfo::meshRectangle( cornerLL, cornerUR, MeshInfo::CRISS, 1, 1 );

  SetupPrimitiveStorage setupStorage( meshInfo,
                                      uint_c ( walberla::mpi::MPIManager::instance()->numProcesses() ) );

  hyteg::loadbalancing::roundRobin( setupStorage );
  std::shared_ptr< PrimitiveStorage > storage = std::make_shared< PrimitiveStorage >( setupStorage );

  // Operator creation and export
  switch( oprTag ) {

    // --------------
    //  P1 operators
    // --------------
  case P1LAPLACE:
    {
      WALBERLA_LOG_INFO_ON_ROOT( "Exporting Laplace operator for P1 elements" );
      hyteg::P1ConstantLaplaceOperator opr( storage, level, level );
      exportOperator< P1ConstantLaplaceOperator, P1Function, P1FunctionTag >( opr, fileName, matName, storage, level, elim );
    }
    break;

  case P1MASS:
    {
      WALBERLA_LOG_INFO_ON_ROOT( "Exporting Mass operator for P1 elements" );
      hyteg::P1ConstantMassOperator opr( storage, level, level );
      exportOperator< P1ConstantMassOperator, P1Function, P1FunctionTag >( opr, fileName, matName, storage, level, elim );
    }
    break;

    // --------------
    //  P2 operators
    // --------------
  case P2LAPLACE:
    {
      WALBERLA_LOG_INFO_ON_ROOT( "Exporting Laplace operator for P2 elements" );
      hyteg::P2ConstantLaplaceOperator opr( storage, level, level );
      exportOperator< P2ConstantLaplaceOperator, P2Function, P2FunctionTag >( opr, fileName, matName, storage, level, elim );
    }
    break;

  case P2MASS:
    {
      WALBERLA_LOG_INFO_ON_ROOT( "Exporting Mass operator for P2 elements" );
      hyteg::P2ConstantMassOperator opr( storage, level, level );
      exportOperator< P2ConstantMassOperator, P2Function, P2FunctionTag >( opr, fileName, matName, storage, level, elim );
    }
    break;

    // -----------------
    //  Mixed operators
    // -----------------
  case P2P1STOKES:
    {
      WALBERLA_LOG_INFO_ON_ROOT( "Exporting Stokes Operator for P2-P1 element" );
      hyteg::P2P1TaylorHoodStokesOperator opr( storage, level, level );
      exportOperator< P2P1TaylorHoodStokesOperator, P2P1TaylorHoodFunction, P2P1TaylorHoodFunctionTag >( opr, fileName, matName, storage, level, elim );
    }
    break;
  }

  WALBERLA_LOG_DEVEL_ON_ROOT( "----------------------------------------------" );

  return 0;
}

/*
 * Copyright (c) 2017-2019 Dominik Thoennes.
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

#include "hyteg/p1functionspace/VertexDoFIndexing.hpp"
#include "core/mpi/all.h"
#include "core/debug/CheckFunctions.h"

using walberla::uint_t;

int main(int argc, char* argv[])
{

  walberla::mpi::Environment walberlaEnv(argc, argv);
  walberla::MPIManager::instance()->useWorldComm();


//  std::string enumStrings[] = {
//      "VERTEX_C",
//      "VERTEX_S",
//      "VERTEX_SE",
//      "VERTEX_E",
//      "VERTEX_N",
//      "VERTEX_NW",
//      "VERTEX_W",
//      "CELL_GRAY_SE",
//      "CELL_GRAY_NE",
//      "CELL_GRAY_NW",
//      "CELL_BLUE_SE",
//      "CELL_BLUE_NW",
//      "CELL_BLUE_SW"
//  };

  /// CHECK VERTEX ///
  std::vector<uint_t> refOne = {1,9,10,2,18,17,0};
  std::vector<uint_t> refFive = {5,13,14,6,22,21,4};
  std::vector<uint_t> result;
  for( const auto & n : hyteg::vertexdof::macroedge::neighborsWithCenter )
  {
    size_t idx = hyteg::vertexdof::macroedge::indexFromVertex( 3, 1, n );
    result.push_back(idx);
  }
  for(size_t i = 0; i < refOne.size(); ++i){
    WALBERLA_CHECK_EQUAL(refOne[i],result[i],"i: " << i);
  }
  result.clear();
  for( const auto & n : hyteg::vertexdof::macroedge::neighborsWithCenter )
  {
    size_t idx = hyteg::vertexdof::macroedge::indexFromVertex( 3, 5, n );
    result.push_back(idx);
    //WALBERLA_LOG_INFO_ON_ROOT(enumStrings[n] << " " << idx);
  }
  for(size_t i = 0; i < refFive.size(); ++i){
    WALBERLA_CHECK_EQUAL(refFive[i],result[i],"i: " << i);
  }
  result.clear();
#if 0
  uint_t counter = 0;
  for(auto it = edgeIndexIterator(-1,3);it != edgeIndexIterator(); ++it){
    WALBERLA_CHECK_EQUAL(counter,*it);
    counter++;
  }
  WALBERLA_CHECK_EQUAL(counter,hyteg::levelinfo::num_microvertices_per_edge(3));

  //counter = hyteg::levelinfo::num_microvertices_per_edge(4);

  for(auto it = edgeIndexIterator(0,3);it != edgeIndexIterator(); ++it){
    WALBERLA_CHECK_EQUAL(counter,*it);
    counter++;
  }
  WALBERLA_CHECK_EQUAL(counter,hyteg::levelinfo::num_microvertices_per_edge(3) * 2 -1);

  counter = hyteg::levelinfo::num_microvertices_per_edge(4) * 2 - 1;
  for(auto it = edgeIndexIterator(1,4);it != edgeIndexIterator(); ++it){
    WALBERLA_CHECK_EQUAL(counter,*it);
    counter++;
  }
  WALBERLA_CHECK_EQUAL(counter,hyteg::levelinfo::num_microvertices_per_edge(4) * 3 - 2);
#endif
}

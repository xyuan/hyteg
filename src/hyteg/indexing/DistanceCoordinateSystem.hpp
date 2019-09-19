/*
 * Copyright (c) 2017-2019 Dominik Thoennes, Nils Kohl.
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

#pragma once

#include "hyteg/indexing/Common.hpp"

namespace hyteg {
namespace indexing {

using indexing::Index;

/// This file contains data structures and functions related to a distance based coordinate system for macro-cells.
///
/// It is somewhat similar to a barycentric coordinate system - however the definitions are different since
/// we measure here the distance from the vertices of a tetrahedron.
///
/// The distance coordinate system describes a point in a macro-cell by its distance to the cell's four vertices V0, ..., V3.
///
/// Example: the point (2, 1, 0) in the default coordinate system on a macro-cell with width == 5 (== level 2 vertexdof)
/// translates to (3, 2, 3, 4)_dist.
///
/// Motivation:
/// The default coordinate system has its origin at vertex V0 and the directions (x, y, z) are defined by the vectors
/// (V1 - V0) (== x), (V2 - V0) (== y) and (V3 - V0) (== z).
/// We name this coordinate system 0123 (origin, x, y, z).
/// By defining another origin at vertex V1 and (x, y, z) by (V0 - V1) (== x), (V2 - V1) (== y) and (V3 - V1)
/// we get the coordinate system 1023.
///
/// Conversion of indices from one system to another for example helps to conveniently assemble stencils on lower dimensional primitives.
/// This conversion is facilitated by the distance based coordinate system.
///
/// Formulas:
///   a, b, c and d denote the four vertices
///   w denotes the width of the macro-cell
///
///   conversion to dist system:
///
///     (x, y, z)_abcd -> dist[a] = sum(x, y, z)
///                       dist[b] = w-1 - x
///                       dist[c] = w-1 - y
///                       dist[d] = w-1 - z
///
///   conversion from dist system to abcd coordinate system:
///
///     (d0, d1, d2, d3)_dist -> x = w-1 - dist[b]
///                              y = w-1 - dist[c]
///                              z = w-1 - dist[d]
///
/// Using previous example:
///   to dist:
///     (2, 1, 0)_0123    -> (2+1+0, 5-1-x, 5-1-y, 5-1-z)_dist = (3, 2, 3, 4)_dist
///   from dist but to different system (0123 -> 1203):
///     (3, 2, 3, 4)_dist -> (5-1-3, 5-1-3, 5-1-4)_1203 = (1, 1, 0)_1203
///

class DistanceIndex : protected PointND< uint_t, 4 >
{
public:

    DistanceIndex() : PointND< uint_t, 4 >() {}

    DistanceIndex( const DistanceIndex & other ) : PointND< uint_t, 4 >( other ) {}

    DistanceIndex( const uint_t & d0, const uint_t & d1, const uint_t & d2, const uint_t & d3 ) {
      x_[0] = d0;
      x_[1] = d1;
      x_[2] = d2;
      x_[3] = d3;
    }

    using PointND< uint_t, 4 >::operator[];

    const uint_t & d0() const { return x_[0]; }
          uint_t & d0() { return x_[0]; }

    const uint_t & d1() const { return x_[1]; }
          uint_t & d1() { return x_[1]; }

    const uint_t & d2() const { return x_[2]; }
          uint_t & d2() { return x_[2]; }

    const uint_t & d3() const { return x_[3]; }
          uint_t & d3() { return x_[3]; }
};

inline DistanceIndex toDistanceIndex( const Index & index, const std::array< uint_t, 4 > & basis, const uint_t & cellWidth )
{
  WALBERLA_ASSERT_LESS_EQUAL( basis[0], 3 );
  WALBERLA_ASSERT_LESS_EQUAL( basis[1], 3 );
  WALBERLA_ASSERT_LESS_EQUAL( basis[2], 3 );
  WALBERLA_ASSERT_LESS_EQUAL( basis[3], 3 );

  WALBERLA_ASSERT_NOT_IDENTICAL( basis[0], basis[1] );
  WALBERLA_ASSERT_NOT_IDENTICAL( basis[0], basis[2] );
  WALBERLA_ASSERT_NOT_IDENTICAL( basis[0], basis[3] );
  WALBERLA_ASSERT_NOT_IDENTICAL( basis[1], basis[2] );
  WALBERLA_ASSERT_NOT_IDENTICAL( basis[1], basis[3] );
  WALBERLA_ASSERT_NOT_IDENTICAL( basis[2], basis[3] );

  DistanceIndex distanceIndex;
  distanceIndex[ basis[0] ] = index.x() + index.y() + index.z();
  distanceIndex[ basis[1] ] = cellWidth - 1 - index.x();
  distanceIndex[ basis[2] ] = cellWidth - 1 - index.y();
  distanceIndex[ basis[3] ] = cellWidth - 1 - index.z();
  return distanceIndex;
}

inline Index fromDistanceIndex( const DistanceIndex & dstIndex, const std::array< uint_t, 4 > & basis, const uint_t & cellWidth )
{
  WALBERLA_ASSERT_LESS_EQUAL( basis[0], 3 );
  WALBERLA_ASSERT_LESS_EQUAL( basis[1], 3 );
  WALBERLA_ASSERT_LESS_EQUAL( basis[2], 3 );
  WALBERLA_ASSERT_LESS_EQUAL( basis[3], 3 );

  WALBERLA_ASSERT_NOT_IDENTICAL( basis[0], basis[1] );
  WALBERLA_ASSERT_NOT_IDENTICAL( basis[0], basis[2] );
  WALBERLA_ASSERT_NOT_IDENTICAL( basis[0], basis[3] );
  WALBERLA_ASSERT_NOT_IDENTICAL( basis[1], basis[2] );
  WALBERLA_ASSERT_NOT_IDENTICAL( basis[1], basis[3] );
  WALBERLA_ASSERT_NOT_IDENTICAL( basis[2], basis[3] );

  return Index( cellWidth - 1 - dstIndex[basis[1]],
                cellWidth - 1 - dstIndex[basis[2]],
                cellWidth - 1 - dstIndex[basis[3]]
              );
}

inline Index basisConversion( const Index & index, const std::array< uint_t, 4 > & srcBasis,
                              const std::array< uint_t, 4 > & dstBasis, const uint_t & cellWidth )
{
  const DistanceIndex dstIdx = toDistanceIndex( index, srcBasis, cellWidth );
  return fromDistanceIndex( dstIdx, dstBasis, cellWidth );
}

}
}
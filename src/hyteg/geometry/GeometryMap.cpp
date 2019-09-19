/*
 * Copyright (c) 2017-2019 Daniel Drzisga, Dominik Thoennes, Marcus Mohr.
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
#include "AffineMap.hpp"
#include "CircularMap.hpp"
#include "IdentityMap.hpp"
#include "PolarCoordsMap.hpp"

namespace hyteg {

real_t GeometryMap::evalDetDF( const Point3D& x )
{
   Matrix2r DF;
   evalDF( x, DF );
   return DF.det();
}

void GeometryMap::serialize( const std::shared_ptr< GeometryMap >& map, walberla::mpi::SendBuffer& sendBuffer )
{
   map->serializeSubClass( sendBuffer );
}

std::shared_ptr< GeometryMap > GeometryMap::deserialize( walberla::mpi::RecvBuffer& recvBuffer )
{
   Type type;
   recvBuffer >> type;

   switch( type )
   {
   case Type::IDENTITY:
      return std::make_shared< IdentityMap >();
   case Type::AFFINE:
      return std::make_shared< AffineMap >( recvBuffer );
   case Type::CIRCULAR:
      return std::make_shared< CircularMap >( recvBuffer );
   case Type::POLAR_COORDS:
      return std::make_shared< PolarCoordsMap >();
   default:
      WALBERLA_ABORT( "Error in deserializing GeometryMap: Unknown Type" )
   }
}

} // namespace hyteg

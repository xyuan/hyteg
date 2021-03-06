/*
 * Copyright (c) 2017-2019 Benjamin Mann.
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

#include <hyteg/p1functionspace/VertexDoFMemory.hpp>
#include <hyteg/mixedoperators/variablestencil/P2P1VariableStencilCommon.hpp>
#include <hyteg/p2functionspace/polynomial/P2StencilPolynomial.hpp>

namespace hyteg {
namespace P2toP1 {

class FacePolynomialMemory
{
 public:

   struct FacePolynomials
   {
      P2::StencilPolynomial<NumStencilentries2D::VtV> VtV;
      P2::StencilPolynomial<NumStencilentries2D::EtV> EtV;
   };

   FacePolynomialMemory() {}

   inline FacePolynomials& addDegree(uint_t degree)
   {
      if (polynomialDegreeExists(degree))
      {
         WALBERLA_LOG_WARNING("Degree already exists.");
      }

      FacePolynomials& poly = polynomials_[degree];
      poly.VtV.initialize(degree);
      poly.EtV.initialize(degree);

      return poly;
   }

   inline bool polynomialDegreeExists(uint_t degree)
   {
      return polynomials_.count(degree) > 0;
   }

   inline FacePolynomials& getPolynomial(uint_t degree)
   {
      return polynomials_[degree];
   }


 private:

   std::map<uint_t, FacePolynomials> polynomials_;
};

} // namespace P2toP1

namespace P1toP2 {

class FacePolynomialMemory
{
 public:

   struct FacePolynomials
   {
      P2::StencilPolynomial<NumStencilentries2D::VtV> VtV;
      P2::StencilPolynomial<NumStencilentries2D::VtE> VtE;
   };

   FacePolynomialMemory() {}

   inline FacePolynomials& addDegree(uint_t degree)
   {
      if (polynomialDegreeExists(degree))
      {
         WALBERLA_LOG_WARNING("Degree already exists.");
      }

      FacePolynomials& poly = polynomials_[degree];
      poly.VtV.initialize(degree);
      poly.VtE.initialize(degree);

      return poly;
   }

   inline bool polynomialDegreeExists(uint_t degree)
   {
      return polynomials_.count(degree) > 0;
   }

   inline FacePolynomials& getPolynomial(uint_t degree)
   {
      return polynomials_[degree];
   }


 private:

   std::map<uint_t, FacePolynomials> polynomials_;
};

} // namespace P1toP2
} // namespace hyteg
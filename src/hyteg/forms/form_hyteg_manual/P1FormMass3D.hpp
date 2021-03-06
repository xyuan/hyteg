/*
 * Copyright (c) 2017-2020 Marcus Mohr.
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

#include "hyteg/forms/form_hyteg_base/P2FormHyTeG.hpp"
#include "hyteg/forms/form_hyteg_manual/QuadratureRules.hpp"
#include "hyteg/geometry/GeometryMap.hpp"

namespace hyteg {

class P1Form_mass3D : public P1FormHyTeG {

public:

  void integrateAll( const std::array< Point3D, 3 >& coords, Matrix3r& elMat ) const {
    WALBERLA_ABORT( "Not implemented." );
  }

  void integrateAll( const std::array< Point3D, 4 >& coords, Matrix4r& elMat ) const final {

// Select quadrature rule
#define CUBAPOINTS cubature::T4_points
#define CUBAWEIGHTS cubature::T4_weights
// #define CUBAPOINTS cubature::T3_points
// #define CUBAWEIGHTS cubature::T3_weights

// Shape functions on unit tetrahedron
#define DEFINE_P1_SHAPE_FUNCTIONS_TET
#include "ShapeFunctionMacros.hpp"
#undef DEFINE_P1_SHAPE_FUNCTIONS_TET

// Executing quadrature rule
#define INTEGRATE3D(i,j)                                                                                                                             \
  elMat(i,j) = 0.0;                                                                                                                                  \
  for( uint_t k = 0; k < CUBAWEIGHTS.size(); k++ ) {                                                                                                 \
    real_t L2 = CUBAPOINTS[k][0];                                                                                                                    \
    real_t L3 = CUBAPOINTS[k][1];                                                                                                                    \
    real_t L4 = CUBAPOINTS[k][2];                                                                                                                    \
    real_t L1 = 1.0 - L2 - L3 - L4;                                                                                                                  \
    mappedPt[0] = ( coords[1][0] - coords[0][0] ) * L2 + ( coords[2][0] - coords[0][0] ) * L3 + ( coords[3][0] - coords[0][0] ) * L4 + coords[0][0]; \
    mappedPt[1] = ( coords[1][1] - coords[0][1] ) * L2 + ( coords[2][1] - coords[0][1] ) * L3 + ( coords[3][1] - coords[0][1] ) * L4 + coords[0][1]; \
    mappedPt[2] = ( coords[1][2] - coords[0][2] ) * L2 + ( coords[2][2] - coords[0][2] ) * L3 + ( coords[3][2] - coords[0][2] ) * L4 + coords[0][2]; \
    real_t detDPsi = std::abs( geometryMap_->evalDF( mappedPt, dummy ) );                                                                            \
    elMat(i,j) += CUBAWEIGHTS[k] * detJacPhiInv * detDPsi * SF_M ## i * SF_M ## j;                                                                   \
  }                                                                                                                                                  \
  elMat(j,i) = elMat(i,j);

    // compute Jacobian determinant of inverse pull-back mapping
    real_t tmp0 = -coords[0][0];
    real_t tmp1 = tmp0 + coords[1][0];
    real_t tmp2 = -coords[0][1];
    real_t tmp3 = tmp2 + coords[2][1];
    real_t tmp4 = -coords[0][2];
    real_t tmp5 = tmp4 + coords[3][2];
    real_t tmp6 = tmp0 + coords[2][0];
    real_t tmp7 = tmp2 + coords[3][1];
    real_t tmp8 = tmp4 + coords[1][2];
    real_t tmp9 = tmp0 + coords[3][0];
    real_t tmp10 = tmp2 + coords[1][1];
    real_t tmp11 = tmp4 + coords[2][2];
    real_t detJacPhiInv = -tmp1*tmp11*tmp7 + tmp1*tmp3*tmp5 + tmp10*tmp11*tmp9 - tmp10*tmp5*tmp6 - tmp3*tmp8*tmp9 + tmp6*tmp7*tmp8;
    detJacPhiInv = std::abs( detJacPhiInv );

    // Cubature point mapped to computational tetrahedron
    Point3D mappedPt;

    // dummy matrix for evaluation of Jacobian of 3D map
    Matrix3r dummy;

    // ------------
    //  Zeroth row
    // ------------

    INTEGRATE3D(0,0)
    INTEGRATE3D(0,1)
    INTEGRATE3D(0,2)
    INTEGRATE3D(0,3)

    // -----------
    //  First row
    // -----------
    INTEGRATE3D(1,1)
    INTEGRATE3D(1,2)
    INTEGRATE3D(1,3)

    // ------------
    //  Second row
    // ------------
    INTEGRATE3D(2,2)
    INTEGRATE3D(2,3)

    // -----------
    //  Third row
    // -----------
    INTEGRATE3D(3,3)

#define UNDEFINE_P1_SHAPE_FUNCTIONS_TET
#include "ShapeFunctionMacros.hpp"
#undef UNDEFINE_P1_SHAPE_FUNCTIONS_TET

#undef CUBAPOINTS
#undef CUBAWEIGHTS
#undef INTEGRATE3D

  }
};
}

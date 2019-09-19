/*
 * Copyright (c) 2017-2019 Daniel Drzisga, Dominik Thoennes, Marcus Mohr, Nils Kohl.
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

#include <array>

#include "hyteg/Operator.hpp"
#include "hyteg/StencilMemory.hpp"
//<<<<<<< HEAD
#include "hyteg/p1functionspace/VertexDoFIndexing.hpp"
#include "hyteg/LevelWiseMemory.hpp"
//
//class p1_diffusion_cell_integral_0_otherwise;
//class p1_tet_diffusion_cell_integral_0_otherwise;
//class p1_stokes_epsilon_cell_integral_0_otherwise;
//class p1_stokes_epsilon_cell_integral_1_otherwise;
//class p1_stokes_epsilon_cell_integral_2_otherwise;
//class p1_stokes_epsilon_cell_integral_3_otherwise;
//class p1_div_cell_integral_0_otherwise;
//class p1_tet_div_tet_cell_integral_0_otherwise;
//class p1_div_cell_integral_1_otherwise;
//class p1_tet_div_tet_cell_integral_1_otherwise;
//class p1_tet_div_tet_cell_integral_2_otherwise;
//class p1_divt_cell_integral_0_otherwise;
//class p1_tet_divt_tet_cell_integral_0_otherwise;
//class p1_divt_cell_integral_1_otherwise;
//class p1_tet_divt_tet_cell_integral_1_otherwise;
//class p1_tet_divt_tet_cell_integral_2_otherwise;
//class p1_mass_cell_integral_0_otherwise;
//class p1_tet_mass_cell_integral_0_otherwise;
//class p1_pspg_cell_integral_0_otherwise;
//class p1_tet_pspg_tet_cell_integral_0_otherwise;
//
//class p2_to_p1_tet_div_tet_cell_integral_0_otherwise;
//class p2_to_p1_tet_div_tet_cell_integral_1_otherwise;
//class p2_to_p1_tet_div_tet_cell_integral_2_otherwise;
//
//class p1_to_p2_tet_divt_tet_cell_integral_0_otherwise;
//class p1_to_p2_tet_divt_tet_cell_integral_1_otherwise;
//class p1_to_p2_tet_divt_tet_cell_integral_2_otherwise;
//
//=======
#include "hyteg/p1functionspace/P1Function.hpp"
#include "hyteg/forms/form_fenics_base/P1FenicsForm.hpp"

namespace hyteg {

using walberla::real_t;

template < class P1Form, bool Diagonal = false, bool Lumped = false, bool InvertDiagonal = false >
class P1ConstantOperator : public Operator< P1Function< real_t >, P1Function< real_t > >
{
 public:
   P1ConstantOperator( const std::shared_ptr< PrimitiveStorage >& storage, size_t minLevel, size_t maxLevel );

   ~P1ConstantOperator() override = default;

   void scale( real_t scalar );

   void apply( const P1Function< real_t >& src,
               const P1Function< real_t >& dst,
               size_t                      level,
               DoFType                     flag,
               UpdateType                  updateType = Replace ) const;

   void smooth_gs( const P1Function< real_t >& dst, const P1Function< real_t >& rhs, size_t level, DoFType flag ) const;

   void smooth_gs_backwards( const P1Function< real_t >& dst, const P1Function< real_t >& rhs, size_t level, DoFType flag ) const
   {
      smooth_sor_backwards( dst, rhs, 1.0, level, flag );
   }

   void smooth_sor( const P1Function< real_t >& dst,
                         const P1Function< real_t >& rhs,
                         real_t                      relax,
                         size_t                      level,
                         DoFType                     flag,
                         const bool &                backwards = false ) const;

    void smooth_sor_backwards( const P1Function< real_t >& dst,
                               const P1Function< real_t >& rhs,
                               real_t                      relax,
                               size_t                      level,
                               DoFType                     flag ) const
    {
      smooth_sor( dst, rhs, relax, level, flag, true );
    }


   void smooth_jac( const P1Function< real_t >& dst,
                    const P1Function< real_t >& rhs,
                    const P1Function< real_t >& tmp,
                    size_t                      level,
                    DoFType                     flag ) const;

   const PrimitiveDataID< StencilMemory< real_t >, Vertex >& getVertexStencilID() const { return vertexStencilID_; }

   const PrimitiveDataID< StencilMemory< real_t >, Edge >& getEdgeStencilID() const { return edgeStencilID_; }

   const PrimitiveDataID< StencilMemory< real_t >, Face >& getFaceStencilID() const { return faceStencilID_; }

   const PrimitiveDataID< LevelWiseMemory< vertexdof::macroface::StencilMap_T >, Face >& getFaceStencil3DID() const { return faceStencil3DID_; }

   const PrimitiveDataID< LevelWiseMemory< vertexdof::macrocell::StencilMap_T >, Cell >& getCellStencilID() const { return cellStencilID_; }

 private:
   void assembleStencils();

   void assembleStencils3D();

 private:
   PrimitiveDataID< StencilMemory< real_t >, Vertex > vertexStencilID_;
   PrimitiveDataID< StencilMemory< real_t >, Edge >   edgeStencilID_;
   PrimitiveDataID< StencilMemory< real_t >, Face >   faceStencilID_;
   PrimitiveDataID< LevelWiseMemory< vertexdof::macroface::StencilMap_T >, Face > faceStencil3DID_;
   PrimitiveDataID< LevelWiseMemory< vertexdof::macrocell::StencilMap_T >, Cell > cellStencilID_;

   P1Form form;
};

typedef P1ConstantOperator< P1FenicsForm< fenics::NoAssemble, fenics::NoAssemble > > P1ZeroOperator;

typedef P1ConstantOperator< P1FenicsForm< p1_diffusion_cell_integral_0_otherwise, p1_tet_diffusion_cell_integral_0_otherwise > >
    P1ConstantLaplaceOperator;
typedef P1ConstantOperator< P1FenicsForm< p1_diffusion_cell_integral_0_otherwise, fenics::UndefinedAssembly >, true >
    P1DiagonalLaplaceOperator;

typedef P1ConstantOperator< P1FenicsForm< p1_stokes_epsilon_cell_integral_0_otherwise > > P1ConstantEpsilonOperator_11;
typedef P1ConstantOperator< P1FenicsForm< p1_stokes_epsilon_cell_integral_1_otherwise > > P1ConstantEpsilonOperator_12;
typedef P1ConstantOperator< P1FenicsForm< p1_stokes_epsilon_cell_integral_2_otherwise > > P1ConstantEpsilonOperator_21;
typedef P1ConstantOperator< P1FenicsForm< p1_stokes_epsilon_cell_integral_3_otherwise > > P1ConstantEpsilonOperator_22;

typedef P1ConstantOperator< P1FenicsForm< p1_div_cell_integral_0_otherwise, p1_tet_div_tet_cell_integral_0_otherwise > >
    P1DivxOperator;
typedef P1ConstantOperator< P1FenicsForm< p1_div_cell_integral_1_otherwise, p1_tet_div_tet_cell_integral_1_otherwise > >
                                                                                                           P1DivyOperator;
typedef P1ConstantOperator< P1FenicsForm< fenics::NoAssemble, p1_tet_div_tet_cell_integral_2_otherwise > > P1DivzOperator;

typedef P1ConstantOperator< P1FenicsForm< p1_divt_cell_integral_0_otherwise, p1_tet_divt_tet_cell_integral_0_otherwise > >
    P1DivTxOperator;
typedef P1ConstantOperator< P1FenicsForm< p1_divt_cell_integral_1_otherwise, p1_tet_divt_tet_cell_integral_1_otherwise > >
                                                                                                            P1DivTyOperator;
typedef P1ConstantOperator< P1FenicsForm< fenics::NoAssemble, p1_tet_divt_tet_cell_integral_2_otherwise > > P1DivTzOperator;

typedef P1ConstantOperator< P1FenicsForm< p1_mass_cell_integral_0_otherwise, p1_tet_mass_cell_integral_0_otherwise > >
    P1ConstantMassOperator;

typedef P1ConstantOperator< P1FenicsForm< p1_mass_cell_integral_0_otherwise, p1_tet_mass_cell_integral_0_otherwise >,
                            false,
                            true,
                            false >
    P1LumpedMassOperator;

typedef P1ConstantOperator< P1FenicsForm< p1_mass_cell_integral_0_otherwise, p1_tet_mass_cell_integral_0_otherwise >,
                            false,
                            true,
                            true >
    P1LumpedInvMassOperator;

typedef P1ConstantOperator< P1FenicsForm< p1_pspg_cell_integral_0_otherwise, p1_tet_pspg_tet_cell_integral_0_otherwise > >
    P1PSPGOperator;
typedef P1ConstantOperator< P1FenicsForm< p1_pspg_cell_integral_0_otherwise, p1_tet_pspg_tet_cell_integral_0_otherwise >, true, false, true >
    P1PSPGInvDiagOperator;

typedef P1ConstantOperator< P1FenicsForm< fenics::NoAssemble, p2_to_p1_tet_div_tet_cell_integral_0_otherwise > >
    P2ToP1DivxVertexToVertexConstantOperator;
typedef P1ConstantOperator< P1FenicsForm< fenics::NoAssemble, p2_to_p1_tet_div_tet_cell_integral_1_otherwise > >
    P2ToP1DivyVertexToVertexConstantOperator;
typedef P1ConstantOperator< P1FenicsForm< fenics::UndefinedAssembly, p2_to_p1_tet_div_tet_cell_integral_2_otherwise > >
    P2ToP1DivzVertexToVertexConstantOperator;

typedef P1ConstantOperator< P1FenicsForm< fenics::NoAssemble, p1_to_p2_tet_divt_tet_cell_integral_0_otherwise > >
    P1ToP1DivTxVertexToVertexConstantOperator;
typedef P1ConstantOperator< P1FenicsForm< fenics::NoAssemble, p1_to_p2_tet_divt_tet_cell_integral_1_otherwise > >
    P1ToP1DivTyVertexToVertexConstantOperator;
typedef P1ConstantOperator< P1FenicsForm< fenics::UndefinedAssembly, p1_to_p2_tet_divt_tet_cell_integral_2_otherwise > >
    P1ToP1DivTzVertexToVertexConstantOperator;

} // namespace hyteg

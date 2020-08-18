/*
 * Copyright (c) 2017-2019 Dominik Thoennes, Marcus Mohr, Nils Kohl.
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

#include "hyteg/p1functionspace/P1Function.hpp"
#include "hyteg/FunctionProperties.hpp"

namespace hyteg {

template <typename ValueType>
class P1StokesFunction
{
public:

  typedef ValueType valueType;

  template< typename VType >
  using FunctionType = P1StokesFunction< VType >;

  typedef P1Function< ValueType > VelocityFunction_T;
  typedef P1Function< ValueType > PressureFunction_T;
  typedef typename FunctionTrait< P1StokesFunction< ValueType > >::Tag Tag;

    P1StokesFunction(const std::string& _name, const std::shared_ptr< PrimitiveStorage > & storage, size_t minLevel, size_t maxLevel)
    : u(_name+"_u", storage, minLevel, maxLevel),
      v(_name+"_v", storage, minLevel, maxLevel),
      w( storage->hasGlobalCells() ? P1Function< ValueType >( _name+"_w", storage, minLevel, maxLevel ) :  P1Function< ValueType >( _name+"_w_dummy", storage )),
      p(_name+"_p", storage, minLevel, maxLevel, BoundaryCondition::createAllInnerBC() )
  {
  }

  std::shared_ptr< PrimitiveStorage > getStorage() const { return u.getStorage(); }

  bool isDummy() const { return false; }

  void interpolate(const std::function<real_t(const hyteg::Point3D&)>& expr, size_t level, DoFType flag = All) const
  {
    u.interpolate(expr, level, flag);
    v.interpolate(expr, level, flag);
    w.interpolate(expr, level, flag);
    p.interpolate(expr, level, flag);
  }

  void interpolate( const real_t& constant, size_t level, DoFType flag = All ) const
  {
     u.interpolate( constant, level, flag );
     v.interpolate( constant, level, flag );
     w.interpolate( constant, level, flag );
     p.interpolate( constant, level, flag );
  }

   /// \brief Copies all values function data from other to this.
   ///
   /// This method can be used safely if the other function is located on a different PrimitiveStorage.
   /// This method also works, if the storages are distributed differently.
   ///
   /// \param other another function
   /// \param level the refinement level
   /// \param localPrimitiveIDsToRank Map that contains as keys all primitive IDs of all primitives that are local regarding the
   ///                                storage of this function, and as values the MPI ranks of the processes that own these
   ///                                primitives regarding the storage of the other function
   /// \param otherPrimitiveIDsToRank Map that contains as keys all primitive IDs of all primitives that are local regarding the
   ///                                storage of the other function, and as values the MPI ranks of the processes that own these
   ///                                primitives regarding the storage this function lives on.
   ///
   void copyFrom( const P1StokesFunction< ValueType >&           other,
                  const uint_t&                                  level,
                  const std::map< PrimitiveID::IDType, uint_t >& localPrimitiveIDsToRank,
                  const std::map< PrimitiveID::IDType, uint_t >& otherPrimitiveIDsToRank ) const
   {
      u.copyFrom( other.u, level, localPrimitiveIDsToRank, otherPrimitiveIDsToRank );
      v.copyFrom( other.v, level, localPrimitiveIDsToRank, otherPrimitiveIDsToRank );
      w.copyFrom( other.w, level, localPrimitiveIDsToRank, otherPrimitiveIDsToRank );
      p.copyFrom( other.p, level, localPrimitiveIDsToRank, otherPrimitiveIDsToRank );
   }

  void swap( const P1StokesFunction< ValueType > & other,
             const uint_t & level,
             const DoFType & flag = All ) const
  {
    u.swap( other.u, level, flag );
    v.swap( other.v, level, flag );
    w.swap( other.w, level, flag );
    p.swap( other.p, level, flag );
  }

  void assign( const std::vector< walberla::real_t >                                               scalars,
               const std::vector< std::reference_wrapper< const P1StokesFunction< ValueType > > >& functions,
               size_t                                                                              level,
               DoFType                                                                             flag = All ) const
  {
     std::vector< std::reference_wrapper< const P1Function< ValueType > > > functions_u;
     std::vector< std::reference_wrapper< const P1Function< ValueType > > > functions_v;
     std::vector< std::reference_wrapper< const P1Function< ValueType > > > functions_w;
     std::vector< std::reference_wrapper< const P1Function< ValueType > > > functions_p;

     for( const P1StokesFunction< ValueType >& function : functions )
     {
        functions_u.push_back( function.u );
        functions_v.push_back( function.v );
        functions_w.push_back( function.w );
        functions_p.push_back( function.p );
     }

     u.assign( scalars, functions_u, level, flag );
     v.assign( scalars, functions_v, level, flag );
     w.assign( scalars, functions_w, level, flag );
     p.assign( scalars, functions_p, level, flag );
  }

  void add( const std::vector< walberla::real_t >                                               scalars,
            const std::vector< std::reference_wrapper< const P1StokesFunction< ValueType > > >& functions,
            size_t                                                                              level,
            DoFType                                                                             flag = All ) const
  {
     std::vector< std::reference_wrapper< const P1Function< ValueType > > > functions_u;
     std::vector< std::reference_wrapper< const P1Function< ValueType > > > functions_v;
     std::vector< std::reference_wrapper< const P1Function< ValueType > > > functions_w;
     std::vector< std::reference_wrapper< const P1Function< ValueType > > > functions_p;

     for( const P1StokesFunction< ValueType >& function : functions )
     {
        functions_u.push_back( function.u );
        functions_v.push_back( function.v );
        functions_w.push_back( function.w );
        functions_p.push_back( function.p );
     }

     u.add( scalars, functions_u, level, flag );
     v.add( scalars, functions_v, level, flag );
     w.add( scalars, functions_w, level, flag );
     p.add( scalars, functions_p, level, flag );
  }

  walberla::real_t dotGlobal(const P1StokesFunction<ValueType>& rhs,const uint_t level,const DoFType flag = All) const
  {
    walberla::real_t sum = u.dotLocal(rhs.u, level, flag);
    sum += v.dotLocal(rhs.v, level, flag);
    sum += w.dotLocal(rhs.w, level, flag);
    sum += p.dotLocal(rhs.p, level, flag);
    walberla::mpi::allReduceInplace( sum, walberla::mpi::SUM, walberla::mpi::MPIManager::instance()->comm() );
    return sum;
  }

  void enableTiming( const std::shared_ptr< walberla::WcTimingTree > & timingTree )
  {
    u.enableTiming(timingTree);
    v.enableTiming(timingTree);
    w.enableTiming(timingTree);
    p.enableTiming(timingTree);
  }

  void enumerate( uint_t level )
  {
    uint_t counterVertexDoFs = hyteg::numberOfLocalDoFs< Tag >( *( u.getStorage() ), level );

    std::vector< uint_t > vertexDoFsPerRank = walberla::mpi::allGather( counterVertexDoFs );

    ValueType offset = 0;

    for( uint_t i = 0; i < uint_c( walberla::MPIManager::instance()->rank() ); ++i )
    {
      offset += static_cast< ValueType >( vertexDoFsPerRank[i] );
    }

    u.enumerate( level, offset );
    v.enumerate( level, offset );
    w.enumerate( level, offset );
    p.enumerate( level, offset );
  }

  BoundaryCondition getVelocityBoundaryCondition() const
  {
     auto bc_u = u.getBoundaryCondition();
     WALBERLA_DEBUG_SECTION()
     {
        auto bc_v = v.getBoundaryCondition();
        auto bc_w = w.getBoundaryCondition();
        WALBERLA_CHECK_EQUAL( bc_u, bc_v, "Velocity components do not have same boundary conditions." );
        WALBERLA_CHECK_EQUAL( bc_u, bc_w, "Velocity components do not have same boundary conditions." );
     }
     return bc_u;
  }

  BoundaryCondition getPressureBoundaryCondition() const { return p.getBoundaryCondition(); }

  void setVelocityBoundaryCondition( BoundaryCondition bc )
  {
     u.setBoundaryCondition( bc );
     v.setBoundaryCondition( bc );
     w.setBoundaryCondition( bc );
  }

  void setPressureBoundaryCondition( BoundaryCondition bc ) { p.setBoundaryCondition( bc ); }

  void copyBoundaryConditionFromFunction( const P1StokesFunction< ValueType >& other )
  {
     setVelocityBoundaryCondition( other.getVelocityBoundaryCondition() );
     setPressureBoundaryCondition( other.getPressureBoundaryCondition() );
  }

  P1Function< ValueType > u;
  P1Function< ValueType > v;
  P1Function< ValueType > w;
  P1Function< ValueType > p;
};

}


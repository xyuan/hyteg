
#pragma once

#include "tinyhhg_core/gridtransferoperators/RestrictionOperator.hpp"
#include "tinyhhg_core/p1functionspace/P1Function.hpp"

namespace hhg {

class P1toP1InjectionRestriction : public RestrictionOperator< P1Function< real_t > >
{
 public:
   void restrict ( const P1Function< real_t > & function, const uint_t & sourceLevel, const DoFType & flag ) const override
   {
     if ( function.isDummy() )
       return;

     if ( function.getStorage()->hasGlobalCells() )
     {
       WALBERLA_ABORT( "P1 -> P1 injection currently not implemented for 3D." )
     }
     else
     {
       restrict2D( function, sourceLevel, flag );
     }
   }

 private:

   void restrict2D( const P1Function< real_t >& function, const uint_t& sourceLevel, const DoFType& flag ) const;

   void restrict3D( const P1Function< real_t >& function, const uint_t& sourceLevel, const DoFType& flag ) const;

   void restrictMacroVertex( const real_t* src, real_t* dst, const uint_t& sourceLevel ) const;

   void restrictMacroEdge( const real_t* src, real_t* dst, const uint_t& sourceLevel ) const;

   void restrictMacroFace( const real_t* src, real_t* dst, const uint_t& sourceLevel ) const;
};

} // namespace hhg
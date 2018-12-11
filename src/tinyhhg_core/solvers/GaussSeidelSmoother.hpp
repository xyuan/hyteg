#pragma once

#include "tinyhhg_core/solvers/Solver.hpp"
#include "core/DataTypes.h"



namespace hhg {

template < class OperatorType >
class GaussSeidelSmoother : public Solver< OperatorType >
{
 public:
   GaussSeidelSmoother()
   : flag_( hhg::Inner | hhg::NeumannBoundary )
   {}

   void solve( const OperatorType&                   A,
               const typename OperatorType::srcType& x,
               const typename OperatorType::dstType& b,
               const walberla::uint_t                level ) override
   {
      A.smooth_gs( x, b, level, flag_ );
   }

 private:
   DoFType flag_;
};

} // namespace hhg
#pragma once

#include "hyteg/p1functionspace/P1ConstantOperator.hpp"
#include "hyteg/primitivestorage/PrimitiveStorage.hpp"
#include "hyteg/solvers/GeometricMultigridSolver.hpp"
#include "hyteg/solvers/Solver.hpp"

namespace hyteg {

template < class OperatorType, class pressureBlockPreconditionerType >
class StokesPressureBlockPreconditioner : public Solver< OperatorType >
{
 public:
   typedef typename OperatorType::srcType FunctionType;

   StokesPressureBlockPreconditioner( const std::shared_ptr< PrimitiveStorage >& storage, uint_t minLevel, uint_t maxLevel )
   : pressureBlockPreconditioner_( std::make_shared< pressureBlockPreconditionerType >( storage, minLevel, maxLevel ) )
   , flag_( hyteg::Inner | hyteg::NeumannBoundary )
   {}

   void solve( const OperatorType&, const FunctionType& x, const FunctionType& b, const uint_t level ) override
   {
      b.assign( {1.0}, {x}, level, flag_ );
      pressureBlockPreconditioner_->apply( x.p, b.p, level, flag_, Replace );
   }

 private:
   std::shared_ptr< pressureBlockPreconditionerType > pressureBlockPreconditioner_;
   hyteg::DoFType                                       flag_;
};

} // namespace hyteg
#pragma once

#include "tinyhhg_core/FunctionMemory.hpp"
#include "tinyhhg_core/PrimitiveID.hpp"
#include "tinyhhg_core/StencilMemory.hpp"
#include "tinyhhg_core/primitives/Face.hpp"

namespace hhg {
namespace P2 {
namespace macroface {

void smoothJacobiVertexDoF( const uint_t&                                            level,
                            const Face&                                              face,
                            const PrimitiveDataID< StencilMemory< real_t >, Face >&  vertexDoFStencilID,
                            const PrimitiveDataID< FunctionMemory< real_t >, Face >& srcVertexDoFID,
                            const PrimitiveDataID< FunctionMemory< real_t >, Face >& dstVertexDoFID,
                            const PrimitiveDataID< StencilMemory< real_t >, Face >&  edgeDoFStencilID,
                            const PrimitiveDataID< FunctionMemory< real_t >, Face >& srcEdgeDoFID,
                            const PrimitiveDataID< FunctionMemory< real_t >, Face >& rhsVertexDoFID,
                            const real_t                                             dampingFactor = 2.0 / 3.0 );

void smoothJacobiEdgeDoF( const uint_t&                                            Level,
                          const Face&                                              face,
                          const PrimitiveDataID< StencilMemory< real_t >, Face >&  vertexDoFStencilID,
                          const PrimitiveDataID< FunctionMemory< real_t >, Face >& srcVertexDoFID,
                          const PrimitiveDataID< StencilMemory< real_t >, Face >&  edgeDoFStencilID,
                          const PrimitiveDataID< FunctionMemory< real_t >, Face >& srcEdgeDoFID,
                          const PrimitiveDataID< FunctionMemory< real_t >, Face >& dstEdgeDoFID,
                          const PrimitiveDataID< FunctionMemory< real_t >, Face >& rhsEdgeDoFID,
                          const real_t                                             dampingFactor = 2.0 / 3.0 );

void smoothGaussSeidel( const uint_t&                                            level,
                        const Face&                                              face,
                        const PrimitiveDataID< StencilMemory< real_t >, Face >&  vertexToVertexStencilID,
                        const PrimitiveDataID< StencilMemory< real_t >, Face >&  edgeToVertexStencilID,
                        const PrimitiveDataID< FunctionMemory< real_t >, Face >& dstVertexDoFID,
                        const PrimitiveDataID< StencilMemory< real_t >, Face >&  vertexToEdgeStencilID,
                        const PrimitiveDataID< StencilMemory< real_t >, Face >&  edgeToEdgeStencilID,
                        const PrimitiveDataID< FunctionMemory< real_t >, Face >& dstEdgeDoFID,
                        const PrimitiveDataID< FunctionMemory< real_t >, Face >& rhsVertexDoFID,
                        const PrimitiveDataID< FunctionMemory< real_t >, Face >& rhsEdgeDoFID );

} // namespace macroface
} // namespace P2
} // namespace hhg

#include "tinyhhg_core/gridtransferoperators/P1toP1InjectionRestriction.hpp"

#include "tinyhhg_core/FunctionMemory.hpp"
#include "tinyhhg_core/Levelinfo.hpp"
#include "tinyhhg_core/p1functionspace/VertexDoFIndexing.hpp"

namespace hhg {

void P1toP1InjectionRestriction::restrict2D( const P1Function< real_t >& function,
                                             const uint_t&               sourceLevel,
                                             const DoFType&              flag ) const
{
   const uint_t destinationLevel  = sourceLevel - 1;
   const auto   storage           = function.getStorage();
   const auto   boundaryCondition = function.getBoundaryCondition();

   function.communicate< Vertex, Edge >( sourceLevel );
   function.communicate< Edge, Face >( sourceLevel );
   function.communicate< Face, Edge >( sourceLevel );
   function.communicate< Edge, Vertex >( sourceLevel );

   for ( const auto& it : storage->getVertices() )
   {
      const Vertex& vertex  = *it.second;
      const auto    srcData = vertex.getData( function.getVertexDataID() )->getPointer( sourceLevel );
      auto          dstData = vertex.getData( function.getVertexDataID() )->getPointer( destinationLevel );

      if ( testFlag( boundaryCondition.getBoundaryType( vertex.getMeshBoundaryFlag() ), flag ) )
      {
         restrictMacroVertex( srcData, dstData, sourceLevel );
      }
   }

   for ( const auto& it : storage->getEdges() )
   {
      const Edge& edge    = *it.second;
      const auto  srcData = edge.getData( function.getEdgeDataID() )->getPointer( sourceLevel );
      auto        dstData = edge.getData( function.getEdgeDataID() )->getPointer( destinationLevel );

      if ( testFlag( boundaryCondition.getBoundaryType( edge.getMeshBoundaryFlag() ), flag ) )
      {
         restrictMacroEdge( srcData, dstData, sourceLevel );
      }
   }

   for ( const auto& it : storage->getFaces() )
   {
      const Face& face    = *it.second;
      const auto  srcData = face.getData( function.getFaceDataID() )->getPointer( sourceLevel );
      auto        dstData = face.getData( function.getFaceDataID() )->getPointer( destinationLevel );

      if ( testFlag( boundaryCondition.getBoundaryType( face.getMeshBoundaryFlag() ), flag ) )
      {
         restrictMacroFace( srcData, dstData, sourceLevel );
      }
   }
}

void P1toP1InjectionRestriction::restrictMacroVertex( const real_t* src,
                                                      real_t*       dst,
                                                      const uint_t& sourceLevel) const
{
   WALBERLA_UNUSED( sourceLevel );
   dst[0] = src[0];
}

void P1toP1InjectionRestriction::restrictMacroEdge( const real_t* src,
                                                    real_t*       dst,
                                                    const uint_t& sourceLevel) const
{
   size_t rowsize_c = levelinfo::num_microvertices_per_edge( sourceLevel - 1 );

   uint_t i_c;
   for ( i_c = 1; i_c < rowsize_c - 1; ++i_c )
   {
      dst[vertexdof::macroedge::indexFromVertex( sourceLevel - 1, i_c, stencilDirection::VERTEX_C )] =
          1.0 * src[vertexdof::macroedge::indexFromVertex( sourceLevel, 2 * i_c, stencilDirection::VERTEX_C )];
   }
}

void P1toP1InjectionRestriction::restrictMacroFace( const real_t* src,
                                                    real_t*       dst,
                                                    const uint_t& sourceLevel ) const
{
   uint_t N_c   = levelinfo::num_microvertices_per_edge( sourceLevel - 1 );
   uint_t N_c_i = N_c;

   real_t tmp;

   for ( uint_t j = 1; j < N_c - 2; ++j )
   {
      for ( uint_t i = 1; i < N_c_i - 2; ++i )
      {
         tmp = src[vertexdof::macroface::indexFromVertex( sourceLevel, 2 * i, 2 * j, stencilDirection::VERTEX_C )];

         dst[vertexdof::macroface::indexFromVertex( sourceLevel - 1, i, j, stencilDirection::VERTEX_C )] = tmp;
      }

      --N_c_i;
   }
}

} // namespace hhg
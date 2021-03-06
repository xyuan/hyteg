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
#include "hyteg/dataexport/VTKOutput.hpp"

#include "core/Format.hpp"

#include "hyteg/Levelinfo.hpp"
#include "hyteg/celldofspace/CellDoFIndexing.hpp"
#include "hyteg/communication/Syncing.hpp"
#include "hyteg/dgfunctionspace/DGFunction.hpp"
#include "hyteg/edgedofspace/EdgeDoFFunction.hpp"
#include "hyteg/edgedofspace/EdgeDoFIndexing.hpp"
#include "hyteg/edgedofspace/EdgeDoFMacroCell.hpp"
#include "hyteg/facedofspace/FaceDoFIndexing.hpp"
#include "hyteg/p1functionspace/P1Function.hpp"
#include "hyteg/p1functionspace/VertexDoFFunction.hpp"
#include "hyteg/p1functionspace/VertexDoFIndexing.hpp"
#include "hyteg/p2functionspace/P2Function.hpp"

namespace hyteg {

using walberla::real_c;

static void writeXMLHeader( std::ostream& output )
{
   WALBERLA_ROOT_SECTION()
   {
      output << "<?xml version=\"1.0\"?>\n";
      output << "<VTKFile type=\"UnstructuredGrid\" version=\"0.1\">\n";
      output << " <UnstructuredGrid>\n";
   }
}

static void writeXMLFooter( std::ostream& output )
{
   WALBERLA_ROOT_SECTION()
   {
      output << " </UnstructuredGrid>\n";
      output << "</VTKFile>\n";
   }
}

static void writePieceHeader( std::ostream& output, const uint_t& numberOfPoints, const uint_t& numberOfCells )
{
   output << "<Piece "
          << "NumberOfPoints=\"" << numberOfPoints << "\" "
          << "NumberOfCells=\"" << numberOfCells << "\""
          << ">\n";
}

static void writePieceFooter( std::ostream& output )
{
   output << "</Piece>\n";
}

static void writePointsHeader( std::ostream& output )
{
   output << "<Points>\n";
   output << "<DataArray type=\"Float64\" NumberOfComponents=\"3\" format=\"ascii\">\n";
   // VTKOutput::openDataElement( output, "Float64", "", 3, VTKOutput::VTK_DATA_FORMAT::ASCII );
}

static void writePointsFooter( std::ostream& output )
{
   output << "\n</DataArray>\n";
   output << "</Points>\n";
}

VTKOutput::VTKOutput( std::string                                dir,
                      std::string                                filename,
                      const std::shared_ptr< PrimitiveStorage >& storage,
                      const uint_t&                              writeFrequency )
: dir_( std::move( dir ) )
, filename_( std::move( filename ) )
, writeFrequency_( writeFrequency )
, write2D_( true )
, storage_( storage )
{
   /// set output to 3D is storage contains cells
   if ( storage->hasGlobalCells() )
   {
      set3D();
   }
}

void VTKOutput::add( const P2Function< real_t > function )
{
   p2Functions_.push_back( function );
   // p1Functions_.push_back( function.getVertexDoFFunctionCopy() );
   // edgeDoFFunctions_.push_back( function.getEdgeDoFFunctionCopy() );
}

void VTKOutput::add( const P1VectorFunction< real_t > function )
{
   p1VecFunctions_.push_back( function );
}

void VTKOutput::add( const P2VectorFunction< real_t > function )
{
   p2VecFunctions_.push_back( function );
}

void VTKOutput::add( P1Function< real_t > function )
{
   p1Functions_.push_back( function );
}

void VTKOutput::add( EdgeDoFFunction< real_t > function )
{
   edgeDoFFunctions_.push_back( function );
}

void VTKOutput::add( DGFunction< real_t > function )
{
   dgFunctions_.push_back( function );
}

void VTKOutput::add( P1StokesFunction< real_t > function )
{
   add( function.uvw );
   add( function.p );
}

void VTKOutput::add( P2P1TaylorHoodFunction< real_t > function )
{
   add( function.uvw );
   add( function.p );
}

void VTKOutput::writeVertexDoFData( std::ostream&                                 output,
                                    const vertexdof::VertexDoFFunction< real_t >& function,
                                    const std::shared_ptr< PrimitiveStorage >&    storage,
                                    const uint_t&                                 level ) const
{
   if ( write2D_ )
   {
      for ( const auto& it : storage->getFaces() )
      {
         const Face& face = *it.second;

         size_t len = levelinfo::num_microvertices_per_face( level );
         output << std::scientific;

         for ( size_t i = 0; i < len; ++i )
         {
            output << face.getData( function.getFaceDataID() )->getPointer( level )[i] << " ";
         }
      }
   }
   else
   {
      for ( const auto& it : storage->getCells() )
      {
         const Cell& cell     = *it.second;
         const auto  cellData = cell.getData( function.getCellDataID() )->getPointer( level );

         output << std::scientific;

         for ( const auto& idxIt : vertexdof::macrocell::Iterator( level ) )
         {
            output << cellData[vertexdof::macrocell::index( level, idxIt.x(), idxIt.y(), idxIt.z() )] << " ";
         }
      }
   }
}

void VTKOutput::writeP1VectorFunctionData( std::ostream&                              output,
                                           const P1VectorFunction< real_t >&          function,
                                           const std::shared_ptr< PrimitiveStorage >& storage,
                                           const uint_t&                              level ) const
{
   if ( write2D_ )
   {
      for ( const auto& it : storage->getFaces() )
      {
         const Face& face = *it.second;

         size_t len = levelinfo::num_microvertices_per_face( level );
         output << std::scientific;

         for ( size_t i = 0; i < len; ++i )
         {
            output << face.getData( function[0].getFaceDataID() )->getPointer( level )[i] << " ";
            output << face.getData( function[1].getFaceDataID() )->getPointer( level )[i] << " ";
            // output << real_t(0) << " "; Paraview needs 3D vector fields to form glyphs
         }
      }
   }
   else
   {
      for ( const auto& it : storage->getCells() )
      {
         const Cell& cell      = *it.second;
         const auto  cellData0 = cell.getData( function[0].getCellDataID() )->getPointer( level );
         const auto  cellData1 = cell.getData( function[1].getCellDataID() )->getPointer( level );
         const auto  cellData2 = cell.getData( function[2].getCellDataID() )->getPointer( level );

         output << std::scientific;

         for ( const auto& idxIt : vertexdof::macrocell::Iterator( level ) )
         {
            output << cellData0[vertexdof::macrocell::index( level, idxIt.x(), idxIt.y(), idxIt.z() )] << " ";
            output << cellData1[vertexdof::macrocell::index( level, idxIt.x(), idxIt.y(), idxIt.z() )] << " ";
            output << cellData2[vertexdof::macrocell::index( level, idxIt.x(), idxIt.y(), idxIt.z() )] << " ";
         }
      }
   }
}

void VTKOutput::writeEdgeDoFData( std::ostream&                              output,
                                  const EdgeDoFFunction< real_t >&           function,
                                  const std::shared_ptr< PrimitiveStorage >& storage,
                                  const uint_t&                              level,
                                  const DoFType&                             dofType ) const
{
   WALBERLA_ASSERT( dofType == VTKOutput::DoFType::EDGE_X || dofType == VTKOutput::DoFType::EDGE_Y ||
                    dofType == VTKOutput::DoFType::EDGE_Z || dofType == VTKOutput::DoFType::EDGE_XY ||
                    dofType == VTKOutput::DoFType::EDGE_XZ || dofType == VTKOutput::DoFType::EDGE_YZ ||
                    dofType == VTKOutput::DoFType::EDGE_XYZ );

   if ( write2D_ )
   {
      for ( const auto& it : storage->getFaces() )
      {
         const Face& face = *it.second;

         output << std::scientific;

         switch ( dofType )
         {
         case VTKOutput::DoFType::EDGE_X:
         {
            for ( const auto& itIdx : edgedof::macroface::Iterator( level ) )
            {
               output << face.getData( function.getFaceDataID() )
                             ->getPointer( level )[edgedof::macroface::horizontalIndex( level, itIdx.col(), itIdx.row() )]
                      << "\n";
            }
            break;
         }
         case VTKOutput::DoFType::EDGE_Y:
         {
            for ( const auto& itIdx : edgedof::macroface::Iterator( level ) )
            {
               output << face.getData( function.getFaceDataID() )
                             ->getPointer( level )[edgedof::macroface::verticalIndex( level, itIdx.col(), itIdx.row() )]
                      << "\n";
            }
            break;
         }
         case VTKOutput::DoFType::EDGE_XY:
         {
            for ( const auto& itIdx : edgedof::macroface::Iterator( level ) )
            {
               output << face.getData( function.getFaceDataID() )
                             ->getPointer( level )[edgedof::macroface::diagonalIndex( level, itIdx.col(), itIdx.row() )]
                      << "\n";
            }
            break;
         }
         default:
            WALBERLA_ABORT( "Bad DoF type in VTK output for edge DoFs" );
            break;
         }
      }
   }
   else
   {
      for ( const auto& it : storage->getCells() )
      {
         const Cell& cell     = *it.second;
         const auto  cellData = cell.getData( function.getCellDataID() )->getPointer( level );

         output << std::scientific;

         if ( dofType == VTKOutput::DoFType::EDGE_XYZ )
         {
            for ( const auto& itIdx : edgedof::macrocell::IteratorXYZ( level ) )
            {
               output << cellData[edgedof::macrocell::xyzIndex( level, itIdx.x(), itIdx.y(), itIdx.z() )] << "\n";
            }
         }
         else
         {
            for ( const auto& itIdx : edgedof::macrocell::Iterator( level ) )
            {
               uint_t idx;
               switch ( dofType )
               {
               case VTKOutput::DoFType::EDGE_X:
                  idx = edgedof::macrocell::xIndex( level, itIdx.x(), itIdx.y(), itIdx.z() );
                  break;
               case VTKOutput::DoFType::EDGE_Y:
                  idx = edgedof::macrocell::yIndex( level, itIdx.x(), itIdx.y(), itIdx.z() );
                  break;
               case VTKOutput::DoFType::EDGE_Z:
                  idx = edgedof::macrocell::zIndex( level, itIdx.x(), itIdx.y(), itIdx.z() );
                  break;
               case VTKOutput::DoFType::EDGE_XY:
                  idx = edgedof::macrocell::xyIndex( level, itIdx.x(), itIdx.y(), itIdx.z() );
                  break;
               case VTKOutput::DoFType::EDGE_XZ:
                  idx = edgedof::macrocell::xzIndex( level, itIdx.x(), itIdx.y(), itIdx.z() );
                  break;
               case VTKOutput::DoFType::EDGE_YZ:
                  idx = edgedof::macrocell::yzIndex( level, itIdx.x(), itIdx.y(), itIdx.z() );
                  break;
               default:
                  WALBERLA_ABORT( "[VTK] Invalid DoFType" );
                  break;
               }
               output << cellData[idx] << "\n";
            }
         }
      }
   }
}

const std::map< VTKOutput::DoFType, std::string > VTKOutput::DoFTypeToString_ = {
    {DoFType::VERTEX, "VertexDoF"},
    {DoFType::EDGE_X, "XEdgeDoF"},
    {DoFType::EDGE_Y, "YEdgeDoF"},
    {DoFType::EDGE_Z, "ZEdgeDoF"},
    {DoFType::EDGE_XY, "XYEdgeDoF"},
    {DoFType::EDGE_XZ, "XZEdgeDoF"},
    {DoFType::EDGE_YZ, "YZEdgeDoF"},
    {DoFType::EDGE_XYZ, "XYZEdgeDoF"},
    {DoFType::DG, "DGDoF"},
    {DoFType::P2, "P2"},
};

std::string VTKOutput::fileNameExtension( const VTKOutput::DoFType& dofType, const uint_t& level, const uint_t& timestep ) const
{
   return walberla::format( "_%s_level%u_ts%u", DoFTypeToString_.at( dofType ).c_str(), level, timestep );
}

void VTKOutput::writePointsForMicroVertices( std::ostream&                              output,
                                             const std::shared_ptr< PrimitiveStorage >& storage,
                                             const uint_t&                              level ) const
{
   if ( write2D_ )
   {
      for ( const auto& it : storage->getFaces() )
      {
         Face& face = *it.second;

         size_t  rowsize = levelinfo::num_microvertices_per_edge( level );
         Point3D x, x0, xBlend;

         x0 = face.coords[0];

         Point3D d0 = ( face.coords[1] - face.coords[0] ) / ( real_c( rowsize ) - 1 );
         Point3D d2 = ( face.coords[2] - face.coords[0] ) / ( real_c( rowsize ) - 1 );

         size_t inner_rowsize = rowsize;

         for ( size_t i = 0; i < rowsize; ++i )
         {
            x = x0;
            x += real_c( i ) * d2;

            for ( size_t j = 0; j < inner_rowsize; ++j )
            {
               face.getGeometryMap()->evalF( x, xBlend );
               output << std::scientific << xBlend[0] << " " << xBlend[1] << " " << xBlend[2] << " ";
               x += d0;
            }

            --inner_rowsize;
         }
      }
   }
   else
   {
      for ( const auto& it : storage->getCells() )
      {
         const Cell& cell = *it.second;

         for ( const auto& idxIt : vertexdof::macrocell::Iterator( level, 0 ) )
         {
            const Point3D vtkPoint = vertexdof::macrocell::coordinateFromIndex( level, cell, idxIt );
            Point3D       xBlend;
            cell.getGeometryMap()->evalF( vtkPoint, xBlend );
            output << std::scientific << xBlend[0] << " " << xBlend[1] << " " << xBlend[2] << "\n";
         }
      }
   }
}

void VTKOutput::writePointsForMicroEdges( std::ostream&                              output,
                                          const std::shared_ptr< PrimitiveStorage >& storage,
                                          const uint_t&                              level,
                                          const VTKOutput::DoFType&                  dofType ) const
{
   if ( write2D_ )
   {
      WALBERLA_ASSERT( dofType == VTKOutput::DoFType::EDGE_X || dofType == VTKOutput::DoFType::EDGE_Y ||
                       dofType == VTKOutput::DoFType::EDGE_XY );

      for ( const auto& it : storage->getFaces() )
      {
         Face& face = *it.second;

         const Point3D faceBottomLeftCoords  = face.coords[0];
         const Point3D faceBottomRightCoords = face.coords[1];
         const Point3D faceTopLeftCoords     = face.coords[2];

         const Point3D horizontalMicroEdgeOffset =
             ( ( faceBottomRightCoords - faceBottomLeftCoords ) / real_c( levelinfo::num_microedges_per_edge( level ) ) ) * 0.5;
         const Point3D verticalMicroEdgeOffset =
             ( ( faceTopLeftCoords - faceBottomLeftCoords ) / real_c( levelinfo::num_microedges_per_edge( level ) ) ) * 0.5;

         Point3D xBlend;

         switch ( dofType )
         {
         case DoFType::EDGE_X:
         {
            for ( const auto& itIdx : edgedof::macroface::Iterator( level, 0 ) )
            {
               const Point3D horizontalMicroEdgePosition =
                   faceBottomLeftCoords + ( real_c( itIdx.col() * 2 + 1 ) * horizontalMicroEdgeOffset +
                                            real_c( itIdx.row() * 2 ) * verticalMicroEdgeOffset );
               face.getGeometryMap()->evalF( horizontalMicroEdgePosition, xBlend );
               output << xBlend[0] << " " << xBlend[1] << " " << xBlend[2] << "\n";
            }
            break;
         }
         case DoFType::EDGE_Y:
         {
            for ( const auto& itIdx : edgedof::macroface::Iterator( level, 0 ) )
            {
               const Point3D verticalMicroEdgePosition =
                   faceBottomLeftCoords + ( real_c( itIdx.col() * 2 ) * horizontalMicroEdgeOffset +
                                            real_c( itIdx.row() * 2 + 1 ) * verticalMicroEdgeOffset );
               face.getGeometryMap()->evalF( verticalMicroEdgePosition, xBlend );
               output << xBlend[0] << " " << xBlend[1] << " " << xBlend[2] << "\n";
            }
            break;
         }
         case DoFType::EDGE_XY:
         {
            for ( const auto& itIdx : edgedof::macroface::Iterator( level, 0 ) )
            {
               const Point3D horizontalMicroEdgePosition =
                   faceBottomLeftCoords + ( real_c( itIdx.col() * 2 + 1 ) * horizontalMicroEdgeOffset +
                                            real_c( itIdx.row() * 2 ) * verticalMicroEdgeOffset );
               const Point3D diagonalMicroEdgePosition = horizontalMicroEdgePosition + verticalMicroEdgeOffset;
               face.getGeometryMap()->evalF( diagonalMicroEdgePosition, xBlend );
               output << xBlend[0] << " " << xBlend[1] << " " << xBlend[2] << "\n";
            }
            break;
         }
         default:
            WALBERLA_ABORT( "Bad DoF type in VTK output for edge DoFs" );
            break;
         }
      }
   }
   else
   {
      WALBERLA_ASSERT( dofType == VTKOutput::DoFType::EDGE_X || dofType == VTKOutput::DoFType::EDGE_Y ||
                       dofType == VTKOutput::DoFType::EDGE_Z || dofType == VTKOutput::DoFType::EDGE_XY ||
                       dofType == VTKOutput::DoFType::EDGE_XZ || dofType == VTKOutput::DoFType::EDGE_YZ ||
                       dofType == VTKOutput::DoFType::EDGE_XYZ );

      for ( const auto& it : storage->getCells() )
      {
         Cell&   cell = *it.second;
         Point3D microEdgePosition;

         if ( dofType == VTKOutput::DoFType::EDGE_XYZ )
         {
            for ( const auto& itIdx : edgedof::macrocell::IteratorXYZ( level, 0 ) )
            {
               microEdgePosition = vertexdof::macrocell::coordinateFromIndex( level, cell, itIdx ) +
                                   edgedof::macrocell::xShiftFromVertex( level, cell ) +
                                   edgedof::macrocell::yShiftFromVertex( level, cell ) +
                                   edgedof::macrocell::zShiftFromVertex( level, cell );
               output << microEdgePosition[0] << " " << microEdgePosition[1] << " " << microEdgePosition[2] << "\n";
            }
         }
         else
         {
            for ( const auto& itIdx : edgedof::macrocell::Iterator( level, 0 ) )
            {
               microEdgePosition = vertexdof::macrocell::coordinateFromIndex( level, cell, itIdx );
               switch ( dofType )
               {
               case DoFType::EDGE_X:
                  microEdgePosition += edgedof::macrocell::xShiftFromVertex( level, cell );
                  break;
               case DoFType::EDGE_Y:
                  microEdgePosition += edgedof::macrocell::yShiftFromVertex( level, cell );
                  break;
               case DoFType::EDGE_Z:
                  microEdgePosition += edgedof::macrocell::zShiftFromVertex( level, cell );
                  break;
               case DoFType::EDGE_XY:
                  microEdgePosition +=
                      edgedof::macrocell::xShiftFromVertex( level, cell ) + edgedof::macrocell::yShiftFromVertex( level, cell );
                  break;
               case DoFType::EDGE_XZ:
                  microEdgePosition +=
                      edgedof::macrocell::xShiftFromVertex( level, cell ) + edgedof::macrocell::zShiftFromVertex( level, cell );
                  break;
               case DoFType::EDGE_YZ:
                  microEdgePosition +=
                      edgedof::macrocell::yShiftFromVertex( level, cell ) + edgedof::macrocell::zShiftFromVertex( level, cell );
                  break;
               default:
                  WALBERLA_ABORT( "[VTK] Invalid DoFType" );
                  break;
               }
               output << microEdgePosition[0] << " " << microEdgePosition[1] << " " << microEdgePosition[2] << "\n";
            }
         }
      }
   }
}

void VTKOutput::writeCells2D( std::ostream&                              output,
                              const std::shared_ptr< PrimitiveStorage >& storage,
                              const uint_t&                              faceWidth ) const
{
   output << "<Cells>\n";
   openDataElement( output, "Int32", "connectivity", 0, VTK_DATA_FORMAT::ASCII );

   const uint_t numberOfCells = ( ( ( faceWidth - 1 ) * faceWidth ) / 2 ) + ( ( ( faceWidth - 2 ) * ( faceWidth - 1 ) ) / 2 );

   // connectivity
   size_t offset = 0;

   for ( auto& it : storage->getFaces() )
   {
      //TODO is it really unused?
      WALBERLA_UNUSED( it );
      size_t rowsize       = faceWidth - 1;
      size_t inner_rowsize = rowsize;

      for ( size_t i = 0; i < rowsize; ++i )
      {
         for ( size_t j = 0; j < inner_rowsize - 1; ++j )
         {
            output << offset << " " << offset + 1 << " " << offset + inner_rowsize + 1 << " ";
            output << offset + 1 << " " << offset + inner_rowsize + 2 << " " << offset + inner_rowsize + 1 << " ";
            ++offset;
         }

         output << offset << " " << offset + 1 << " " << offset + inner_rowsize + 1 << " ";

         offset += 2;
         --inner_rowsize;
      }

      ++offset;
   }

   output << "\n</DataArray>\n";
   openDataElement( output, "Int32", "offsets", 0, VTK_DATA_FORMAT::ASCII );

   // offsets
   offset = 3;
   for ( auto& it : storage->getFaces() )
   {
      WALBERLA_UNUSED( it );

      for ( size_t i = 0; i < numberOfCells; ++i )
      {
         output << offset << " ";
         offset += 3;
      }
   }

   output << "\n</DataArray>\n";
   openDataElement( output, "UInt8", "types", 0, VTK_DATA_FORMAT::ASCII );

   // cell types
   for ( auto& it : storage->getFaces() )
   {
      WALBERLA_UNUSED( it );
      for ( size_t i = 0; i < numberOfCells; ++i )
      {
         output << "5 ";
      }
   }

   output << "\n</DataArray>\n";
   output << "</Cells>\n";
}

void VTKOutput::writeCells3D( std::ostream&                              output,
                              const std::shared_ptr< PrimitiveStorage >& storage,
                              const uint_t&                              width ) const
{
   output << "<Cells>\n";
   openDataElement( output, "Int32", "connectivity", 0, VTK_DATA_FORMAT::ASCII );

   // calculates the position of the point in the VTK list of points from a logical vertex index
   auto calcVTKPointArrayPosition = [width]( const indexing::Index& vertexIndex ) -> uint_t {
      const uint_t zOffset = levelinfo::num_microvertices_per_cell_from_width( width ) -
                             levelinfo::num_microvertices_per_cell_from_width( width - vertexIndex.z() );
      const uint_t yOffset = levelinfo::num_microvertices_per_face_from_width( width - vertexIndex.z() ) -
                             levelinfo::num_microvertices_per_face_from_width( width - vertexIndex.z() - vertexIndex.y() );
      const uint_t xOffset = vertexIndex.x();
      return xOffset + yOffset + zOffset;
   };

   const uint_t numberOfVertices = levelinfo::num_microvertices_per_cell_from_width( width );
   const uint_t numberOfCells    = levelinfo::num_microcells_per_cell_from_width( width );

   for ( uint_t macroCellIdx = 0; macroCellIdx < storage->getNumberOfLocalCells(); macroCellIdx++ )
   {
      for ( const auto& it : indexing::CellIterator( width - 1 ) )
      {
         const auto spanningVertexIndices = celldof::macrocell::getMicroVerticesFromMicroCell( it, celldof::CellType::WHITE_UP );

         for ( const auto& spanningVertexIndex : spanningVertexIndices )
         {
            output << macroCellIdx * numberOfVertices + calcVTKPointArrayPosition( spanningVertexIndex ) << " ";
         }
         output << "\n";
      }

      for ( const auto& it : indexing::CellIterator( width - 2 ) )
      {
         const auto spanningVertexIndices = celldof::macrocell::getMicroVerticesFromMicroCell( it, celldof::CellType::BLUE_UP );

         for ( const auto& spanningVertexIndex : spanningVertexIndices )
         {
            output << macroCellIdx * numberOfVertices + calcVTKPointArrayPosition( spanningVertexIndex ) << " ";
         }
         output << "\n";
      }

      for ( const auto& it : indexing::CellIterator( width - 2 ) )
      {
         const auto spanningVertexIndices = celldof::macrocell::getMicroVerticesFromMicroCell( it, celldof::CellType::GREEN_UP );

         for ( const auto& spanningVertexIndex : spanningVertexIndices )
         {
            output << macroCellIdx * numberOfVertices + calcVTKPointArrayPosition( spanningVertexIndex ) << " ";
         }
         output << "\n";
      }

      for ( const auto& it : indexing::CellIterator( width - 3 ) )
      {
         const auto spanningVertexIndices =
             celldof::macrocell::getMicroVerticesFromMicroCell( it, celldof::CellType::WHITE_DOWN );

         for ( const auto& spanningVertexIndex : spanningVertexIndices )
         {
            output << macroCellIdx * numberOfVertices + calcVTKPointArrayPosition( spanningVertexIndex ) << " ";
         }
         output << "\n";
      }

      for ( const auto& it : indexing::CellIterator( width - 2 ) )
      {
         const auto spanningVertexIndices = celldof::macrocell::getMicroVerticesFromMicroCell( it, celldof::CellType::BLUE_DOWN );

         for ( const auto& spanningVertexIndex : spanningVertexIndices )
         {
            output << macroCellIdx * numberOfVertices + calcVTKPointArrayPosition( spanningVertexIndex ) << " ";
         }
         output << "\n";
      }

      for ( const auto& it : indexing::CellIterator( width - 2 ) )
      {
         const auto spanningVertexIndices =
             celldof::macrocell::getMicroVerticesFromMicroCell( it, celldof::CellType::GREEN_DOWN );

         for ( const auto& spanningVertexIndex : spanningVertexIndices )
         {
            output << macroCellIdx * numberOfVertices + calcVTKPointArrayPosition( spanningVertexIndex ) << " ";
         }
         output << "\n";
      }
   }

   output << "\n</DataArray>\n";
   openDataElement( output, "Int32", "offsets", 0, VTK_DATA_FORMAT::ASCII );

   // offsets
   uint_t offset = 4;
   for ( const auto& it : storage->getCells() )
   {
      WALBERLA_UNUSED( it );

      for ( size_t i = 0; i < numberOfCells; ++i )
      {
         output << offset << " ";
         offset += 4;
      }
   }

   output << "\n</DataArray>\n";
   openDataElement( output, "UInt8", "types", 0, VTK_DATA_FORMAT::ASCII );

   // cell types
   for ( const auto& it : storage->getCells() )
   {
      WALBERLA_UNUSED( it );
      for ( size_t i = 0; i < numberOfCells; ++i )
      {
         output << "10 ";
      }
   }

   output << "\n</DataArray>\n";
   output << "</Cells>\n";
}

void VTKOutput::writeP1( std::ostream& output, const uint_t& level ) const
{
   if ( getNumRegisteredFunctions( DoFType::VERTEX ) == 0 )
   {
      return;
   }

   //auto storage = p1Functions_[0].getStorage();
   auto storage = storage_;

   const uint_t numberOfPoints2D = storage->getNumberOfLocalFaces() * levelinfo::num_microvertices_per_face( level );
   const uint_t numberOfCells2D  = storage->getNumberOfLocalFaces() * levelinfo::num_microfaces_per_face( level );

   const uint_t numberOfPoints3D = storage->getNumberOfLocalCells() * levelinfo::num_microvertices_per_cell( level );
   const uint_t numberOfCells3D  = storage->getNumberOfLocalCells() * levelinfo::num_microcells_per_cell( level );

   if ( write2D_ )
   {
      writePieceHeader( output, numberOfPoints2D, numberOfCells2D );
   }
   else
   {
      writePieceHeader( output, numberOfPoints3D, numberOfCells3D );
   }

   writePointsHeader( output );
   writePointsForMicroVertices( output, storage, level );
   writePointsFooter( output );

   if ( write2D_ )
   {
      writeCells2D( output, storage, levelinfo::num_microvertices_per_edge( level ) );
   }
   else
   {
      writeCells3D( output, storage, levelinfo::num_microvertices_per_edge( level ) );
   }

   output << "<PointData>\n";

   for ( const auto& function : p1Functions_ )
   {
      openDataElement( output, "Float64", function.getFunctionName(), 1, VTK_DATA_FORMAT::ASCII );
      writeVertexDoFData( output, function, storage, level );
      output << "\n</DataArray>\n";
   }

   for ( const auto& function : p1VecFunctions_ )
   {
      uint_t dim = write2D_ ? 2 : 3;
      openDataElement( output, "Float64", function.getFunctionName(), dim, VTK_DATA_FORMAT::ASCII );
      writeP1VectorFunctionData( output, function, storage, level );
      output << "\n</DataArray>\n";
   }

   output << "</PointData>\n";

   writePieceFooter( output );
}

void VTKOutput::writeEdgeDoFs( std::ostream& output, const uint_t& level, const VTKOutput::DoFType& dofType ) const
{
   WALBERLA_ASSERT( dofType == VTKOutput::DoFType::EDGE_X || dofType == VTKOutput::DoFType::EDGE_Y ||
                    dofType == VTKOutput::DoFType::EDGE_Z || dofType == VTKOutput::DoFType::EDGE_XY ||
                    dofType == VTKOutput::DoFType::EDGE_XZ || dofType == VTKOutput::DoFType::EDGE_YZ ||
                    dofType == VTKOutput::DoFType::EDGE_XYZ );

   if ( edgeDoFFunctions_.size() == 0 )
   {
      return;
   }

   auto storage = edgeDoFFunctions_[0].getStorage();

   const uint_t numberOfPoints2D = storage->getNumberOfLocalFaces() * levelinfo::num_microedges_per_face( level ) / 3;
   const uint_t faceWidth        = levelinfo::num_microedges_per_edge( level );
   const uint_t numberOfCells2D  = storage->getNumberOfLocalFaces() * ( ( ( ( faceWidth - 1 ) * faceWidth ) / 2 ) +
                                                                       ( ( ( faceWidth - 2 ) * ( faceWidth - 1 ) ) / 2 ) );

   const uint_t numberOfPoints3D = storage->getNumberOfLocalCells() * [dofType, level]() {
      if ( dofType == VTKOutput::DoFType::EDGE_XYZ )
         return levelinfo::num_microvertices_per_cell_from_width( levelinfo::num_microedges_per_edge( level ) - 1 );
      else
         return levelinfo::num_microvertices_per_cell_from_width( levelinfo::num_microedges_per_edge( level ) );
   }();
   const uint_t numberOfCells3D = storage->getNumberOfLocalCells() * [dofType, level]() {
      if ( dofType == VTKOutput::DoFType::EDGE_XYZ )
         return levelinfo::num_microcells_per_cell_from_width( levelinfo::num_microedges_per_edge( level ) - 1 );
      else
         return levelinfo::num_microcells_per_cell_from_width( levelinfo::num_microedges_per_edge( level ) );
   }();

   if ( write2D_ )
   {
      writePieceHeader( output, numberOfPoints2D, numberOfCells2D );
   }
   else
   {
      writePieceHeader( output, numberOfPoints3D, numberOfCells3D );
   }
   writePointsHeader( output );
   writePointsForMicroEdges( output, storage, level, dofType );
   writePointsFooter( output );

   output << "<PointData>\n";

   for ( const auto& function : edgeDoFFunctions_ )
   {
      openDataElement( output, "Float64", function.getFunctionName(), 1, VTK_DATA_FORMAT::ASCII );

      writeEdgeDoFData( output, function, storage, level, dofType );

      output << "\n</DataArray>\n";
   }

   output << "</PointData>\n";

   if ( write2D_ )
   {
      writeCells2D( output, storage, levelinfo::num_microedges_per_edge( level ) );
   }
   else
   {
      if ( dofType == VTKOutput::DoFType::EDGE_XYZ )
         writeCells3D( output, storage, levelinfo::num_microedges_per_edge( level ) - 1 );
      else
         writeCells3D( output, storage, levelinfo::num_microedges_per_edge( level ) );
   }

   writePieceFooter( output );
}

void VTKOutput::writeDGDoFs( std::ostream& output, const uint_t& level ) const
{
   if ( dgFunctions_.size() == 0 )
   {
      return;
   }

   auto storage = dgFunctions_[0].getStorage();

   const uint_t numberOfPoints = storage->getNumberOfLocalFaces() * levelinfo::num_microvertices_per_face( level );
   const uint_t numberOfCells  = storage->getNumberOfLocalFaces() * levelinfo::num_microfaces_per_face( level );

   writePieceHeader( output, numberOfPoints, numberOfCells );

   writePointsHeader( output );
   writePointsForMicroVertices( output, storage, level );
   writePointsFooter( output );

   writeCells2D( output, storage, levelinfo::num_microvertices_per_edge( level ) );

   output << "<CellData>";

   for ( const auto& function : dgFunctions_ )
   {
      openDataElement( output, "Float64", function.getFunctionName(), 1, VTK_DATA_FORMAT::ASCII );

      for ( const auto& it : storage->getFaces() )
      {
         const Face& face = *it.second;

         uint_t rowsize       = levelinfo::num_microvertices_per_edge( level );
         uint_t inner_rowsize = rowsize;
         output << std::scientific;

         uint_t idx;

         for ( size_t j = 0; j < rowsize - 1; ++j )
         {
            for ( size_t i = 0; i < inner_rowsize - 2; ++i )
            {
               idx = facedof::macroface::indexFaceFromGrayFace( level, i, j, stencilDirection::CELL_GRAY_C );
               output << face.getData( function.getFaceDataID() )->getPointer( level )[idx] << " ";
               idx = facedof::macroface::indexFaceFromBlueFace( level, i, j, stencilDirection::CELL_BLUE_C );
               output << face.getData( function.getFaceDataID() )->getPointer( level )[idx] << " ";
            }
            idx = facedof::macroface::indexFaceFromGrayFace( level, inner_rowsize - 2, j, stencilDirection::CELL_GRAY_C );
            output << face.getData( function.getFaceDataID() )->getPointer( level )[idx] << " ";
            --inner_rowsize;
         }
      }
      output << "\n</DataArray>\n";
   }

   output << "\n</CellData>\n";

   writePieceFooter( output );
}

void VTKOutput::writeP2( std::ostream& output, const uint_t& level ) const
{
   if ( getNumRegisteredFunctions( DoFType::P2 ) == 0 )
   {
      return;
   }

   // auto storage = p2Functions_[0].getStorage();
   auto storage = storage_;

   const uint_t numberOfPoints = write2D_ ?
                                     storage->getNumberOfLocalFaces() * levelinfo::num_microvertices_per_face( level + 1 ) :
                                     storage->getNumberOfLocalCells() * levelinfo::num_microvertices_per_cell( level + 1 );
   const uint_t numberOfCells = write2D_ ? storage->getNumberOfLocalFaces() * levelinfo::num_microfaces_per_face( level + 1 ) :
                                           storage->getNumberOfLocalCells() * levelinfo::num_microcells_per_cell( level + 1 );
   ;

   writePieceHeader( output, numberOfPoints, numberOfCells );

   writePointsHeader( output );
   writePointsForMicroVertices( output, storage, level + 1 );
   writePointsFooter( output );

   if ( write2D_ )
   {
      writeCells2D( output, storage, levelinfo::num_microvertices_per_edge( level + 1 ) );
   }
   else
   {
      writeCells3D( output, storage, levelinfo::num_microvertices_per_edge( level + 1 ) );
   }

   output << "<PointData>\n";

   for ( const auto& function : p2Functions_ )
   {
      writeSingleP2Function( function, output, level );
   }

#ifdef P2_VEC_SCALAR_OUTPUT
   for ( const auto& function : p2VecFunctions_ )
   {
      for ( uint_t idx = 0; idx < ( write2D_ ? 2 : 3 ); ++idx )
      {
         writeSingleP2Function( function[idx], output, level );
      }
   }
#else
   for ( const auto& function : p2VecFunctions_ )
   {
      writeSingleP2VectorFunction( function, output, level );
   }
#endif

   output << "</PointData>\n";

   writePieceFooter( output );
}

void VTKOutput::writeSingleP2Function( const P2Function< real_t >& function, std::ostream& output, const uint_t& level ) const
{
   auto storage = function.getStorage();
   openDataElement( output, "Float64", function.getFunctionName(), 1, VTK_DATA_FORMAT::ASCII );

   if ( write2D_ )
   {
      for ( const auto& itFaces : storage->getFaces() )
      {
         const Face& face = *itFaces.second;

         output << std::scientific;

         for ( const auto& it : vertexdof::macroface::Iterator( level + 1, 0 ) )
         {
            if ( it.row() % 2 == 0 )
            {
               if ( it.col() % 2 == 0 )
               {
                  output << face.getData( function.getVertexDoFFunction().getFaceDataID() )
                                ->getPointer( level )[vertexdof::macroface::indexFromVertex(
                                    level, it.col() / 2, it.row() / 2, stencilDirection::VERTEX_C )]
                         << " ";
               }
               else
               {
                  output << face.getData( function.getEdgeDoFFunction().getFaceDataID() )
                                ->getPointer(
                                    level )[edgedof::macroface::horizontalIndex( level, ( it.col() - 1 ) / 2, it.row() / 2 )]
                         << " ";
               }
            }
            else
            {
               if ( it.col() % 2 == 0 )
               {
                  output << face.getData( function.getEdgeDoFFunction().getFaceDataID() )
                                ->getPointer(
                                    level )[edgedof::macroface::verticalIndex( level, it.col() / 2, ( it.row() - 1 ) / 2 )]
                         << " ";
               }
               else
               {
                  output
                      << face.getData( function.getEdgeDoFFunction().getFaceDataID() )
                             ->getPointer(
                                 level )[edgedof::macroface::diagonalIndex( level, ( it.col() - 1 ) / 2, ( it.row() - 1 ) / 2 )]
                      << " ";
               }
            }
         }
      }
   }
   else
   {
      for ( const auto& itCells : storage->getCells() )
      {
         const Cell& cell       = *itCells.second;
         auto        vertexData = cell.getData( function.getVertexDoFFunction().getCellDataID() )->getPointer( level );
         auto        edgeData   = cell.getData( function.getEdgeDoFFunction().getCellDataID() )->getPointer( level );

         output << std::scientific;

         for ( const auto& it : vertexdof::macrocell::Iterator( level + 1, 0 ) )
         {
            const auto   x   = it.x();
            const auto   y   = it.y();
            const auto   z   = it.z();
            const uint_t mod = ( z % 2 << 0 ) | ( y % 2 << 1 ) | ( x % 2 << 2 );

            switch ( mod )
            {
            case 0b000:
               output
                   << vertexData[vertexdof::macrocell::indexFromVertex( level, x / 2, y / 2, z / 2, stencilDirection::VERTEX_C )]
                   << " ";
               break;
            case 0b100:
               output << edgeData[edgedof::macrocell::xIndex( level, ( x - 1 ) / 2, y / 2, z / 2 )] << " ";
               break;
            case 0b010:
               output << edgeData[edgedof::macrocell::yIndex( level, x / 2, ( y - 1 ) / 2, z / 2 )] << " ";
               break;
            case 0b001:
               output << edgeData[edgedof::macrocell::zIndex( level, x / 2, y / 2, ( z - 1 ) / 2 )] << " ";
               break;
            case 0b110:
               output << edgeData[edgedof::macrocell::xyIndex( level, ( x - 1 ) / 2, ( y - 1 ) / 2, z / 2 )] << " ";
               break;
            case 0b101:
               output << edgeData[edgedof::macrocell::xzIndex( level, ( x - 1 ) / 2, y / 2, ( z - 1 ) / 2 )] << " ";
               break;
            case 0b011:
               output << edgeData[edgedof::macrocell::yzIndex( level, x / 2, ( y - 1 ) / 2, ( z - 1 ) / 2 )] << " ";
               break;
            case 0b111:
               output << edgeData[edgedof::macrocell::xyzIndex( level, ( x - 1 ) / 2, ( y - 1 ) / 2, ( z - 1 ) / 2 )] << " ";
               break;
            }
         }
      }
   }

   output << "\n</DataArray>\n";
}

void VTKOutput::writeSingleP2VectorFunction( const P2VectorFunction< real_t >& function,
                                             std::ostream&                     output,
                                             const uint_t&                     level ) const
{
   auto storage = function.getStorage();
   openDataElement( output, "Float64", function.getFunctionName(), function.getDimension(), VTK_DATA_FORMAT::ASCII );

   if ( write2D_ )
   {
      for ( const auto& itFaces : storage->getFaces() )
      {
         const Face& face = *itFaces.second;

         output << std::scientific;

         for ( const auto& it : vertexdof::macroface::Iterator( level + 1, 0 ) )
         {
            if ( it.row() % 2 == 0 )
            {
               if ( it.col() % 2 == 0 )
               {
                  output << face.getData( function[0].getVertexDoFFunction().getFaceDataID() )
                                ->getPointer( level )[vertexdof::macroface::indexFromVertex(
                                    level, it.col() / 2, it.row() / 2, stencilDirection::VERTEX_C )]
                         << " ";
                  output << face.getData( function[1].getVertexDoFFunction().getFaceDataID() )
                                ->getPointer( level )[vertexdof::macroface::indexFromVertex(
                                    level, it.col() / 2, it.row() / 2, stencilDirection::VERTEX_C )]
                         << " ";
               }
               else
               {
                  output << face.getData( function[0].getEdgeDoFFunction().getFaceDataID() )
                                ->getPointer(
                                    level )[edgedof::macroface::horizontalIndex( level, ( it.col() - 1 ) / 2, it.row() / 2 )]
                         << " ";
                  output << face.getData( function[1].getEdgeDoFFunction().getFaceDataID() )
                                ->getPointer(
                                    level )[edgedof::macroface::horizontalIndex( level, ( it.col() - 1 ) / 2, it.row() / 2 )]
                         << " ";
               }
            }
            else
            {
               if ( it.col() % 2 == 0 )
               {
                  output << face.getData( function[0].getEdgeDoFFunction().getFaceDataID() )
                                ->getPointer(
                                    level )[edgedof::macroface::verticalIndex( level, it.col() / 2, ( it.row() - 1 ) / 2 )]
                         << " ";
                  output << face.getData( function[1].getEdgeDoFFunction().getFaceDataID() )
                                ->getPointer(
                                    level )[edgedof::macroface::verticalIndex( level, it.col() / 2, ( it.row() - 1 ) / 2 )]
                         << " ";
               }
               else
               {
                  output
                      << face.getData( function[0].getEdgeDoFFunction().getFaceDataID() )
                             ->getPointer(
                                 level )[edgedof::macroface::diagonalIndex( level, ( it.col() - 1 ) / 2, ( it.row() - 1 ) / 2 )]
                      << " ";
                  output
                      << face.getData( function[1].getEdgeDoFFunction().getFaceDataID() )
                             ->getPointer(
                                 level )[edgedof::macroface::diagonalIndex( level, ( it.col() - 1 ) / 2, ( it.row() - 1 ) / 2 )]
                      << " ";
               }
            }
         }
      }
   }
   else
   {
      for ( const auto& itCells : storage->getCells() )
      {
         const Cell& cell = *itCells.second;

         auto vertexData0 = cell.getData( function[0].getVertexDoFFunction().getCellDataID() )->getPointer( level );
         auto vertexData1 = cell.getData( function[1].getVertexDoFFunction().getCellDataID() )->getPointer( level );
         auto vertexData2 = cell.getData( function[2].getVertexDoFFunction().getCellDataID() )->getPointer( level );

         auto edgeData0 = cell.getData( function[0].getEdgeDoFFunction().getCellDataID() )->getPointer( level );
         auto edgeData1 = cell.getData( function[1].getEdgeDoFFunction().getCellDataID() )->getPointer( level );
         auto edgeData2 = cell.getData( function[2].getEdgeDoFFunction().getCellDataID() )->getPointer( level );

         output << std::scientific;

         for ( const auto& it : vertexdof::macrocell::Iterator( level + 1, 0 ) )
         {
            const auto   x   = it.x();
            const auto   y   = it.y();
            const auto   z   = it.z();
            const uint_t mod = ( z % 2 << 0 ) | ( y % 2 << 1 ) | ( x % 2 << 2 );

            switch ( mod )
            {
            case 0b000:
               output
                   << vertexData0[vertexdof::macrocell::indexFromVertex( level, x / 2, y / 2, z / 2, stencilDirection::VERTEX_C )]
                   << " "
                   << vertexData1[vertexdof::macrocell::indexFromVertex( level, x / 2, y / 2, z / 2, stencilDirection::VERTEX_C )]
                   << " "
                   << vertexData2[vertexdof::macrocell::indexFromVertex( level, x / 2, y / 2, z / 2, stencilDirection::VERTEX_C )]
                   << " ";
               break;
            case 0b100:
               output << edgeData0[edgedof::macrocell::xIndex( level, ( x - 1 ) / 2, y / 2, z / 2 )] << " ";
               output << edgeData1[edgedof::macrocell::xIndex( level, ( x - 1 ) / 2, y / 2, z / 2 )] << " ";
               output << edgeData2[edgedof::macrocell::xIndex( level, ( x - 1 ) / 2, y / 2, z / 2 )] << " ";
               break;
            case 0b010:
               output << edgeData0[edgedof::macrocell::yIndex( level, x / 2, ( y - 1 ) / 2, z / 2 )] << " ";
               output << edgeData1[edgedof::macrocell::yIndex( level, x / 2, ( y - 1 ) / 2, z / 2 )] << " ";
               output << edgeData2[edgedof::macrocell::yIndex( level, x / 2, ( y - 1 ) / 2, z / 2 )] << " ";
               break;
            case 0b001:
               output << edgeData0[edgedof::macrocell::zIndex( level, x / 2, y / 2, ( z - 1 ) / 2 )] << " ";
               output << edgeData1[edgedof::macrocell::zIndex( level, x / 2, y / 2, ( z - 1 ) / 2 )] << " ";
               output << edgeData2[edgedof::macrocell::zIndex( level, x / 2, y / 2, ( z - 1 ) / 2 )] << " ";
               break;
            case 0b110:
               output << edgeData0[edgedof::macrocell::xyIndex( level, ( x - 1 ) / 2, ( y - 1 ) / 2, z / 2 )] << " ";
               output << edgeData1[edgedof::macrocell::xyIndex( level, ( x - 1 ) / 2, ( y - 1 ) / 2, z / 2 )] << " ";
               output << edgeData2[edgedof::macrocell::xyIndex( level, ( x - 1 ) / 2, ( y - 1 ) / 2, z / 2 )] << " ";
               break;
            case 0b101:
               output << edgeData0[edgedof::macrocell::xzIndex( level, ( x - 1 ) / 2, y / 2, ( z - 1 ) / 2 )] << " ";
               output << edgeData1[edgedof::macrocell::xzIndex( level, ( x - 1 ) / 2, y / 2, ( z - 1 ) / 2 )] << " ";
               output << edgeData2[edgedof::macrocell::xzIndex( level, ( x - 1 ) / 2, y / 2, ( z - 1 ) / 2 )] << " ";
               break;
            case 0b011:
               output << edgeData0[edgedof::macrocell::yzIndex( level, x / 2, ( y - 1 ) / 2, ( z - 1 ) / 2 )] << " ";
               output << edgeData1[edgedof::macrocell::yzIndex( level, x / 2, ( y - 1 ) / 2, ( z - 1 ) / 2 )] << " ";
               output << edgeData2[edgedof::macrocell::yzIndex( level, x / 2, ( y - 1 ) / 2, ( z - 1 ) / 2 )] << " ";
               break;
            case 0b111:
               output << edgeData0[edgedof::macrocell::xyzIndex( level, ( x - 1 ) / 2, ( y - 1 ) / 2, ( z - 1 ) / 2 )] << " ";
               output << edgeData1[edgedof::macrocell::xyzIndex( level, ( x - 1 ) / 2, ( y - 1 ) / 2, ( z - 1 ) / 2 )] << " ";
               output << edgeData2[edgedof::macrocell::xyzIndex( level, ( x - 1 ) / 2, ( y - 1 ) / 2, ( z - 1 ) / 2 )] << " ";
               break;
            }
         }
      }
   }

   output << "\n</DataArray>\n";
}

void VTKOutput::writeDoFByType( std::ostream& output, const uint_t& level, const VTKOutput::DoFType& dofType ) const
{
   switch ( dofType )
   {
   case DoFType::VERTEX:
      writeP1( output, level );
      break;
   case DoFType::EDGE_X:
   case DoFType::EDGE_Y:
   case DoFType::EDGE_Z:
   case DoFType::EDGE_XY:
   case DoFType::EDGE_XZ:
   case DoFType::EDGE_YZ:
   case DoFType::EDGE_XYZ:
      writeEdgeDoFs( output, level, dofType );
      break;
   case DoFType::DG:
      writeDGDoFs( output, level );
      break;
   case DoFType::P2:
      writeP2( output, level );
      break;
   default:
      WALBERLA_ABORT( "[VTK] DoFType not supported!" );
      break;
   }
}

uint_t VTKOutput::getNumRegisteredFunctions( const VTKOutput::DoFType& dofType ) const
{
   switch ( dofType )
   {
   case DoFType::VERTEX:
      return p1Functions_.size() + p1VecFunctions_.size();
   case DoFType::EDGE_X:
   case DoFType::EDGE_Y:
   case DoFType::EDGE_Z:
   case DoFType::EDGE_XY:
   case DoFType::EDGE_XZ:
   case DoFType::EDGE_YZ:
   case DoFType::EDGE_XYZ:
      return edgeDoFFunctions_.size();
   case DoFType::DG:
      return dgFunctions_.size();
      break;
   case DoFType::P2:
      return p2Functions_.size() + p2VecFunctions_.size();
      break;
   default:
      WALBERLA_ABORT( "[VTK] DoFType not supported!" );
      return 0;
   }
}

void VTKOutput::write( const uint_t& level, const uint_t& timestep ) const
{
   if ( level <= 1 )
   {
      return;
   }

   storage_->getTimingTree()->start( "VTK write" );

   if ( writeFrequency_ > 0 && timestep % writeFrequency_ == 0 )
   {
      syncAllFunctions( level );

      const std::vector< VTKOutput::DoFType > dofTypes2D = {
          DoFType::VERTEX, DoFType::EDGE_X, DoFType::EDGE_Y, DoFType::EDGE_XY, DoFType::DG, DoFType::P2};

      const std::vector< VTKOutput::DoFType > dofTypes3D = {DoFType::VERTEX,
                                                            DoFType::EDGE_X,
                                                            DoFType::EDGE_Y,
                                                            DoFType::EDGE_Z,
                                                            DoFType::EDGE_XY,
                                                            DoFType::EDGE_XZ,
                                                            DoFType::EDGE_YZ,
                                                            DoFType::EDGE_XYZ,
                                                            DoFType::DG,
                                                            DoFType::P2};

      auto dofTypes = write2D_ ? dofTypes2D : dofTypes3D;

      for ( const auto& dofType : dofTypes )
      {
         if ( getNumRegisteredFunctions( dofType ) > 0 )
         {
            const std::string completeFilePath = walberla::format(
                "%s/%s%s.vtu", dir_.c_str(), filename_.c_str(), fileNameExtension( dofType, level, timestep ).c_str() );
            //( fmt::format( "{}/{}{}.vtu", dir_, filename_, fileNameExtension( dofType, level, timestep ) ) );

            std::ostringstream output;

            writeXMLHeader( output );

            writeDoFByType( output, level, dofType );

            walberla::mpi::writeMPITextFile( completeFilePath, output.str() );

            WALBERLA_ROOT_SECTION()
            {
               std::ofstream pvtu_file;
               pvtu_file.open( completeFilePath.c_str(), std::ofstream::out | std::ofstream::app );
               WALBERLA_CHECK( !!pvtu_file, "[VTKWriter] Error opening file: " << completeFilePath );
               writeXMLFooter( pvtu_file );
               pvtu_file.close();
            }
         }
      }
   }

   storage_->getTimingTree()->stop( "VTK write" );
}

void VTKOutput::openDataElement( std::ostream&         output,
                                 const std::string&    type,
                                 const std::string&    name,
                                 const uint_t          nComponents,
                                 const VTK_DATA_FORMAT fmt ) const
{
   // open element and write type
   output << "<DataArray type=\"" << type << "\"";

   // write name, if given
   if ( name.length() > 0 )
   {
      output << " Name=\"" << name << "\"";
   }

   // write number of components, if required
   if ( nComponents > 0 )
   {
      output << " NumberOfComponents=\"" << nComponents << "\"";
   }
   // specify format
   WALBERLA_UNUSED( fmt );
   WALBERLA_ASSERT( fmt == VTK_DATA_FORMAT::ASCII, "Only ASCII is supported as VTK_DATA_FORMAT at the moment" );
   output << " format=\"ascii\">\n";
}

void VTKOutput::syncAllFunctions( const uint_t& level ) const
{
   for ( const auto& function : p1Functions_ )
   {
      hyteg::communication::syncFunctionBetweenPrimitives< hyteg::P1Function< real_t > >( function, level );
   }

   for ( const auto& function : p1VecFunctions_ )
   {
      hyteg::communication::syncVectorFunctionBetweenPrimitives( function, level );
   }

   for ( const auto& function : p2Functions_ )
   {
      hyteg::communication::syncP2FunctionBetweenPrimitives( function, level );
   }

   for ( const auto& function : p2VecFunctions_ )
   {
      hyteg::communication::syncVectorFunctionBetweenPrimitives( function, level );
   }

   for ( const auto& function : edgeDoFFunctions_ )
   {
      hyteg::communication::syncFunctionBetweenPrimitives< hyteg::EdgeDoFFunction< real_t > >( function, level );
   }

   for ( const auto& function : dgFunctions_ )
   {
      function.communicate< Vertex, Edge >( level );
      function.communicate< Edge, Face >( level );
   }
}

} // namespace hyteg

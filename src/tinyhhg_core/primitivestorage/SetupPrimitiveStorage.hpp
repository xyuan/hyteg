
#pragma once

#include "core/debug/Debug.h"
#include "tinyhhg_core/mesh/MeshInfo.hpp"
#include "tinyhhg_core/PrimitiveID.hpp"
#include "tinyhhg_core/primitives/Primitive.hpp"
#include "tinyhhg_core/primitives/Vertex.hpp"
#include "tinyhhg_core/primitives/Edge.hpp"
#include "tinyhhg_core/primitives/Face.hpp"
#include "tinyhhg_core/primitives/Cell.hpp"

#include <map>
#include <set>
#include <tuple>
#include <vector>

namespace hhg {

using walberla::real_t;
using walberla::memory_t;

class SetupPrimitiveStorage
{
public:

  typedef std::map< PrimitiveID::IDType, std::shared_ptr< Primitive > > PrimitiveMap;
  typedef std::map< PrimitiveID::IDType, std::shared_ptr< Vertex > >    VertexMap;
  typedef std::map< PrimitiveID::IDType, std::shared_ptr< Edge > >      EdgeMap;
  typedef std::map< PrimitiveID::IDType, std::shared_ptr< Face > >      FaceMap;
  typedef std::map< PrimitiveID::IDType, std::shared_ptr< Cell > >      CellMap;

  SetupPrimitiveStorage( const MeshInfo & meshInfo, const uint_t & numberOfProcesses );

  void toStream( std::ostream & os, bool verbose = false ) const;

  uint_t getNumberOfProcesses() const { return numberOfProcesses_; }
  uint_t getNumberOfEmptyProcesses() const;

  bool primitiveExists( const PrimitiveID & id ) const { return vertexExists( id ) || edgeExists( id ) || faceExists( id ) || cellExists( id ); }
  bool vertexExists   ( const PrimitiveID & id ) const { return vertices_.count( id.getID() ) > 0; }
  bool edgeExists     ( const PrimitiveID & id ) const { return edges_.count( id.getID() )    > 0; }
  bool faceExists     ( const PrimitiveID & id ) const { return faces_.count( id.getID() )    > 0; }
  bool cellExists     ( const PrimitiveID & id ) const { return cells_.count( id.getID() )    > 0; }

        Primitive * getPrimitive( const PrimitiveID & id );
  const Primitive * getPrimitive( const PrimitiveID & id ) const;
        Vertex * getVertex( const PrimitiveID & id )       { return vertexExists( id ) ? vertices_.at( id.getID() ).get() : nullptr; }
  const Vertex * getVertex( const PrimitiveID & id ) const { return vertexExists( id ) ? vertices_.at( id.getID() ).get() : nullptr; }
        Edge   * getEdge  ( const PrimitiveID & id )       { return edgeExists( id )   ? edges_.at( id.getID() ).get()    : nullptr; }
  const Edge   * getEdge  ( const PrimitiveID & id ) const { return edgeExists( id )   ? edges_.at( id.getID() ).get()    : nullptr; }
        Face   * getFace  ( const PrimitiveID & id )       { return faceExists( id )   ? faces_.at( id.getID() ).get()    : nullptr; }
  const Face   * getFace  ( const PrimitiveID & id ) const { return faceExists( id )   ? faces_.at( id.getID() ).get()    : nullptr; }
        Cell   * getCell  ( const PrimitiveID & id )       { return cellExists( id )   ? cells_.at( id.getID() ).get()    : nullptr; }
  const Cell   * getCell  ( const PrimitiveID & id ) const { return cellExists( id )   ? cells_.at( id.getID() ).get()    : nullptr; }

  void getSetupPrimitives( PrimitiveMap & setupPrimitiveMap ) const;

  uint_t getNumberOfPrimitives() const { return getNumberOfVertices() + getNumberOfEdges() + getNumberOfFaces() + getNumberOfCells(); }
  uint_t getNumberOfVertices  () const { return vertices_.size(); }
  uint_t getNumberOfEdges     () const { return edges_.size();    }
  uint_t getNumberOfFaces     () const { return faces_.size();    }
  uint_t getNumberOfCells     () const { return cells_.size();    }

  VertexMap::iterator beginVertices() { return vertices_.begin(); }
  VertexMap::iterator endVertices()   { return vertices_.end(); }

  EdgeMap::iterator beginEdges()      { return edges_.begin(); }
  EdgeMap::iterator endEdges()        { return edges_.end(); }

  FaceMap::iterator beginFaces()      { return faces_.begin(); }
  FaceMap::iterator endFaces()        { return faces_.end(); }

  CellMap::iterator beginCells()      { return cells_.begin(); }
  CellMap::iterator endCells()        { return cells_.end(); }

  VertexMap::const_iterator beginVertices() const { return vertices_.begin(); }
  VertexMap::const_iterator endVertices()   const { return vertices_.end(); }

  EdgeMap::const_iterator beginEdges()      const { return edges_.begin(); }
  EdgeMap::const_iterator endEdges()        const { return edges_.end(); }

  FaceMap::const_iterator beginFaces()      const { return faces_.begin(); }
  FaceMap::const_iterator endFaces()        const { return faces_.end(); }

  CellMap::const_iterator beginCells()      const { return cells_.begin(); }
  CellMap::const_iterator endCells()        const { return cells_.end(); }

  void   setTargetRank( const PrimitiveID & primitiveID, const uint_t & targetRank )       { primitiveIDToTargetRankMap_[ primitiveID.getID() ] = targetRank; }
  uint_t getTargetRank( const PrimitiveID & primitiveID )                            const { return primitiveIDToTargetRankMap_.at( primitiveID.getID() ); }

  void setGeometryMap( const PrimitiveID & primitiveID, const std::shared_ptr<GeometryMap>& map) { getPrimitive(primitiveID)->geometryMap_ = map; }

  void setMeshBoundaryFlag( const PrimitiveID & primitiveID, const uint_t & meshBoundaryFlag ) { getPrimitive(primitiveID)->meshBoundaryFlag_ = meshBoundaryFlag; }

  /// Sets the mesh boundary flag of the primitives to a specified value if they are located on the boundary of the domain
  /// \param meshBoundaryFlagOnBoundary the flag the primitives are set to if they are located on the boundary
  /// \param meshBoundaryFlagInner the flag the primitives are set to if they are not located on the boundary
  /// \param highestDimensionAlwaysInner if true, cells in 3D meshes and faces in 2D meshes are treated as inner primitives
  void setMeshBoundaryFlagsOnBoundary( const uint_t & meshBoundaryFlagOnBoundary, const uint_t & meshBoundaryFlagInner, const bool & highestDimensionAlwaysInner );

  /// Returns true, if the primitive lies on the boundary.
  /// \param primitiveID the ID of the primitive to be tested
  /// \param highestDimensionAlwaysInner if true, this method always returns false if the targeted primitive is of highest dimension (cells for 3D, faces for 2D meshes)
  bool onBoundary( const PrimitiveID & primitiveID, const bool & highestDimensionAlwaysInner = false ) const;

private:

  typedef std::map< uint_t, std::vector< PrimitiveID::IDType > > RankToSetupPrimitivesMap;

  PrimitiveID generatePrimitiveID() const;

  void assembleRankToSetupPrimitivesMap( RankToSetupPrimitivesMap & rankToSetupPrimitivesMap ) const;

  /// Returns the number of primitives on the target rank with the least number of primitives
  uint_t getMinPrimitivesPerRank() const;
  /// Returns the number of primitives on the target rank with the largest number of primitives
  uint_t getMaxPrimitivesPerRank() const;
  /// Returns the average number of primitives per rank
  real_t getAvgPrimitivesPerRank() const;

  /// Returns the number of primitives that lie on the boundary
  uint_t getNumVerticesOnBoundary() const;
  uint_t getNumEdgesOnBoundary() const;
  uint_t getNumFacesOnBoundary() const;
  uint_t getNumCellsOnBoundary() const;

  uint_t numberOfProcesses_;

  VertexMap vertices_;
  EdgeMap   edges_;
  FaceMap   faces_;
  CellMap   cells_;

  std::map< PrimitiveID::IDType, uint_t > primitiveIDToTargetRankMap_;

};

inline std::ostream & operator<<( std::ostream & os, const SetupPrimitiveStorage & storage )
{
  storage.toStream( os );
  return os;
}

} // namespace hhg

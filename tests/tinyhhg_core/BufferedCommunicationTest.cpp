
#include "core/Environment.h"
#include "core/debug/CheckFunctions.h"
#include "core/debug/TestSubsystem.h"
#include "tinyhhg_core/tinyhhg.hpp"

namespace hhg {

struct VertexTestData
{
  uint_t ownID;
  std::vector< uint_t > edgeIDs;
};

struct EdgeTestData
{
  uint_t ownID;
  std::vector< uint_t > vertexIDs;
};

struct VertexTestDataHandling : OnlyInitializeDataHandling< VertexTestData, Vertex >
{
  virtual std::shared_ptr< VertexTestData > initialize( const Vertex * const primitive ) const
  {
    auto data = std::make_shared< VertexTestData >();
    data->ownID = primitive->getID().getID();
    return data;
  }
};

struct EdgeTestDataHandling : OnlyInitializeDataHandling< EdgeTestData, Edge >
{
  virtual std::shared_ptr< EdgeTestData > initialize( const Edge * const primitive ) const
  {
    auto data = std::make_shared< EdgeTestData >();
    data->ownID = primitive->getID().getID();
    return data;
  }
};


class TestPackInfo : public communication::PackInfo
{
public:

  TestPackInfo( PrimitiveDataID< VertexTestData, Vertex > & vertexDataID,
		PrimitiveDataID< EdgeTestData,   Edge >   & edgeDataID ) :
		  vertexDataID_( vertexDataID ), edgeDataID_( edgeDataID )
  {}

  virtual void packVertexForEdge(const Vertex *sender, const PrimitiveID &receiver, walberla::mpi::SendBuffer &buffer)
  {
    WALBERLA_UNUSED( receiver );
    VertexTestData * data = sender->getData( vertexDataID_ );
    buffer << data->ownID;
    // WALBERLA_LOG_INFO( "Packing | Vertex: " << sender->getID().getID() << ", Receiver: " << receiver.getID() << ", Data: " << data->someInt );
  }

  virtual void unpackEdgeFromVertex(Edge *receiver, const PrimitiveID &sender, walberla::mpi::RecvBuffer &buffer)
  {
    WALBERLA_UNUSED( sender );

    EdgeTestData * data = receiver->getData( edgeDataID_ );
    uint_t vertexData;
    buffer >> vertexData;
    // WALBERLA_LOG_INFO( "Unpacking | Edge: " << receiver->getID().getID() << ", Data: " << vertexData );
    data->vertexIDs.push_back( vertexData );
  }

  virtual void communicateLocalVertexToEdge(const Vertex *sender, Edge *receiver)
  {
    VertexTestData * vertexData = sender->getData( vertexDataID_ );
    EdgeTestData   * edgeData   = receiver->getData( edgeDataID_ );
    // WALBERLA_LOG_INFO( "Direct | Vertex: " << sender->getID().getID() << ", Edge: " << receiver->getID().getID() << ", Data: " << vertexData->someInt );
    edgeData->vertexIDs.push_back( vertexData->ownID );
  }


  virtual void packEdgeForVertex(const Edge *sender, const PrimitiveID &receiver, walberla::mpi::SendBuffer &buffer)
  {
    WALBERLA_UNUSED( receiver );
    EdgeTestData * data = sender->getData( edgeDataID_ );
    buffer << data->ownID;
  }

  virtual void unpackVertexFromEdge(Vertex *receiver, const PrimitiveID &sender, walberla::mpi::RecvBuffer &buffer)
  {
    WALBERLA_UNUSED( sender );

    VertexTestData * data = receiver->getData( vertexDataID_ );
    uint_t edgeData;
    buffer >> edgeData;
    data->edgeIDs.push_back( edgeData );
  }

  virtual void communicateLocalEdgeToVertex(const Edge *sender, Vertex *receiver)
  {
    EdgeTestData   * edgeData   = sender->getData( edgeDataID_ );
    VertexTestData * vertexData = receiver->getData( vertexDataID_ );
    vertexData->edgeIDs.push_back( edgeData->ownID );
  }


  virtual void packEdgeForFace(const Edge *sender, const PrimitiveID &receiver, walberla::mpi::SendBuffer &buffer)
  {
    WALBERLA_UNUSED( sender   );
    WALBERLA_UNUSED( receiver );
    WALBERLA_UNUSED( buffer   );
  }

  virtual void unpackFaceFromEdge(Face *receiver, const PrimitiveID &sender, walberla::mpi::RecvBuffer &buffer)
  {
    WALBERLA_UNUSED( sender   );
    WALBERLA_UNUSED( receiver );
    WALBERLA_UNUSED( buffer   );
  }

  virtual void communicateLocalEdgeToFace(const Edge *sender, Face *receiver)
  {
    WALBERLA_UNUSED( sender   );
    WALBERLA_UNUSED( receiver );
  }


  virtual void packFaceForEdge(const Face *sender, const PrimitiveID &receiver, walberla::mpi::SendBuffer &buffer)
  {
    WALBERLA_UNUSED( sender   );
    WALBERLA_UNUSED( receiver );
    WALBERLA_UNUSED( buffer   );
  }

  virtual void unpackEdgeFromFace(Edge *receiver, const PrimitiveID &sender, walberla::mpi::RecvBuffer &buffer)
  {
    WALBERLA_UNUSED( sender   );
    WALBERLA_UNUSED( receiver );
    WALBERLA_UNUSED( buffer   );
  }

  virtual void communicateLocalFaceToEdge(const Face *sender, Edge *receiver)
  {
    WALBERLA_UNUSED( sender   );
    WALBERLA_UNUSED( receiver );
  }

private:

  PrimitiveDataID< VertexTestData, Vertex > vertexDataID_;
  PrimitiveDataID< EdgeTestData,   Edge >   edgeDataID_;

};

static void testBufferedCommunication()
{

  std::string meshFileName = "../../data/meshes/bfs_126el.msh";

  MeshInfo meshInfo = MeshInfo::fromGmshFile( meshFileName );
  SetupPrimitiveStorage setupStorage( meshInfo, uint_c ( walberla::mpi::MPIManager::instance()->numProcesses() ) );

  loadbalancing::roundRobin( setupStorage );

  // WALBERLA_LOG_INFO_ON_ROOT( setupStorage );
  WALBERLA_MPI_BARRIER();

  std::shared_ptr< PrimitiveStorage > storage( new PrimitiveStorage( setupStorage ) );

  communication::BufferedCommunicator communicator( storage );

  auto vertexTestDataHandling = std::make_shared< VertexTestDataHandling >();
  auto edgeTestDataHandling = std::make_shared< EdgeTestDataHandling >();

  PrimitiveDataID< VertexTestData, Vertex > vertexTestDataID;
  storage->addVertexData( vertexTestDataID, vertexTestDataHandling, "vertex data" );

  PrimitiveDataID< EdgeTestData, Edge > edgeTestDataID;
  storage->addEdgeData  ( edgeTestDataID, edgeTestDataHandling,   "edge data" );

  std::shared_ptr< TestPackInfo > testPackInfo( new TestPackInfo( vertexTestDataID, edgeTestDataID ) );

  for ( auto it = storage->beginVertices(); it != storage->endVertices(); it++ )
  {
    auto vertex = it->second;
    auto data = vertex->getData( vertexTestDataID );
    WALBERLA_CHECK_EQUAL( data->ownID, vertex->getID().getID() );
  }

  for ( auto it = storage->beginEdges(); it != storage->endEdges(); it++ )
  {
    auto edge = it->second;
    auto data = edge->getData( edgeTestDataID );
    WALBERLA_CHECK_EQUAL( data->vertexIDs.size(), 0 );
  }

  communicator.addPackInfo( testPackInfo );
  communicator.setLocalCommunicationMode( communication::BufferedCommunicator::LocalCommunicationMode::BUFFERED_MPI );

  std::shared_ptr< walberla::WcTimingTree > timingTree( new walberla::WcTimingTree() );
  communicator.enableTiming( timingTree );

  communicator.communicate< Vertex, Edge >();
#if 0
  communicator.startCommunication< Vertex, Edge >();
  communicator.endCommunication< Vertex, Edge >();
#endif

  communicator.startCommunication< Edge, Vertex >();

  for ( auto it = storage->beginEdges(); it != storage->endEdges(); it++ )
  {
    auto edge = it->second;
    auto data = edge->getData( edgeTestDataID );
    WALBERLA_CHECK_EQUAL( data->vertexIDs.size(), 2 );
    WALBERLA_CHECK_UNEQUAL( data->vertexIDs[0], data->vertexIDs[1], "Failing on Edge: " << it->first );

    for ( const auto & lowerDimNeighborID : edge->getLowerDimNeighbors() )
    {
      WALBERLA_CHECK( data->vertexIDs[0] == lowerDimNeighborID.getID() || data->vertexIDs[1] == lowerDimNeighborID.getID(), "Failing on Edge: " << lowerDimNeighborID.getID() );
    }

    // WALBERLA_LOG_INFO( "Edge " << edge->getID().getID() << " received: " << data->someInts[0] << ", " << data->someInts[1] );
  }

  communicator.endCommunication< Edge, Vertex >(); // checking interleaved communication and processing

  for ( auto it = storage->beginVertices(); it != storage->endVertices(); it++ )
  {
    auto vertex = it->second;
    auto data = vertex->getData( vertexTestDataID );
    WALBERLA_CHECK_GREATER( data->edgeIDs.size(), 0 );
    std::set< uint_t > edgeIdsSet( data->edgeIDs.begin(), data->edgeIDs.end() );
    WALBERLA_CHECK_EQUAL( data->edgeIDs.size(), edgeIdsSet.size() );

    for ( const auto & higherDimNeighborID : vertex->getHigherDimNeighbors() )
    {
      WALBERLA_CHECK_EQUAL( edgeIdsSet.count( higherDimNeighborID.getID() ), 1 );
    }
  }

  WALBERLA_MPI_SECTION()
  {
    const walberla::WcTimingTree tt = timingTree->getReduced();
    WALBERLA_LOG_INFO_ON_ROOT( tt );
  }
  WALBERLA_NON_MPI_SECTION()
  {
    WALBERLA_LOG_INFO_ON_ROOT( *timingTree );
  }

}

} // namespace hhg


int main( int argc, char* argv[] )
{
   walberla::debug::enterTestMode();

   walberla::Environment walberlaEnv(argc, argv);
   walberla::logging::Logging::instance()->setLogLevel( walberla::logging::Logging::PROGRESS );
   walberla::MPIManager::instance()->useWorldComm();
   hhg::testBufferedCommunication();

   return EXIT_SUCCESS;
}

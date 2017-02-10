#ifndef P1VERTEX_HPP
#define P1VERTEX_HPP

#include <levelinfo.hpp>
#include <comm.hpp>

#include <fmt/format.h>

namespace hhg
{
namespace P1Vertex
{

inline void allocate(Vertex& vertex, size_t memory_id, size_t minLevel, size_t maxLevel)
{
  vertex.data.push_back(std::vector<double*>());

  for (size_t level = minLevel; level <= maxLevel; ++level)
  {
    size_t num_deps = vertex.edges.size();
    size_t total_n_dofs = levelinfo::num_microvertices_per_vertex(level) + num_deps;
    double* new_data = new double[total_n_dofs];
    memset(new_data, 0, total_n_dofs * sizeof(double));
    vertex.data[memory_id].push_back(new_data);
  }
}

inline void free(Vertex& vertex, size_t memory_id, size_t minLevel, size_t maxLevel)
{
  for (size_t level = minLevel; level <= maxLevel; ++level)
  {
    delete[] vertex.data[memory_id][level - minLevel];
  }
}

inline void interpolate(Vertex& vertex, size_t memory_id, std::function<double(const hhg::Point3D&)>& expr, size_t level)
{
  vertex.data[memory_id][level-2][0] = expr(vertex.coords);
}

template<size_t N>
inline void assign(Vertex& vertex, std::array<double, N>& scalars, std::array<size_t, N>& src_ids, size_t dst_id, size_t level)
{
  double tmp = scalars[0] * vertex.data[src_ids[0]][level-2][0];

  for (size_t i = 1; i < N; ++i)
  {
    tmp += scalars[i] * vertex.data[src_ids[i]][level-2][0];
  }

  vertex.data[dst_id][level-2][0] = tmp;
}

template<size_t N>
inline void add(Vertex& vertex, std::array<double, N>& scalars, std::array<size_t, N>& src_ids, size_t dst_id, size_t level)
{
  double tmp = 0.0;

  for (size_t i = 0; i < N; ++i)
  {
    tmp += scalars[i] * vertex.data[src_ids[i]][level-2][0];
  }

  vertex.data[dst_id][level-2][0] += tmp;
}

inline double dot(Vertex& vertex, size_t lhs_id, size_t rhs_id, size_t level)
{
  return vertex.data[lhs_id][level-2][0] * vertex.data[rhs_id][level-2][0];
}

inline void apply(Vertex& vertex, size_t opr_id, size_t src_id, size_t dst_id, size_t level)
{
  double* opr_data = vertex.opr_data[opr_id][0];
  double* src = vertex.data[src_id][level-2];
  double* dst = vertex.data[dst_id][level-2];

  dst[0] = opr_data[0] * src[0];

  for (size_t i = 0; i < vertex.edges.size(); ++i)
  {
    dst[0] += opr_data[i+1] * src[i+1];
  }
}

inline void smooth_gs(Vertex& vertex, size_t opr_id, size_t f_id, size_t rhs_id, size_t level)
{
  double* opr_data = vertex.opr_data[opr_id][0];
  double* dst = vertex.data[f_id][level-2];
  double* rhs = vertex.data[rhs_id][level-2];

  dst[0] = rhs[0];

  for (size_t i = 0; i < vertex.edges.size(); ++i)
  {
    dst[0] -= opr_data[i+1] * dst[i+1];
  }

  dst[0] /= opr_data[0];
}

inline void pull_halos(Vertex& vertex, size_t memory_id, size_t level)
{
  size_t i = 1;
  int rk = hhg::Comm::get().rk;

  for (Edge* edge : vertex.edges)
  {
    if (vertex.rank == rk)
    {
      if (edge->rank == rk)
      {
        if(edge->vertex_index(vertex) == 0)
        {
          vertex.data[memory_id][level-2][i] = edge->data[memory_id][level-2][1];
        }
        else
        {
          vertex.data[memory_id][level-2][i] = edge->data[memory_id][level-2][levelinfo::num_microvertices_per_edge(level) - 2];
        }
      }
      else
      {
        MPI_Recv(&vertex.data[memory_id][level-2][i], 1, MPI_DOUBLE, edge->rank, i, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
      }
    }
    else if (edge->rank == rk)
    {
      if(edge->vertex_index(vertex) == 0)
      {
        MPI_Send(&edge->data[memory_id][level-2][1], 1, MPI_DOUBLE, vertex.rank, i, MPI_COMM_WORLD);
      }
      else
      {
        MPI_Send(&edge->data[memory_id][level-2][levelinfo::num_microvertices_per_edge(level) - 2], 1, MPI_DOUBLE, vertex.rank, i, MPI_COMM_WORLD);
      }
    }

    i += 1;
  }
}

inline void prolongate(Vertex& vertex, size_t memory_id, size_t level)
{
  vertex.data[memory_id][level-2+1][0] = vertex.data[memory_id][level-2][0];
}

inline void restrict(Vertex& vertex, size_t memory_id, size_t level)
{
  double* vertex_data_f = vertex.data[memory_id][level-2];
  double* vertex_data_c = vertex.data[memory_id][level-2-1];

  vertex_data_c[0] = vertex_data_f[0];

  size_t i = 1;
  for (Edge* edge : vertex.edges)
  {
    vertex_data_c[0] += 0.5 * vertex_data_f[i];
    i += 1;
  }
}

}
}

#endif /* P1VERTEX_HPP */
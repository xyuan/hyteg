/*
 * Copyright (c) 2019 Nils Kohl, Dominik Thoennes.
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

//////////////////////////////////////////////////////////////////////////////
// This file is generated! To fix issues, please fix them in the generator. //
//////////////////////////////////////////////////////////////////////////////

#include "communicate_buffered_unpack_edgedof_face_to_cell.hpp"

namespace hyteg {
namespace edgedof {
namespace comm {
namespace generated {

void communicate_buffered_unpack_edgedof_face_to_cell(double * RESTRICT _data_edge_cell_dst_X, double * RESTRICT _data_edge_cell_dst_XY, double * RESTRICT _data_edge_cell_dst_XZ, double * RESTRICT _data_edge_cell_dst_Y, double * RESTRICT _data_edge_cell_dst_YZ, double * RESTRICT _data_edge_cell_dst_Z, double const * RESTRICT const _data_recv_buffer, int32_t level, int64_t neighbor_cell_local_vertex_id_0, int64_t neighbor_cell_local_vertex_id_1, int64_t neighbor_cell_local_vertex_id_2, int64_t recv_buffer_first_element_idx)
{
   if (((0) == (neighbor_cell_local_vertex_id_0)) && ((1) == (neighbor_cell_local_vertex_id_1)) && ((2) == (neighbor_cell_local_vertex_id_2)))
   {
      
      communicate_buffered_unpack_edgedof_face_to_cell_impl_012(_data_edge_cell_dst_X, _data_edge_cell_dst_XY, _data_edge_cell_dst_Y, _data_recv_buffer, level, recv_buffer_first_element_idx);
      
      return;
   } 
   if (((0) == (neighbor_cell_local_vertex_id_0)) && ((1) == (neighbor_cell_local_vertex_id_1)) && ((3) == (neighbor_cell_local_vertex_id_2)))
   {
      
      communicate_buffered_unpack_edgedof_face_to_cell_impl_013(_data_edge_cell_dst_X, _data_edge_cell_dst_XZ, _data_edge_cell_dst_Z, _data_recv_buffer, level, recv_buffer_first_element_idx);
      
      return;
   } 
   if (((0) == (neighbor_cell_local_vertex_id_0)) && ((1) == (neighbor_cell_local_vertex_id_2)) && ((2) == (neighbor_cell_local_vertex_id_1)))
   {
      
      communicate_buffered_unpack_edgedof_face_to_cell_impl_021(_data_edge_cell_dst_X, _data_edge_cell_dst_XY, _data_edge_cell_dst_Y, _data_recv_buffer, level, recv_buffer_first_element_idx);
      
      return;
   } 
   if (((0) == (neighbor_cell_local_vertex_id_0)) && ((2) == (neighbor_cell_local_vertex_id_1)) && ((3) == (neighbor_cell_local_vertex_id_2)))
   {
      
      communicate_buffered_unpack_edgedof_face_to_cell_impl_023(_data_edge_cell_dst_Y, _data_edge_cell_dst_YZ, _data_edge_cell_dst_Z, _data_recv_buffer, level, recv_buffer_first_element_idx);
      
      return;
   } 
   if (((0) == (neighbor_cell_local_vertex_id_0)) && ((1) == (neighbor_cell_local_vertex_id_2)) && ((3) == (neighbor_cell_local_vertex_id_1)))
   {
      
      communicate_buffered_unpack_edgedof_face_to_cell_impl_031(_data_edge_cell_dst_X, _data_edge_cell_dst_XZ, _data_edge_cell_dst_Z, _data_recv_buffer, level, recv_buffer_first_element_idx);
      
      return;
   } 
   if (((0) == (neighbor_cell_local_vertex_id_0)) && ((2) == (neighbor_cell_local_vertex_id_2)) && ((3) == (neighbor_cell_local_vertex_id_1)))
   {
      
      communicate_buffered_unpack_edgedof_face_to_cell_impl_032(_data_edge_cell_dst_Y, _data_edge_cell_dst_YZ, _data_edge_cell_dst_Z, _data_recv_buffer, level, recv_buffer_first_element_idx);
      
      return;
   } 
   if (((0) == (neighbor_cell_local_vertex_id_1)) && ((1) == (neighbor_cell_local_vertex_id_0)) && ((2) == (neighbor_cell_local_vertex_id_2)))
   {
      
      communicate_buffered_unpack_edgedof_face_to_cell_impl_102(_data_edge_cell_dst_X, _data_edge_cell_dst_XY, _data_edge_cell_dst_Y, _data_recv_buffer, level, recv_buffer_first_element_idx);
      
      return;
   } 
   if (((0) == (neighbor_cell_local_vertex_id_1)) && ((1) == (neighbor_cell_local_vertex_id_0)) && ((3) == (neighbor_cell_local_vertex_id_2)))
   {
      
      communicate_buffered_unpack_edgedof_face_to_cell_impl_103(_data_edge_cell_dst_X, _data_edge_cell_dst_XZ, _data_edge_cell_dst_Z, _data_recv_buffer, level, recv_buffer_first_element_idx);
      
      return;
   } 
   if (((0) == (neighbor_cell_local_vertex_id_2)) && ((1) == (neighbor_cell_local_vertex_id_0)) && ((2) == (neighbor_cell_local_vertex_id_1)))
   {
      
      communicate_buffered_unpack_edgedof_face_to_cell_impl_120(_data_edge_cell_dst_X, _data_edge_cell_dst_XY, _data_edge_cell_dst_Y, _data_recv_buffer, level, recv_buffer_first_element_idx);
      
      return;
   } 
   if (((1) == (neighbor_cell_local_vertex_id_0)) && ((2) == (neighbor_cell_local_vertex_id_1)) && ((3) == (neighbor_cell_local_vertex_id_2)))
   {
      
      communicate_buffered_unpack_edgedof_face_to_cell_impl_123(_data_edge_cell_dst_XY, _data_edge_cell_dst_XZ, _data_edge_cell_dst_YZ, _data_recv_buffer, level, recv_buffer_first_element_idx);
      
      return;
   } 
   if (((0) == (neighbor_cell_local_vertex_id_2)) && ((1) == (neighbor_cell_local_vertex_id_0)) && ((3) == (neighbor_cell_local_vertex_id_1)))
   {
      
      communicate_buffered_unpack_edgedof_face_to_cell_impl_130(_data_edge_cell_dst_X, _data_edge_cell_dst_XZ, _data_edge_cell_dst_Z, _data_recv_buffer, level, recv_buffer_first_element_idx);
      
      return;
   } 
   if (((1) == (neighbor_cell_local_vertex_id_0)) && ((2) == (neighbor_cell_local_vertex_id_2)) && ((3) == (neighbor_cell_local_vertex_id_1)))
   {
      
      communicate_buffered_unpack_edgedof_face_to_cell_impl_132(_data_edge_cell_dst_XY, _data_edge_cell_dst_XZ, _data_edge_cell_dst_YZ, _data_recv_buffer, level, recv_buffer_first_element_idx);
      
      return;
   } 
   if (((0) == (neighbor_cell_local_vertex_id_1)) && ((1) == (neighbor_cell_local_vertex_id_2)) && ((2) == (neighbor_cell_local_vertex_id_0)))
   {
      
      communicate_buffered_unpack_edgedof_face_to_cell_impl_201(_data_edge_cell_dst_X, _data_edge_cell_dst_XY, _data_edge_cell_dst_Y, _data_recv_buffer, level, recv_buffer_first_element_idx);
      
      return;
   } 
   if (((0) == (neighbor_cell_local_vertex_id_1)) && ((2) == (neighbor_cell_local_vertex_id_0)) && ((3) == (neighbor_cell_local_vertex_id_2)))
   {
      
      communicate_buffered_unpack_edgedof_face_to_cell_impl_203(_data_edge_cell_dst_Y, _data_edge_cell_dst_YZ, _data_edge_cell_dst_Z, _data_recv_buffer, level, recv_buffer_first_element_idx);
      
      return;
   } 
   if (((0) == (neighbor_cell_local_vertex_id_2)) && ((1) == (neighbor_cell_local_vertex_id_1)) && ((2) == (neighbor_cell_local_vertex_id_0)))
   {
      
      communicate_buffered_unpack_edgedof_face_to_cell_impl_210(_data_edge_cell_dst_X, _data_edge_cell_dst_XY, _data_edge_cell_dst_Y, _data_recv_buffer, level, recv_buffer_first_element_idx);
      
      return;
   } 
   if (((1) == (neighbor_cell_local_vertex_id_1)) && ((2) == (neighbor_cell_local_vertex_id_0)) && ((3) == (neighbor_cell_local_vertex_id_2)))
   {
      
      communicate_buffered_unpack_edgedof_face_to_cell_impl_213(_data_edge_cell_dst_XY, _data_edge_cell_dst_XZ, _data_edge_cell_dst_YZ, _data_recv_buffer, level, recv_buffer_first_element_idx);
      
      return;
   } 
   if (((0) == (neighbor_cell_local_vertex_id_2)) && ((2) == (neighbor_cell_local_vertex_id_0)) && ((3) == (neighbor_cell_local_vertex_id_1)))
   {
      
      communicate_buffered_unpack_edgedof_face_to_cell_impl_230(_data_edge_cell_dst_Y, _data_edge_cell_dst_YZ, _data_edge_cell_dst_Z, _data_recv_buffer, level, recv_buffer_first_element_idx);
      
      return;
   } 
   if (((1) == (neighbor_cell_local_vertex_id_2)) && ((2) == (neighbor_cell_local_vertex_id_0)) && ((3) == (neighbor_cell_local_vertex_id_1)))
   {
      
      communicate_buffered_unpack_edgedof_face_to_cell_impl_231(_data_edge_cell_dst_XY, _data_edge_cell_dst_XZ, _data_edge_cell_dst_YZ, _data_recv_buffer, level, recv_buffer_first_element_idx);
      
      return;
   } 
   if (((0) == (neighbor_cell_local_vertex_id_1)) && ((1) == (neighbor_cell_local_vertex_id_2)) && ((3) == (neighbor_cell_local_vertex_id_0)))
   {
      
      communicate_buffered_unpack_edgedof_face_to_cell_impl_301(_data_edge_cell_dst_X, _data_edge_cell_dst_XZ, _data_edge_cell_dst_Z, _data_recv_buffer, level, recv_buffer_first_element_idx);
      
      return;
   } 
   if (((0) == (neighbor_cell_local_vertex_id_1)) && ((2) == (neighbor_cell_local_vertex_id_2)) && ((3) == (neighbor_cell_local_vertex_id_0)))
   {
      
      communicate_buffered_unpack_edgedof_face_to_cell_impl_302(_data_edge_cell_dst_Y, _data_edge_cell_dst_YZ, _data_edge_cell_dst_Z, _data_recv_buffer, level, recv_buffer_first_element_idx);
      
      return;
   } 
   if (((0) == (neighbor_cell_local_vertex_id_2)) && ((1) == (neighbor_cell_local_vertex_id_1)) && ((3) == (neighbor_cell_local_vertex_id_0)))
   {
      
      communicate_buffered_unpack_edgedof_face_to_cell_impl_310(_data_edge_cell_dst_X, _data_edge_cell_dst_XZ, _data_edge_cell_dst_Z, _data_recv_buffer, level, recv_buffer_first_element_idx);
      
      return;
   } 
   if (((1) == (neighbor_cell_local_vertex_id_1)) && ((2) == (neighbor_cell_local_vertex_id_2)) && ((3) == (neighbor_cell_local_vertex_id_0)))
   {
      
      communicate_buffered_unpack_edgedof_face_to_cell_impl_312(_data_edge_cell_dst_XY, _data_edge_cell_dst_XZ, _data_edge_cell_dst_YZ, _data_recv_buffer, level, recv_buffer_first_element_idx);
      
      return;
   } 
   if (((0) == (neighbor_cell_local_vertex_id_2)) && ((2) == (neighbor_cell_local_vertex_id_1)) && ((3) == (neighbor_cell_local_vertex_id_0)))
   {
      
      communicate_buffered_unpack_edgedof_face_to_cell_impl_320(_data_edge_cell_dst_Y, _data_edge_cell_dst_YZ, _data_edge_cell_dst_Z, _data_recv_buffer, level, recv_buffer_first_element_idx);
      
      return;
   } 
   if (((1) == (neighbor_cell_local_vertex_id_2)) && ((2) == (neighbor_cell_local_vertex_id_1)) && ((3) == (neighbor_cell_local_vertex_id_0)))
   {
      
      communicate_buffered_unpack_edgedof_face_to_cell_impl_321(_data_edge_cell_dst_XY, _data_edge_cell_dst_XZ, _data_edge_cell_dst_YZ, _data_recv_buffer, level, recv_buffer_first_element_idx);
      
      return;
   } 
}


} // namespace generated
} // namespace comm
} // namespace edgedof
} // namespace hyteg

//////////////////////////////////////////////////////////////////////////////
// This file is generated! To fix issues, please fix them in the generator. //
//////////////////////////////////////////////////////////////////////////////

#pragma once
#include "all.hpp"
#include "core/Macros.h"
#include "hyteg/edgedofspace/EdgeDoFOrientation.hpp"
#include "hyteg/indexing/Common.hpp"
#include <map>
#define RESTRICT WALBERLA_RESTRICT

namespace hyteg {
namespace vertexdof {
namespace comm {
namespace generated {

void communicate_directly_vertexdof_cell_to_face_colored_impl_230(double const * RESTRICT const _data_p1_cell_src_group_0_const, double * RESTRICT _data_p1_face_dst_gl0, int32_t level);

} // namespace generated
} // namespace comm
} // namespace vertexdof
} // namespace hyteg
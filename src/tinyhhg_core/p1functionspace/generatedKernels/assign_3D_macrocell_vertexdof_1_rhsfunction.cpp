
//////////////////////////////////////////////////////////////////////////////
// This file is generated! To fix issues, please fix them in the generator. //
//////////////////////////////////////////////////////////////////////////////

#include "assign_3D_macrocell_vertexdof_1_rhsfunction.hpp"

namespace hhg {
namespace vertexdof {
namespace macrocell {
namespace generated {

static void assign_3D_macrocell_vertexdof_1_rhs_function_level_any(double * RESTRICT _data_p1FaceDst, double * RESTRICT _data_p1FaceSrc, double c, int64_t level)
{
   for (int ctr_3 = 1; ctr_3 < (1 << (level)); ctr_3 += 1)
   {
      for (int ctr_2 = 1; ctr_2 < -ctr_3 + (1 << (level)); ctr_2 += 1)
      {
         // cell (inner)
         for (int ctr_1 = 1; ctr_1 < -ctr_2 - ctr_3 + (1 << (level)); ctr_1 += 1)
         {
            _data_p1FaceDst[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 2) - ((ctr_2*(ctr_2 + 1)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6))] = c*_data_p1FaceSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 2) - ((ctr_2*(ctr_2 + 1)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6))];
         }
      }
   }
}


void assign_3D_macrocell_vertexdof_1_rhs_function(double * RESTRICT _data_p1FaceDst, double * RESTRICT _data_p1FaceSrc, double c, int64_t level)
{
    switch( level )
    {

    default:
        assign_3D_macrocell_vertexdof_1_rhs_function_level_any(_data_p1FaceDst, _data_p1FaceSrc, c, level);
        break;
    }
}
    

} // namespace generated
} // namespace macrocell
} // namespace vertexdof
} // namespace hhg
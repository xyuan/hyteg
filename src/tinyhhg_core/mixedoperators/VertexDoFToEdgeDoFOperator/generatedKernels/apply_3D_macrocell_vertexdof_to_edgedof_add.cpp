
//////////////////////////////////////////////////////////////////////////////
// This file is generated! To fix issues, please fix them in the generator. //
//////////////////////////////////////////////////////////////////////////////

#include "GeneratedKernelsVertexToEdgeMacroCell3D.hpp"

namespace hhg {
namespace VertexDoFToEdgeDoF {
namespace generated {

static void apply_3D_macrocell_vertexdof_to_edgedof_add_level_2(double * _data_edgeCellDst_X, double * _data_edgeCellDst_XY, double * _data_edgeCellDst_XYZ, double * _data_edgeCellDst_XZ, double * _data_edgeCellDst_Y, double * _data_edgeCellDst_YZ, double * _data_edgeCellDst_Z, double * _data_vertexCellSrc, std::map< hhg::edgedof::EdgeDoFOrientation, std::map< hhg::indexing::IndexIncrement, double > > v2eStencilMap)
{
   const double xi_112 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::XYZ][{ 0, 0, 1 }];
   const double xi_113 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::XYZ][{ 0, 1, 0 }];
   const double xi_114 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::XYZ][{ 0, 1, 1 }];
   const double xi_115 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::XYZ][{ 1, 0, 0 }];
   const double xi_116 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::XYZ][{ 1, 0, 1 }];
   const double xi_117 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::XYZ][{ 1, 1, 0 }];
   const double xi_141 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::YZ][{ -1, 1, 0 }];
   const double xi_142 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::YZ][{ -1, 1, 1 }];
   const double xi_143 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::YZ][{ 0, 0, 0 }];
   const double xi_144 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::YZ][{ 0, 0, 1 }];
   const double xi_145 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::YZ][{ 0, 1, 0 }];
   const double xi_146 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::YZ][{ 0, 1, 1 }];
   const double xi_147 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::YZ][{ 1, 0, 0 }];
   const double xi_148 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::YZ][{ 1, 0, 1 }];
   const double xi_175 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::XZ][{ 0, 0, 0 }];
   const double xi_176 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::XZ][{ 0, 0, 1 }];
   const double xi_177 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::XZ][{ 0, 1, 0 }];
   const double xi_178 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::XZ][{ 1, -1, 1 }];
   const double xi_179 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::XZ][{ 1, 0, 0 }];
   const double xi_180 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::XZ][{ 1, 0, 1 }];
   const double xi_298 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::Z][{ -1, 0, 1 }];
   const double xi_299 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::Z][{ -1, 1, 0 }];
   const double xi_300 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::Z][{ 0, -1, 1 }];
   const double xi_301 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::Z][{ 0, 0, 0 }];
   const double xi_302 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::Z][{ 0, 0, 1 }];
   const double xi_303 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::Z][{ 0, 1, 0 }];
   const double xi_304 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::Z][{ 1, -1, 1 }];
   const double xi_305 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::Z][{ 1, 0, 0 }];
   const double xi_226 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::XY][{ 0, 0, 0 }];
   const double xi_227 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::XY][{ 0, 0, 1 }];
   const double xi_228 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::XY][{ 0, 1, -1 }];
   const double xi_229 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::XY][{ 0, 1, 0 }];
   const double xi_230 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::XY][{ 1, 0, 0 }];
   const double xi_231 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::XY][{ 1, 0, 1 }];
   const double xi_232 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::XY][{ 1, 1, -1 }];
   const double xi_233 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::XY][{ 1, 1, 0 }];
   const double xi_362 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::Y][{ -1, 1, 0 }];
   const double xi_363 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::Y][{ 0, 0, 0 }];
   const double xi_364 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::Y][{ 0, 0, 1 }];
   const double xi_365 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::Y][{ 0, 1, -1 }];
   const double xi_366 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::Y][{ 0, 1, 0 }];
   const double xi_367 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::Y][{ 1, 0, 0 }];
   const double xi_426 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::X][{ 0, 0, 0 }];
   const double xi_427 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::X][{ 0, 0, 1 }];
   const double xi_428 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::X][{ 0, 1, -1 }];
   const double xi_429 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::X][{ 0, 1, 0 }];
   const double xi_430 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::X][{ 1, -1, 0 }];
   const double xi_431 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::X][{ 1, -1, 1 }];
   const double xi_432 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::X][{ 1, 0, -1 }];
   const double xi_433 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::X][{ 1, 0, 0 }];
   for (int ctr_3 = 0; ctr_3 < 1; ctr_3 += 1)
   {
      for (int ctr_2 = 0; ctr_2 < 1; ctr_2 += 1)
      {
         // vertex 0
         for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
         {
            const double xi_126 = _data_edgeCellDst_XYZ[ctr_1 + ctr_2*(-ctr_3 + 4) + ((60) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 3)*(-ctr_3 + 4)*(-ctr_3 + 5)) / (6))];
            const double xi_120 = xi_112*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 5) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))];
            const double xi_121 = xi_113*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + 6) + ((210) / (6)) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6))];
            const double xi_122 = xi_114*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + 5) + ((210) / (6)) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))];
            const double xi_123 = xi_115*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 6) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6)) + 1];
            const double xi_124 = xi_116*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 5) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6)) + 1];
            const double xi_125 = xi_117*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + 6) + ((210) / (6)) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6)) + 1];
            _data_edgeCellDst_XYZ[ctr_1 + ctr_2*(-ctr_3 + 4) + ((60) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 3)*(-ctr_3 + 4)*(-ctr_3 + 5)) / (6))] = xi_120 + xi_121 + xi_122 + xi_123 + xi_124 + xi_125 + xi_126;
         }
         // edge 0
         for (int ctr_1 = 1; ctr_1 < 3; ctr_1 += 1)
         {
            const double xi_165 = _data_edgeCellDst_YZ[ctr_1 + ctr_2*(-ctr_3 + 5) + ((120) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))];
            const double xi_172 = _data_edgeCellDst_XYZ[ctr_1 + ctr_2*(-ctr_3 + 4) + ((60) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 3)*(-ctr_3 + 4)*(-ctr_3 + 5)) / (6))];
            const double xi_157 = xi_141*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + 6) + ((210) / (6)) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6)) - 1];
            const double xi_158 = xi_142*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + 5) + ((210) / (6)) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6)) - 1];
            const double xi_159 = xi_143*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 6) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6))];
            const double xi_160 = xi_144*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 5) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))];
            const double xi_161 = xi_145*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + 6) + ((210) / (6)) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6))];
            const double xi_162 = xi_146*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + 5) + ((210) / (6)) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))];
            const double xi_163 = xi_147*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 6) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6)) + 1];
            const double xi_164 = xi_148*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 5) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6)) + 1];
            const double xi_166 = xi_112*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 5) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))];
            const double xi_167 = xi_113*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + 6) + ((210) / (6)) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6))];
            const double xi_168 = xi_114*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + 5) + ((210) / (6)) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))];
            const double xi_169 = xi_115*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 6) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6)) + 1];
            const double xi_170 = xi_116*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 5) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6)) + 1];
            const double xi_171 = xi_117*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + 6) + ((210) / (6)) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6)) + 1];
            _data_edgeCellDst_YZ[ctr_1 + ctr_2*(-ctr_3 + 5) + ((120) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))] = xi_157 + xi_158 + xi_159 + xi_160 + xi_161 + xi_162 + xi_163 + xi_164 + xi_165;
            _data_edgeCellDst_XYZ[ctr_1 + ctr_2*(-ctr_3 + 4) + ((60) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 3)*(-ctr_3 + 4)*(-ctr_3 + 5)) / (6))] = xi_166 + xi_167 + xi_168 + xi_169 + xi_170 + xi_171 + xi_172;
         }
      }
      for (int ctr_2 = 1; ctr_2 < -ctr_3 + 3; ctr_2 += 1)
      {
         // edge 1
         for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
         {
            const double xi_195 = _data_edgeCellDst_XZ[ctr_1 + ctr_2*(-ctr_3 + 5) + ((120) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))];
            const double xi_202 = _data_edgeCellDst_XYZ[ctr_1 + ctr_2*(-ctr_3 + 4) + ((60) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 3)*(-ctr_3 + 4)*(-ctr_3 + 5)) / (6))];
            const double xi_189 = xi_175*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 6) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6))];
            const double xi_190 = xi_176*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 5) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))];
            const double xi_191 = xi_177*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + 6) + ((210) / (6)) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6))];
            const double xi_192 = xi_178*_data_vertexCellSrc[ctr_1 + (ctr_2 - 1)*(-ctr_3 + 5) + ((210) / (6)) - ((ctr_2*(ctr_2 - 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6)) + 1];
            const double xi_193 = xi_179*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 6) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6)) + 1];
            const double xi_194 = xi_180*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 5) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6)) + 1];
            const double xi_196 = xi_112*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 5) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))];
            const double xi_197 = xi_113*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + 6) + ((210) / (6)) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6))];
            const double xi_198 = xi_114*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + 5) + ((210) / (6)) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))];
            const double xi_199 = xi_115*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 6) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6)) + 1];
            const double xi_200 = xi_116*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 5) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6)) + 1];
            const double xi_201 = xi_117*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + 6) + ((210) / (6)) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6)) + 1];
            _data_edgeCellDst_XZ[ctr_1 + ctr_2*(-ctr_3 + 5) + ((120) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))] = xi_189 + xi_190 + xi_191 + xi_192 + xi_193 + xi_194 + xi_195;
            _data_edgeCellDst_XYZ[ctr_1 + ctr_2*(-ctr_3 + 4) + ((60) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 3)*(-ctr_3 + 4)*(-ctr_3 + 5)) / (6))] = xi_196 + xi_197 + xi_198 + xi_199 + xi_200 + xi_201 + xi_202;
         }
         // face 0
         for (int ctr_1 = 1; ctr_1 < -ctr_2 + 3; ctr_1 += 1)
         {
            const double xi_336 = _data_edgeCellDst_Z[ctr_1 + ctr_2*(-ctr_3 + 5) + ((120) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))];
            const double xi_343 = _data_edgeCellDst_XZ[ctr_1 + ctr_2*(-ctr_3 + 5) + ((120) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))];
            const double xi_352 = _data_edgeCellDst_YZ[ctr_1 + ctr_2*(-ctr_3 + 5) + ((120) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))];
            const double xi_359 = _data_edgeCellDst_XYZ[ctr_1 + ctr_2*(-ctr_3 + 4) + ((60) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 3)*(-ctr_3 + 4)*(-ctr_3 + 5)) / (6))];
            const double xi_328 = xi_298*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 5) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6)) - 1];
            const double xi_329 = xi_299*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + 6) + ((210) / (6)) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6)) - 1];
            const double xi_330 = xi_300*_data_vertexCellSrc[ctr_1 + (ctr_2 - 1)*(-ctr_3 + 5) + ((210) / (6)) - ((ctr_2*(ctr_2 - 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))];
            const double xi_331 = xi_301*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 6) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6))];
            const double xi_332 = xi_302*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 5) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))];
            const double xi_333 = xi_303*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + 6) + ((210) / (6)) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6))];
            const double xi_334 = xi_304*_data_vertexCellSrc[ctr_1 + (ctr_2 - 1)*(-ctr_3 + 5) + ((210) / (6)) - ((ctr_2*(ctr_2 - 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6)) + 1];
            const double xi_335 = xi_305*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 6) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6)) + 1];
            const double xi_337 = xi_175*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 6) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6))];
            const double xi_338 = xi_176*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 5) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))];
            const double xi_339 = xi_177*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + 6) + ((210) / (6)) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6))];
            const double xi_340 = xi_178*_data_vertexCellSrc[ctr_1 + (ctr_2 - 1)*(-ctr_3 + 5) + ((210) / (6)) - ((ctr_2*(ctr_2 - 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6)) + 1];
            const double xi_341 = xi_179*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 6) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6)) + 1];
            const double xi_342 = xi_180*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 5) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6)) + 1];
            const double xi_344 = xi_141*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + 6) + ((210) / (6)) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6)) - 1];
            const double xi_345 = xi_142*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + 5) + ((210) / (6)) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6)) - 1];
            const double xi_346 = xi_143*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 6) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6))];
            const double xi_347 = xi_144*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 5) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))];
            const double xi_348 = xi_145*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + 6) + ((210) / (6)) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6))];
            const double xi_349 = xi_146*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + 5) + ((210) / (6)) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))];
            const double xi_350 = xi_147*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 6) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6)) + 1];
            const double xi_351 = xi_148*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 5) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6)) + 1];
            const double xi_353 = xi_112*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 5) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))];
            const double xi_354 = xi_113*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + 6) + ((210) / (6)) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6))];
            const double xi_355 = xi_114*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + 5) + ((210) / (6)) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))];
            const double xi_356 = xi_115*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 6) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6)) + 1];
            const double xi_357 = xi_116*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 5) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6)) + 1];
            const double xi_358 = xi_117*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + 6) + ((210) / (6)) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6)) + 1];
            _data_edgeCellDst_Z[ctr_1 + ctr_2*(-ctr_3 + 5) + ((120) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))] = xi_328 + xi_329 + xi_330 + xi_331 + xi_332 + xi_333 + xi_334 + xi_335 + xi_336;
            _data_edgeCellDst_XZ[ctr_1 + ctr_2*(-ctr_3 + 5) + ((120) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))] = xi_337 + xi_338 + xi_339 + xi_340 + xi_341 + xi_342 + xi_343;
            _data_edgeCellDst_YZ[ctr_1 + ctr_2*(-ctr_3 + 5) + ((120) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))] = xi_344 + xi_345 + xi_346 + xi_347 + xi_348 + xi_349 + xi_350 + xi_351 + xi_352;
            _data_edgeCellDst_XYZ[ctr_1 + ctr_2*(-ctr_3 + 4) + ((60) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 3)*(-ctr_3 + 4)*(-ctr_3 + 5)) / (6))] = xi_353 + xi_354 + xi_355 + xi_356 + xi_357 + xi_358 + xi_359;
         }
         // edge 2
         for (int ctr_1 = -ctr_2 + 3; ctr_1 < -ctr_2 + 4; ctr_1 += 1)
         {
            const double xi_223 = _data_edgeCellDst_Z[ctr_1 + ctr_2*(-ctr_3 + 5) + ((120) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))];
            const double xi_215 = xi_298*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 5) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6)) - 1];
            const double xi_216 = xi_299*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + 6) + ((210) / (6)) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6)) - 1];
            const double xi_217 = xi_300*_data_vertexCellSrc[ctr_1 + (ctr_2 - 1)*(-ctr_3 + 5) + ((210) / (6)) - ((ctr_2*(ctr_2 - 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))];
            const double xi_218 = xi_301*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 6) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6))];
            const double xi_219 = xi_302*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 5) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))];
            const double xi_220 = xi_303*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + 6) + ((210) / (6)) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6))];
            const double xi_221 = xi_304*_data_vertexCellSrc[ctr_1 + (ctr_2 - 1)*(-ctr_3 + 5) + ((210) / (6)) - ((ctr_2*(ctr_2 - 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6)) + 1];
            const double xi_222 = xi_305*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 6) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6)) + 1];
            _data_edgeCellDst_Z[ctr_1 + ctr_2*(-ctr_3 + 5) + ((120) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))] = xi_215 + xi_216 + xi_217 + xi_218 + xi_219 + xi_220 + xi_221 + xi_222 + xi_223;
         }
      }
   }
   for (int ctr_3 = 1; ctr_3 < 3; ctr_3 += 1)
   {
      for (int ctr_2 = 0; ctr_2 < 1; ctr_2 += 1)
      {
         // edge 3
         for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
         {
            const double xi_250 = _data_edgeCellDst_XY[ctr_1 + ctr_2*(-ctr_3 + 5) + ((120) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))];
            const double xi_257 = _data_edgeCellDst_XYZ[ctr_1 + ctr_2*(-ctr_3 + 4) + ((60) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 3)*(-ctr_3 + 4)*(-ctr_3 + 5)) / (6))];
            const double xi_242 = xi_226*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 6) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6))];
            const double xi_243 = xi_227*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 5) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))];
            const double xi_244 = xi_228*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + 7) + ((210) / (6)) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + 6)*(-ctr_3 + 7)*(-ctr_3 + 8)) / (6))];
            const double xi_245 = xi_229*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + 6) + ((210) / (6)) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6))];
            const double xi_246 = xi_230*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 6) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6)) + 1];
            const double xi_247 = xi_231*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 5) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6)) + 1];
            const double xi_248 = xi_232*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + 7) + ((210) / (6)) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + 6)*(-ctr_3 + 7)*(-ctr_3 + 8)) / (6)) + 1];
            const double xi_249 = xi_233*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + 6) + ((210) / (6)) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6)) + 1];
            const double xi_251 = xi_112*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 5) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))];
            const double xi_252 = xi_113*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + 6) + ((210) / (6)) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6))];
            const double xi_253 = xi_114*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + 5) + ((210) / (6)) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))];
            const double xi_254 = xi_115*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 6) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6)) + 1];
            const double xi_255 = xi_116*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 5) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6)) + 1];
            const double xi_256 = xi_117*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + 6) + ((210) / (6)) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6)) + 1];
            _data_edgeCellDst_XY[ctr_1 + ctr_2*(-ctr_3 + 5) + ((120) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))] = xi_242 + xi_243 + xi_244 + xi_245 + xi_246 + xi_247 + xi_248 + xi_249 + xi_250;
            _data_edgeCellDst_XYZ[ctr_1 + ctr_2*(-ctr_3 + 4) + ((60) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 3)*(-ctr_3 + 4)*(-ctr_3 + 5)) / (6))] = xi_251 + xi_252 + xi_253 + xi_254 + xi_255 + xi_256 + xi_257;
         }
         // face 1
         for (int ctr_1 = 1; ctr_1 < -ctr_3 + 3; ctr_1 += 1)
         {
            const double xi_398 = _data_edgeCellDst_Y[ctr_1 + ctr_2*(-ctr_3 + 5) + ((120) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))];
            const double xi_407 = _data_edgeCellDst_XY[ctr_1 + ctr_2*(-ctr_3 + 5) + ((120) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))];
            const double xi_416 = _data_edgeCellDst_YZ[ctr_1 + ctr_2*(-ctr_3 + 5) + ((120) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))];
            const double xi_423 = _data_edgeCellDst_XYZ[ctr_1 + ctr_2*(-ctr_3 + 4) + ((60) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 3)*(-ctr_3 + 4)*(-ctr_3 + 5)) / (6))];
            const double xi_392 = xi_362*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + 6) + ((210) / (6)) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6)) - 1];
            const double xi_393 = xi_363*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 6) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6))];
            const double xi_394 = xi_364*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 5) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))];
            const double xi_395 = xi_365*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + 7) + ((210) / (6)) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + 6)*(-ctr_3 + 7)*(-ctr_3 + 8)) / (6))];
            const double xi_396 = xi_366*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + 6) + ((210) / (6)) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6))];
            const double xi_397 = xi_367*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 6) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6)) + 1];
            const double xi_399 = xi_226*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 6) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6))];
            const double xi_400 = xi_227*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 5) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))];
            const double xi_401 = xi_228*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + 7) + ((210) / (6)) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + 6)*(-ctr_3 + 7)*(-ctr_3 + 8)) / (6))];
            const double xi_402 = xi_229*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + 6) + ((210) / (6)) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6))];
            const double xi_403 = xi_230*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 6) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6)) + 1];
            const double xi_404 = xi_231*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 5) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6)) + 1];
            const double xi_405 = xi_232*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + 7) + ((210) / (6)) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + 6)*(-ctr_3 + 7)*(-ctr_3 + 8)) / (6)) + 1];
            const double xi_406 = xi_233*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + 6) + ((210) / (6)) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6)) + 1];
            const double xi_408 = xi_141*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + 6) + ((210) / (6)) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6)) - 1];
            const double xi_409 = xi_142*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + 5) + ((210) / (6)) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6)) - 1];
            const double xi_410 = xi_143*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 6) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6))];
            const double xi_411 = xi_144*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 5) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))];
            const double xi_412 = xi_145*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + 6) + ((210) / (6)) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6))];
            const double xi_413 = xi_146*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + 5) + ((210) / (6)) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))];
            const double xi_414 = xi_147*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 6) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6)) + 1];
            const double xi_415 = xi_148*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 5) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6)) + 1];
            const double xi_417 = xi_112*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 5) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))];
            const double xi_418 = xi_113*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + 6) + ((210) / (6)) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6))];
            const double xi_419 = xi_114*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + 5) + ((210) / (6)) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))];
            const double xi_420 = xi_115*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 6) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6)) + 1];
            const double xi_421 = xi_116*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 5) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6)) + 1];
            const double xi_422 = xi_117*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + 6) + ((210) / (6)) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6)) + 1];
            _data_edgeCellDst_Y[ctr_1 + ctr_2*(-ctr_3 + 5) + ((120) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))] = xi_392 + xi_393 + xi_394 + xi_395 + xi_396 + xi_397 + xi_398;
            _data_edgeCellDst_XY[ctr_1 + ctr_2*(-ctr_3 + 5) + ((120) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))] = xi_399 + xi_400 + xi_401 + xi_402 + xi_403 + xi_404 + xi_405 + xi_406 + xi_407;
            _data_edgeCellDst_YZ[ctr_1 + ctr_2*(-ctr_3 + 5) + ((120) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))] = xi_408 + xi_409 + xi_410 + xi_411 + xi_412 + xi_413 + xi_414 + xi_415 + xi_416;
            _data_edgeCellDst_XYZ[ctr_1 + ctr_2*(-ctr_3 + 4) + ((60) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 3)*(-ctr_3 + 4)*(-ctr_3 + 5)) / (6))] = xi_417 + xi_418 + xi_419 + xi_420 + xi_421 + xi_422 + xi_423;
         }
         // edge 4
         for (int ctr_1 = -ctr_3 + 3; ctr_1 < -ctr_3 + 4; ctr_1 += 1)
         {
            const double xi_274 = _data_edgeCellDst_Y[ctr_1 + ctr_2*(-ctr_3 + 5) + ((120) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))];
            const double xi_268 = xi_362*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + 6) + ((210) / (6)) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6)) - 1];
            const double xi_269 = xi_363*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 6) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6))];
            const double xi_270 = xi_364*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 5) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))];
            const double xi_271 = xi_365*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + 7) + ((210) / (6)) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + 6)*(-ctr_3 + 7)*(-ctr_3 + 8)) / (6))];
            const double xi_272 = xi_366*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + 6) + ((210) / (6)) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6))];
            const double xi_273 = xi_367*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 6) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6)) + 1];
            _data_edgeCellDst_Y[ctr_1 + ctr_2*(-ctr_3 + 5) + ((120) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))] = xi_268 + xi_269 + xi_270 + xi_271 + xi_272 + xi_273 + xi_274;
         }
      }
      for (int ctr_2 = 1; ctr_2 < -ctr_3 + 3; ctr_2 += 1)
      {
         // face 2
         for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
         {
            const double xi_464 = _data_edgeCellDst_X[ctr_1 + ctr_2*(-ctr_3 + 5) + ((120) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))];
            const double xi_473 = _data_edgeCellDst_XY[ctr_1 + ctr_2*(-ctr_3 + 5) + ((120) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))];
            const double xi_480 = _data_edgeCellDst_XZ[ctr_1 + ctr_2*(-ctr_3 + 5) + ((120) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))];
            const double xi_487 = _data_edgeCellDst_XYZ[ctr_1 + ctr_2*(-ctr_3 + 4) + ((60) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 3)*(-ctr_3 + 4)*(-ctr_3 + 5)) / (6))];
            const double xi_456 = xi_426*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 6) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6))];
            const double xi_457 = xi_427*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 5) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))];
            const double xi_458 = xi_428*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + 7) + ((210) / (6)) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + 6)*(-ctr_3 + 7)*(-ctr_3 + 8)) / (6))];
            const double xi_459 = xi_429*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + 6) + ((210) / (6)) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6))];
            const double xi_460 = xi_430*_data_vertexCellSrc[ctr_1 + (ctr_2 - 1)*(-ctr_3 + 6) + ((210) / (6)) - ((ctr_2*(ctr_2 - 1)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6)) + 1];
            const double xi_461 = xi_431*_data_vertexCellSrc[ctr_1 + (ctr_2 - 1)*(-ctr_3 + 5) + ((210) / (6)) - ((ctr_2*(ctr_2 - 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6)) + 1];
            const double xi_462 = xi_432*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 7) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 6)*(-ctr_3 + 7)*(-ctr_3 + 8)) / (6)) + 1];
            const double xi_463 = xi_433*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 6) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6)) + 1];
            const double xi_465 = xi_226*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 6) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6))];
            const double xi_466 = xi_227*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 5) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))];
            const double xi_467 = xi_228*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + 7) + ((210) / (6)) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + 6)*(-ctr_3 + 7)*(-ctr_3 + 8)) / (6))];
            const double xi_468 = xi_229*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + 6) + ((210) / (6)) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6))];
            const double xi_469 = xi_230*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 6) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6)) + 1];
            const double xi_470 = xi_231*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 5) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6)) + 1];
            const double xi_471 = xi_232*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + 7) + ((210) / (6)) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + 6)*(-ctr_3 + 7)*(-ctr_3 + 8)) / (6)) + 1];
            const double xi_472 = xi_233*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + 6) + ((210) / (6)) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6)) + 1];
            const double xi_474 = xi_175*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 6) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6))];
            const double xi_475 = xi_176*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 5) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))];
            const double xi_476 = xi_177*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + 6) + ((210) / (6)) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6))];
            const double xi_477 = xi_178*_data_vertexCellSrc[ctr_1 + (ctr_2 - 1)*(-ctr_3 + 5) + ((210) / (6)) - ((ctr_2*(ctr_2 - 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6)) + 1];
            const double xi_478 = xi_179*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 6) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6)) + 1];
            const double xi_479 = xi_180*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 5) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6)) + 1];
            const double xi_481 = xi_112*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 5) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))];
            const double xi_482 = xi_113*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + 6) + ((210) / (6)) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6))];
            const double xi_483 = xi_114*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + 5) + ((210) / (6)) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))];
            const double xi_484 = xi_115*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 6) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6)) + 1];
            const double xi_485 = xi_116*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 5) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6)) + 1];
            const double xi_486 = xi_117*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + 6) + ((210) / (6)) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6)) + 1];
            _data_edgeCellDst_X[ctr_1 + ctr_2*(-ctr_3 + 5) + ((120) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))] = xi_456 + xi_457 + xi_458 + xi_459 + xi_460 + xi_461 + xi_462 + xi_463 + xi_464;
            _data_edgeCellDst_XY[ctr_1 + ctr_2*(-ctr_3 + 5) + ((120) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))] = xi_465 + xi_466 + xi_467 + xi_468 + xi_469 + xi_470 + xi_471 + xi_472 + xi_473;
            _data_edgeCellDst_XZ[ctr_1 + ctr_2*(-ctr_3 + 5) + ((120) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))] = xi_474 + xi_475 + xi_476 + xi_477 + xi_478 + xi_479 + xi_480;
            _data_edgeCellDst_XYZ[ctr_1 + ctr_2*(-ctr_3 + 4) + ((60) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 3)*(-ctr_3 + 4)*(-ctr_3 + 5)) / (6))] = xi_481 + xi_482 + xi_483 + xi_484 + xi_485 + xi_486 + xi_487;
         }
         // cell (inner)
         for (int ctr_1 = 1; ctr_1 < -ctr_2 - ctr_3 + 3; ctr_1 += 1)
         {
            const double xi_61 = _data_edgeCellDst_X[ctr_1 + ctr_2*(-ctr_3 + 5) + ((120) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))];
            const double xi_68 = _data_edgeCellDst_Y[ctr_1 + ctr_2*(-ctr_3 + 5) + ((120) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))];
            const double xi_77 = _data_edgeCellDst_Z[ctr_1 + ctr_2*(-ctr_3 + 5) + ((120) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))];
            const double xi_86 = _data_edgeCellDst_XY[ctr_1 + ctr_2*(-ctr_3 + 5) + ((120) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))];
            const double xi_93 = _data_edgeCellDst_XZ[ctr_1 + ctr_2*(-ctr_3 + 5) + ((120) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))];
            const double xi_102 = _data_edgeCellDst_YZ[ctr_1 + ctr_2*(-ctr_3 + 5) + ((120) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))];
            const double xi_109 = _data_edgeCellDst_XYZ[ctr_1 + ctr_2*(-ctr_3 + 4) + ((60) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 3)*(-ctr_3 + 4)*(-ctr_3 + 5)) / (6))];
            const double xi_53 = xi_426*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 6) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6))];
            const double xi_54 = xi_427*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 5) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))];
            const double xi_55 = xi_428*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + 7) + ((210) / (6)) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + 6)*(-ctr_3 + 7)*(-ctr_3 + 8)) / (6))];
            const double xi_56 = xi_429*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + 6) + ((210) / (6)) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6))];
            const double xi_57 = xi_430*_data_vertexCellSrc[ctr_1 + (ctr_2 - 1)*(-ctr_3 + 6) + ((210) / (6)) - ((ctr_2*(ctr_2 - 1)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6)) + 1];
            const double xi_58 = xi_431*_data_vertexCellSrc[ctr_1 + (ctr_2 - 1)*(-ctr_3 + 5) + ((210) / (6)) - ((ctr_2*(ctr_2 - 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6)) + 1];
            const double xi_59 = xi_432*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 7) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 6)*(-ctr_3 + 7)*(-ctr_3 + 8)) / (6)) + 1];
            const double xi_60 = xi_433*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 6) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6)) + 1];
            const double xi_67 = xi_362*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + 6) + ((210) / (6)) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6)) - 1];
            const double xi_62 = xi_363*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 6) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6))];
            const double xi_63 = xi_364*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 5) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))];
            const double xi_64 = xi_365*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + 7) + ((210) / (6)) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + 6)*(-ctr_3 + 7)*(-ctr_3 + 8)) / (6))];
            const double xi_65 = xi_366*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + 6) + ((210) / (6)) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6))];
            const double xi_66 = xi_367*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 6) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6)) + 1];
            const double xi_69 = xi_298*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 5) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6)) - 1];
            const double xi_70 = xi_299*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + 6) + ((210) / (6)) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6)) - 1];
            const double xi_71 = xi_300*_data_vertexCellSrc[ctr_1 + (ctr_2 - 1)*(-ctr_3 + 5) + ((210) / (6)) - ((ctr_2*(ctr_2 - 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))];
            const double xi_72 = xi_301*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 6) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6))];
            const double xi_73 = xi_302*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 5) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))];
            const double xi_74 = xi_303*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + 6) + ((210) / (6)) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6))];
            const double xi_75 = xi_304*_data_vertexCellSrc[ctr_1 + (ctr_2 - 1)*(-ctr_3 + 5) + ((210) / (6)) - ((ctr_2*(ctr_2 - 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6)) + 1];
            const double xi_76 = xi_305*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 6) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6)) + 1];
            const double xi_78 = xi_226*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 6) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6))];
            const double xi_79 = xi_227*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 5) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))];
            const double xi_80 = xi_228*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + 7) + ((210) / (6)) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + 6)*(-ctr_3 + 7)*(-ctr_3 + 8)) / (6))];
            const double xi_81 = xi_229*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + 6) + ((210) / (6)) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6))];
            const double xi_82 = xi_230*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 6) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6)) + 1];
            const double xi_83 = xi_231*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 5) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6)) + 1];
            const double xi_84 = xi_232*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + 7) + ((210) / (6)) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + 6)*(-ctr_3 + 7)*(-ctr_3 + 8)) / (6)) + 1];
            const double xi_85 = xi_233*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + 6) + ((210) / (6)) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6)) + 1];
            const double xi_87 = xi_175*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 6) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6))];
            const double xi_88 = xi_176*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 5) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))];
            const double xi_89 = xi_177*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + 6) + ((210) / (6)) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6))];
            const double xi_90 = xi_178*_data_vertexCellSrc[ctr_1 + (ctr_2 - 1)*(-ctr_3 + 5) + ((210) / (6)) - ((ctr_2*(ctr_2 - 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6)) + 1];
            const double xi_91 = xi_179*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 6) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6)) + 1];
            const double xi_92 = xi_180*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 5) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6)) + 1];
            const double xi_94 = xi_141*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + 6) + ((210) / (6)) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6)) - 1];
            const double xi_95 = xi_142*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + 5) + ((210) / (6)) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6)) - 1];
            const double xi_96 = xi_143*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 6) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6))];
            const double xi_97 = xi_144*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 5) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))];
            const double xi_98 = xi_145*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + 6) + ((210) / (6)) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6))];
            const double xi_99 = xi_146*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + 5) + ((210) / (6)) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))];
            const double xi_100 = xi_147*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 6) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6)) + 1];
            const double xi_101 = xi_148*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 5) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6)) + 1];
            const double xi_103 = xi_112*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 5) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))];
            const double xi_104 = xi_113*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + 6) + ((210) / (6)) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6))];
            const double xi_105 = xi_114*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + 5) + ((210) / (6)) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))];
            const double xi_106 = xi_115*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 6) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6)) + 1];
            const double xi_107 = xi_116*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 5) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6)) + 1];
            const double xi_108 = xi_117*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + 6) + ((210) / (6)) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6)) + 1];
            _data_edgeCellDst_X[ctr_1 + ctr_2*(-ctr_3 + 5) + ((120) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))] = xi_53 + xi_54 + xi_55 + xi_56 + xi_57 + xi_58 + xi_59 + xi_60 + xi_61;
            _data_edgeCellDst_Y[ctr_1 + ctr_2*(-ctr_3 + 5) + ((120) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))] = xi_62 + xi_63 + xi_64 + xi_65 + xi_66 + xi_67 + xi_68;
            _data_edgeCellDst_Z[ctr_1 + ctr_2*(-ctr_3 + 5) + ((120) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))] = xi_69 + xi_70 + xi_71 + xi_72 + xi_73 + xi_74 + xi_75 + xi_76 + xi_77;
            _data_edgeCellDst_XY[ctr_1 + ctr_2*(-ctr_3 + 5) + ((120) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))] = xi_78 + xi_79 + xi_80 + xi_81 + xi_82 + xi_83 + xi_84 + xi_85 + xi_86;
            _data_edgeCellDst_XZ[ctr_1 + ctr_2*(-ctr_3 + 5) + ((120) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))] = xi_87 + xi_88 + xi_89 + xi_90 + xi_91 + xi_92 + xi_93;
            _data_edgeCellDst_YZ[ctr_1 + ctr_2*(-ctr_3 + 5) + ((120) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))] = xi_100 + xi_101 + xi_102 + xi_94 + xi_95 + xi_96 + xi_97 + xi_98 + xi_99;
            _data_edgeCellDst_XYZ[ctr_1 + ctr_2*(-ctr_3 + 4) + ((60) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 3)*(-ctr_3 + 4)*(-ctr_3 + 5)) / (6))] = xi_103 + xi_104 + xi_105 + xi_106 + xi_107 + xi_108 + xi_109;
         }
         // face 3
         for (int ctr_1 = -ctr_2 - ctr_3 + 3; ctr_1 < -ctr_2 - ctr_3 + 4; ctr_1 += 1)
         {
            const double xi_522 = _data_edgeCellDst_X[ctr_1 + ctr_2*(-ctr_3 + 5) + ((120) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))];
            const double xi_529 = _data_edgeCellDst_Y[ctr_1 + ctr_2*(-ctr_3 + 5) + ((120) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))];
            const double xi_538 = _data_edgeCellDst_Z[ctr_1 + ctr_2*(-ctr_3 + 5) + ((120) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))];
            const double xi_514 = xi_426*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 6) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6))];
            const double xi_515 = xi_427*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 5) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))];
            const double xi_516 = xi_428*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + 7) + ((210) / (6)) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + 6)*(-ctr_3 + 7)*(-ctr_3 + 8)) / (6))];
            const double xi_517 = xi_429*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + 6) + ((210) / (6)) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6))];
            const double xi_518 = xi_430*_data_vertexCellSrc[ctr_1 + (ctr_2 - 1)*(-ctr_3 + 6) + ((210) / (6)) - ((ctr_2*(ctr_2 - 1)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6)) + 1];
            const double xi_519 = xi_431*_data_vertexCellSrc[ctr_1 + (ctr_2 - 1)*(-ctr_3 + 5) + ((210) / (6)) - ((ctr_2*(ctr_2 - 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6)) + 1];
            const double xi_520 = xi_432*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 7) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 6)*(-ctr_3 + 7)*(-ctr_3 + 8)) / (6)) + 1];
            const double xi_521 = xi_433*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 6) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6)) + 1];
            const double xi_523 = xi_362*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + 6) + ((210) / (6)) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6)) - 1];
            const double xi_524 = xi_363*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 6) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6))];
            const double xi_525 = xi_364*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 5) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))];
            const double xi_526 = xi_365*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + 7) + ((210) / (6)) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + 6)*(-ctr_3 + 7)*(-ctr_3 + 8)) / (6))];
            const double xi_527 = xi_366*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + 6) + ((210) / (6)) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6))];
            const double xi_528 = xi_367*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 6) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6)) + 1];
            const double xi_530 = xi_298*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 5) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6)) - 1];
            const double xi_531 = xi_299*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + 6) + ((210) / (6)) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6)) - 1];
            const double xi_532 = xi_300*_data_vertexCellSrc[ctr_1 + (ctr_2 - 1)*(-ctr_3 + 5) + ((210) / (6)) - ((ctr_2*(ctr_2 - 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))];
            const double xi_533 = xi_301*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 6) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6))];
            const double xi_534 = xi_302*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 5) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))];
            const double xi_535 = xi_303*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + 6) + ((210) / (6)) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6))];
            const double xi_536 = xi_304*_data_vertexCellSrc[ctr_1 + (ctr_2 - 1)*(-ctr_3 + 5) + ((210) / (6)) - ((ctr_2*(ctr_2 - 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6)) + 1];
            const double xi_537 = xi_305*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 6) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6)) + 1];
            _data_edgeCellDst_X[ctr_1 + ctr_2*(-ctr_3 + 5) + ((120) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))] = xi_514 + xi_515 + xi_516 + xi_517 + xi_518 + xi_519 + xi_520 + xi_521 + xi_522;
            _data_edgeCellDst_Y[ctr_1 + ctr_2*(-ctr_3 + 5) + ((120) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))] = xi_523 + xi_524 + xi_525 + xi_526 + xi_527 + xi_528 + xi_529;
            _data_edgeCellDst_Z[ctr_1 + ctr_2*(-ctr_3 + 5) + ((120) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))] = xi_530 + xi_531 + xi_532 + xi_533 + xi_534 + xi_535 + xi_536 + xi_537 + xi_538;
         }
      }
      for (int ctr_2 = -ctr_3 + 3; ctr_2 < -ctr_3 + 4; ctr_2 += 1)
      {
         // edge 5
         for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
         {
            const double xi_295 = _data_edgeCellDst_X[ctr_1 + ctr_2*(-ctr_3 + 5) + ((120) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))];
            const double xi_287 = xi_426*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 6) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6))];
            const double xi_288 = xi_427*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 5) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))];
            const double xi_289 = xi_428*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + 7) + ((210) / (6)) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + 6)*(-ctr_3 + 7)*(-ctr_3 + 8)) / (6))];
            const double xi_290 = xi_429*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + 6) + ((210) / (6)) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6))];
            const double xi_291 = xi_430*_data_vertexCellSrc[ctr_1 + (ctr_2 - 1)*(-ctr_3 + 6) + ((210) / (6)) - ((ctr_2*(ctr_2 - 1)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6)) + 1];
            const double xi_292 = xi_431*_data_vertexCellSrc[ctr_1 + (ctr_2 - 1)*(-ctr_3 + 5) + ((210) / (6)) - ((ctr_2*(ctr_2 - 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6)) + 1];
            const double xi_293 = xi_432*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 7) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 6)*(-ctr_3 + 7)*(-ctr_3 + 8)) / (6)) + 1];
            const double xi_294 = xi_433*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + 6) + ((210) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 5)*(-ctr_3 + 6)*(-ctr_3 + 7)) / (6)) + 1];
            _data_edgeCellDst_X[ctr_1 + ctr_2*(-ctr_3 + 5) + ((120) / (6)) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + 4)*(-ctr_3 + 5)*(-ctr_3 + 6)) / (6))] = xi_287 + xi_288 + xi_289 + xi_290 + xi_291 + xi_292 + xi_293 + xi_294 + xi_295;
         }
      }
   }
   {
      
   }
}

static void apply_3D_macrocell_vertexdof_to_edgedof_add_level_any(double * _data_edgeCellDst_X, double * _data_edgeCellDst_XY, double * _data_edgeCellDst_XYZ, double * _data_edgeCellDst_XZ, double * _data_edgeCellDst_Y, double * _data_edgeCellDst_YZ, double * _data_edgeCellDst_Z, double * _data_vertexCellSrc, int64_t level, std::map< hhg::edgedof::EdgeDoFOrientation, std::map< hhg::indexing::IndexIncrement, double > > v2eStencilMap)
{
   const double xi_112 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::XYZ][{ 0, 0, 1 }];
   const double xi_113 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::XYZ][{ 0, 1, 0 }];
   const double xi_114 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::XYZ][{ 0, 1, 1 }];
   const double xi_115 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::XYZ][{ 1, 0, 0 }];
   const double xi_116 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::XYZ][{ 1, 0, 1 }];
   const double xi_117 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::XYZ][{ 1, 1, 0 }];
   const double xi_141 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::YZ][{ -1, 1, 0 }];
   const double xi_142 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::YZ][{ -1, 1, 1 }];
   const double xi_143 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::YZ][{ 0, 0, 0 }];
   const double xi_144 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::YZ][{ 0, 0, 1 }];
   const double xi_145 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::YZ][{ 0, 1, 0 }];
   const double xi_146 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::YZ][{ 0, 1, 1 }];
   const double xi_147 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::YZ][{ 1, 0, 0 }];
   const double xi_148 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::YZ][{ 1, 0, 1 }];
   const double xi_175 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::XZ][{ 0, 0, 0 }];
   const double xi_176 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::XZ][{ 0, 0, 1 }];
   const double xi_177 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::XZ][{ 0, 1, 0 }];
   const double xi_178 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::XZ][{ 1, -1, 1 }];
   const double xi_179 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::XZ][{ 1, 0, 0 }];
   const double xi_180 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::XZ][{ 1, 0, 1 }];
   const double xi_298 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::Z][{ -1, 0, 1 }];
   const double xi_299 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::Z][{ -1, 1, 0 }];
   const double xi_300 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::Z][{ 0, -1, 1 }];
   const double xi_301 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::Z][{ 0, 0, 0 }];
   const double xi_302 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::Z][{ 0, 0, 1 }];
   const double xi_303 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::Z][{ 0, 1, 0 }];
   const double xi_304 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::Z][{ 1, -1, 1 }];
   const double xi_305 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::Z][{ 1, 0, 0 }];
   const double xi_226 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::XY][{ 0, 0, 0 }];
   const double xi_227 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::XY][{ 0, 0, 1 }];
   const double xi_228 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::XY][{ 0, 1, -1 }];
   const double xi_229 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::XY][{ 0, 1, 0 }];
   const double xi_230 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::XY][{ 1, 0, 0 }];
   const double xi_231 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::XY][{ 1, 0, 1 }];
   const double xi_232 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::XY][{ 1, 1, -1 }];
   const double xi_233 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::XY][{ 1, 1, 0 }];
   const double xi_362 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::Y][{ -1, 1, 0 }];
   const double xi_363 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::Y][{ 0, 0, 0 }];
   const double xi_364 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::Y][{ 0, 0, 1 }];
   const double xi_365 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::Y][{ 0, 1, -1 }];
   const double xi_366 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::Y][{ 0, 1, 0 }];
   const double xi_367 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::Y][{ 1, 0, 0 }];
   const double xi_426 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::X][{ 0, 0, 0 }];
   const double xi_427 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::X][{ 0, 0, 1 }];
   const double xi_428 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::X][{ 0, 1, -1 }];
   const double xi_429 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::X][{ 0, 1, 0 }];
   const double xi_430 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::X][{ 1, -1, 0 }];
   const double xi_431 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::X][{ 1, -1, 1 }];
   const double xi_432 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::X][{ 1, 0, -1 }];
   const double xi_433 = v2eStencilMap[hhg::edgedof::EdgeDoFOrientation::X][{ 1, 0, 0 }];
   for (int ctr_3 = 0; ctr_3 < 1; ctr_3 += 1)
   {
      for (int ctr_2 = 0; ctr_2 < 1; ctr_2 += 1)
      {
         // vertex 0
         for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
         {
            const double xi_126 = _data_edgeCellDst_XYZ[ctr_1 + ctr_2*(-ctr_3 + (1 << (level))) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) - 1)*(-ctr_3 + (1 << (level)) + 1)) / (6)) + ((((1 << (level)) - 1)*((1 << (level)) + 1)*(1 << (level))) / (6))];
            const double xi_120 = xi_112*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6))];
            const double xi_121 = xi_113*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + (1 << (level)) + 2) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6))];
            const double xi_122 = xi_114*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + (1 << (level)) + 1) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6))];
            const double xi_123 = xi_115*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 2) - ((ctr_2*(ctr_2 + 1)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6)) + 1];
            const double xi_124 = xi_116*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) + 1];
            const double xi_125 = xi_117*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + (1 << (level)) + 2) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6)) + 1];
            _data_edgeCellDst_XYZ[ctr_1 + ctr_2*(-ctr_3 + (1 << (level))) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) - 1)*(-ctr_3 + (1 << (level)) + 1)) / (6)) + ((((1 << (level)) - 1)*((1 << (level)) + 1)*(1 << (level))) / (6))] = xi_120 + xi_121 + xi_122 + xi_123 + xi_124 + xi_125 + xi_126;
         }
         // edge 0
         for (int ctr_1 = 1; ctr_1 < (1 << (level)) - 1; ctr_1 += 1)
         {
            const double xi_165 = _data_edgeCellDst_YZ[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*(1 << (level))) / (6))];
            const double xi_172 = _data_edgeCellDst_XYZ[ctr_1 + ctr_2*(-ctr_3 + (1 << (level))) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) - 1)*(-ctr_3 + (1 << (level)) + 1)) / (6)) + ((((1 << (level)) - 1)*((1 << (level)) + 1)*(1 << (level))) / (6))];
            const double xi_157 = xi_141*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + (1 << (level)) + 2) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6)) - 1];
            const double xi_158 = xi_142*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + (1 << (level)) + 1) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - 1];
            const double xi_159 = xi_143*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 2) - ((ctr_2*(ctr_2 + 1)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6))];
            const double xi_160 = xi_144*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6))];
            const double xi_161 = xi_145*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + (1 << (level)) + 2) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6))];
            const double xi_162 = xi_146*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + (1 << (level)) + 1) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6))];
            const double xi_163 = xi_147*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 2) - ((ctr_2*(ctr_2 + 1)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6)) + 1];
            const double xi_164 = xi_148*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) + 1];
            const double xi_166 = xi_112*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6))];
            const double xi_167 = xi_113*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + (1 << (level)) + 2) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6))];
            const double xi_168 = xi_114*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + (1 << (level)) + 1) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6))];
            const double xi_169 = xi_115*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 2) - ((ctr_2*(ctr_2 + 1)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6)) + 1];
            const double xi_170 = xi_116*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) + 1];
            const double xi_171 = xi_117*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + (1 << (level)) + 2) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6)) + 1];
            _data_edgeCellDst_YZ[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*(1 << (level))) / (6))] = xi_157 + xi_158 + xi_159 + xi_160 + xi_161 + xi_162 + xi_163 + xi_164 + xi_165;
            _data_edgeCellDst_XYZ[ctr_1 + ctr_2*(-ctr_3 + (1 << (level))) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) - 1)*(-ctr_3 + (1 << (level)) + 1)) / (6)) + ((((1 << (level)) - 1)*((1 << (level)) + 1)*(1 << (level))) / (6))] = xi_166 + xi_167 + xi_168 + xi_169 + xi_170 + xi_171 + xi_172;
         }
      }
      for (int ctr_2 = 1; ctr_2 < -ctr_3 + (1 << (level)) - 1; ctr_2 += 1)
      {
         // edge 1
         for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
         {
            const double xi_195 = _data_edgeCellDst_XZ[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*(1 << (level))) / (6))];
            const double xi_202 = _data_edgeCellDst_XYZ[ctr_1 + ctr_2*(-ctr_3 + (1 << (level))) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) - 1)*(-ctr_3 + (1 << (level)) + 1)) / (6)) + ((((1 << (level)) - 1)*((1 << (level)) + 1)*(1 << (level))) / (6))];
            const double xi_189 = xi_175*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 2) - ((ctr_2*(ctr_2 + 1)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6))];
            const double xi_190 = xi_176*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6))];
            const double xi_191 = xi_177*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + (1 << (level)) + 2) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6))];
            const double xi_192 = xi_178*_data_vertexCellSrc[ctr_1 + (ctr_2 - 1)*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 - 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) + 1];
            const double xi_193 = xi_179*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 2) - ((ctr_2*(ctr_2 + 1)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6)) + 1];
            const double xi_194 = xi_180*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) + 1];
            const double xi_196 = xi_112*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6))];
            const double xi_197 = xi_113*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + (1 << (level)) + 2) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6))];
            const double xi_198 = xi_114*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + (1 << (level)) + 1) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6))];
            const double xi_199 = xi_115*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 2) - ((ctr_2*(ctr_2 + 1)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6)) + 1];
            const double xi_200 = xi_116*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) + 1];
            const double xi_201 = xi_117*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + (1 << (level)) + 2) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6)) + 1];
            _data_edgeCellDst_XZ[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*(1 << (level))) / (6))] = xi_189 + xi_190 + xi_191 + xi_192 + xi_193 + xi_194 + xi_195;
            _data_edgeCellDst_XYZ[ctr_1 + ctr_2*(-ctr_3 + (1 << (level))) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) - 1)*(-ctr_3 + (1 << (level)) + 1)) / (6)) + ((((1 << (level)) - 1)*((1 << (level)) + 1)*(1 << (level))) / (6))] = xi_196 + xi_197 + xi_198 + xi_199 + xi_200 + xi_201 + xi_202;
         }
         // face 0
         for (int ctr_1 = 1; ctr_1 < -ctr_2 + (1 << (level)) - 1; ctr_1 += 1)
         {
            const double xi_336 = _data_edgeCellDst_Z[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*(1 << (level))) / (6))];
            const double xi_343 = _data_edgeCellDst_XZ[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*(1 << (level))) / (6))];
            const double xi_352 = _data_edgeCellDst_YZ[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*(1 << (level))) / (6))];
            const double xi_359 = _data_edgeCellDst_XYZ[ctr_1 + ctr_2*(-ctr_3 + (1 << (level))) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) - 1)*(-ctr_3 + (1 << (level)) + 1)) / (6)) + ((((1 << (level)) - 1)*((1 << (level)) + 1)*(1 << (level))) / (6))];
            const double xi_328 = xi_298*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - 1];
            const double xi_329 = xi_299*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + (1 << (level)) + 2) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6)) - 1];
            const double xi_330 = xi_300*_data_vertexCellSrc[ctr_1 + (ctr_2 - 1)*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 - 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6))];
            const double xi_331 = xi_301*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 2) - ((ctr_2*(ctr_2 + 1)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6))];
            const double xi_332 = xi_302*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6))];
            const double xi_333 = xi_303*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + (1 << (level)) + 2) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6))];
            const double xi_334 = xi_304*_data_vertexCellSrc[ctr_1 + (ctr_2 - 1)*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 - 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) + 1];
            const double xi_335 = xi_305*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 2) - ((ctr_2*(ctr_2 + 1)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6)) + 1];
            const double xi_337 = xi_175*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 2) - ((ctr_2*(ctr_2 + 1)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6))];
            const double xi_338 = xi_176*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6))];
            const double xi_339 = xi_177*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + (1 << (level)) + 2) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6))];
            const double xi_340 = xi_178*_data_vertexCellSrc[ctr_1 + (ctr_2 - 1)*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 - 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) + 1];
            const double xi_341 = xi_179*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 2) - ((ctr_2*(ctr_2 + 1)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6)) + 1];
            const double xi_342 = xi_180*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) + 1];
            const double xi_344 = xi_141*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + (1 << (level)) + 2) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6)) - 1];
            const double xi_345 = xi_142*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + (1 << (level)) + 1) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - 1];
            const double xi_346 = xi_143*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 2) - ((ctr_2*(ctr_2 + 1)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6))];
            const double xi_347 = xi_144*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6))];
            const double xi_348 = xi_145*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + (1 << (level)) + 2) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6))];
            const double xi_349 = xi_146*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + (1 << (level)) + 1) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6))];
            const double xi_350 = xi_147*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 2) - ((ctr_2*(ctr_2 + 1)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6)) + 1];
            const double xi_351 = xi_148*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) + 1];
            const double xi_353 = xi_112*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6))];
            const double xi_354 = xi_113*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + (1 << (level)) + 2) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6))];
            const double xi_355 = xi_114*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + (1 << (level)) + 1) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6))];
            const double xi_356 = xi_115*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 2) - ((ctr_2*(ctr_2 + 1)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6)) + 1];
            const double xi_357 = xi_116*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) + 1];
            const double xi_358 = xi_117*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + (1 << (level)) + 2) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6)) + 1];
            _data_edgeCellDst_Z[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*(1 << (level))) / (6))] = xi_328 + xi_329 + xi_330 + xi_331 + xi_332 + xi_333 + xi_334 + xi_335 + xi_336;
            _data_edgeCellDst_XZ[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*(1 << (level))) / (6))] = xi_337 + xi_338 + xi_339 + xi_340 + xi_341 + xi_342 + xi_343;
            _data_edgeCellDst_YZ[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*(1 << (level))) / (6))] = xi_344 + xi_345 + xi_346 + xi_347 + xi_348 + xi_349 + xi_350 + xi_351 + xi_352;
            _data_edgeCellDst_XYZ[ctr_1 + ctr_2*(-ctr_3 + (1 << (level))) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) - 1)*(-ctr_3 + (1 << (level)) + 1)) / (6)) + ((((1 << (level)) - 1)*((1 << (level)) + 1)*(1 << (level))) / (6))] = xi_353 + xi_354 + xi_355 + xi_356 + xi_357 + xi_358 + xi_359;
         }
         // edge 2
         for (int ctr_1 = -ctr_2 + (1 << (level)) - 1; ctr_1 < -ctr_2 + (1 << (level)); ctr_1 += 1)
         {
            const double xi_223 = _data_edgeCellDst_Z[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*(1 << (level))) / (6))];
            const double xi_215 = xi_298*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - 1];
            const double xi_216 = xi_299*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + (1 << (level)) + 2) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6)) - 1];
            const double xi_217 = xi_300*_data_vertexCellSrc[ctr_1 + (ctr_2 - 1)*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 - 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6))];
            const double xi_218 = xi_301*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 2) - ((ctr_2*(ctr_2 + 1)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6))];
            const double xi_219 = xi_302*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6))];
            const double xi_220 = xi_303*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + (1 << (level)) + 2) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6))];
            const double xi_221 = xi_304*_data_vertexCellSrc[ctr_1 + (ctr_2 - 1)*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 - 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) + 1];
            const double xi_222 = xi_305*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 2) - ((ctr_2*(ctr_2 + 1)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6)) + 1];
            _data_edgeCellDst_Z[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*(1 << (level))) / (6))] = xi_215 + xi_216 + xi_217 + xi_218 + xi_219 + xi_220 + xi_221 + xi_222 + xi_223;
         }
      }
   }
   for (int ctr_3 = 1; ctr_3 < (1 << (level)) - 1; ctr_3 += 1)
   {
      for (int ctr_2 = 0; ctr_2 < 1; ctr_2 += 1)
      {
         // edge 3
         for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
         {
            const double xi_250 = _data_edgeCellDst_XY[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*(1 << (level))) / (6))];
            const double xi_257 = _data_edgeCellDst_XYZ[ctr_1 + ctr_2*(-ctr_3 + (1 << (level))) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) - 1)*(-ctr_3 + (1 << (level)) + 1)) / (6)) + ((((1 << (level)) - 1)*((1 << (level)) + 1)*(1 << (level))) / (6))];
            const double xi_242 = xi_226*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 2) - ((ctr_2*(ctr_2 + 1)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6))];
            const double xi_243 = xi_227*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6))];
            const double xi_244 = xi_228*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + (1 << (level)) + 3) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)*(-ctr_3 + (1 << (level)) + 4)) / (6))];
            const double xi_245 = xi_229*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + (1 << (level)) + 2) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6))];
            const double xi_246 = xi_230*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 2) - ((ctr_2*(ctr_2 + 1)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6)) + 1];
            const double xi_247 = xi_231*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) + 1];
            const double xi_248 = xi_232*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + (1 << (level)) + 3) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)*(-ctr_3 + (1 << (level)) + 4)) / (6)) + 1];
            const double xi_249 = xi_233*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + (1 << (level)) + 2) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6)) + 1];
            const double xi_251 = xi_112*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6))];
            const double xi_252 = xi_113*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + (1 << (level)) + 2) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6))];
            const double xi_253 = xi_114*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + (1 << (level)) + 1) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6))];
            const double xi_254 = xi_115*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 2) - ((ctr_2*(ctr_2 + 1)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6)) + 1];
            const double xi_255 = xi_116*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) + 1];
            const double xi_256 = xi_117*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + (1 << (level)) + 2) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6)) + 1];
            _data_edgeCellDst_XY[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*(1 << (level))) / (6))] = xi_242 + xi_243 + xi_244 + xi_245 + xi_246 + xi_247 + xi_248 + xi_249 + xi_250;
            _data_edgeCellDst_XYZ[ctr_1 + ctr_2*(-ctr_3 + (1 << (level))) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) - 1)*(-ctr_3 + (1 << (level)) + 1)) / (6)) + ((((1 << (level)) - 1)*((1 << (level)) + 1)*(1 << (level))) / (6))] = xi_251 + xi_252 + xi_253 + xi_254 + xi_255 + xi_256 + xi_257;
         }
         // face 1
         for (int ctr_1 = 1; ctr_1 < -ctr_3 + (1 << (level)) - 1; ctr_1 += 1)
         {
            const double xi_398 = _data_edgeCellDst_Y[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*(1 << (level))) / (6))];
            const double xi_407 = _data_edgeCellDst_XY[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*(1 << (level))) / (6))];
            const double xi_416 = _data_edgeCellDst_YZ[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*(1 << (level))) / (6))];
            const double xi_423 = _data_edgeCellDst_XYZ[ctr_1 + ctr_2*(-ctr_3 + (1 << (level))) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) - 1)*(-ctr_3 + (1 << (level)) + 1)) / (6)) + ((((1 << (level)) - 1)*((1 << (level)) + 1)*(1 << (level))) / (6))];
            const double xi_392 = xi_362*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + (1 << (level)) + 2) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6)) - 1];
            const double xi_393 = xi_363*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 2) - ((ctr_2*(ctr_2 + 1)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6))];
            const double xi_394 = xi_364*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6))];
            const double xi_395 = xi_365*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + (1 << (level)) + 3) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)*(-ctr_3 + (1 << (level)) + 4)) / (6))];
            const double xi_396 = xi_366*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + (1 << (level)) + 2) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6))];
            const double xi_397 = xi_367*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 2) - ((ctr_2*(ctr_2 + 1)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6)) + 1];
            const double xi_399 = xi_226*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 2) - ((ctr_2*(ctr_2 + 1)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6))];
            const double xi_400 = xi_227*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6))];
            const double xi_401 = xi_228*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + (1 << (level)) + 3) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)*(-ctr_3 + (1 << (level)) + 4)) / (6))];
            const double xi_402 = xi_229*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + (1 << (level)) + 2) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6))];
            const double xi_403 = xi_230*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 2) - ((ctr_2*(ctr_2 + 1)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6)) + 1];
            const double xi_404 = xi_231*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) + 1];
            const double xi_405 = xi_232*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + (1 << (level)) + 3) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)*(-ctr_3 + (1 << (level)) + 4)) / (6)) + 1];
            const double xi_406 = xi_233*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + (1 << (level)) + 2) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6)) + 1];
            const double xi_408 = xi_141*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + (1 << (level)) + 2) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6)) - 1];
            const double xi_409 = xi_142*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + (1 << (level)) + 1) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - 1];
            const double xi_410 = xi_143*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 2) - ((ctr_2*(ctr_2 + 1)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6))];
            const double xi_411 = xi_144*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6))];
            const double xi_412 = xi_145*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + (1 << (level)) + 2) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6))];
            const double xi_413 = xi_146*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + (1 << (level)) + 1) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6))];
            const double xi_414 = xi_147*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 2) - ((ctr_2*(ctr_2 + 1)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6)) + 1];
            const double xi_415 = xi_148*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) + 1];
            const double xi_417 = xi_112*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6))];
            const double xi_418 = xi_113*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + (1 << (level)) + 2) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6))];
            const double xi_419 = xi_114*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + (1 << (level)) + 1) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6))];
            const double xi_420 = xi_115*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 2) - ((ctr_2*(ctr_2 + 1)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6)) + 1];
            const double xi_421 = xi_116*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) + 1];
            const double xi_422 = xi_117*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + (1 << (level)) + 2) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6)) + 1];
            _data_edgeCellDst_Y[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*(1 << (level))) / (6))] = xi_392 + xi_393 + xi_394 + xi_395 + xi_396 + xi_397 + xi_398;
            _data_edgeCellDst_XY[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*(1 << (level))) / (6))] = xi_399 + xi_400 + xi_401 + xi_402 + xi_403 + xi_404 + xi_405 + xi_406 + xi_407;
            _data_edgeCellDst_YZ[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*(1 << (level))) / (6))] = xi_408 + xi_409 + xi_410 + xi_411 + xi_412 + xi_413 + xi_414 + xi_415 + xi_416;
            _data_edgeCellDst_XYZ[ctr_1 + ctr_2*(-ctr_3 + (1 << (level))) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) - 1)*(-ctr_3 + (1 << (level)) + 1)) / (6)) + ((((1 << (level)) - 1)*((1 << (level)) + 1)*(1 << (level))) / (6))] = xi_417 + xi_418 + xi_419 + xi_420 + xi_421 + xi_422 + xi_423;
         }
         // edge 4
         for (int ctr_1 = -ctr_3 + (1 << (level)) - 1; ctr_1 < -ctr_3 + (1 << (level)); ctr_1 += 1)
         {
            const double xi_274 = _data_edgeCellDst_Y[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*(1 << (level))) / (6))];
            const double xi_268 = xi_362*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + (1 << (level)) + 2) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6)) - 1];
            const double xi_269 = xi_363*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 2) - ((ctr_2*(ctr_2 + 1)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6))];
            const double xi_270 = xi_364*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6))];
            const double xi_271 = xi_365*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + (1 << (level)) + 3) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)*(-ctr_3 + (1 << (level)) + 4)) / (6))];
            const double xi_272 = xi_366*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + (1 << (level)) + 2) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6))];
            const double xi_273 = xi_367*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 2) - ((ctr_2*(ctr_2 + 1)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6)) + 1];
            _data_edgeCellDst_Y[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*(1 << (level))) / (6))] = xi_268 + xi_269 + xi_270 + xi_271 + xi_272 + xi_273 + xi_274;
         }
      }
      for (int ctr_2 = 1; ctr_2 < -ctr_3 + (1 << (level)) - 1; ctr_2 += 1)
      {
         // face 2
         for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
         {
            const double xi_464 = _data_edgeCellDst_X[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*(1 << (level))) / (6))];
            const double xi_473 = _data_edgeCellDst_XY[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*(1 << (level))) / (6))];
            const double xi_480 = _data_edgeCellDst_XZ[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*(1 << (level))) / (6))];
            const double xi_487 = _data_edgeCellDst_XYZ[ctr_1 + ctr_2*(-ctr_3 + (1 << (level))) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) - 1)*(-ctr_3 + (1 << (level)) + 1)) / (6)) + ((((1 << (level)) - 1)*((1 << (level)) + 1)*(1 << (level))) / (6))];
            const double xi_456 = xi_426*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 2) - ((ctr_2*(ctr_2 + 1)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6))];
            const double xi_457 = xi_427*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6))];
            const double xi_458 = xi_428*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + (1 << (level)) + 3) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)*(-ctr_3 + (1 << (level)) + 4)) / (6))];
            const double xi_459 = xi_429*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + (1 << (level)) + 2) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6))];
            const double xi_460 = xi_430*_data_vertexCellSrc[ctr_1 + (ctr_2 - 1)*(-ctr_3 + (1 << (level)) + 2) - ((ctr_2*(ctr_2 - 1)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6)) + 1];
            const double xi_461 = xi_431*_data_vertexCellSrc[ctr_1 + (ctr_2 - 1)*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 - 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) + 1];
            const double xi_462 = xi_432*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 3) - ((ctr_2*(ctr_2 + 1)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)*(-ctr_3 + (1 << (level)) + 4)) / (6)) + 1];
            const double xi_463 = xi_433*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 2) - ((ctr_2*(ctr_2 + 1)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6)) + 1];
            const double xi_465 = xi_226*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 2) - ((ctr_2*(ctr_2 + 1)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6))];
            const double xi_466 = xi_227*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6))];
            const double xi_467 = xi_228*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + (1 << (level)) + 3) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)*(-ctr_3 + (1 << (level)) + 4)) / (6))];
            const double xi_468 = xi_229*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + (1 << (level)) + 2) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6))];
            const double xi_469 = xi_230*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 2) - ((ctr_2*(ctr_2 + 1)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6)) + 1];
            const double xi_470 = xi_231*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) + 1];
            const double xi_471 = xi_232*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + (1 << (level)) + 3) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)*(-ctr_3 + (1 << (level)) + 4)) / (6)) + 1];
            const double xi_472 = xi_233*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + (1 << (level)) + 2) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6)) + 1];
            const double xi_474 = xi_175*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 2) - ((ctr_2*(ctr_2 + 1)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6))];
            const double xi_475 = xi_176*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6))];
            const double xi_476 = xi_177*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + (1 << (level)) + 2) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6))];
            const double xi_477 = xi_178*_data_vertexCellSrc[ctr_1 + (ctr_2 - 1)*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 - 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) + 1];
            const double xi_478 = xi_179*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 2) - ((ctr_2*(ctr_2 + 1)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6)) + 1];
            const double xi_479 = xi_180*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) + 1];
            const double xi_481 = xi_112*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6))];
            const double xi_482 = xi_113*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + (1 << (level)) + 2) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6))];
            const double xi_483 = xi_114*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + (1 << (level)) + 1) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6))];
            const double xi_484 = xi_115*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 2) - ((ctr_2*(ctr_2 + 1)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6)) + 1];
            const double xi_485 = xi_116*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) + 1];
            const double xi_486 = xi_117*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + (1 << (level)) + 2) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6)) + 1];
            _data_edgeCellDst_X[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*(1 << (level))) / (6))] = xi_456 + xi_457 + xi_458 + xi_459 + xi_460 + xi_461 + xi_462 + xi_463 + xi_464;
            _data_edgeCellDst_XY[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*(1 << (level))) / (6))] = xi_465 + xi_466 + xi_467 + xi_468 + xi_469 + xi_470 + xi_471 + xi_472 + xi_473;
            _data_edgeCellDst_XZ[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*(1 << (level))) / (6))] = xi_474 + xi_475 + xi_476 + xi_477 + xi_478 + xi_479 + xi_480;
            _data_edgeCellDst_XYZ[ctr_1 + ctr_2*(-ctr_3 + (1 << (level))) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) - 1)*(-ctr_3 + (1 << (level)) + 1)) / (6)) + ((((1 << (level)) - 1)*((1 << (level)) + 1)*(1 << (level))) / (6))] = xi_481 + xi_482 + xi_483 + xi_484 + xi_485 + xi_486 + xi_487;
         }
         // cell (inner)
         for (int ctr_1 = 1; ctr_1 < -ctr_2 - ctr_3 + (1 << (level)) - 1; ctr_1 += 1)
         {
            const double xi_61 = _data_edgeCellDst_X[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*(1 << (level))) / (6))];
            const double xi_68 = _data_edgeCellDst_Y[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*(1 << (level))) / (6))];
            const double xi_77 = _data_edgeCellDst_Z[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*(1 << (level))) / (6))];
            const double xi_86 = _data_edgeCellDst_XY[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*(1 << (level))) / (6))];
            const double xi_93 = _data_edgeCellDst_XZ[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*(1 << (level))) / (6))];
            const double xi_102 = _data_edgeCellDst_YZ[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*(1 << (level))) / (6))];
            const double xi_109 = _data_edgeCellDst_XYZ[ctr_1 + ctr_2*(-ctr_3 + (1 << (level))) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) - 1)*(-ctr_3 + (1 << (level)) + 1)) / (6)) + ((((1 << (level)) - 1)*((1 << (level)) + 1)*(1 << (level))) / (6))];
            const double xi_53 = xi_426*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 2) - ((ctr_2*(ctr_2 + 1)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6))];
            const double xi_54 = xi_427*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6))];
            const double xi_55 = xi_428*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + (1 << (level)) + 3) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)*(-ctr_3 + (1 << (level)) + 4)) / (6))];
            const double xi_56 = xi_429*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + (1 << (level)) + 2) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6))];
            const double xi_57 = xi_430*_data_vertexCellSrc[ctr_1 + (ctr_2 - 1)*(-ctr_3 + (1 << (level)) + 2) - ((ctr_2*(ctr_2 - 1)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6)) + 1];
            const double xi_58 = xi_431*_data_vertexCellSrc[ctr_1 + (ctr_2 - 1)*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 - 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) + 1];
            const double xi_59 = xi_432*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 3) - ((ctr_2*(ctr_2 + 1)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)*(-ctr_3 + (1 << (level)) + 4)) / (6)) + 1];
            const double xi_60 = xi_433*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 2) - ((ctr_2*(ctr_2 + 1)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6)) + 1];
            const double xi_67 = xi_362*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + (1 << (level)) + 2) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6)) - 1];
            const double xi_62 = xi_363*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 2) - ((ctr_2*(ctr_2 + 1)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6))];
            const double xi_63 = xi_364*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6))];
            const double xi_64 = xi_365*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + (1 << (level)) + 3) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)*(-ctr_3 + (1 << (level)) + 4)) / (6))];
            const double xi_65 = xi_366*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + (1 << (level)) + 2) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6))];
            const double xi_66 = xi_367*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 2) - ((ctr_2*(ctr_2 + 1)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6)) + 1];
            const double xi_69 = xi_298*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - 1];
            const double xi_70 = xi_299*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + (1 << (level)) + 2) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6)) - 1];
            const double xi_71 = xi_300*_data_vertexCellSrc[ctr_1 + (ctr_2 - 1)*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 - 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6))];
            const double xi_72 = xi_301*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 2) - ((ctr_2*(ctr_2 + 1)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6))];
            const double xi_73 = xi_302*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6))];
            const double xi_74 = xi_303*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + (1 << (level)) + 2) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6))];
            const double xi_75 = xi_304*_data_vertexCellSrc[ctr_1 + (ctr_2 - 1)*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 - 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) + 1];
            const double xi_76 = xi_305*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 2) - ((ctr_2*(ctr_2 + 1)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6)) + 1];
            const double xi_78 = xi_226*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 2) - ((ctr_2*(ctr_2 + 1)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6))];
            const double xi_79 = xi_227*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6))];
            const double xi_80 = xi_228*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + (1 << (level)) + 3) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)*(-ctr_3 + (1 << (level)) + 4)) / (6))];
            const double xi_81 = xi_229*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + (1 << (level)) + 2) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6))];
            const double xi_82 = xi_230*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 2) - ((ctr_2*(ctr_2 + 1)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6)) + 1];
            const double xi_83 = xi_231*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) + 1];
            const double xi_84 = xi_232*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + (1 << (level)) + 3) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)*(-ctr_3 + (1 << (level)) + 4)) / (6)) + 1];
            const double xi_85 = xi_233*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + (1 << (level)) + 2) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6)) + 1];
            const double xi_87 = xi_175*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 2) - ((ctr_2*(ctr_2 + 1)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6))];
            const double xi_88 = xi_176*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6))];
            const double xi_89 = xi_177*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + (1 << (level)) + 2) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6))];
            const double xi_90 = xi_178*_data_vertexCellSrc[ctr_1 + (ctr_2 - 1)*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 - 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) + 1];
            const double xi_91 = xi_179*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 2) - ((ctr_2*(ctr_2 + 1)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6)) + 1];
            const double xi_92 = xi_180*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) + 1];
            const double xi_94 = xi_141*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + (1 << (level)) + 2) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6)) - 1];
            const double xi_95 = xi_142*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + (1 << (level)) + 1) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - 1];
            const double xi_96 = xi_143*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 2) - ((ctr_2*(ctr_2 + 1)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6))];
            const double xi_97 = xi_144*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6))];
            const double xi_98 = xi_145*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + (1 << (level)) + 2) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6))];
            const double xi_99 = xi_146*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + (1 << (level)) + 1) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6))];
            const double xi_100 = xi_147*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 2) - ((ctr_2*(ctr_2 + 1)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6)) + 1];
            const double xi_101 = xi_148*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) + 1];
            const double xi_103 = xi_112*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6))];
            const double xi_104 = xi_113*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + (1 << (level)) + 2) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6))];
            const double xi_105 = xi_114*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + (1 << (level)) + 1) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6))];
            const double xi_106 = xi_115*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 2) - ((ctr_2*(ctr_2 + 1)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6)) + 1];
            const double xi_107 = xi_116*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) + 1];
            const double xi_108 = xi_117*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + (1 << (level)) + 2) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6)) + 1];
            _data_edgeCellDst_X[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*(1 << (level))) / (6))] = xi_53 + xi_54 + xi_55 + xi_56 + xi_57 + xi_58 + xi_59 + xi_60 + xi_61;
            _data_edgeCellDst_Y[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*(1 << (level))) / (6))] = xi_62 + xi_63 + xi_64 + xi_65 + xi_66 + xi_67 + xi_68;
            _data_edgeCellDst_Z[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*(1 << (level))) / (6))] = xi_69 + xi_70 + xi_71 + xi_72 + xi_73 + xi_74 + xi_75 + xi_76 + xi_77;
            _data_edgeCellDst_XY[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*(1 << (level))) / (6))] = xi_78 + xi_79 + xi_80 + xi_81 + xi_82 + xi_83 + xi_84 + xi_85 + xi_86;
            _data_edgeCellDst_XZ[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*(1 << (level))) / (6))] = xi_87 + xi_88 + xi_89 + xi_90 + xi_91 + xi_92 + xi_93;
            _data_edgeCellDst_YZ[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*(1 << (level))) / (6))] = xi_100 + xi_101 + xi_102 + xi_94 + xi_95 + xi_96 + xi_97 + xi_98 + xi_99;
            _data_edgeCellDst_XYZ[ctr_1 + ctr_2*(-ctr_3 + (1 << (level))) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) - 1)*(-ctr_3 + (1 << (level)) + 1)) / (6)) + ((((1 << (level)) - 1)*((1 << (level)) + 1)*(1 << (level))) / (6))] = xi_103 + xi_104 + xi_105 + xi_106 + xi_107 + xi_108 + xi_109;
         }
         // face 3
         for (int ctr_1 = -ctr_2 - ctr_3 + (1 << (level)) - 1; ctr_1 < -ctr_2 - ctr_3 + (1 << (level)); ctr_1 += 1)
         {
            const double xi_522 = _data_edgeCellDst_X[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*(1 << (level))) / (6))];
            const double xi_529 = _data_edgeCellDst_Y[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*(1 << (level))) / (6))];
            const double xi_538 = _data_edgeCellDst_Z[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*(1 << (level))) / (6))];
            const double xi_514 = xi_426*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 2) - ((ctr_2*(ctr_2 + 1)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6))];
            const double xi_515 = xi_427*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6))];
            const double xi_516 = xi_428*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + (1 << (level)) + 3) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)*(-ctr_3 + (1 << (level)) + 4)) / (6))];
            const double xi_517 = xi_429*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + (1 << (level)) + 2) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6))];
            const double xi_518 = xi_430*_data_vertexCellSrc[ctr_1 + (ctr_2 - 1)*(-ctr_3 + (1 << (level)) + 2) - ((ctr_2*(ctr_2 - 1)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6)) + 1];
            const double xi_519 = xi_431*_data_vertexCellSrc[ctr_1 + (ctr_2 - 1)*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 - 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) + 1];
            const double xi_520 = xi_432*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 3) - ((ctr_2*(ctr_2 + 1)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)*(-ctr_3 + (1 << (level)) + 4)) / (6)) + 1];
            const double xi_521 = xi_433*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 2) - ((ctr_2*(ctr_2 + 1)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6)) + 1];
            const double xi_523 = xi_362*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + (1 << (level)) + 2) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6)) - 1];
            const double xi_524 = xi_363*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 2) - ((ctr_2*(ctr_2 + 1)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6))];
            const double xi_525 = xi_364*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6))];
            const double xi_526 = xi_365*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + (1 << (level)) + 3) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)*(-ctr_3 + (1 << (level)) + 4)) / (6))];
            const double xi_527 = xi_366*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + (1 << (level)) + 2) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6))];
            const double xi_528 = xi_367*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 2) - ((ctr_2*(ctr_2 + 1)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6)) + 1];
            const double xi_530 = xi_298*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - 1];
            const double xi_531 = xi_299*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + (1 << (level)) + 2) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6)) - 1];
            const double xi_532 = xi_300*_data_vertexCellSrc[ctr_1 + (ctr_2 - 1)*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 - 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6))];
            const double xi_533 = xi_301*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 2) - ((ctr_2*(ctr_2 + 1)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6))];
            const double xi_534 = xi_302*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6))];
            const double xi_535 = xi_303*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + (1 << (level)) + 2) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6))];
            const double xi_536 = xi_304*_data_vertexCellSrc[ctr_1 + (ctr_2 - 1)*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 - 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) + 1];
            const double xi_537 = xi_305*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 2) - ((ctr_2*(ctr_2 + 1)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6)) + 1];
            _data_edgeCellDst_X[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*(1 << (level))) / (6))] = xi_514 + xi_515 + xi_516 + xi_517 + xi_518 + xi_519 + xi_520 + xi_521 + xi_522;
            _data_edgeCellDst_Y[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*(1 << (level))) / (6))] = xi_523 + xi_524 + xi_525 + xi_526 + xi_527 + xi_528 + xi_529;
            _data_edgeCellDst_Z[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*(1 << (level))) / (6))] = xi_530 + xi_531 + xi_532 + xi_533 + xi_534 + xi_535 + xi_536 + xi_537 + xi_538;
         }
      }
      for (int ctr_2 = -ctr_3 + (1 << (level)) - 1; ctr_2 < -ctr_3 + (1 << (level)); ctr_2 += 1)
      {
         // edge 5
         for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
         {
            const double xi_295 = _data_edgeCellDst_X[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*(1 << (level))) / (6))];
            const double xi_287 = xi_426*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 2) - ((ctr_2*(ctr_2 + 1)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6))];
            const double xi_288 = xi_427*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6))];
            const double xi_289 = xi_428*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + (1 << (level)) + 3) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)*(-ctr_3 + (1 << (level)) + 4)) / (6))];
            const double xi_290 = xi_429*_data_vertexCellSrc[ctr_1 + (ctr_2 + 1)*(-ctr_3 + (1 << (level)) + 2) - (((ctr_2 + 1)*(ctr_2 + 2)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6))];
            const double xi_291 = xi_430*_data_vertexCellSrc[ctr_1 + (ctr_2 - 1)*(-ctr_3 + (1 << (level)) + 2) - ((ctr_2*(ctr_2 - 1)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6)) + 1];
            const double xi_292 = xi_431*_data_vertexCellSrc[ctr_1 + (ctr_2 - 1)*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 - 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) + 1];
            const double xi_293 = xi_432*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 3) - ((ctr_2*(ctr_2 + 1)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)*(-ctr_3 + (1 << (level)) + 4)) / (6)) + 1];
            const double xi_294 = xi_433*_data_vertexCellSrc[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 2) - ((ctr_2*(ctr_2 + 1)) / (2)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*((1 << (level)) + 3)) / (6)) - (((-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)*(-ctr_3 + (1 << (level)) + 3)) / (6)) + 1];
            _data_edgeCellDst_X[ctr_1 + ctr_2*(-ctr_3 + (1 << (level)) + 1) - ((ctr_2*(ctr_2 + 1)) / (2)) - (((-ctr_3 + (1 << (level)))*(-ctr_3 + (1 << (level)) + 1)*(-ctr_3 + (1 << (level)) + 2)) / (6)) + ((((1 << (level)) + 1)*((1 << (level)) + 2)*(1 << (level))) / (6))] = xi_287 + xi_288 + xi_289 + xi_290 + xi_291 + xi_292 + xi_293 + xi_294 + xi_295;
         }
      }
   }
   {
      
   }
}


void apply_3D_macrocell_vertexdof_to_edgedof_add(double * _data_edgeCellDst_X, double * _data_edgeCellDst_XY, double * _data_edgeCellDst_XYZ, double * _data_edgeCellDst_XZ, double * _data_edgeCellDst_Y, double * _data_edgeCellDst_YZ, double * _data_edgeCellDst_Z, double * _data_vertexCellSrc, int64_t level, std::map< hhg::edgedof::EdgeDoFOrientation, std::map< hhg::indexing::IndexIncrement, double > > v2eStencilMap)
{
    switch( level )
    {
    case 2:
        apply_3D_macrocell_vertexdof_to_edgedof_add_level_2(_data_edgeCellDst_X, _data_edgeCellDst_XY, _data_edgeCellDst_XYZ, _data_edgeCellDst_XZ, _data_edgeCellDst_Y, _data_edgeCellDst_YZ, _data_edgeCellDst_Z, _data_vertexCellSrc, v2eStencilMap);
        break;
    default:
        apply_3D_macrocell_vertexdof_to_edgedof_add_level_any(_data_edgeCellDst_X, _data_edgeCellDst_XY, _data_edgeCellDst_XYZ, _data_edgeCellDst_XZ, _data_edgeCellDst_Y, _data_edgeCellDst_YZ, _data_edgeCellDst_Z, _data_vertexCellSrc, level, v2eStencilMap);
        break;
    }
}
    

} // namespace generated
} // namespace VertexDoFToEdgeDoF
} // namespace hhg
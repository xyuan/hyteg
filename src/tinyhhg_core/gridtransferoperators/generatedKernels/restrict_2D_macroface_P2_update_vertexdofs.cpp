
//////////////////////////////////////////////////////////////////////////////
// This file is generated! To fix issues, please fix them in the generator. //
//////////////////////////////////////////////////////////////////////////////

#include "GeneratedKernelsP2MacroFace2D.hpp"

namespace hhg {
namespace P2 {
namespace macroface {
namespace generated {

static void restrict_2D_macroface_P2_update_vertexdofs_level_2(double * RESTRICT _data_edgeFineSrc_X, double * RESTRICT _data_edgeFineSrc_XY, double * RESTRICT _data_edgeFineSrc_Y, double * RESTRICT _data_vertexCoarseDst, double * RESTRICT _data_vertexFineSrc, double num_neighbor_faces_edge0, double num_neighbor_faces_edge1, double num_neighbor_faces_edge2, double num_neighbor_faces_vertex0, double num_neighbor_faces_vertex1, double num_neighbor_faces_vertex2)
{
   const double xi_103 = 1 / (num_neighbor_faces_vertex0);
   const double xi_106 = 1 / (num_neighbor_faces_edge0);
   const double xi_107 = 1 / (num_neighbor_faces_edge2);
   const double xi_119 = 1 / (num_neighbor_faces_vertex1);
   const double xi_123 = 1 / (num_neighbor_faces_edge1);
   const double xi_135 = 1 / (num_neighbor_faces_vertex2);
   for (int ctr_2 = 0; ctr_2 < 1; ctr_2 += 1)
   {
      // bottom left vertex
      for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
      {
         const double xi_109 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 18*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 9];
         const double xi_110 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_111 = 1.0*xi_103*_data_vertexFineSrc[2*ctr_1 + 20*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_112 = xi_106*0.375*_data_edgeFineSrc_X[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_114 = xi_106*-0.125*_data_edgeFineSrc_X[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_113 = xi_107*0.375*_data_edgeFineSrc_Y[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_115 = xi_107*-0.125*_data_edgeFineSrc_Y[2*ctr_1 + 18*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 9];
         _data_vertexCoarseDst[ctr_1 + 6*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_109 + xi_110 + xi_111 + xi_112 + xi_113 + xi_114 + xi_115;
      }
      // bottom edge
      for (int ctr_1 = 1; ctr_1 < 4; ctr_1 += 1)
      {
         const double xi_37 = 0.375*_data_edgeFineSrc_XY[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_38 = 0.375*_data_edgeFineSrc_Y[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_39 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 18*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8];
         const double xi_40 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_41 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 18*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 7];
         const double xi_42 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 18*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 7];
         const double xi_43 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 18*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 9];
         const double xi_44 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 18*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8];
         const double xi_45 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 18*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 9];
         const double xi_46 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_47 = 1.0*xi_106*_data_vertexFineSrc[2*ctr_1 + 20*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_48 = xi_106*0.375*_data_edgeFineSrc_X[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_49 = xi_106*0.375*_data_edgeFineSrc_X[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_50 = xi_106*-0.125*_data_edgeFineSrc_X[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_51 = xi_106*-0.125*_data_edgeFineSrc_X[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         _data_vertexCoarseDst[ctr_1 + 6*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_37 + xi_38 + xi_39 + xi_40 + xi_41 + xi_42 + xi_43 + xi_44 + xi_45 + xi_46 + xi_47 + xi_48 + xi_49 + xi_50 + xi_51;
      }
      // bottom right vertex
      for (int ctr_1 = 4; ctr_1 < 5; ctr_1 += 1)
      {
         const double xi_125 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_126 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 18*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 7];
         const double xi_127 = 1.0*xi_119*_data_vertexFineSrc[2*ctr_1 + 20*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_128 = xi_106*0.375*_data_edgeFineSrc_X[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_130 = xi_106*-0.125*_data_edgeFineSrc_X[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_129 = xi_123*0.375*_data_edgeFineSrc_XY[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_131 = xi_123*-0.125*_data_edgeFineSrc_XY[2*ctr_1 + 18*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 7];
         _data_vertexCoarseDst[ctr_1 + 6*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_125 + xi_126 + xi_127 + xi_128 + xi_129 + xi_130 + xi_131;
      }
   }
   for (int ctr_2 = 1; ctr_2 < 4; ctr_2 += 1)
   {
      // left edge
      for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
      {
         const double xi_85 = 0.375*_data_edgeFineSrc_XY[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 9];
         const double xi_86 = 0.375*_data_edgeFineSrc_X[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_87 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 18*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 18];
         const double xi_88 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 8];
         const double xi_89 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 18*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 17];
         const double xi_90 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 18*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 9];
         const double xi_91 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 8];
         const double xi_92 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_93 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 18*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 17];
         const double xi_94 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_95 = 1.0*xi_107*_data_vertexFineSrc[2*ctr_1 + 20*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_96 = xi_107*0.375*_data_edgeFineSrc_Y[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 9];
         const double xi_97 = xi_107*0.375*_data_edgeFineSrc_Y[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_98 = xi_107*-0.125*_data_edgeFineSrc_Y[2*ctr_1 + 18*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 18];
         const double xi_99 = xi_107*-0.125*_data_edgeFineSrc_Y[2*ctr_1 + 18*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 9];
         _data_vertexCoarseDst[ctr_1 + 6*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_85 + xi_86 + xi_87 + xi_88 + xi_89 + xi_90 + xi_91 + xi_92 + xi_93 + xi_94 + xi_95 + xi_96 + xi_97 + xi_98 + xi_99;
      }
      // inner triangle
      for (int ctr_1 = 1; ctr_1 < -ctr_2 + 4; ctr_1 += 1)
      {
         const double xi_3 = 0.375*_data_edgeFineSrc_XY[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_4 = 0.375*_data_edgeFineSrc_XY[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 9];
         const double xi_5 = 0.375*_data_edgeFineSrc_X[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_6 = 0.375*_data_edgeFineSrc_X[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_7 = 0.375*_data_edgeFineSrc_Y[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 9];
         const double xi_8 = 0.375*_data_edgeFineSrc_Y[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_9 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 18*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8];
         const double xi_10 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_11 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 18*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 7];
         const double xi_12 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 18*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 18];
         const double xi_13 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 8];
         const double xi_14 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 18*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 17];
         const double xi_15 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 10];
         const double xi_16 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_17 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 18*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 7];
         const double xi_18 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 18*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 9];
         const double xi_19 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 8];
         const double xi_20 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_21 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 10];
         const double xi_22 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 18*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8];
         const double xi_23 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 18*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 18];
         const double xi_24 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 18*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 9];
         const double xi_25 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 18*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 17];
         const double xi_26 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_27 = _data_vertexFineSrc[2*ctr_1 + 20*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         _data_vertexCoarseDst[ctr_1 + 6*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_10 + xi_11 + xi_12 + xi_13 + xi_14 + xi_15 + xi_16 + xi_17 + xi_18 + xi_19 + xi_20 + xi_21 + xi_22 + xi_23 + xi_24 + xi_25 + xi_26 + xi_27 + xi_3 + xi_4 + xi_5 + xi_6 + xi_7 + xi_8 + xi_9;
      }
      // diagonal edge
      for (int ctr_1 = -ctr_2 + 4; ctr_1 < -ctr_2 + 5; ctr_1 += 1)
      {
         const double xi_61 = 0.375*_data_edgeFineSrc_X[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_62 = 0.375*_data_edgeFineSrc_Y[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 9];
         const double xi_63 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_64 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 18*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 18];
         const double xi_65 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 10];
         const double xi_66 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_67 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 18*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 7];
         const double xi_68 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 10];
         const double xi_69 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 18*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 18];
         const double xi_70 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 18*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 17];
         const double xi_71 = 1.0*xi_123*_data_vertexFineSrc[2*ctr_1 + 20*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_72 = xi_123*0.375*_data_edgeFineSrc_XY[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_73 = xi_123*0.375*_data_edgeFineSrc_XY[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 9];
         const double xi_74 = xi_123*-0.125*_data_edgeFineSrc_XY[2*ctr_1 + 18*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 7];
         const double xi_75 = xi_123*-0.125*_data_edgeFineSrc_XY[2*ctr_1 + 18*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 17];
         _data_vertexCoarseDst[ctr_1 + 6*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_61 + xi_62 + xi_63 + xi_64 + xi_65 + xi_66 + xi_67 + xi_68 + xi_69 + xi_70 + xi_71 + xi_72 + xi_73 + xi_74 + xi_75;
      }
   }
   for (int ctr_2 = 4; ctr_2 < 5; ctr_2 += 1)
   {
      // top vertex
      for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
      {
         const double xi_141 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 18*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 18];
         const double xi_142 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 18*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 17];
         const double xi_143 = 1.0*xi_135*_data_vertexFineSrc[2*ctr_1 + 20*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_144 = xi_123*0.375*_data_edgeFineSrc_XY[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 9];
         const double xi_146 = xi_123*-0.125*_data_edgeFineSrc_XY[2*ctr_1 + 18*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 17];
         const double xi_145 = xi_107*0.375*_data_edgeFineSrc_Y[2*ctr_1 + 18*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 9];
         const double xi_147 = xi_107*-0.125*_data_edgeFineSrc_Y[2*ctr_1 + 18*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 18];
         _data_vertexCoarseDst[ctr_1 + 6*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_141 + xi_142 + xi_143 + xi_144 + xi_145 + xi_146 + xi_147;
      }
   }
   {
      
   }
}

static void restrict_2D_macroface_P2_update_vertexdofs_level_3(double * RESTRICT _data_edgeFineSrc_X, double * RESTRICT _data_edgeFineSrc_XY, double * RESTRICT _data_edgeFineSrc_Y, double * RESTRICT _data_vertexCoarseDst, double * RESTRICT _data_vertexFineSrc, double num_neighbor_faces_edge0, double num_neighbor_faces_edge1, double num_neighbor_faces_edge2, double num_neighbor_faces_vertex0, double num_neighbor_faces_vertex1, double num_neighbor_faces_vertex2)
{
   const double xi_103 = 1 / (num_neighbor_faces_vertex0);
   const double xi_106 = 1 / (num_neighbor_faces_edge0);
   const double xi_107 = 1 / (num_neighbor_faces_edge2);
   const double xi_119 = 1 / (num_neighbor_faces_vertex1);
   const double xi_123 = 1 / (num_neighbor_faces_edge1);
   const double xi_135 = 1 / (num_neighbor_faces_vertex2);
   for (int ctr_2 = 0; ctr_2 < 1; ctr_2 += 1)
   {
      // bottom left vertex
      for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
      {
         const double xi_109 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 34*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 17];
         const double xi_110 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_111 = 1.0*xi_103*_data_vertexFineSrc[2*ctr_1 + 36*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_112 = xi_106*0.375*_data_edgeFineSrc_X[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_114 = xi_106*-0.125*_data_edgeFineSrc_X[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_113 = xi_107*0.375*_data_edgeFineSrc_Y[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_115 = xi_107*-0.125*_data_edgeFineSrc_Y[2*ctr_1 + 34*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 17];
         _data_vertexCoarseDst[ctr_1 + 10*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_109 + xi_110 + xi_111 + xi_112 + xi_113 + xi_114 + xi_115;
      }
      // bottom edge
      for (int ctr_1 = 1; ctr_1 < 8; ctr_1 += 1)
      {
         const double xi_37 = 0.375*_data_edgeFineSrc_XY[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_38 = 0.375*_data_edgeFineSrc_Y[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_39 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 34*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16];
         const double xi_40 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_41 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 34*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 15];
         const double xi_42 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 34*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 15];
         const double xi_43 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 34*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 17];
         const double xi_44 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 34*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16];
         const double xi_45 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 34*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 17];
         const double xi_46 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_47 = 1.0*xi_106*_data_vertexFineSrc[2*ctr_1 + 36*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_48 = xi_106*0.375*_data_edgeFineSrc_X[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_49 = xi_106*0.375*_data_edgeFineSrc_X[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_50 = xi_106*-0.125*_data_edgeFineSrc_X[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_51 = xi_106*-0.125*_data_edgeFineSrc_X[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         _data_vertexCoarseDst[ctr_1 + 10*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_37 + xi_38 + xi_39 + xi_40 + xi_41 + xi_42 + xi_43 + xi_44 + xi_45 + xi_46 + xi_47 + xi_48 + xi_49 + xi_50 + xi_51;
      }
      // bottom right vertex
      for (int ctr_1 = 8; ctr_1 < 9; ctr_1 += 1)
      {
         const double xi_125 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_126 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 34*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 15];
         const double xi_127 = 1.0*xi_119*_data_vertexFineSrc[2*ctr_1 + 36*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_128 = xi_106*0.375*_data_edgeFineSrc_X[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_130 = xi_106*-0.125*_data_edgeFineSrc_X[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_129 = xi_123*0.375*_data_edgeFineSrc_XY[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_131 = xi_123*-0.125*_data_edgeFineSrc_XY[2*ctr_1 + 34*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 15];
         _data_vertexCoarseDst[ctr_1 + 10*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_125 + xi_126 + xi_127 + xi_128 + xi_129 + xi_130 + xi_131;
      }
   }
   for (int ctr_2 = 1; ctr_2 < 8; ctr_2 += 1)
   {
      // left edge
      for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
      {
         const double xi_85 = 0.375*_data_edgeFineSrc_XY[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 17];
         const double xi_86 = 0.375*_data_edgeFineSrc_X[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_87 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 34*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 34];
         const double xi_88 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 16];
         const double xi_89 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 34*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 33];
         const double xi_90 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 34*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 17];
         const double xi_91 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 16];
         const double xi_92 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_93 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 34*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 33];
         const double xi_94 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_95 = 1.0*xi_107*_data_vertexFineSrc[2*ctr_1 + 36*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_96 = xi_107*0.375*_data_edgeFineSrc_Y[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 17];
         const double xi_97 = xi_107*0.375*_data_edgeFineSrc_Y[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_98 = xi_107*-0.125*_data_edgeFineSrc_Y[2*ctr_1 + 34*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 34];
         const double xi_99 = xi_107*-0.125*_data_edgeFineSrc_Y[2*ctr_1 + 34*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 17];
         _data_vertexCoarseDst[ctr_1 + 10*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_85 + xi_86 + xi_87 + xi_88 + xi_89 + xi_90 + xi_91 + xi_92 + xi_93 + xi_94 + xi_95 + xi_96 + xi_97 + xi_98 + xi_99;
      }
      // inner triangle
      for (int ctr_1 = 1; ctr_1 < -ctr_2 + 8; ctr_1 += 1)
      {
         const double xi_3 = 0.375*_data_edgeFineSrc_XY[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_4 = 0.375*_data_edgeFineSrc_XY[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 17];
         const double xi_5 = 0.375*_data_edgeFineSrc_X[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_6 = 0.375*_data_edgeFineSrc_X[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_7 = 0.375*_data_edgeFineSrc_Y[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 17];
         const double xi_8 = 0.375*_data_edgeFineSrc_Y[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_9 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 34*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16];
         const double xi_10 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_11 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 34*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 15];
         const double xi_12 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 34*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 34];
         const double xi_13 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 16];
         const double xi_14 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 34*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 33];
         const double xi_15 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 18];
         const double xi_16 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_17 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 34*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 15];
         const double xi_18 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 34*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 17];
         const double xi_19 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 16];
         const double xi_20 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_21 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 18];
         const double xi_22 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 34*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16];
         const double xi_23 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 34*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 34];
         const double xi_24 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 34*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 17];
         const double xi_25 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 34*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 33];
         const double xi_26 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_27 = _data_vertexFineSrc[2*ctr_1 + 36*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         _data_vertexCoarseDst[ctr_1 + 10*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_10 + xi_11 + xi_12 + xi_13 + xi_14 + xi_15 + xi_16 + xi_17 + xi_18 + xi_19 + xi_20 + xi_21 + xi_22 + xi_23 + xi_24 + xi_25 + xi_26 + xi_27 + xi_3 + xi_4 + xi_5 + xi_6 + xi_7 + xi_8 + xi_9;
      }
      // diagonal edge
      for (int ctr_1 = -ctr_2 + 8; ctr_1 < -ctr_2 + 9; ctr_1 += 1)
      {
         const double xi_61 = 0.375*_data_edgeFineSrc_X[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_62 = 0.375*_data_edgeFineSrc_Y[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 17];
         const double xi_63 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_64 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 34*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 34];
         const double xi_65 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 18];
         const double xi_66 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_67 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 34*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 15];
         const double xi_68 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 18];
         const double xi_69 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 34*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 34];
         const double xi_70 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 34*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 33];
         const double xi_71 = 1.0*xi_123*_data_vertexFineSrc[2*ctr_1 + 36*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_72 = xi_123*0.375*_data_edgeFineSrc_XY[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_73 = xi_123*0.375*_data_edgeFineSrc_XY[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 17];
         const double xi_74 = xi_123*-0.125*_data_edgeFineSrc_XY[2*ctr_1 + 34*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 15];
         const double xi_75 = xi_123*-0.125*_data_edgeFineSrc_XY[2*ctr_1 + 34*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 33];
         _data_vertexCoarseDst[ctr_1 + 10*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_61 + xi_62 + xi_63 + xi_64 + xi_65 + xi_66 + xi_67 + xi_68 + xi_69 + xi_70 + xi_71 + xi_72 + xi_73 + xi_74 + xi_75;
      }
   }
   for (int ctr_2 = 8; ctr_2 < 9; ctr_2 += 1)
   {
      // top vertex
      for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
      {
         const double xi_141 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 34*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 34];
         const double xi_142 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 34*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 33];
         const double xi_143 = 1.0*xi_135*_data_vertexFineSrc[2*ctr_1 + 36*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_144 = xi_123*0.375*_data_edgeFineSrc_XY[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 17];
         const double xi_146 = xi_123*-0.125*_data_edgeFineSrc_XY[2*ctr_1 + 34*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 33];
         const double xi_145 = xi_107*0.375*_data_edgeFineSrc_Y[2*ctr_1 + 34*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 17];
         const double xi_147 = xi_107*-0.125*_data_edgeFineSrc_Y[2*ctr_1 + 34*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 34];
         _data_vertexCoarseDst[ctr_1 + 10*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_141 + xi_142 + xi_143 + xi_144 + xi_145 + xi_146 + xi_147;
      }
   }
   {
      
   }
}

static void restrict_2D_macroface_P2_update_vertexdofs_level_4(double * RESTRICT _data_edgeFineSrc_X, double * RESTRICT _data_edgeFineSrc_XY, double * RESTRICT _data_edgeFineSrc_Y, double * RESTRICT _data_vertexCoarseDst, double * RESTRICT _data_vertexFineSrc, double num_neighbor_faces_edge0, double num_neighbor_faces_edge1, double num_neighbor_faces_edge2, double num_neighbor_faces_vertex0, double num_neighbor_faces_vertex1, double num_neighbor_faces_vertex2)
{
   const double xi_103 = 1 / (num_neighbor_faces_vertex0);
   const double xi_106 = 1 / (num_neighbor_faces_edge0);
   const double xi_107 = 1 / (num_neighbor_faces_edge2);
   const double xi_119 = 1 / (num_neighbor_faces_vertex1);
   const double xi_123 = 1 / (num_neighbor_faces_edge1);
   const double xi_135 = 1 / (num_neighbor_faces_vertex2);
   for (int ctr_2 = 0; ctr_2 < 1; ctr_2 += 1)
   {
      // bottom left vertex
      for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
      {
         const double xi_109 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 66*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 33];
         const double xi_110 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_111 = 1.0*xi_103*_data_vertexFineSrc[2*ctr_1 + 68*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_112 = xi_106*0.375*_data_edgeFineSrc_X[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_114 = xi_106*-0.125*_data_edgeFineSrc_X[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_113 = xi_107*0.375*_data_edgeFineSrc_Y[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_115 = xi_107*-0.125*_data_edgeFineSrc_Y[2*ctr_1 + 66*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 33];
         _data_vertexCoarseDst[ctr_1 + 18*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_109 + xi_110 + xi_111 + xi_112 + xi_113 + xi_114 + xi_115;
      }
      // bottom edge
      for (int ctr_1 = 1; ctr_1 < 16; ctr_1 += 1)
      {
         const double xi_37 = 0.375*_data_edgeFineSrc_XY[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_38 = 0.375*_data_edgeFineSrc_Y[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_39 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 66*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32];
         const double xi_40 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_41 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 66*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 31];
         const double xi_42 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 66*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 31];
         const double xi_43 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 66*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 33];
         const double xi_44 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 66*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32];
         const double xi_45 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 66*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 33];
         const double xi_46 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_47 = 1.0*xi_106*_data_vertexFineSrc[2*ctr_1 + 68*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_48 = xi_106*0.375*_data_edgeFineSrc_X[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_49 = xi_106*0.375*_data_edgeFineSrc_X[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_50 = xi_106*-0.125*_data_edgeFineSrc_X[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_51 = xi_106*-0.125*_data_edgeFineSrc_X[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         _data_vertexCoarseDst[ctr_1 + 18*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_37 + xi_38 + xi_39 + xi_40 + xi_41 + xi_42 + xi_43 + xi_44 + xi_45 + xi_46 + xi_47 + xi_48 + xi_49 + xi_50 + xi_51;
      }
      // bottom right vertex
      for (int ctr_1 = 16; ctr_1 < 17; ctr_1 += 1)
      {
         const double xi_125 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_126 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 66*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 31];
         const double xi_127 = 1.0*xi_119*_data_vertexFineSrc[2*ctr_1 + 68*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_128 = xi_106*0.375*_data_edgeFineSrc_X[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_130 = xi_106*-0.125*_data_edgeFineSrc_X[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_129 = xi_123*0.375*_data_edgeFineSrc_XY[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_131 = xi_123*-0.125*_data_edgeFineSrc_XY[2*ctr_1 + 66*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 31];
         _data_vertexCoarseDst[ctr_1 + 18*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_125 + xi_126 + xi_127 + xi_128 + xi_129 + xi_130 + xi_131;
      }
   }
   for (int ctr_2 = 1; ctr_2 < 16; ctr_2 += 1)
   {
      // left edge
      for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
      {
         const double xi_85 = 0.375*_data_edgeFineSrc_XY[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 33];
         const double xi_86 = 0.375*_data_edgeFineSrc_X[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_87 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 66*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 66];
         const double xi_88 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 32];
         const double xi_89 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 66*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 65];
         const double xi_90 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 66*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 33];
         const double xi_91 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 32];
         const double xi_92 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_93 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 66*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 65];
         const double xi_94 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_95 = 1.0*xi_107*_data_vertexFineSrc[2*ctr_1 + 68*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_96 = xi_107*0.375*_data_edgeFineSrc_Y[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 33];
         const double xi_97 = xi_107*0.375*_data_edgeFineSrc_Y[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_98 = xi_107*-0.125*_data_edgeFineSrc_Y[2*ctr_1 + 66*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 66];
         const double xi_99 = xi_107*-0.125*_data_edgeFineSrc_Y[2*ctr_1 + 66*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 33];
         _data_vertexCoarseDst[ctr_1 + 18*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_85 + xi_86 + xi_87 + xi_88 + xi_89 + xi_90 + xi_91 + xi_92 + xi_93 + xi_94 + xi_95 + xi_96 + xi_97 + xi_98 + xi_99;
      }
      // inner triangle
      for (int ctr_1 = 1; ctr_1 < -ctr_2 + 16; ctr_1 += 1)
      {
         const double xi_3 = 0.375*_data_edgeFineSrc_XY[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_4 = 0.375*_data_edgeFineSrc_XY[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 33];
         const double xi_5 = 0.375*_data_edgeFineSrc_X[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_6 = 0.375*_data_edgeFineSrc_X[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_7 = 0.375*_data_edgeFineSrc_Y[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 33];
         const double xi_8 = 0.375*_data_edgeFineSrc_Y[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_9 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 66*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32];
         const double xi_10 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_11 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 66*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 31];
         const double xi_12 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 66*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 66];
         const double xi_13 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 32];
         const double xi_14 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 66*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 65];
         const double xi_15 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 34];
         const double xi_16 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_17 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 66*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 31];
         const double xi_18 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 66*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 33];
         const double xi_19 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 32];
         const double xi_20 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_21 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 34];
         const double xi_22 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 66*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32];
         const double xi_23 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 66*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 66];
         const double xi_24 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 66*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 33];
         const double xi_25 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 66*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 65];
         const double xi_26 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_27 = _data_vertexFineSrc[2*ctr_1 + 68*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         _data_vertexCoarseDst[ctr_1 + 18*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_10 + xi_11 + xi_12 + xi_13 + xi_14 + xi_15 + xi_16 + xi_17 + xi_18 + xi_19 + xi_20 + xi_21 + xi_22 + xi_23 + xi_24 + xi_25 + xi_26 + xi_27 + xi_3 + xi_4 + xi_5 + xi_6 + xi_7 + xi_8 + xi_9;
      }
      // diagonal edge
      for (int ctr_1 = -ctr_2 + 16; ctr_1 < -ctr_2 + 17; ctr_1 += 1)
      {
         const double xi_61 = 0.375*_data_edgeFineSrc_X[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_62 = 0.375*_data_edgeFineSrc_Y[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 33];
         const double xi_63 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_64 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 66*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 66];
         const double xi_65 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 34];
         const double xi_66 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_67 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 66*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 31];
         const double xi_68 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 34];
         const double xi_69 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 66*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 66];
         const double xi_70 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 66*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 65];
         const double xi_71 = 1.0*xi_123*_data_vertexFineSrc[2*ctr_1 + 68*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_72 = xi_123*0.375*_data_edgeFineSrc_XY[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_73 = xi_123*0.375*_data_edgeFineSrc_XY[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 33];
         const double xi_74 = xi_123*-0.125*_data_edgeFineSrc_XY[2*ctr_1 + 66*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 31];
         const double xi_75 = xi_123*-0.125*_data_edgeFineSrc_XY[2*ctr_1 + 66*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 65];
         _data_vertexCoarseDst[ctr_1 + 18*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_61 + xi_62 + xi_63 + xi_64 + xi_65 + xi_66 + xi_67 + xi_68 + xi_69 + xi_70 + xi_71 + xi_72 + xi_73 + xi_74 + xi_75;
      }
   }
   for (int ctr_2 = 16; ctr_2 < 17; ctr_2 += 1)
   {
      // top vertex
      for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
      {
         const double xi_141 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 66*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 66];
         const double xi_142 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 66*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 65];
         const double xi_143 = 1.0*xi_135*_data_vertexFineSrc[2*ctr_1 + 68*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_144 = xi_123*0.375*_data_edgeFineSrc_XY[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 33];
         const double xi_146 = xi_123*-0.125*_data_edgeFineSrc_XY[2*ctr_1 + 66*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 65];
         const double xi_145 = xi_107*0.375*_data_edgeFineSrc_Y[2*ctr_1 + 66*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 33];
         const double xi_147 = xi_107*-0.125*_data_edgeFineSrc_Y[2*ctr_1 + 66*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 66];
         _data_vertexCoarseDst[ctr_1 + 18*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_141 + xi_142 + xi_143 + xi_144 + xi_145 + xi_146 + xi_147;
      }
   }
   {
      
   }
}

static void restrict_2D_macroface_P2_update_vertexdofs_level_5(double * RESTRICT _data_edgeFineSrc_X, double * RESTRICT _data_edgeFineSrc_XY, double * RESTRICT _data_edgeFineSrc_Y, double * RESTRICT _data_vertexCoarseDst, double * RESTRICT _data_vertexFineSrc, double num_neighbor_faces_edge0, double num_neighbor_faces_edge1, double num_neighbor_faces_edge2, double num_neighbor_faces_vertex0, double num_neighbor_faces_vertex1, double num_neighbor_faces_vertex2)
{
   const double xi_103 = 1 / (num_neighbor_faces_vertex0);
   const double xi_106 = 1 / (num_neighbor_faces_edge0);
   const double xi_107 = 1 / (num_neighbor_faces_edge2);
   const double xi_119 = 1 / (num_neighbor_faces_vertex1);
   const double xi_123 = 1 / (num_neighbor_faces_edge1);
   const double xi_135 = 1 / (num_neighbor_faces_vertex2);
   for (int ctr_2 = 0; ctr_2 < 1; ctr_2 += 1)
   {
      // bottom left vertex
      for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
      {
         const double xi_109 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 130*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 65];
         const double xi_110 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_111 = 1.0*xi_103*_data_vertexFineSrc[2*ctr_1 + 132*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_112 = xi_106*0.375*_data_edgeFineSrc_X[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_114 = xi_106*-0.125*_data_edgeFineSrc_X[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_113 = xi_107*0.375*_data_edgeFineSrc_Y[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_115 = xi_107*-0.125*_data_edgeFineSrc_Y[2*ctr_1 + 130*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 65];
         _data_vertexCoarseDst[ctr_1 + 34*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_109 + xi_110 + xi_111 + xi_112 + xi_113 + xi_114 + xi_115;
      }
      // bottom edge
      for (int ctr_1 = 1; ctr_1 < 32; ctr_1 += 1)
      {
         const double xi_37 = 0.375*_data_edgeFineSrc_XY[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_38 = 0.375*_data_edgeFineSrc_Y[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_39 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 130*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 64];
         const double xi_40 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_41 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 130*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 63];
         const double xi_42 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 130*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 63];
         const double xi_43 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 130*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 65];
         const double xi_44 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 130*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 64];
         const double xi_45 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 130*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 65];
         const double xi_46 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_47 = 1.0*xi_106*_data_vertexFineSrc[2*ctr_1 + 132*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_48 = xi_106*0.375*_data_edgeFineSrc_X[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_49 = xi_106*0.375*_data_edgeFineSrc_X[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_50 = xi_106*-0.125*_data_edgeFineSrc_X[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_51 = xi_106*-0.125*_data_edgeFineSrc_X[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         _data_vertexCoarseDst[ctr_1 + 34*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_37 + xi_38 + xi_39 + xi_40 + xi_41 + xi_42 + xi_43 + xi_44 + xi_45 + xi_46 + xi_47 + xi_48 + xi_49 + xi_50 + xi_51;
      }
      // bottom right vertex
      for (int ctr_1 = 32; ctr_1 < 33; ctr_1 += 1)
      {
         const double xi_125 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_126 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 130*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 63];
         const double xi_127 = 1.0*xi_119*_data_vertexFineSrc[2*ctr_1 + 132*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_128 = xi_106*0.375*_data_edgeFineSrc_X[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_130 = xi_106*-0.125*_data_edgeFineSrc_X[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_129 = xi_123*0.375*_data_edgeFineSrc_XY[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_131 = xi_123*-0.125*_data_edgeFineSrc_XY[2*ctr_1 + 130*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 63];
         _data_vertexCoarseDst[ctr_1 + 34*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_125 + xi_126 + xi_127 + xi_128 + xi_129 + xi_130 + xi_131;
      }
   }
   for (int ctr_2 = 1; ctr_2 < 32; ctr_2 += 1)
   {
      // left edge
      for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
      {
         const double xi_85 = 0.375*_data_edgeFineSrc_XY[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 65];
         const double xi_86 = 0.375*_data_edgeFineSrc_X[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_87 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 130*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 130];
         const double xi_88 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 64];
         const double xi_89 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 130*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 129];
         const double xi_90 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 130*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 65];
         const double xi_91 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 64];
         const double xi_92 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_93 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 130*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 129];
         const double xi_94 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_95 = 1.0*xi_107*_data_vertexFineSrc[2*ctr_1 + 132*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_96 = xi_107*0.375*_data_edgeFineSrc_Y[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 65];
         const double xi_97 = xi_107*0.375*_data_edgeFineSrc_Y[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_98 = xi_107*-0.125*_data_edgeFineSrc_Y[2*ctr_1 + 130*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 130];
         const double xi_99 = xi_107*-0.125*_data_edgeFineSrc_Y[2*ctr_1 + 130*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 65];
         _data_vertexCoarseDst[ctr_1 + 34*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_85 + xi_86 + xi_87 + xi_88 + xi_89 + xi_90 + xi_91 + xi_92 + xi_93 + xi_94 + xi_95 + xi_96 + xi_97 + xi_98 + xi_99;
      }
      // inner triangle
      for (int ctr_1 = 1; ctr_1 < -ctr_2 + 32; ctr_1 += 1)
      {
         const double xi_3 = 0.375*_data_edgeFineSrc_XY[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_4 = 0.375*_data_edgeFineSrc_XY[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 65];
         const double xi_5 = 0.375*_data_edgeFineSrc_X[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_6 = 0.375*_data_edgeFineSrc_X[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_7 = 0.375*_data_edgeFineSrc_Y[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 65];
         const double xi_8 = 0.375*_data_edgeFineSrc_Y[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_9 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 130*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 64];
         const double xi_10 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_11 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 130*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 63];
         const double xi_12 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 130*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 130];
         const double xi_13 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 64];
         const double xi_14 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 130*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 129];
         const double xi_15 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 66];
         const double xi_16 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_17 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 130*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 63];
         const double xi_18 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 130*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 65];
         const double xi_19 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 64];
         const double xi_20 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_21 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 66];
         const double xi_22 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 130*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 64];
         const double xi_23 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 130*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 130];
         const double xi_24 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 130*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 65];
         const double xi_25 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 130*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 129];
         const double xi_26 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_27 = _data_vertexFineSrc[2*ctr_1 + 132*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         _data_vertexCoarseDst[ctr_1 + 34*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_10 + xi_11 + xi_12 + xi_13 + xi_14 + xi_15 + xi_16 + xi_17 + xi_18 + xi_19 + xi_20 + xi_21 + xi_22 + xi_23 + xi_24 + xi_25 + xi_26 + xi_27 + xi_3 + xi_4 + xi_5 + xi_6 + xi_7 + xi_8 + xi_9;
      }
      // diagonal edge
      for (int ctr_1 = -ctr_2 + 32; ctr_1 < -ctr_2 + 33; ctr_1 += 1)
      {
         const double xi_61 = 0.375*_data_edgeFineSrc_X[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_62 = 0.375*_data_edgeFineSrc_Y[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 65];
         const double xi_63 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_64 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 130*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 130];
         const double xi_65 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 66];
         const double xi_66 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_67 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 130*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 63];
         const double xi_68 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 66];
         const double xi_69 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 130*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 130];
         const double xi_70 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 130*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 129];
         const double xi_71 = 1.0*xi_123*_data_vertexFineSrc[2*ctr_1 + 132*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_72 = xi_123*0.375*_data_edgeFineSrc_XY[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_73 = xi_123*0.375*_data_edgeFineSrc_XY[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 65];
         const double xi_74 = xi_123*-0.125*_data_edgeFineSrc_XY[2*ctr_1 + 130*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 63];
         const double xi_75 = xi_123*-0.125*_data_edgeFineSrc_XY[2*ctr_1 + 130*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 129];
         _data_vertexCoarseDst[ctr_1 + 34*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_61 + xi_62 + xi_63 + xi_64 + xi_65 + xi_66 + xi_67 + xi_68 + xi_69 + xi_70 + xi_71 + xi_72 + xi_73 + xi_74 + xi_75;
      }
   }
   for (int ctr_2 = 32; ctr_2 < 33; ctr_2 += 1)
   {
      // top vertex
      for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
      {
         const double xi_141 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 130*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 130];
         const double xi_142 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 130*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 129];
         const double xi_143 = 1.0*xi_135*_data_vertexFineSrc[2*ctr_1 + 132*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_144 = xi_123*0.375*_data_edgeFineSrc_XY[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 65];
         const double xi_146 = xi_123*-0.125*_data_edgeFineSrc_XY[2*ctr_1 + 130*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 129];
         const double xi_145 = xi_107*0.375*_data_edgeFineSrc_Y[2*ctr_1 + 130*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 65];
         const double xi_147 = xi_107*-0.125*_data_edgeFineSrc_Y[2*ctr_1 + 130*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 130];
         _data_vertexCoarseDst[ctr_1 + 34*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_141 + xi_142 + xi_143 + xi_144 + xi_145 + xi_146 + xi_147;
      }
   }
   {
      
   }
}

static void restrict_2D_macroface_P2_update_vertexdofs_level_6(double * RESTRICT _data_edgeFineSrc_X, double * RESTRICT _data_edgeFineSrc_XY, double * RESTRICT _data_edgeFineSrc_Y, double * RESTRICT _data_vertexCoarseDst, double * RESTRICT _data_vertexFineSrc, double num_neighbor_faces_edge0, double num_neighbor_faces_edge1, double num_neighbor_faces_edge2, double num_neighbor_faces_vertex0, double num_neighbor_faces_vertex1, double num_neighbor_faces_vertex2)
{
   const double xi_103 = 1 / (num_neighbor_faces_vertex0);
   const double xi_106 = 1 / (num_neighbor_faces_edge0);
   const double xi_107 = 1 / (num_neighbor_faces_edge2);
   const double xi_119 = 1 / (num_neighbor_faces_vertex1);
   const double xi_123 = 1 / (num_neighbor_faces_edge1);
   const double xi_135 = 1 / (num_neighbor_faces_vertex2);
   for (int ctr_2 = 0; ctr_2 < 1; ctr_2 += 1)
   {
      // bottom left vertex
      for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
      {
         const double xi_109 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 258*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 129];
         const double xi_110 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_111 = 1.0*xi_103*_data_vertexFineSrc[2*ctr_1 + 260*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_112 = xi_106*0.375*_data_edgeFineSrc_X[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_114 = xi_106*-0.125*_data_edgeFineSrc_X[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_113 = xi_107*0.375*_data_edgeFineSrc_Y[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_115 = xi_107*-0.125*_data_edgeFineSrc_Y[2*ctr_1 + 258*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 129];
         _data_vertexCoarseDst[ctr_1 + 66*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_109 + xi_110 + xi_111 + xi_112 + xi_113 + xi_114 + xi_115;
      }
      // bottom edge
      for (int ctr_1 = 1; ctr_1 < 64; ctr_1 += 1)
      {
         const double xi_37 = 0.375*_data_edgeFineSrc_XY[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_38 = 0.375*_data_edgeFineSrc_Y[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_39 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 258*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 128];
         const double xi_40 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_41 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 258*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 127];
         const double xi_42 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 258*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 127];
         const double xi_43 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 258*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 129];
         const double xi_44 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 258*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 128];
         const double xi_45 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 258*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 129];
         const double xi_46 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_47 = 1.0*xi_106*_data_vertexFineSrc[2*ctr_1 + 260*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_48 = xi_106*0.375*_data_edgeFineSrc_X[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_49 = xi_106*0.375*_data_edgeFineSrc_X[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_50 = xi_106*-0.125*_data_edgeFineSrc_X[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_51 = xi_106*-0.125*_data_edgeFineSrc_X[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         _data_vertexCoarseDst[ctr_1 + 66*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_37 + xi_38 + xi_39 + xi_40 + xi_41 + xi_42 + xi_43 + xi_44 + xi_45 + xi_46 + xi_47 + xi_48 + xi_49 + xi_50 + xi_51;
      }
      // bottom right vertex
      for (int ctr_1 = 64; ctr_1 < 65; ctr_1 += 1)
      {
         const double xi_125 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_126 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 258*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 127];
         const double xi_127 = 1.0*xi_119*_data_vertexFineSrc[2*ctr_1 + 260*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_128 = xi_106*0.375*_data_edgeFineSrc_X[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_130 = xi_106*-0.125*_data_edgeFineSrc_X[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_129 = xi_123*0.375*_data_edgeFineSrc_XY[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_131 = xi_123*-0.125*_data_edgeFineSrc_XY[2*ctr_1 + 258*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 127];
         _data_vertexCoarseDst[ctr_1 + 66*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_125 + xi_126 + xi_127 + xi_128 + xi_129 + xi_130 + xi_131;
      }
   }
   for (int ctr_2 = 1; ctr_2 < 64; ctr_2 += 1)
   {
      // left edge
      for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
      {
         const double xi_85 = 0.375*_data_edgeFineSrc_XY[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 129];
         const double xi_86 = 0.375*_data_edgeFineSrc_X[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_87 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 258*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 258];
         const double xi_88 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 128];
         const double xi_89 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 258*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 257];
         const double xi_90 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 258*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 129];
         const double xi_91 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 128];
         const double xi_92 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_93 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 258*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 257];
         const double xi_94 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_95 = 1.0*xi_107*_data_vertexFineSrc[2*ctr_1 + 260*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_96 = xi_107*0.375*_data_edgeFineSrc_Y[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 129];
         const double xi_97 = xi_107*0.375*_data_edgeFineSrc_Y[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_98 = xi_107*-0.125*_data_edgeFineSrc_Y[2*ctr_1 + 258*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 258];
         const double xi_99 = xi_107*-0.125*_data_edgeFineSrc_Y[2*ctr_1 + 258*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 129];
         _data_vertexCoarseDst[ctr_1 + 66*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_85 + xi_86 + xi_87 + xi_88 + xi_89 + xi_90 + xi_91 + xi_92 + xi_93 + xi_94 + xi_95 + xi_96 + xi_97 + xi_98 + xi_99;
      }
      // inner triangle
      for (int ctr_1 = 1; ctr_1 < -ctr_2 + 64; ctr_1 += 1)
      {
         const double xi_3 = 0.375*_data_edgeFineSrc_XY[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_4 = 0.375*_data_edgeFineSrc_XY[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 129];
         const double xi_5 = 0.375*_data_edgeFineSrc_X[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_6 = 0.375*_data_edgeFineSrc_X[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_7 = 0.375*_data_edgeFineSrc_Y[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 129];
         const double xi_8 = 0.375*_data_edgeFineSrc_Y[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_9 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 258*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 128];
         const double xi_10 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_11 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 258*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 127];
         const double xi_12 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 258*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 258];
         const double xi_13 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 128];
         const double xi_14 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 258*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 257];
         const double xi_15 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 130];
         const double xi_16 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_17 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 258*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 127];
         const double xi_18 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 258*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 129];
         const double xi_19 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 128];
         const double xi_20 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_21 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 130];
         const double xi_22 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 258*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 128];
         const double xi_23 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 258*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 258];
         const double xi_24 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 258*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 129];
         const double xi_25 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 258*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 257];
         const double xi_26 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_27 = _data_vertexFineSrc[2*ctr_1 + 260*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         _data_vertexCoarseDst[ctr_1 + 66*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_10 + xi_11 + xi_12 + xi_13 + xi_14 + xi_15 + xi_16 + xi_17 + xi_18 + xi_19 + xi_20 + xi_21 + xi_22 + xi_23 + xi_24 + xi_25 + xi_26 + xi_27 + xi_3 + xi_4 + xi_5 + xi_6 + xi_7 + xi_8 + xi_9;
      }
      // diagonal edge
      for (int ctr_1 = -ctr_2 + 64; ctr_1 < -ctr_2 + 65; ctr_1 += 1)
      {
         const double xi_61 = 0.375*_data_edgeFineSrc_X[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_62 = 0.375*_data_edgeFineSrc_Y[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 129];
         const double xi_63 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_64 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 258*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 258];
         const double xi_65 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 130];
         const double xi_66 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_67 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 258*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 127];
         const double xi_68 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 130];
         const double xi_69 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 258*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 258];
         const double xi_70 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 258*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 257];
         const double xi_71 = 1.0*xi_123*_data_vertexFineSrc[2*ctr_1 + 260*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_72 = xi_123*0.375*_data_edgeFineSrc_XY[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_73 = xi_123*0.375*_data_edgeFineSrc_XY[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 129];
         const double xi_74 = xi_123*-0.125*_data_edgeFineSrc_XY[2*ctr_1 + 258*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 127];
         const double xi_75 = xi_123*-0.125*_data_edgeFineSrc_XY[2*ctr_1 + 258*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 257];
         _data_vertexCoarseDst[ctr_1 + 66*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_61 + xi_62 + xi_63 + xi_64 + xi_65 + xi_66 + xi_67 + xi_68 + xi_69 + xi_70 + xi_71 + xi_72 + xi_73 + xi_74 + xi_75;
      }
   }
   for (int ctr_2 = 64; ctr_2 < 65; ctr_2 += 1)
   {
      // top vertex
      for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
      {
         const double xi_141 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 258*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 258];
         const double xi_142 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 258*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 257];
         const double xi_143 = 1.0*xi_135*_data_vertexFineSrc[2*ctr_1 + 260*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_144 = xi_123*0.375*_data_edgeFineSrc_XY[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 129];
         const double xi_146 = xi_123*-0.125*_data_edgeFineSrc_XY[2*ctr_1 + 258*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 257];
         const double xi_145 = xi_107*0.375*_data_edgeFineSrc_Y[2*ctr_1 + 258*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 129];
         const double xi_147 = xi_107*-0.125*_data_edgeFineSrc_Y[2*ctr_1 + 258*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 258];
         _data_vertexCoarseDst[ctr_1 + 66*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_141 + xi_142 + xi_143 + xi_144 + xi_145 + xi_146 + xi_147;
      }
   }
   {
      
   }
}

static void restrict_2D_macroface_P2_update_vertexdofs_level_7(double * RESTRICT _data_edgeFineSrc_X, double * RESTRICT _data_edgeFineSrc_XY, double * RESTRICT _data_edgeFineSrc_Y, double * RESTRICT _data_vertexCoarseDst, double * RESTRICT _data_vertexFineSrc, double num_neighbor_faces_edge0, double num_neighbor_faces_edge1, double num_neighbor_faces_edge2, double num_neighbor_faces_vertex0, double num_neighbor_faces_vertex1, double num_neighbor_faces_vertex2)
{
   const double xi_103 = 1 / (num_neighbor_faces_vertex0);
   const double xi_106 = 1 / (num_neighbor_faces_edge0);
   const double xi_107 = 1 / (num_neighbor_faces_edge2);
   const double xi_119 = 1 / (num_neighbor_faces_vertex1);
   const double xi_123 = 1 / (num_neighbor_faces_edge1);
   const double xi_135 = 1 / (num_neighbor_faces_vertex2);
   for (int ctr_2 = 0; ctr_2 < 1; ctr_2 += 1)
   {
      // bottom left vertex
      for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
      {
         const double xi_109 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 514*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 257];
         const double xi_110 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_111 = 1.0*xi_103*_data_vertexFineSrc[2*ctr_1 + 516*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_112 = xi_106*0.375*_data_edgeFineSrc_X[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_114 = xi_106*-0.125*_data_edgeFineSrc_X[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_113 = xi_107*0.375*_data_edgeFineSrc_Y[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_115 = xi_107*-0.125*_data_edgeFineSrc_Y[2*ctr_1 + 514*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 257];
         _data_vertexCoarseDst[ctr_1 + 130*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_109 + xi_110 + xi_111 + xi_112 + xi_113 + xi_114 + xi_115;
      }
      // bottom edge
      for (int ctr_1 = 1; ctr_1 < 128; ctr_1 += 1)
      {
         const double xi_37 = 0.375*_data_edgeFineSrc_XY[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_38 = 0.375*_data_edgeFineSrc_Y[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_39 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 514*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 256];
         const double xi_40 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_41 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 514*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 255];
         const double xi_42 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 514*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 255];
         const double xi_43 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 514*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 257];
         const double xi_44 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 514*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 256];
         const double xi_45 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 514*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 257];
         const double xi_46 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_47 = 1.0*xi_106*_data_vertexFineSrc[2*ctr_1 + 516*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_48 = xi_106*0.375*_data_edgeFineSrc_X[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_49 = xi_106*0.375*_data_edgeFineSrc_X[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_50 = xi_106*-0.125*_data_edgeFineSrc_X[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_51 = xi_106*-0.125*_data_edgeFineSrc_X[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         _data_vertexCoarseDst[ctr_1 + 130*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_37 + xi_38 + xi_39 + xi_40 + xi_41 + xi_42 + xi_43 + xi_44 + xi_45 + xi_46 + xi_47 + xi_48 + xi_49 + xi_50 + xi_51;
      }
      // bottom right vertex
      for (int ctr_1 = 128; ctr_1 < 129; ctr_1 += 1)
      {
         const double xi_125 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_126 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 514*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 255];
         const double xi_127 = 1.0*xi_119*_data_vertexFineSrc[2*ctr_1 + 516*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_128 = xi_106*0.375*_data_edgeFineSrc_X[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_130 = xi_106*-0.125*_data_edgeFineSrc_X[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_129 = xi_123*0.375*_data_edgeFineSrc_XY[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_131 = xi_123*-0.125*_data_edgeFineSrc_XY[2*ctr_1 + 514*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 255];
         _data_vertexCoarseDst[ctr_1 + 130*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_125 + xi_126 + xi_127 + xi_128 + xi_129 + xi_130 + xi_131;
      }
   }
   for (int ctr_2 = 1; ctr_2 < 128; ctr_2 += 1)
   {
      // left edge
      for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
      {
         const double xi_85 = 0.375*_data_edgeFineSrc_XY[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 257];
         const double xi_86 = 0.375*_data_edgeFineSrc_X[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_87 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 514*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 514];
         const double xi_88 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 256];
         const double xi_89 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 514*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 513];
         const double xi_90 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 514*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 257];
         const double xi_91 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 256];
         const double xi_92 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_93 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 514*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 513];
         const double xi_94 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_95 = 1.0*xi_107*_data_vertexFineSrc[2*ctr_1 + 516*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_96 = xi_107*0.375*_data_edgeFineSrc_Y[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 257];
         const double xi_97 = xi_107*0.375*_data_edgeFineSrc_Y[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_98 = xi_107*-0.125*_data_edgeFineSrc_Y[2*ctr_1 + 514*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 514];
         const double xi_99 = xi_107*-0.125*_data_edgeFineSrc_Y[2*ctr_1 + 514*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 257];
         _data_vertexCoarseDst[ctr_1 + 130*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_85 + xi_86 + xi_87 + xi_88 + xi_89 + xi_90 + xi_91 + xi_92 + xi_93 + xi_94 + xi_95 + xi_96 + xi_97 + xi_98 + xi_99;
      }
      // inner triangle
      for (int ctr_1 = 1; ctr_1 < -ctr_2 + 128; ctr_1 += 1)
      {
         const double xi_3 = 0.375*_data_edgeFineSrc_XY[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_4 = 0.375*_data_edgeFineSrc_XY[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 257];
         const double xi_5 = 0.375*_data_edgeFineSrc_X[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_6 = 0.375*_data_edgeFineSrc_X[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_7 = 0.375*_data_edgeFineSrc_Y[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 257];
         const double xi_8 = 0.375*_data_edgeFineSrc_Y[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_9 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 514*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 256];
         const double xi_10 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_11 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 514*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 255];
         const double xi_12 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 514*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 514];
         const double xi_13 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 256];
         const double xi_14 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 514*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 513];
         const double xi_15 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 258];
         const double xi_16 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_17 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 514*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 255];
         const double xi_18 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 514*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 257];
         const double xi_19 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 256];
         const double xi_20 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_21 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 258];
         const double xi_22 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 514*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 256];
         const double xi_23 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 514*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 514];
         const double xi_24 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 514*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 257];
         const double xi_25 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 514*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 513];
         const double xi_26 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_27 = _data_vertexFineSrc[2*ctr_1 + 516*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         _data_vertexCoarseDst[ctr_1 + 130*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_10 + xi_11 + xi_12 + xi_13 + xi_14 + xi_15 + xi_16 + xi_17 + xi_18 + xi_19 + xi_20 + xi_21 + xi_22 + xi_23 + xi_24 + xi_25 + xi_26 + xi_27 + xi_3 + xi_4 + xi_5 + xi_6 + xi_7 + xi_8 + xi_9;
      }
      // diagonal edge
      for (int ctr_1 = -ctr_2 + 128; ctr_1 < -ctr_2 + 129; ctr_1 += 1)
      {
         const double xi_61 = 0.375*_data_edgeFineSrc_X[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_62 = 0.375*_data_edgeFineSrc_Y[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 257];
         const double xi_63 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_64 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 514*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 514];
         const double xi_65 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 258];
         const double xi_66 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_67 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 514*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 255];
         const double xi_68 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 258];
         const double xi_69 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 514*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 514];
         const double xi_70 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 514*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 513];
         const double xi_71 = 1.0*xi_123*_data_vertexFineSrc[2*ctr_1 + 516*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_72 = xi_123*0.375*_data_edgeFineSrc_XY[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_73 = xi_123*0.375*_data_edgeFineSrc_XY[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 257];
         const double xi_74 = xi_123*-0.125*_data_edgeFineSrc_XY[2*ctr_1 + 514*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 255];
         const double xi_75 = xi_123*-0.125*_data_edgeFineSrc_XY[2*ctr_1 + 514*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 513];
         _data_vertexCoarseDst[ctr_1 + 130*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_61 + xi_62 + xi_63 + xi_64 + xi_65 + xi_66 + xi_67 + xi_68 + xi_69 + xi_70 + xi_71 + xi_72 + xi_73 + xi_74 + xi_75;
      }
   }
   for (int ctr_2 = 128; ctr_2 < 129; ctr_2 += 1)
   {
      // top vertex
      for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
      {
         const double xi_141 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 514*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 514];
         const double xi_142 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 514*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 513];
         const double xi_143 = 1.0*xi_135*_data_vertexFineSrc[2*ctr_1 + 516*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_144 = xi_123*0.375*_data_edgeFineSrc_XY[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 257];
         const double xi_146 = xi_123*-0.125*_data_edgeFineSrc_XY[2*ctr_1 + 514*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 513];
         const double xi_145 = xi_107*0.375*_data_edgeFineSrc_Y[2*ctr_1 + 514*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 257];
         const double xi_147 = xi_107*-0.125*_data_edgeFineSrc_Y[2*ctr_1 + 514*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 514];
         _data_vertexCoarseDst[ctr_1 + 130*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_141 + xi_142 + xi_143 + xi_144 + xi_145 + xi_146 + xi_147;
      }
   }
   {
      
   }
}

static void restrict_2D_macroface_P2_update_vertexdofs_level_8(double * RESTRICT _data_edgeFineSrc_X, double * RESTRICT _data_edgeFineSrc_XY, double * RESTRICT _data_edgeFineSrc_Y, double * RESTRICT _data_vertexCoarseDst, double * RESTRICT _data_vertexFineSrc, double num_neighbor_faces_edge0, double num_neighbor_faces_edge1, double num_neighbor_faces_edge2, double num_neighbor_faces_vertex0, double num_neighbor_faces_vertex1, double num_neighbor_faces_vertex2)
{
   const double xi_103 = 1 / (num_neighbor_faces_vertex0);
   const double xi_106 = 1 / (num_neighbor_faces_edge0);
   const double xi_107 = 1 / (num_neighbor_faces_edge2);
   const double xi_119 = 1 / (num_neighbor_faces_vertex1);
   const double xi_123 = 1 / (num_neighbor_faces_edge1);
   const double xi_135 = 1 / (num_neighbor_faces_vertex2);
   for (int ctr_2 = 0; ctr_2 < 1; ctr_2 += 1)
   {
      // bottom left vertex
      for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
      {
         const double xi_109 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 1026*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 513];
         const double xi_110 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_111 = 1.0*xi_103*_data_vertexFineSrc[2*ctr_1 + 1028*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_112 = xi_106*0.375*_data_edgeFineSrc_X[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_114 = xi_106*-0.125*_data_edgeFineSrc_X[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_113 = xi_107*0.375*_data_edgeFineSrc_Y[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_115 = xi_107*-0.125*_data_edgeFineSrc_Y[2*ctr_1 + 1026*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 513];
         _data_vertexCoarseDst[ctr_1 + 258*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_109 + xi_110 + xi_111 + xi_112 + xi_113 + xi_114 + xi_115;
      }
      // bottom edge
      for (int ctr_1 = 1; ctr_1 < 256; ctr_1 += 1)
      {
         const double xi_37 = 0.375*_data_edgeFineSrc_XY[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_38 = 0.375*_data_edgeFineSrc_Y[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_39 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 1026*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 512];
         const double xi_40 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_41 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 1026*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 511];
         const double xi_42 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 1026*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 511];
         const double xi_43 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 1026*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 513];
         const double xi_44 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 1026*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 512];
         const double xi_45 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 1026*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 513];
         const double xi_46 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_47 = 1.0*xi_106*_data_vertexFineSrc[2*ctr_1 + 1028*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_48 = xi_106*0.375*_data_edgeFineSrc_X[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_49 = xi_106*0.375*_data_edgeFineSrc_X[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_50 = xi_106*-0.125*_data_edgeFineSrc_X[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_51 = xi_106*-0.125*_data_edgeFineSrc_X[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         _data_vertexCoarseDst[ctr_1 + 258*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_37 + xi_38 + xi_39 + xi_40 + xi_41 + xi_42 + xi_43 + xi_44 + xi_45 + xi_46 + xi_47 + xi_48 + xi_49 + xi_50 + xi_51;
      }
      // bottom right vertex
      for (int ctr_1 = 256; ctr_1 < 257; ctr_1 += 1)
      {
         const double xi_125 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_126 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 1026*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 511];
         const double xi_127 = 1.0*xi_119*_data_vertexFineSrc[2*ctr_1 + 1028*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_128 = xi_106*0.375*_data_edgeFineSrc_X[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_130 = xi_106*-0.125*_data_edgeFineSrc_X[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_129 = xi_123*0.375*_data_edgeFineSrc_XY[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_131 = xi_123*-0.125*_data_edgeFineSrc_XY[2*ctr_1 + 1026*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 511];
         _data_vertexCoarseDst[ctr_1 + 258*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_125 + xi_126 + xi_127 + xi_128 + xi_129 + xi_130 + xi_131;
      }
   }
   for (int ctr_2 = 1; ctr_2 < 256; ctr_2 += 1)
   {
      // left edge
      for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
      {
         const double xi_85 = 0.375*_data_edgeFineSrc_XY[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 513];
         const double xi_86 = 0.375*_data_edgeFineSrc_X[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_87 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 1026*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 1026];
         const double xi_88 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 512];
         const double xi_89 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 1026*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 1025];
         const double xi_90 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 1026*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 513];
         const double xi_91 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 512];
         const double xi_92 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_93 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 1026*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 1025];
         const double xi_94 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_95 = 1.0*xi_107*_data_vertexFineSrc[2*ctr_1 + 1028*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_96 = xi_107*0.375*_data_edgeFineSrc_Y[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 513];
         const double xi_97 = xi_107*0.375*_data_edgeFineSrc_Y[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_98 = xi_107*-0.125*_data_edgeFineSrc_Y[2*ctr_1 + 1026*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 1026];
         const double xi_99 = xi_107*-0.125*_data_edgeFineSrc_Y[2*ctr_1 + 1026*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 513];
         _data_vertexCoarseDst[ctr_1 + 258*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_85 + xi_86 + xi_87 + xi_88 + xi_89 + xi_90 + xi_91 + xi_92 + xi_93 + xi_94 + xi_95 + xi_96 + xi_97 + xi_98 + xi_99;
      }
      // inner triangle
      for (int ctr_1 = 1; ctr_1 < -ctr_2 + 256; ctr_1 += 1)
      {
         const double xi_3 = 0.375*_data_edgeFineSrc_XY[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_4 = 0.375*_data_edgeFineSrc_XY[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 513];
         const double xi_5 = 0.375*_data_edgeFineSrc_X[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_6 = 0.375*_data_edgeFineSrc_X[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_7 = 0.375*_data_edgeFineSrc_Y[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 513];
         const double xi_8 = 0.375*_data_edgeFineSrc_Y[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_9 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 1026*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 512];
         const double xi_10 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_11 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 1026*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 511];
         const double xi_12 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 1026*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 1026];
         const double xi_13 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 512];
         const double xi_14 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 1026*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 1025];
         const double xi_15 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 514];
         const double xi_16 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_17 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 1026*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 511];
         const double xi_18 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 1026*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 513];
         const double xi_19 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 512];
         const double xi_20 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_21 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 514];
         const double xi_22 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 1026*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 512];
         const double xi_23 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 1026*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 1026];
         const double xi_24 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 1026*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 513];
         const double xi_25 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 1026*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 1025];
         const double xi_26 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_27 = _data_vertexFineSrc[2*ctr_1 + 1028*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         _data_vertexCoarseDst[ctr_1 + 258*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_10 + xi_11 + xi_12 + xi_13 + xi_14 + xi_15 + xi_16 + xi_17 + xi_18 + xi_19 + xi_20 + xi_21 + xi_22 + xi_23 + xi_24 + xi_25 + xi_26 + xi_27 + xi_3 + xi_4 + xi_5 + xi_6 + xi_7 + xi_8 + xi_9;
      }
      // diagonal edge
      for (int ctr_1 = -ctr_2 + 256; ctr_1 < -ctr_2 + 257; ctr_1 += 1)
      {
         const double xi_61 = 0.375*_data_edgeFineSrc_X[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_62 = 0.375*_data_edgeFineSrc_Y[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 513];
         const double xi_63 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_64 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 1026*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 1026];
         const double xi_65 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 514];
         const double xi_66 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_67 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 1026*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 511];
         const double xi_68 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 514];
         const double xi_69 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 1026*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 1026];
         const double xi_70 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 1026*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 1025];
         const double xi_71 = 1.0*xi_123*_data_vertexFineSrc[2*ctr_1 + 1028*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_72 = xi_123*0.375*_data_edgeFineSrc_XY[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_73 = xi_123*0.375*_data_edgeFineSrc_XY[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 513];
         const double xi_74 = xi_123*-0.125*_data_edgeFineSrc_XY[2*ctr_1 + 1026*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 511];
         const double xi_75 = xi_123*-0.125*_data_edgeFineSrc_XY[2*ctr_1 + 1026*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 1025];
         _data_vertexCoarseDst[ctr_1 + 258*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_61 + xi_62 + xi_63 + xi_64 + xi_65 + xi_66 + xi_67 + xi_68 + xi_69 + xi_70 + xi_71 + xi_72 + xi_73 + xi_74 + xi_75;
      }
   }
   for (int ctr_2 = 256; ctr_2 < 257; ctr_2 += 1)
   {
      // top vertex
      for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
      {
         const double xi_141 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 1026*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 1026];
         const double xi_142 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 1026*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 1025];
         const double xi_143 = 1.0*xi_135*_data_vertexFineSrc[2*ctr_1 + 1028*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_144 = xi_123*0.375*_data_edgeFineSrc_XY[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 513];
         const double xi_146 = xi_123*-0.125*_data_edgeFineSrc_XY[2*ctr_1 + 1026*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 1025];
         const double xi_145 = xi_107*0.375*_data_edgeFineSrc_Y[2*ctr_1 + 1026*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 513];
         const double xi_147 = xi_107*-0.125*_data_edgeFineSrc_Y[2*ctr_1 + 1026*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 1026];
         _data_vertexCoarseDst[ctr_1 + 258*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_141 + xi_142 + xi_143 + xi_144 + xi_145 + xi_146 + xi_147;
      }
   }
   {
      
   }
}

static void restrict_2D_macroface_P2_update_vertexdofs_level_9(double * RESTRICT _data_edgeFineSrc_X, double * RESTRICT _data_edgeFineSrc_XY, double * RESTRICT _data_edgeFineSrc_Y, double * RESTRICT _data_vertexCoarseDst, double * RESTRICT _data_vertexFineSrc, double num_neighbor_faces_edge0, double num_neighbor_faces_edge1, double num_neighbor_faces_edge2, double num_neighbor_faces_vertex0, double num_neighbor_faces_vertex1, double num_neighbor_faces_vertex2)
{
   const double xi_103 = 1 / (num_neighbor_faces_vertex0);
   const double xi_106 = 1 / (num_neighbor_faces_edge0);
   const double xi_107 = 1 / (num_neighbor_faces_edge2);
   const double xi_119 = 1 / (num_neighbor_faces_vertex1);
   const double xi_123 = 1 / (num_neighbor_faces_edge1);
   const double xi_135 = 1 / (num_neighbor_faces_vertex2);
   for (int ctr_2 = 0; ctr_2 < 1; ctr_2 += 1)
   {
      // bottom left vertex
      for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
      {
         const double xi_109 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 2050*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1025];
         const double xi_110 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_111 = 1.0*xi_103*_data_vertexFineSrc[2*ctr_1 + 2052*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_112 = xi_106*0.375*_data_edgeFineSrc_X[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_114 = xi_106*-0.125*_data_edgeFineSrc_X[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_113 = xi_107*0.375*_data_edgeFineSrc_Y[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_115 = xi_107*-0.125*_data_edgeFineSrc_Y[2*ctr_1 + 2050*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1025];
         _data_vertexCoarseDst[ctr_1 + 514*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_109 + xi_110 + xi_111 + xi_112 + xi_113 + xi_114 + xi_115;
      }
      // bottom edge
      for (int ctr_1 = 1; ctr_1 < 512; ctr_1 += 1)
      {
         const double xi_37 = 0.375*_data_edgeFineSrc_XY[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_38 = 0.375*_data_edgeFineSrc_Y[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_39 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 2050*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1024];
         const double xi_40 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_41 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 2050*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1023];
         const double xi_42 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 2050*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1023];
         const double xi_43 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 2050*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1025];
         const double xi_44 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 2050*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1024];
         const double xi_45 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 2050*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1025];
         const double xi_46 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_47 = 1.0*xi_106*_data_vertexFineSrc[2*ctr_1 + 2052*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_48 = xi_106*0.375*_data_edgeFineSrc_X[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_49 = xi_106*0.375*_data_edgeFineSrc_X[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_50 = xi_106*-0.125*_data_edgeFineSrc_X[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_51 = xi_106*-0.125*_data_edgeFineSrc_X[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         _data_vertexCoarseDst[ctr_1 + 514*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_37 + xi_38 + xi_39 + xi_40 + xi_41 + xi_42 + xi_43 + xi_44 + xi_45 + xi_46 + xi_47 + xi_48 + xi_49 + xi_50 + xi_51;
      }
      // bottom right vertex
      for (int ctr_1 = 512; ctr_1 < 513; ctr_1 += 1)
      {
         const double xi_125 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_126 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 2050*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1023];
         const double xi_127 = 1.0*xi_119*_data_vertexFineSrc[2*ctr_1 + 2052*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_128 = xi_106*0.375*_data_edgeFineSrc_X[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_130 = xi_106*-0.125*_data_edgeFineSrc_X[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_129 = xi_123*0.375*_data_edgeFineSrc_XY[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_131 = xi_123*-0.125*_data_edgeFineSrc_XY[2*ctr_1 + 2050*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1023];
         _data_vertexCoarseDst[ctr_1 + 514*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_125 + xi_126 + xi_127 + xi_128 + xi_129 + xi_130 + xi_131;
      }
   }
   for (int ctr_2 = 1; ctr_2 < 512; ctr_2 += 1)
   {
      // left edge
      for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
      {
         const double xi_85 = 0.375*_data_edgeFineSrc_XY[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 1025];
         const double xi_86 = 0.375*_data_edgeFineSrc_X[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_87 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 2050*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 2050];
         const double xi_88 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 1024];
         const double xi_89 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 2050*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 2049];
         const double xi_90 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 2050*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1025];
         const double xi_91 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 1024];
         const double xi_92 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_93 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 2050*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 2049];
         const double xi_94 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_95 = 1.0*xi_107*_data_vertexFineSrc[2*ctr_1 + 2052*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_96 = xi_107*0.375*_data_edgeFineSrc_Y[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 1025];
         const double xi_97 = xi_107*0.375*_data_edgeFineSrc_Y[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_98 = xi_107*-0.125*_data_edgeFineSrc_Y[2*ctr_1 + 2050*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 2050];
         const double xi_99 = xi_107*-0.125*_data_edgeFineSrc_Y[2*ctr_1 + 2050*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1025];
         _data_vertexCoarseDst[ctr_1 + 514*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_85 + xi_86 + xi_87 + xi_88 + xi_89 + xi_90 + xi_91 + xi_92 + xi_93 + xi_94 + xi_95 + xi_96 + xi_97 + xi_98 + xi_99;
      }
      // inner triangle
      for (int ctr_1 = 1; ctr_1 < -ctr_2 + 512; ctr_1 += 1)
      {
         const double xi_3 = 0.375*_data_edgeFineSrc_XY[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_4 = 0.375*_data_edgeFineSrc_XY[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 1025];
         const double xi_5 = 0.375*_data_edgeFineSrc_X[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_6 = 0.375*_data_edgeFineSrc_X[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_7 = 0.375*_data_edgeFineSrc_Y[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 1025];
         const double xi_8 = 0.375*_data_edgeFineSrc_Y[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_9 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 2050*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1024];
         const double xi_10 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_11 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 2050*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1023];
         const double xi_12 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 2050*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 2050];
         const double xi_13 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 1024];
         const double xi_14 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 2050*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 2049];
         const double xi_15 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 1026];
         const double xi_16 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_17 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 2050*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1023];
         const double xi_18 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 2050*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1025];
         const double xi_19 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 1024];
         const double xi_20 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_21 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 1026];
         const double xi_22 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 2050*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1024];
         const double xi_23 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 2050*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 2050];
         const double xi_24 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 2050*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1025];
         const double xi_25 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 2050*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 2049];
         const double xi_26 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_27 = _data_vertexFineSrc[2*ctr_1 + 2052*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         _data_vertexCoarseDst[ctr_1 + 514*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_10 + xi_11 + xi_12 + xi_13 + xi_14 + xi_15 + xi_16 + xi_17 + xi_18 + xi_19 + xi_20 + xi_21 + xi_22 + xi_23 + xi_24 + xi_25 + xi_26 + xi_27 + xi_3 + xi_4 + xi_5 + xi_6 + xi_7 + xi_8 + xi_9;
      }
      // diagonal edge
      for (int ctr_1 = -ctr_2 + 512; ctr_1 < -ctr_2 + 513; ctr_1 += 1)
      {
         const double xi_61 = 0.375*_data_edgeFineSrc_X[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_62 = 0.375*_data_edgeFineSrc_Y[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 1025];
         const double xi_63 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_64 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 2050*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 2050];
         const double xi_65 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 1026];
         const double xi_66 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_67 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 2050*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1023];
         const double xi_68 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 1026];
         const double xi_69 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 2050*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 2050];
         const double xi_70 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 2050*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 2049];
         const double xi_71 = 1.0*xi_123*_data_vertexFineSrc[2*ctr_1 + 2052*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_72 = xi_123*0.375*_data_edgeFineSrc_XY[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_73 = xi_123*0.375*_data_edgeFineSrc_XY[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 1025];
         const double xi_74 = xi_123*-0.125*_data_edgeFineSrc_XY[2*ctr_1 + 2050*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 1023];
         const double xi_75 = xi_123*-0.125*_data_edgeFineSrc_XY[2*ctr_1 + 2050*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 2049];
         _data_vertexCoarseDst[ctr_1 + 514*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_61 + xi_62 + xi_63 + xi_64 + xi_65 + xi_66 + xi_67 + xi_68 + xi_69 + xi_70 + xi_71 + xi_72 + xi_73 + xi_74 + xi_75;
      }
   }
   for (int ctr_2 = 512; ctr_2 < 513; ctr_2 += 1)
   {
      // top vertex
      for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
      {
         const double xi_141 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 2050*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 2050];
         const double xi_142 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 2050*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 2049];
         const double xi_143 = 1.0*xi_135*_data_vertexFineSrc[2*ctr_1 + 2052*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_144 = xi_123*0.375*_data_edgeFineSrc_XY[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 1025];
         const double xi_146 = xi_123*-0.125*_data_edgeFineSrc_XY[2*ctr_1 + 2050*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 2049];
         const double xi_145 = xi_107*0.375*_data_edgeFineSrc_Y[2*ctr_1 + 2050*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 1025];
         const double xi_147 = xi_107*-0.125*_data_edgeFineSrc_Y[2*ctr_1 + 2050*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 2050];
         _data_vertexCoarseDst[ctr_1 + 514*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_141 + xi_142 + xi_143 + xi_144 + xi_145 + xi_146 + xi_147;
      }
   }
   {
      
   }
}

static void restrict_2D_macroface_P2_update_vertexdofs_level_10(double * RESTRICT _data_edgeFineSrc_X, double * RESTRICT _data_edgeFineSrc_XY, double * RESTRICT _data_edgeFineSrc_Y, double * RESTRICT _data_vertexCoarseDst, double * RESTRICT _data_vertexFineSrc, double num_neighbor_faces_edge0, double num_neighbor_faces_edge1, double num_neighbor_faces_edge2, double num_neighbor_faces_vertex0, double num_neighbor_faces_vertex1, double num_neighbor_faces_vertex2)
{
   const double xi_103 = 1 / (num_neighbor_faces_vertex0);
   const double xi_106 = 1 / (num_neighbor_faces_edge0);
   const double xi_107 = 1 / (num_neighbor_faces_edge2);
   const double xi_119 = 1 / (num_neighbor_faces_vertex1);
   const double xi_123 = 1 / (num_neighbor_faces_edge1);
   const double xi_135 = 1 / (num_neighbor_faces_vertex2);
   for (int ctr_2 = 0; ctr_2 < 1; ctr_2 += 1)
   {
      // bottom left vertex
      for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
      {
         const double xi_109 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 4098*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 2049];
         const double xi_110 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_111 = 1.0*xi_103*_data_vertexFineSrc[2*ctr_1 + 4100*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_112 = xi_106*0.375*_data_edgeFineSrc_X[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_114 = xi_106*-0.125*_data_edgeFineSrc_X[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_113 = xi_107*0.375*_data_edgeFineSrc_Y[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_115 = xi_107*-0.125*_data_edgeFineSrc_Y[2*ctr_1 + 4098*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 2049];
         _data_vertexCoarseDst[ctr_1 + 1026*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_109 + xi_110 + xi_111 + xi_112 + xi_113 + xi_114 + xi_115;
      }
      // bottom edge
      for (int ctr_1 = 1; ctr_1 < 1024; ctr_1 += 1)
      {
         const double xi_37 = 0.375*_data_edgeFineSrc_XY[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_38 = 0.375*_data_edgeFineSrc_Y[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_39 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 4098*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 2048];
         const double xi_40 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_41 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 4098*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 2047];
         const double xi_42 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 4098*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 2047];
         const double xi_43 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 4098*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 2049];
         const double xi_44 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 4098*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 2048];
         const double xi_45 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 4098*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 2049];
         const double xi_46 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_47 = 1.0*xi_106*_data_vertexFineSrc[2*ctr_1 + 4100*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_48 = xi_106*0.375*_data_edgeFineSrc_X[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_49 = xi_106*0.375*_data_edgeFineSrc_X[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_50 = xi_106*-0.125*_data_edgeFineSrc_X[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_51 = xi_106*-0.125*_data_edgeFineSrc_X[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         _data_vertexCoarseDst[ctr_1 + 1026*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_37 + xi_38 + xi_39 + xi_40 + xi_41 + xi_42 + xi_43 + xi_44 + xi_45 + xi_46 + xi_47 + xi_48 + xi_49 + xi_50 + xi_51;
      }
      // bottom right vertex
      for (int ctr_1 = 1024; ctr_1 < 1025; ctr_1 += 1)
      {
         const double xi_125 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_126 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 4098*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 2047];
         const double xi_127 = 1.0*xi_119*_data_vertexFineSrc[2*ctr_1 + 4100*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_128 = xi_106*0.375*_data_edgeFineSrc_X[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_130 = xi_106*-0.125*_data_edgeFineSrc_X[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_129 = xi_123*0.375*_data_edgeFineSrc_XY[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_131 = xi_123*-0.125*_data_edgeFineSrc_XY[2*ctr_1 + 4098*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 2047];
         _data_vertexCoarseDst[ctr_1 + 1026*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_125 + xi_126 + xi_127 + xi_128 + xi_129 + xi_130 + xi_131;
      }
   }
   for (int ctr_2 = 1; ctr_2 < 1024; ctr_2 += 1)
   {
      // left edge
      for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
      {
         const double xi_85 = 0.375*_data_edgeFineSrc_XY[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 2049];
         const double xi_86 = 0.375*_data_edgeFineSrc_X[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_87 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 4098*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 4098];
         const double xi_88 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 2048];
         const double xi_89 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 4098*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 4097];
         const double xi_90 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 4098*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 2049];
         const double xi_91 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 2048];
         const double xi_92 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_93 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 4098*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 4097];
         const double xi_94 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_95 = 1.0*xi_107*_data_vertexFineSrc[2*ctr_1 + 4100*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_96 = xi_107*0.375*_data_edgeFineSrc_Y[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 2049];
         const double xi_97 = xi_107*0.375*_data_edgeFineSrc_Y[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_98 = xi_107*-0.125*_data_edgeFineSrc_Y[2*ctr_1 + 4098*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 4098];
         const double xi_99 = xi_107*-0.125*_data_edgeFineSrc_Y[2*ctr_1 + 4098*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 2049];
         _data_vertexCoarseDst[ctr_1 + 1026*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_85 + xi_86 + xi_87 + xi_88 + xi_89 + xi_90 + xi_91 + xi_92 + xi_93 + xi_94 + xi_95 + xi_96 + xi_97 + xi_98 + xi_99;
      }
      // inner triangle
      for (int ctr_1 = 1; ctr_1 < -ctr_2 + 1024; ctr_1 += 1)
      {
         const double xi_3 = 0.375*_data_edgeFineSrc_XY[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_4 = 0.375*_data_edgeFineSrc_XY[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 2049];
         const double xi_5 = 0.375*_data_edgeFineSrc_X[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_6 = 0.375*_data_edgeFineSrc_X[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_7 = 0.375*_data_edgeFineSrc_Y[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 2049];
         const double xi_8 = 0.375*_data_edgeFineSrc_Y[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_9 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 4098*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 2048];
         const double xi_10 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_11 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 4098*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 2047];
         const double xi_12 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 4098*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 4098];
         const double xi_13 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 2048];
         const double xi_14 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 4098*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 4097];
         const double xi_15 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 2050];
         const double xi_16 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_17 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 4098*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 2047];
         const double xi_18 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 4098*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 2049];
         const double xi_19 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 2048];
         const double xi_20 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_21 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 2050];
         const double xi_22 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 4098*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 2048];
         const double xi_23 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 4098*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 4098];
         const double xi_24 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 4098*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 2049];
         const double xi_25 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 4098*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 4097];
         const double xi_26 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_27 = _data_vertexFineSrc[2*ctr_1 + 4100*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         _data_vertexCoarseDst[ctr_1 + 1026*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_10 + xi_11 + xi_12 + xi_13 + xi_14 + xi_15 + xi_16 + xi_17 + xi_18 + xi_19 + xi_20 + xi_21 + xi_22 + xi_23 + xi_24 + xi_25 + xi_26 + xi_27 + xi_3 + xi_4 + xi_5 + xi_6 + xi_7 + xi_8 + xi_9;
      }
      // diagonal edge
      for (int ctr_1 = -ctr_2 + 1024; ctr_1 < -ctr_2 + 1025; ctr_1 += 1)
      {
         const double xi_61 = 0.375*_data_edgeFineSrc_X[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_62 = 0.375*_data_edgeFineSrc_Y[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 2049];
         const double xi_63 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_64 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 4098*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 4098];
         const double xi_65 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 2050];
         const double xi_66 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_67 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 4098*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 2047];
         const double xi_68 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 2050];
         const double xi_69 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 4098*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 4098];
         const double xi_70 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 4098*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 4097];
         const double xi_71 = 1.0*xi_123*_data_vertexFineSrc[2*ctr_1 + 4100*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_72 = xi_123*0.375*_data_edgeFineSrc_XY[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_73 = xi_123*0.375*_data_edgeFineSrc_XY[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 2049];
         const double xi_74 = xi_123*-0.125*_data_edgeFineSrc_XY[2*ctr_1 + 4098*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 2047];
         const double xi_75 = xi_123*-0.125*_data_edgeFineSrc_XY[2*ctr_1 + 4098*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 4097];
         _data_vertexCoarseDst[ctr_1 + 1026*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_61 + xi_62 + xi_63 + xi_64 + xi_65 + xi_66 + xi_67 + xi_68 + xi_69 + xi_70 + xi_71 + xi_72 + xi_73 + xi_74 + xi_75;
      }
   }
   for (int ctr_2 = 1024; ctr_2 < 1025; ctr_2 += 1)
   {
      // top vertex
      for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
      {
         const double xi_141 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 4098*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 4098];
         const double xi_142 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 4098*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 4097];
         const double xi_143 = 1.0*xi_135*_data_vertexFineSrc[2*ctr_1 + 4100*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_144 = xi_123*0.375*_data_edgeFineSrc_XY[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 2049];
         const double xi_146 = xi_123*-0.125*_data_edgeFineSrc_XY[2*ctr_1 + 4098*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 4097];
         const double xi_145 = xi_107*0.375*_data_edgeFineSrc_Y[2*ctr_1 + 4098*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 2049];
         const double xi_147 = xi_107*-0.125*_data_edgeFineSrc_Y[2*ctr_1 + 4098*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 4098];
         _data_vertexCoarseDst[ctr_1 + 1026*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_141 + xi_142 + xi_143 + xi_144 + xi_145 + xi_146 + xi_147;
      }
   }
   {
      
   }
}

static void restrict_2D_macroface_P2_update_vertexdofs_level_11(double * RESTRICT _data_edgeFineSrc_X, double * RESTRICT _data_edgeFineSrc_XY, double * RESTRICT _data_edgeFineSrc_Y, double * RESTRICT _data_vertexCoarseDst, double * RESTRICT _data_vertexFineSrc, double num_neighbor_faces_edge0, double num_neighbor_faces_edge1, double num_neighbor_faces_edge2, double num_neighbor_faces_vertex0, double num_neighbor_faces_vertex1, double num_neighbor_faces_vertex2)
{
   const double xi_103 = 1 / (num_neighbor_faces_vertex0);
   const double xi_106 = 1 / (num_neighbor_faces_edge0);
   const double xi_107 = 1 / (num_neighbor_faces_edge2);
   const double xi_119 = 1 / (num_neighbor_faces_vertex1);
   const double xi_123 = 1 / (num_neighbor_faces_edge1);
   const double xi_135 = 1 / (num_neighbor_faces_vertex2);
   for (int ctr_2 = 0; ctr_2 < 1; ctr_2 += 1)
   {
      // bottom left vertex
      for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
      {
         const double xi_109 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 8194*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 4097];
         const double xi_110 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_111 = 1.0*xi_103*_data_vertexFineSrc[2*ctr_1 + 8196*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_112 = xi_106*0.375*_data_edgeFineSrc_X[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_114 = xi_106*-0.125*_data_edgeFineSrc_X[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_113 = xi_107*0.375*_data_edgeFineSrc_Y[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_115 = xi_107*-0.125*_data_edgeFineSrc_Y[2*ctr_1 + 8194*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 4097];
         _data_vertexCoarseDst[ctr_1 + 2050*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_109 + xi_110 + xi_111 + xi_112 + xi_113 + xi_114 + xi_115;
      }
      // bottom edge
      for (int ctr_1 = 1; ctr_1 < 2048; ctr_1 += 1)
      {
         const double xi_37 = 0.375*_data_edgeFineSrc_XY[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_38 = 0.375*_data_edgeFineSrc_Y[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_39 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 8194*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 4096];
         const double xi_40 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_41 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 8194*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 4095];
         const double xi_42 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 8194*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 4095];
         const double xi_43 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 8194*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 4097];
         const double xi_44 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 8194*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 4096];
         const double xi_45 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 8194*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 4097];
         const double xi_46 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_47 = 1.0*xi_106*_data_vertexFineSrc[2*ctr_1 + 8196*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_48 = xi_106*0.375*_data_edgeFineSrc_X[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_49 = xi_106*0.375*_data_edgeFineSrc_X[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_50 = xi_106*-0.125*_data_edgeFineSrc_X[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_51 = xi_106*-0.125*_data_edgeFineSrc_X[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         _data_vertexCoarseDst[ctr_1 + 2050*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_37 + xi_38 + xi_39 + xi_40 + xi_41 + xi_42 + xi_43 + xi_44 + xi_45 + xi_46 + xi_47 + xi_48 + xi_49 + xi_50 + xi_51;
      }
      // bottom right vertex
      for (int ctr_1 = 2048; ctr_1 < 2049; ctr_1 += 1)
      {
         const double xi_125 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_126 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 8194*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 4095];
         const double xi_127 = 1.0*xi_119*_data_vertexFineSrc[2*ctr_1 + 8196*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_128 = xi_106*0.375*_data_edgeFineSrc_X[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_130 = xi_106*-0.125*_data_edgeFineSrc_X[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_129 = xi_123*0.375*_data_edgeFineSrc_XY[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_131 = xi_123*-0.125*_data_edgeFineSrc_XY[2*ctr_1 + 8194*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 4095];
         _data_vertexCoarseDst[ctr_1 + 2050*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_125 + xi_126 + xi_127 + xi_128 + xi_129 + xi_130 + xi_131;
      }
   }
   for (int ctr_2 = 1; ctr_2 < 2048; ctr_2 += 1)
   {
      // left edge
      for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
      {
         const double xi_85 = 0.375*_data_edgeFineSrc_XY[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 4097];
         const double xi_86 = 0.375*_data_edgeFineSrc_X[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_87 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 8194*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 8194];
         const double xi_88 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 4096];
         const double xi_89 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 8194*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 8193];
         const double xi_90 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 8194*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 4097];
         const double xi_91 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 4096];
         const double xi_92 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_93 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 8194*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 8193];
         const double xi_94 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_95 = 1.0*xi_107*_data_vertexFineSrc[2*ctr_1 + 8196*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_96 = xi_107*0.375*_data_edgeFineSrc_Y[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 4097];
         const double xi_97 = xi_107*0.375*_data_edgeFineSrc_Y[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_98 = xi_107*-0.125*_data_edgeFineSrc_Y[2*ctr_1 + 8194*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 8194];
         const double xi_99 = xi_107*-0.125*_data_edgeFineSrc_Y[2*ctr_1 + 8194*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 4097];
         _data_vertexCoarseDst[ctr_1 + 2050*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_85 + xi_86 + xi_87 + xi_88 + xi_89 + xi_90 + xi_91 + xi_92 + xi_93 + xi_94 + xi_95 + xi_96 + xi_97 + xi_98 + xi_99;
      }
      // inner triangle
      for (int ctr_1 = 1; ctr_1 < -ctr_2 + 2048; ctr_1 += 1)
      {
         const double xi_3 = 0.375*_data_edgeFineSrc_XY[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_4 = 0.375*_data_edgeFineSrc_XY[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 4097];
         const double xi_5 = 0.375*_data_edgeFineSrc_X[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_6 = 0.375*_data_edgeFineSrc_X[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_7 = 0.375*_data_edgeFineSrc_Y[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 4097];
         const double xi_8 = 0.375*_data_edgeFineSrc_Y[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_9 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 8194*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 4096];
         const double xi_10 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_11 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 8194*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 4095];
         const double xi_12 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 8194*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 8194];
         const double xi_13 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 4096];
         const double xi_14 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 8194*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 8193];
         const double xi_15 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 4098];
         const double xi_16 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_17 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 8194*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 4095];
         const double xi_18 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 8194*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 4097];
         const double xi_19 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 4096];
         const double xi_20 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_21 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 4098];
         const double xi_22 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 8194*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 4096];
         const double xi_23 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 8194*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 8194];
         const double xi_24 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 8194*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 4097];
         const double xi_25 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 8194*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 8193];
         const double xi_26 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_27 = _data_vertexFineSrc[2*ctr_1 + 8196*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         _data_vertexCoarseDst[ctr_1 + 2050*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_10 + xi_11 + xi_12 + xi_13 + xi_14 + xi_15 + xi_16 + xi_17 + xi_18 + xi_19 + xi_20 + xi_21 + xi_22 + xi_23 + xi_24 + xi_25 + xi_26 + xi_27 + xi_3 + xi_4 + xi_5 + xi_6 + xi_7 + xi_8 + xi_9;
      }
      // diagonal edge
      for (int ctr_1 = -ctr_2 + 2048; ctr_1 < -ctr_2 + 2049; ctr_1 += 1)
      {
         const double xi_61 = 0.375*_data_edgeFineSrc_X[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_62 = 0.375*_data_edgeFineSrc_Y[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 4097];
         const double xi_63 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_64 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 8194*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 8194];
         const double xi_65 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 4098];
         const double xi_66 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_67 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 8194*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 4095];
         const double xi_68 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 4098];
         const double xi_69 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 8194*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 8194];
         const double xi_70 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 8194*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 8193];
         const double xi_71 = 1.0*xi_123*_data_vertexFineSrc[2*ctr_1 + 8196*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_72 = xi_123*0.375*_data_edgeFineSrc_XY[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_73 = xi_123*0.375*_data_edgeFineSrc_XY[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 4097];
         const double xi_74 = xi_123*-0.125*_data_edgeFineSrc_XY[2*ctr_1 + 8194*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 4095];
         const double xi_75 = xi_123*-0.125*_data_edgeFineSrc_XY[2*ctr_1 + 8194*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 8193];
         _data_vertexCoarseDst[ctr_1 + 2050*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_61 + xi_62 + xi_63 + xi_64 + xi_65 + xi_66 + xi_67 + xi_68 + xi_69 + xi_70 + xi_71 + xi_72 + xi_73 + xi_74 + xi_75;
      }
   }
   for (int ctr_2 = 2048; ctr_2 < 2049; ctr_2 += 1)
   {
      // top vertex
      for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
      {
         const double xi_141 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 8194*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 8194];
         const double xi_142 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 8194*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 8193];
         const double xi_143 = 1.0*xi_135*_data_vertexFineSrc[2*ctr_1 + 8196*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_144 = xi_123*0.375*_data_edgeFineSrc_XY[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 4097];
         const double xi_146 = xi_123*-0.125*_data_edgeFineSrc_XY[2*ctr_1 + 8194*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 8193];
         const double xi_145 = xi_107*0.375*_data_edgeFineSrc_Y[2*ctr_1 + 8194*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 4097];
         const double xi_147 = xi_107*-0.125*_data_edgeFineSrc_Y[2*ctr_1 + 8194*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 8194];
         _data_vertexCoarseDst[ctr_1 + 2050*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_141 + xi_142 + xi_143 + xi_144 + xi_145 + xi_146 + xi_147;
      }
   }
   {
      
   }
}

static void restrict_2D_macroface_P2_update_vertexdofs_level_12(double * RESTRICT _data_edgeFineSrc_X, double * RESTRICT _data_edgeFineSrc_XY, double * RESTRICT _data_edgeFineSrc_Y, double * RESTRICT _data_vertexCoarseDst, double * RESTRICT _data_vertexFineSrc, double num_neighbor_faces_edge0, double num_neighbor_faces_edge1, double num_neighbor_faces_edge2, double num_neighbor_faces_vertex0, double num_neighbor_faces_vertex1, double num_neighbor_faces_vertex2)
{
   const double xi_103 = 1 / (num_neighbor_faces_vertex0);
   const double xi_106 = 1 / (num_neighbor_faces_edge0);
   const double xi_107 = 1 / (num_neighbor_faces_edge2);
   const double xi_119 = 1 / (num_neighbor_faces_vertex1);
   const double xi_123 = 1 / (num_neighbor_faces_edge1);
   const double xi_135 = 1 / (num_neighbor_faces_vertex2);
   for (int ctr_2 = 0; ctr_2 < 1; ctr_2 += 1)
   {
      // bottom left vertex
      for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
      {
         const double xi_109 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 16386*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8193];
         const double xi_110 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_111 = 1.0*xi_103*_data_vertexFineSrc[2*ctr_1 + 16388*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_112 = xi_106*0.375*_data_edgeFineSrc_X[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_114 = xi_106*-0.125*_data_edgeFineSrc_X[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_113 = xi_107*0.375*_data_edgeFineSrc_Y[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_115 = xi_107*-0.125*_data_edgeFineSrc_Y[2*ctr_1 + 16386*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8193];
         _data_vertexCoarseDst[ctr_1 + 4098*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_109 + xi_110 + xi_111 + xi_112 + xi_113 + xi_114 + xi_115;
      }
      // bottom edge
      for (int ctr_1 = 1; ctr_1 < 4096; ctr_1 += 1)
      {
         const double xi_37 = 0.375*_data_edgeFineSrc_XY[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_38 = 0.375*_data_edgeFineSrc_Y[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_39 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 16386*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8192];
         const double xi_40 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_41 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 16386*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8191];
         const double xi_42 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 16386*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8191];
         const double xi_43 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 16386*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8193];
         const double xi_44 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 16386*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8192];
         const double xi_45 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 16386*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8193];
         const double xi_46 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_47 = 1.0*xi_106*_data_vertexFineSrc[2*ctr_1 + 16388*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_48 = xi_106*0.375*_data_edgeFineSrc_X[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_49 = xi_106*0.375*_data_edgeFineSrc_X[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_50 = xi_106*-0.125*_data_edgeFineSrc_X[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_51 = xi_106*-0.125*_data_edgeFineSrc_X[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         _data_vertexCoarseDst[ctr_1 + 4098*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_37 + xi_38 + xi_39 + xi_40 + xi_41 + xi_42 + xi_43 + xi_44 + xi_45 + xi_46 + xi_47 + xi_48 + xi_49 + xi_50 + xi_51;
      }
      // bottom right vertex
      for (int ctr_1 = 4096; ctr_1 < 4097; ctr_1 += 1)
      {
         const double xi_125 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_126 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 16386*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8191];
         const double xi_127 = 1.0*xi_119*_data_vertexFineSrc[2*ctr_1 + 16388*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_128 = xi_106*0.375*_data_edgeFineSrc_X[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_130 = xi_106*-0.125*_data_edgeFineSrc_X[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_129 = xi_123*0.375*_data_edgeFineSrc_XY[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_131 = xi_123*-0.125*_data_edgeFineSrc_XY[2*ctr_1 + 16386*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8191];
         _data_vertexCoarseDst[ctr_1 + 4098*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_125 + xi_126 + xi_127 + xi_128 + xi_129 + xi_130 + xi_131;
      }
   }
   for (int ctr_2 = 1; ctr_2 < 4096; ctr_2 += 1)
   {
      // left edge
      for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
      {
         const double xi_85 = 0.375*_data_edgeFineSrc_XY[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 8193];
         const double xi_86 = 0.375*_data_edgeFineSrc_X[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_87 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 16386*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 16386];
         const double xi_88 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 8192];
         const double xi_89 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 16386*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 16385];
         const double xi_90 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 16386*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8193];
         const double xi_91 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 8192];
         const double xi_92 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_93 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 16386*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 16385];
         const double xi_94 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_95 = 1.0*xi_107*_data_vertexFineSrc[2*ctr_1 + 16388*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_96 = xi_107*0.375*_data_edgeFineSrc_Y[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 8193];
         const double xi_97 = xi_107*0.375*_data_edgeFineSrc_Y[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_98 = xi_107*-0.125*_data_edgeFineSrc_Y[2*ctr_1 + 16386*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 16386];
         const double xi_99 = xi_107*-0.125*_data_edgeFineSrc_Y[2*ctr_1 + 16386*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8193];
         _data_vertexCoarseDst[ctr_1 + 4098*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_85 + xi_86 + xi_87 + xi_88 + xi_89 + xi_90 + xi_91 + xi_92 + xi_93 + xi_94 + xi_95 + xi_96 + xi_97 + xi_98 + xi_99;
      }
      // inner triangle
      for (int ctr_1 = 1; ctr_1 < -ctr_2 + 4096; ctr_1 += 1)
      {
         const double xi_3 = 0.375*_data_edgeFineSrc_XY[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_4 = 0.375*_data_edgeFineSrc_XY[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 8193];
         const double xi_5 = 0.375*_data_edgeFineSrc_X[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_6 = 0.375*_data_edgeFineSrc_X[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_7 = 0.375*_data_edgeFineSrc_Y[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 8193];
         const double xi_8 = 0.375*_data_edgeFineSrc_Y[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_9 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 16386*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8192];
         const double xi_10 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_11 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 16386*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8191];
         const double xi_12 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 16386*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 16386];
         const double xi_13 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 8192];
         const double xi_14 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 16386*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 16385];
         const double xi_15 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 8194];
         const double xi_16 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_17 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 16386*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8191];
         const double xi_18 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 16386*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8193];
         const double xi_19 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 8192];
         const double xi_20 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_21 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 8194];
         const double xi_22 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 16386*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8192];
         const double xi_23 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 16386*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 16386];
         const double xi_24 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 16386*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8193];
         const double xi_25 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 16386*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 16385];
         const double xi_26 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_27 = _data_vertexFineSrc[2*ctr_1 + 16388*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         _data_vertexCoarseDst[ctr_1 + 4098*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_10 + xi_11 + xi_12 + xi_13 + xi_14 + xi_15 + xi_16 + xi_17 + xi_18 + xi_19 + xi_20 + xi_21 + xi_22 + xi_23 + xi_24 + xi_25 + xi_26 + xi_27 + xi_3 + xi_4 + xi_5 + xi_6 + xi_7 + xi_8 + xi_9;
      }
      // diagonal edge
      for (int ctr_1 = -ctr_2 + 4096; ctr_1 < -ctr_2 + 4097; ctr_1 += 1)
      {
         const double xi_61 = 0.375*_data_edgeFineSrc_X[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_62 = 0.375*_data_edgeFineSrc_Y[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 8193];
         const double xi_63 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_64 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 16386*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 16386];
         const double xi_65 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 8194];
         const double xi_66 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_67 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 16386*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8191];
         const double xi_68 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 8194];
         const double xi_69 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 16386*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 16386];
         const double xi_70 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 16386*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 16385];
         const double xi_71 = 1.0*xi_123*_data_vertexFineSrc[2*ctr_1 + 16388*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_72 = xi_123*0.375*_data_edgeFineSrc_XY[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_73 = xi_123*0.375*_data_edgeFineSrc_XY[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 8193];
         const double xi_74 = xi_123*-0.125*_data_edgeFineSrc_XY[2*ctr_1 + 16386*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 8191];
         const double xi_75 = xi_123*-0.125*_data_edgeFineSrc_XY[2*ctr_1 + 16386*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 16385];
         _data_vertexCoarseDst[ctr_1 + 4098*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_61 + xi_62 + xi_63 + xi_64 + xi_65 + xi_66 + xi_67 + xi_68 + xi_69 + xi_70 + xi_71 + xi_72 + xi_73 + xi_74 + xi_75;
      }
   }
   for (int ctr_2 = 4096; ctr_2 < 4097; ctr_2 += 1)
   {
      // top vertex
      for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
      {
         const double xi_141 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 16386*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 16386];
         const double xi_142 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 16386*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 16385];
         const double xi_143 = 1.0*xi_135*_data_vertexFineSrc[2*ctr_1 + 16388*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_144 = xi_123*0.375*_data_edgeFineSrc_XY[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 8193];
         const double xi_146 = xi_123*-0.125*_data_edgeFineSrc_XY[2*ctr_1 + 16386*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 16385];
         const double xi_145 = xi_107*0.375*_data_edgeFineSrc_Y[2*ctr_1 + 16386*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 8193];
         const double xi_147 = xi_107*-0.125*_data_edgeFineSrc_Y[2*ctr_1 + 16386*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 16386];
         _data_vertexCoarseDst[ctr_1 + 4098*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_141 + xi_142 + xi_143 + xi_144 + xi_145 + xi_146 + xi_147;
      }
   }
   {
      
   }
}

static void restrict_2D_macroface_P2_update_vertexdofs_level_13(double * RESTRICT _data_edgeFineSrc_X, double * RESTRICT _data_edgeFineSrc_XY, double * RESTRICT _data_edgeFineSrc_Y, double * RESTRICT _data_vertexCoarseDst, double * RESTRICT _data_vertexFineSrc, double num_neighbor_faces_edge0, double num_neighbor_faces_edge1, double num_neighbor_faces_edge2, double num_neighbor_faces_vertex0, double num_neighbor_faces_vertex1, double num_neighbor_faces_vertex2)
{
   const double xi_103 = 1 / (num_neighbor_faces_vertex0);
   const double xi_106 = 1 / (num_neighbor_faces_edge0);
   const double xi_107 = 1 / (num_neighbor_faces_edge2);
   const double xi_119 = 1 / (num_neighbor_faces_vertex1);
   const double xi_123 = 1 / (num_neighbor_faces_edge1);
   const double xi_135 = 1 / (num_neighbor_faces_vertex2);
   for (int ctr_2 = 0; ctr_2 < 1; ctr_2 += 1)
   {
      // bottom left vertex
      for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
      {
         const double xi_109 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 32770*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16385];
         const double xi_110 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_111 = 1.0*xi_103*_data_vertexFineSrc[2*ctr_1 + 32772*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_112 = xi_106*0.375*_data_edgeFineSrc_X[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_114 = xi_106*-0.125*_data_edgeFineSrc_X[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_113 = xi_107*0.375*_data_edgeFineSrc_Y[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_115 = xi_107*-0.125*_data_edgeFineSrc_Y[2*ctr_1 + 32770*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16385];
         _data_vertexCoarseDst[ctr_1 + 8194*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_109 + xi_110 + xi_111 + xi_112 + xi_113 + xi_114 + xi_115;
      }
      // bottom edge
      for (int ctr_1 = 1; ctr_1 < 8192; ctr_1 += 1)
      {
         const double xi_37 = 0.375*_data_edgeFineSrc_XY[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_38 = 0.375*_data_edgeFineSrc_Y[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_39 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 32770*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16384];
         const double xi_40 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_41 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 32770*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16383];
         const double xi_42 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 32770*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16383];
         const double xi_43 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 32770*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16385];
         const double xi_44 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 32770*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16384];
         const double xi_45 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 32770*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16385];
         const double xi_46 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_47 = 1.0*xi_106*_data_vertexFineSrc[2*ctr_1 + 32772*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_48 = xi_106*0.375*_data_edgeFineSrc_X[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_49 = xi_106*0.375*_data_edgeFineSrc_X[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_50 = xi_106*-0.125*_data_edgeFineSrc_X[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_51 = xi_106*-0.125*_data_edgeFineSrc_X[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         _data_vertexCoarseDst[ctr_1 + 8194*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_37 + xi_38 + xi_39 + xi_40 + xi_41 + xi_42 + xi_43 + xi_44 + xi_45 + xi_46 + xi_47 + xi_48 + xi_49 + xi_50 + xi_51;
      }
      // bottom right vertex
      for (int ctr_1 = 8192; ctr_1 < 8193; ctr_1 += 1)
      {
         const double xi_125 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_126 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 32770*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16383];
         const double xi_127 = 1.0*xi_119*_data_vertexFineSrc[2*ctr_1 + 32772*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_128 = xi_106*0.375*_data_edgeFineSrc_X[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_130 = xi_106*-0.125*_data_edgeFineSrc_X[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_129 = xi_123*0.375*_data_edgeFineSrc_XY[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_131 = xi_123*-0.125*_data_edgeFineSrc_XY[2*ctr_1 + 32770*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16383];
         _data_vertexCoarseDst[ctr_1 + 8194*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_125 + xi_126 + xi_127 + xi_128 + xi_129 + xi_130 + xi_131;
      }
   }
   for (int ctr_2 = 1; ctr_2 < 8192; ctr_2 += 1)
   {
      // left edge
      for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
      {
         const double xi_85 = 0.375*_data_edgeFineSrc_XY[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 16385];
         const double xi_86 = 0.375*_data_edgeFineSrc_X[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_87 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 32770*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 32770];
         const double xi_88 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 16384];
         const double xi_89 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 32770*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 32769];
         const double xi_90 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 32770*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16385];
         const double xi_91 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 16384];
         const double xi_92 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_93 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 32770*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 32769];
         const double xi_94 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_95 = 1.0*xi_107*_data_vertexFineSrc[2*ctr_1 + 32772*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_96 = xi_107*0.375*_data_edgeFineSrc_Y[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 16385];
         const double xi_97 = xi_107*0.375*_data_edgeFineSrc_Y[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_98 = xi_107*-0.125*_data_edgeFineSrc_Y[2*ctr_1 + 32770*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 32770];
         const double xi_99 = xi_107*-0.125*_data_edgeFineSrc_Y[2*ctr_1 + 32770*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16385];
         _data_vertexCoarseDst[ctr_1 + 8194*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_85 + xi_86 + xi_87 + xi_88 + xi_89 + xi_90 + xi_91 + xi_92 + xi_93 + xi_94 + xi_95 + xi_96 + xi_97 + xi_98 + xi_99;
      }
      // inner triangle
      for (int ctr_1 = 1; ctr_1 < -ctr_2 + 8192; ctr_1 += 1)
      {
         const double xi_3 = 0.375*_data_edgeFineSrc_XY[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_4 = 0.375*_data_edgeFineSrc_XY[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 16385];
         const double xi_5 = 0.375*_data_edgeFineSrc_X[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_6 = 0.375*_data_edgeFineSrc_X[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_7 = 0.375*_data_edgeFineSrc_Y[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 16385];
         const double xi_8 = 0.375*_data_edgeFineSrc_Y[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_9 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 32770*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16384];
         const double xi_10 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_11 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 32770*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16383];
         const double xi_12 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 32770*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 32770];
         const double xi_13 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 16384];
         const double xi_14 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 32770*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 32769];
         const double xi_15 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 16386];
         const double xi_16 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_17 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 32770*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16383];
         const double xi_18 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 32770*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16385];
         const double xi_19 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 16384];
         const double xi_20 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_21 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 16386];
         const double xi_22 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 32770*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16384];
         const double xi_23 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 32770*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 32770];
         const double xi_24 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 32770*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16385];
         const double xi_25 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 32770*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 32769];
         const double xi_26 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_27 = _data_vertexFineSrc[2*ctr_1 + 32772*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         _data_vertexCoarseDst[ctr_1 + 8194*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_10 + xi_11 + xi_12 + xi_13 + xi_14 + xi_15 + xi_16 + xi_17 + xi_18 + xi_19 + xi_20 + xi_21 + xi_22 + xi_23 + xi_24 + xi_25 + xi_26 + xi_27 + xi_3 + xi_4 + xi_5 + xi_6 + xi_7 + xi_8 + xi_9;
      }
      // diagonal edge
      for (int ctr_1 = -ctr_2 + 8192; ctr_1 < -ctr_2 + 8193; ctr_1 += 1)
      {
         const double xi_61 = 0.375*_data_edgeFineSrc_X[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_62 = 0.375*_data_edgeFineSrc_Y[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 16385];
         const double xi_63 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_64 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 32770*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 32770];
         const double xi_65 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 16386];
         const double xi_66 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_67 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 32770*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16383];
         const double xi_68 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 16386];
         const double xi_69 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 32770*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 32770];
         const double xi_70 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 32770*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 32769];
         const double xi_71 = 1.0*xi_123*_data_vertexFineSrc[2*ctr_1 + 32772*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_72 = xi_123*0.375*_data_edgeFineSrc_XY[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_73 = xi_123*0.375*_data_edgeFineSrc_XY[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 16385];
         const double xi_74 = xi_123*-0.125*_data_edgeFineSrc_XY[2*ctr_1 + 32770*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 16383];
         const double xi_75 = xi_123*-0.125*_data_edgeFineSrc_XY[2*ctr_1 + 32770*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 32769];
         _data_vertexCoarseDst[ctr_1 + 8194*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_61 + xi_62 + xi_63 + xi_64 + xi_65 + xi_66 + xi_67 + xi_68 + xi_69 + xi_70 + xi_71 + xi_72 + xi_73 + xi_74 + xi_75;
      }
   }
   for (int ctr_2 = 8192; ctr_2 < 8193; ctr_2 += 1)
   {
      // top vertex
      for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
      {
         const double xi_141 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 32770*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 32770];
         const double xi_142 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 32770*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 32769];
         const double xi_143 = 1.0*xi_135*_data_vertexFineSrc[2*ctr_1 + 32772*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_144 = xi_123*0.375*_data_edgeFineSrc_XY[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 16385];
         const double xi_146 = xi_123*-0.125*_data_edgeFineSrc_XY[2*ctr_1 + 32770*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 32769];
         const double xi_145 = xi_107*0.375*_data_edgeFineSrc_Y[2*ctr_1 + 32770*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 16385];
         const double xi_147 = xi_107*-0.125*_data_edgeFineSrc_Y[2*ctr_1 + 32770*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 32770];
         _data_vertexCoarseDst[ctr_1 + 8194*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_141 + xi_142 + xi_143 + xi_144 + xi_145 + xi_146 + xi_147;
      }
   }
   {
      
   }
}

static void restrict_2D_macroface_P2_update_vertexdofs_level_14(double * RESTRICT _data_edgeFineSrc_X, double * RESTRICT _data_edgeFineSrc_XY, double * RESTRICT _data_edgeFineSrc_Y, double * RESTRICT _data_vertexCoarseDst, double * RESTRICT _data_vertexFineSrc, double num_neighbor_faces_edge0, double num_neighbor_faces_edge1, double num_neighbor_faces_edge2, double num_neighbor_faces_vertex0, double num_neighbor_faces_vertex1, double num_neighbor_faces_vertex2)
{
   const double xi_103 = 1 / (num_neighbor_faces_vertex0);
   const double xi_106 = 1 / (num_neighbor_faces_edge0);
   const double xi_107 = 1 / (num_neighbor_faces_edge2);
   const double xi_119 = 1 / (num_neighbor_faces_vertex1);
   const double xi_123 = 1 / (num_neighbor_faces_edge1);
   const double xi_135 = 1 / (num_neighbor_faces_vertex2);
   for (int ctr_2 = 0; ctr_2 < 1; ctr_2 += 1)
   {
      // bottom left vertex
      for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
      {
         const double xi_109 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 65538*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32769];
         const double xi_110 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_111 = 1.0*xi_103*_data_vertexFineSrc[2*ctr_1 + 65540*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_112 = xi_106*0.375*_data_edgeFineSrc_X[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_114 = xi_106*-0.125*_data_edgeFineSrc_X[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_113 = xi_107*0.375*_data_edgeFineSrc_Y[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_115 = xi_107*-0.125*_data_edgeFineSrc_Y[2*ctr_1 + 65538*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32769];
         _data_vertexCoarseDst[ctr_1 + 16386*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_109 + xi_110 + xi_111 + xi_112 + xi_113 + xi_114 + xi_115;
      }
      // bottom edge
      for (int ctr_1 = 1; ctr_1 < 16384; ctr_1 += 1)
      {
         const double xi_37 = 0.375*_data_edgeFineSrc_XY[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_38 = 0.375*_data_edgeFineSrc_Y[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_39 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 65538*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32768];
         const double xi_40 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_41 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 65538*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32767];
         const double xi_42 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 65538*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32767];
         const double xi_43 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 65538*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32769];
         const double xi_44 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 65538*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32768];
         const double xi_45 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 65538*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32769];
         const double xi_46 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_47 = 1.0*xi_106*_data_vertexFineSrc[2*ctr_1 + 65540*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_48 = xi_106*0.375*_data_edgeFineSrc_X[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_49 = xi_106*0.375*_data_edgeFineSrc_X[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_50 = xi_106*-0.125*_data_edgeFineSrc_X[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_51 = xi_106*-0.125*_data_edgeFineSrc_X[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         _data_vertexCoarseDst[ctr_1 + 16386*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_37 + xi_38 + xi_39 + xi_40 + xi_41 + xi_42 + xi_43 + xi_44 + xi_45 + xi_46 + xi_47 + xi_48 + xi_49 + xi_50 + xi_51;
      }
      // bottom right vertex
      for (int ctr_1 = 16384; ctr_1 < 16385; ctr_1 += 1)
      {
         const double xi_125 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_126 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 65538*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32767];
         const double xi_127 = 1.0*xi_119*_data_vertexFineSrc[2*ctr_1 + 65540*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_128 = xi_106*0.375*_data_edgeFineSrc_X[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_130 = xi_106*-0.125*_data_edgeFineSrc_X[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_129 = xi_123*0.375*_data_edgeFineSrc_XY[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_131 = xi_123*-0.125*_data_edgeFineSrc_XY[2*ctr_1 + 65538*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32767];
         _data_vertexCoarseDst[ctr_1 + 16386*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_125 + xi_126 + xi_127 + xi_128 + xi_129 + xi_130 + xi_131;
      }
   }
   for (int ctr_2 = 1; ctr_2 < 16384; ctr_2 += 1)
   {
      // left edge
      for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
      {
         const double xi_85 = 0.375*_data_edgeFineSrc_XY[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 32769];
         const double xi_86 = 0.375*_data_edgeFineSrc_X[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_87 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 65538*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 65538];
         const double xi_88 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 32768];
         const double xi_89 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 65538*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 65537];
         const double xi_90 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 65538*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32769];
         const double xi_91 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 32768];
         const double xi_92 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_93 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 65538*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 65537];
         const double xi_94 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_95 = 1.0*xi_107*_data_vertexFineSrc[2*ctr_1 + 65540*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_96 = xi_107*0.375*_data_edgeFineSrc_Y[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 32769];
         const double xi_97 = xi_107*0.375*_data_edgeFineSrc_Y[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_98 = xi_107*-0.125*_data_edgeFineSrc_Y[2*ctr_1 + 65538*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 65538];
         const double xi_99 = xi_107*-0.125*_data_edgeFineSrc_Y[2*ctr_1 + 65538*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32769];
         _data_vertexCoarseDst[ctr_1 + 16386*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_85 + xi_86 + xi_87 + xi_88 + xi_89 + xi_90 + xi_91 + xi_92 + xi_93 + xi_94 + xi_95 + xi_96 + xi_97 + xi_98 + xi_99;
      }
      // inner triangle
      for (int ctr_1 = 1; ctr_1 < -ctr_2 + 16384; ctr_1 += 1)
      {
         const double xi_3 = 0.375*_data_edgeFineSrc_XY[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_4 = 0.375*_data_edgeFineSrc_XY[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 32769];
         const double xi_5 = 0.375*_data_edgeFineSrc_X[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_6 = 0.375*_data_edgeFineSrc_X[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_7 = 0.375*_data_edgeFineSrc_Y[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 32769];
         const double xi_8 = 0.375*_data_edgeFineSrc_Y[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_9 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 65538*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32768];
         const double xi_10 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_11 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 65538*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32767];
         const double xi_12 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 65538*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 65538];
         const double xi_13 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 32768];
         const double xi_14 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 65538*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 65537];
         const double xi_15 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 32770];
         const double xi_16 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_17 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 65538*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32767];
         const double xi_18 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 65538*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32769];
         const double xi_19 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 32768];
         const double xi_20 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_21 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 32770];
         const double xi_22 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 65538*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32768];
         const double xi_23 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 65538*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 65538];
         const double xi_24 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 65538*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32769];
         const double xi_25 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 65538*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 65537];
         const double xi_26 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_27 = _data_vertexFineSrc[2*ctr_1 + 65540*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         _data_vertexCoarseDst[ctr_1 + 16386*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_10 + xi_11 + xi_12 + xi_13 + xi_14 + xi_15 + xi_16 + xi_17 + xi_18 + xi_19 + xi_20 + xi_21 + xi_22 + xi_23 + xi_24 + xi_25 + xi_26 + xi_27 + xi_3 + xi_4 + xi_5 + xi_6 + xi_7 + xi_8 + xi_9;
      }
      // diagonal edge
      for (int ctr_1 = -ctr_2 + 16384; ctr_1 < -ctr_2 + 16385; ctr_1 += 1)
      {
         const double xi_61 = 0.375*_data_edgeFineSrc_X[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_62 = 0.375*_data_edgeFineSrc_Y[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 32769];
         const double xi_63 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_64 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 65538*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 65538];
         const double xi_65 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 32770];
         const double xi_66 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_67 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 65538*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32767];
         const double xi_68 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 32770];
         const double xi_69 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 65538*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 65538];
         const double xi_70 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 65538*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 65537];
         const double xi_71 = 1.0*xi_123*_data_vertexFineSrc[2*ctr_1 + 65540*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_72 = xi_123*0.375*_data_edgeFineSrc_XY[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_73 = xi_123*0.375*_data_edgeFineSrc_XY[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 32769];
         const double xi_74 = xi_123*-0.125*_data_edgeFineSrc_XY[2*ctr_1 + 65538*ctr_2 - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) + 32767];
         const double xi_75 = xi_123*-0.125*_data_edgeFineSrc_XY[2*ctr_1 + 65538*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 65537];
         _data_vertexCoarseDst[ctr_1 + 16386*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_61 + xi_62 + xi_63 + xi_64 + xi_65 + xi_66 + xi_67 + xi_68 + xi_69 + xi_70 + xi_71 + xi_72 + xi_73 + xi_74 + xi_75;
      }
   }
   for (int ctr_2 = 16384; ctr_2 < 16385; ctr_2 += 1)
   {
      // top vertex
      for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
      {
         const double xi_141 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 65538*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 65538];
         const double xi_142 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 65538*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 65537];
         const double xi_143 = 1.0*xi_135*_data_vertexFineSrc[2*ctr_1 + 65540*ctr_2 - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_144 = xi_123*0.375*_data_edgeFineSrc_XY[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 32769];
         const double xi_146 = xi_123*-0.125*_data_edgeFineSrc_XY[2*ctr_1 + 65538*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 65537];
         const double xi_145 = xi_107*0.375*_data_edgeFineSrc_Y[2*ctr_1 + 65538*ctr_2 - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 32769];
         const double xi_147 = xi_107*-0.125*_data_edgeFineSrc_Y[2*ctr_1 + 65538*ctr_2 - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) - 65538];
         _data_vertexCoarseDst[ctr_1 + 16386*ctr_2 - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_141 + xi_142 + xi_143 + xi_144 + xi_145 + xi_146 + xi_147;
      }
   }
   {
      
   }
}

static void restrict_2D_macroface_P2_update_vertexdofs_level_any(double * RESTRICT _data_edgeFineSrc_X, double * RESTRICT _data_edgeFineSrc_XY, double * RESTRICT _data_edgeFineSrc_Y, double * RESTRICT _data_vertexCoarseDst, double * RESTRICT _data_vertexFineSrc, int64_t coarse_level, double num_neighbor_faces_edge0, double num_neighbor_faces_edge1, double num_neighbor_faces_edge2, double num_neighbor_faces_vertex0, double num_neighbor_faces_vertex1, double num_neighbor_faces_vertex2)
{
   const double xi_103 = 1 / (num_neighbor_faces_vertex0);
   const double xi_106 = 1 / (num_neighbor_faces_edge0);
   const double xi_107 = 1 / (num_neighbor_faces_edge2);
   const double xi_119 = 1 / (num_neighbor_faces_vertex1);
   const double xi_123 = 1 / (num_neighbor_faces_edge1);
   const double xi_135 = 1 / (num_neighbor_faces_vertex2);
   for (int ctr_2 = 0; ctr_2 < 1; ctr_2 += 1)
   {
      // bottom left vertex
      for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
      {
         const double xi_109 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + (2*ctr_2 + 1)*((1 << (coarse_level + 1)) + 1) - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2))];
         const double xi_110 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_111 = 1.0*xi_103*_data_vertexFineSrc[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 2) - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_112 = xi_106*0.375*_data_edgeFineSrc_X[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_114 = xi_106*-0.125*_data_edgeFineSrc_X[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_113 = xi_107*0.375*_data_edgeFineSrc_Y[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_115 = xi_107*-0.125*_data_edgeFineSrc_Y[2*ctr_1 + (2*ctr_2 + 1)*((1 << (coarse_level + 1)) + 1) - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2))];
         _data_vertexCoarseDst[ctr_1 + ctr_2*((1 << (coarse_level)) + 2) - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_109 + xi_110 + xi_111 + xi_112 + xi_113 + xi_114 + xi_115;
      }
      // bottom edge
      for (int ctr_1 = 1; ctr_1 < (1 << (coarse_level)); ctr_1 += 1)
      {
         const double xi_37 = 0.375*_data_edgeFineSrc_XY[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_38 = 0.375*_data_edgeFineSrc_Y[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_39 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + (2*ctr_2 + 1)*((1 << (coarse_level + 1)) + 1) - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) - 1];
         const double xi_40 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_41 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + (2*ctr_2 + 1)*((1 << (coarse_level + 1)) + 1) - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) - 2];
         const double xi_42 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + (2*ctr_2 + 1)*((1 << (coarse_level + 1)) + 1) - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) - 2];
         const double xi_43 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + (2*ctr_2 + 1)*((1 << (coarse_level + 1)) + 1) - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2))];
         const double xi_44 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + (2*ctr_2 + 1)*((1 << (coarse_level + 1)) + 1) - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) - 1];
         const double xi_45 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + (2*ctr_2 + 1)*((1 << (coarse_level + 1)) + 1) - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2))];
         const double xi_46 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_47 = 1.0*xi_106*_data_vertexFineSrc[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 2) - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_48 = xi_106*0.375*_data_edgeFineSrc_X[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_49 = xi_106*0.375*_data_edgeFineSrc_X[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_50 = xi_106*-0.125*_data_edgeFineSrc_X[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_51 = xi_106*-0.125*_data_edgeFineSrc_X[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         _data_vertexCoarseDst[ctr_1 + ctr_2*((1 << (coarse_level)) + 2) - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_37 + xi_38 + xi_39 + xi_40 + xi_41 + xi_42 + xi_43 + xi_44 + xi_45 + xi_46 + xi_47 + xi_48 + xi_49 + xi_50 + xi_51;
      }
      // bottom right vertex
      for (int ctr_1 = (1 << (coarse_level)); ctr_1 < (1 << (coarse_level)) + 1; ctr_1 += 1)
      {
         const double xi_125 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_126 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + (2*ctr_2 + 1)*((1 << (coarse_level + 1)) + 1) - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) - 2];
         const double xi_127 = 1.0*xi_119*_data_vertexFineSrc[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 2) - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_128 = xi_106*0.375*_data_edgeFineSrc_X[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_130 = xi_106*-0.125*_data_edgeFineSrc_X[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_129 = xi_123*0.375*_data_edgeFineSrc_XY[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_131 = xi_123*-0.125*_data_edgeFineSrc_XY[2*ctr_1 + (2*ctr_2 + 1)*((1 << (coarse_level + 1)) + 1) - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) - 2];
         _data_vertexCoarseDst[ctr_1 + ctr_2*((1 << (coarse_level)) + 2) - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_125 + xi_126 + xi_127 + xi_128 + xi_129 + xi_130 + xi_131;
      }
   }
   for (int ctr_2 = 1; ctr_2 < (1 << (coarse_level)); ctr_2 += 1)
   {
      // left edge
      for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
      {
         const double xi_85 = 0.375*_data_edgeFineSrc_XY[2*ctr_1 + (2*ctr_2 - 1)*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 - 1)) / (2))];
         const double xi_86 = 0.375*_data_edgeFineSrc_X[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_87 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + (2*ctr_2 - 2)*((1 << (coarse_level + 1)) + 1) - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2))];
         const double xi_88 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + (2*ctr_2 - 1)*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) + 1];
         const double xi_89 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + (2*ctr_2 - 2)*((1 << (coarse_level + 1)) + 1) - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) + 1];
         const double xi_90 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + (2*ctr_2 + 1)*((1 << (coarse_level + 1)) + 1) - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2))];
         const double xi_91 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + (2*ctr_2 - 1)*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) + 1];
         const double xi_92 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_93 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + (2*ctr_2 - 2)*((1 << (coarse_level + 1)) + 1) - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) + 1];
         const double xi_94 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_95 = 1.0*xi_107*_data_vertexFineSrc[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 2) - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_96 = xi_107*0.375*_data_edgeFineSrc_Y[2*ctr_1 + (2*ctr_2 - 1)*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 - 1)) / (2))];
         const double xi_97 = xi_107*0.375*_data_edgeFineSrc_Y[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_98 = xi_107*-0.125*_data_edgeFineSrc_Y[2*ctr_1 + (2*ctr_2 - 2)*((1 << (coarse_level + 1)) + 1) - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2))];
         const double xi_99 = xi_107*-0.125*_data_edgeFineSrc_Y[2*ctr_1 + (2*ctr_2 + 1)*((1 << (coarse_level + 1)) + 1) - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2))];
         _data_vertexCoarseDst[ctr_1 + ctr_2*((1 << (coarse_level)) + 2) - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_85 + xi_86 + xi_87 + xi_88 + xi_89 + xi_90 + xi_91 + xi_92 + xi_93 + xi_94 + xi_95 + xi_96 + xi_97 + xi_98 + xi_99;
      }
      // inner triangle
      for (int ctr_1 = 1; ctr_1 < -ctr_2 + (1 << (coarse_level)); ctr_1 += 1)
      {
         const double xi_3 = 0.375*_data_edgeFineSrc_XY[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_4 = 0.375*_data_edgeFineSrc_XY[2*ctr_1 + (2*ctr_2 - 1)*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 - 1)) / (2))];
         const double xi_5 = 0.375*_data_edgeFineSrc_X[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_6 = 0.375*_data_edgeFineSrc_X[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_7 = 0.375*_data_edgeFineSrc_Y[2*ctr_1 + (2*ctr_2 - 1)*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 - 1)) / (2))];
         const double xi_8 = 0.375*_data_edgeFineSrc_Y[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_9 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + (2*ctr_2 + 1)*((1 << (coarse_level + 1)) + 1) - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) - 1];
         const double xi_10 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_11 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + (2*ctr_2 + 1)*((1 << (coarse_level + 1)) + 1) - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) - 2];
         const double xi_12 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + (2*ctr_2 - 2)*((1 << (coarse_level + 1)) + 1) - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2))];
         const double xi_13 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + (2*ctr_2 - 1)*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) + 1];
         const double xi_14 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + (2*ctr_2 - 2)*((1 << (coarse_level + 1)) + 1) - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) + 1];
         const double xi_15 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + (2*ctr_2 - 1)*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 1];
         const double xi_16 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_17 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + (2*ctr_2 + 1)*((1 << (coarse_level + 1)) + 1) - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) - 2];
         const double xi_18 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + (2*ctr_2 + 1)*((1 << (coarse_level + 1)) + 1) - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2))];
         const double xi_19 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + (2*ctr_2 - 1)*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) + 1];
         const double xi_20 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_21 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + (2*ctr_2 - 1)*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 1];
         const double xi_22 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + (2*ctr_2 + 1)*((1 << (coarse_level + 1)) + 1) - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) - 1];
         const double xi_23 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + (2*ctr_2 - 2)*((1 << (coarse_level + 1)) + 1) - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2))];
         const double xi_24 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + (2*ctr_2 + 1)*((1 << (coarse_level + 1)) + 1) - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2))];
         const double xi_25 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + (2*ctr_2 - 2)*((1 << (coarse_level + 1)) + 1) - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) + 1];
         const double xi_26 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) + 1];
         const double xi_27 = _data_vertexFineSrc[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 2) - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         _data_vertexCoarseDst[ctr_1 + ctr_2*((1 << (coarse_level)) + 2) - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_10 + xi_11 + xi_12 + xi_13 + xi_14 + xi_15 + xi_16 + xi_17 + xi_18 + xi_19 + xi_20 + xi_21 + xi_22 + xi_23 + xi_24 + xi_25 + xi_26 + xi_27 + xi_3 + xi_4 + xi_5 + xi_6 + xi_7 + xi_8 + xi_9;
      }
      // diagonal edge
      for (int ctr_1 = -ctr_2 + (1 << (coarse_level)); ctr_1 < -ctr_2 + (1 << (coarse_level)) + 1; ctr_1 += 1)
      {
         const double xi_61 = 0.375*_data_edgeFineSrc_X[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_62 = 0.375*_data_edgeFineSrc_Y[2*ctr_1 + (2*ctr_2 - 1)*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 - 1)) / (2))];
         const double xi_63 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_64 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + (2*ctr_2 - 2)*((1 << (coarse_level + 1)) + 1) - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2))];
         const double xi_65 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + (2*ctr_2 - 1)*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 1];
         const double xi_66 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 2];
         const double xi_67 = -0.125*_data_edgeFineSrc_X[2*ctr_1 + (2*ctr_2 + 1)*((1 << (coarse_level + 1)) + 1) - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) - 2];
         const double xi_68 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + (2*ctr_2 - 1)*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 - 1)) / (2)) - 1];
         const double xi_69 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + (2*ctr_2 - 2)*((1 << (coarse_level + 1)) + 1) - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2))];
         const double xi_70 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + (2*ctr_2 - 2)*((1 << (coarse_level + 1)) + 1) - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) + 1];
         const double xi_71 = 1.0*xi_123*_data_vertexFineSrc[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 2) - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_72 = xi_123*0.375*_data_edgeFineSrc_XY[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 + 1)) / (2)) - 1];
         const double xi_73 = xi_123*0.375*_data_edgeFineSrc_XY[2*ctr_1 + (2*ctr_2 - 1)*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 - 1)) / (2))];
         const double xi_74 = xi_123*-0.125*_data_edgeFineSrc_XY[2*ctr_1 + (2*ctr_2 + 1)*((1 << (coarse_level + 1)) + 1) - (((2*ctr_2 + 1)*(2*ctr_2 + 2)) / (2)) - 2];
         const double xi_75 = xi_123*-0.125*_data_edgeFineSrc_XY[2*ctr_1 + (2*ctr_2 - 2)*((1 << (coarse_level + 1)) + 1) - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) + 1];
         _data_vertexCoarseDst[ctr_1 + ctr_2*((1 << (coarse_level)) + 2) - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_61 + xi_62 + xi_63 + xi_64 + xi_65 + xi_66 + xi_67 + xi_68 + xi_69 + xi_70 + xi_71 + xi_72 + xi_73 + xi_74 + xi_75;
      }
   }
   for (int ctr_2 = (1 << (coarse_level)); ctr_2 < (1 << (coarse_level)) + 1; ctr_2 += 1)
   {
      // top vertex
      for (int ctr_1 = 0; ctr_1 < 1; ctr_1 += 1)
      {
         const double xi_141 = -0.125*_data_edgeFineSrc_XY[2*ctr_1 + (2*ctr_2 - 2)*((1 << (coarse_level + 1)) + 1) - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2))];
         const double xi_142 = -0.125*_data_edgeFineSrc_Y[2*ctr_1 + (2*ctr_2 - 2)*((1 << (coarse_level + 1)) + 1) - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) + 1];
         const double xi_143 = 1.0*xi_135*_data_vertexFineSrc[2*ctr_1 + 2*ctr_2*((1 << (coarse_level + 1)) + 2) - ((2*ctr_2*(2*ctr_2 + 1)) / (2))];
         const double xi_144 = xi_123*0.375*_data_edgeFineSrc_XY[2*ctr_1 + (2*ctr_2 - 1)*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 - 1)) / (2))];
         const double xi_146 = xi_123*-0.125*_data_edgeFineSrc_XY[2*ctr_1 + (2*ctr_2 - 2)*((1 << (coarse_level + 1)) + 1) - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2)) + 1];
         const double xi_145 = xi_107*0.375*_data_edgeFineSrc_Y[2*ctr_1 + (2*ctr_2 - 1)*((1 << (coarse_level + 1)) + 1) - ((2*ctr_2*(2*ctr_2 - 1)) / (2))];
         const double xi_147 = xi_107*-0.125*_data_edgeFineSrc_Y[2*ctr_1 + (2*ctr_2 - 2)*((1 << (coarse_level + 1)) + 1) - (((2*ctr_2 - 2)*(2*ctr_2 - 1)) / (2))];
         _data_vertexCoarseDst[ctr_1 + ctr_2*((1 << (coarse_level)) + 2) - ((ctr_2*(ctr_2 + 1)) / (2))] = xi_141 + xi_142 + xi_143 + xi_144 + xi_145 + xi_146 + xi_147;
      }
   }
   {
      
   }
}


void restrict_2D_macroface_P2_update_vertexdofs(double * RESTRICT _data_edgeFineSrc_X, double * RESTRICT _data_edgeFineSrc_XY, double * RESTRICT _data_edgeFineSrc_Y, double * RESTRICT _data_vertexCoarseDst, double * RESTRICT _data_vertexFineSrc, int64_t coarse_level, double num_neighbor_faces_edge0, double num_neighbor_faces_edge1, double num_neighbor_faces_edge2, double num_neighbor_faces_vertex0, double num_neighbor_faces_vertex1, double num_neighbor_faces_vertex2)
{
    switch( coarse_level )
    {
    case 2:
        restrict_2D_macroface_P2_update_vertexdofs_level_2(_data_edgeFineSrc_X, _data_edgeFineSrc_XY, _data_edgeFineSrc_Y, _data_vertexCoarseDst, _data_vertexFineSrc, num_neighbor_faces_edge0, num_neighbor_faces_edge1, num_neighbor_faces_edge2, num_neighbor_faces_vertex0, num_neighbor_faces_vertex1, num_neighbor_faces_vertex2);
        break;
    case 3:
        restrict_2D_macroface_P2_update_vertexdofs_level_3(_data_edgeFineSrc_X, _data_edgeFineSrc_XY, _data_edgeFineSrc_Y, _data_vertexCoarseDst, _data_vertexFineSrc, num_neighbor_faces_edge0, num_neighbor_faces_edge1, num_neighbor_faces_edge2, num_neighbor_faces_vertex0, num_neighbor_faces_vertex1, num_neighbor_faces_vertex2);
        break;
    case 4:
        restrict_2D_macroface_P2_update_vertexdofs_level_4(_data_edgeFineSrc_X, _data_edgeFineSrc_XY, _data_edgeFineSrc_Y, _data_vertexCoarseDst, _data_vertexFineSrc, num_neighbor_faces_edge0, num_neighbor_faces_edge1, num_neighbor_faces_edge2, num_neighbor_faces_vertex0, num_neighbor_faces_vertex1, num_neighbor_faces_vertex2);
        break;
    case 5:
        restrict_2D_macroface_P2_update_vertexdofs_level_5(_data_edgeFineSrc_X, _data_edgeFineSrc_XY, _data_edgeFineSrc_Y, _data_vertexCoarseDst, _data_vertexFineSrc, num_neighbor_faces_edge0, num_neighbor_faces_edge1, num_neighbor_faces_edge2, num_neighbor_faces_vertex0, num_neighbor_faces_vertex1, num_neighbor_faces_vertex2);
        break;
    case 6:
        restrict_2D_macroface_P2_update_vertexdofs_level_6(_data_edgeFineSrc_X, _data_edgeFineSrc_XY, _data_edgeFineSrc_Y, _data_vertexCoarseDst, _data_vertexFineSrc, num_neighbor_faces_edge0, num_neighbor_faces_edge1, num_neighbor_faces_edge2, num_neighbor_faces_vertex0, num_neighbor_faces_vertex1, num_neighbor_faces_vertex2);
        break;
    case 7:
        restrict_2D_macroface_P2_update_vertexdofs_level_7(_data_edgeFineSrc_X, _data_edgeFineSrc_XY, _data_edgeFineSrc_Y, _data_vertexCoarseDst, _data_vertexFineSrc, num_neighbor_faces_edge0, num_neighbor_faces_edge1, num_neighbor_faces_edge2, num_neighbor_faces_vertex0, num_neighbor_faces_vertex1, num_neighbor_faces_vertex2);
        break;
    case 8:
        restrict_2D_macroface_P2_update_vertexdofs_level_8(_data_edgeFineSrc_X, _data_edgeFineSrc_XY, _data_edgeFineSrc_Y, _data_vertexCoarseDst, _data_vertexFineSrc, num_neighbor_faces_edge0, num_neighbor_faces_edge1, num_neighbor_faces_edge2, num_neighbor_faces_vertex0, num_neighbor_faces_vertex1, num_neighbor_faces_vertex2);
        break;
    case 9:
        restrict_2D_macroface_P2_update_vertexdofs_level_9(_data_edgeFineSrc_X, _data_edgeFineSrc_XY, _data_edgeFineSrc_Y, _data_vertexCoarseDst, _data_vertexFineSrc, num_neighbor_faces_edge0, num_neighbor_faces_edge1, num_neighbor_faces_edge2, num_neighbor_faces_vertex0, num_neighbor_faces_vertex1, num_neighbor_faces_vertex2);
        break;
    case 10:
        restrict_2D_macroface_P2_update_vertexdofs_level_10(_data_edgeFineSrc_X, _data_edgeFineSrc_XY, _data_edgeFineSrc_Y, _data_vertexCoarseDst, _data_vertexFineSrc, num_neighbor_faces_edge0, num_neighbor_faces_edge1, num_neighbor_faces_edge2, num_neighbor_faces_vertex0, num_neighbor_faces_vertex1, num_neighbor_faces_vertex2);
        break;
    case 11:
        restrict_2D_macroface_P2_update_vertexdofs_level_11(_data_edgeFineSrc_X, _data_edgeFineSrc_XY, _data_edgeFineSrc_Y, _data_vertexCoarseDst, _data_vertexFineSrc, num_neighbor_faces_edge0, num_neighbor_faces_edge1, num_neighbor_faces_edge2, num_neighbor_faces_vertex0, num_neighbor_faces_vertex1, num_neighbor_faces_vertex2);
        break;
    case 12:
        restrict_2D_macroface_P2_update_vertexdofs_level_12(_data_edgeFineSrc_X, _data_edgeFineSrc_XY, _data_edgeFineSrc_Y, _data_vertexCoarseDst, _data_vertexFineSrc, num_neighbor_faces_edge0, num_neighbor_faces_edge1, num_neighbor_faces_edge2, num_neighbor_faces_vertex0, num_neighbor_faces_vertex1, num_neighbor_faces_vertex2);
        break;
    case 13:
        restrict_2D_macroface_P2_update_vertexdofs_level_13(_data_edgeFineSrc_X, _data_edgeFineSrc_XY, _data_edgeFineSrc_Y, _data_vertexCoarseDst, _data_vertexFineSrc, num_neighbor_faces_edge0, num_neighbor_faces_edge1, num_neighbor_faces_edge2, num_neighbor_faces_vertex0, num_neighbor_faces_vertex1, num_neighbor_faces_vertex2);
        break;
    case 14:
        restrict_2D_macroface_P2_update_vertexdofs_level_14(_data_edgeFineSrc_X, _data_edgeFineSrc_XY, _data_edgeFineSrc_Y, _data_vertexCoarseDst, _data_vertexFineSrc, num_neighbor_faces_edge0, num_neighbor_faces_edge1, num_neighbor_faces_edge2, num_neighbor_faces_vertex0, num_neighbor_faces_vertex1, num_neighbor_faces_vertex2);
        break;
    default:
        restrict_2D_macroface_P2_update_vertexdofs_level_any(_data_edgeFineSrc_X, _data_edgeFineSrc_XY, _data_edgeFineSrc_Y, _data_vertexCoarseDst, _data_vertexFineSrc, coarse_level, num_neighbor_faces_edge0, num_neighbor_faces_edge1, num_neighbor_faces_edge2, num_neighbor_faces_vertex0, num_neighbor_faces_vertex1, num_neighbor_faces_vertex2);
        break;
    }
}
    

} // namespace generated
} // namespace macroface
} // namespace P2
} // namespace hhg
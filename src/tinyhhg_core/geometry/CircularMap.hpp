#pragma once

#include "core/math/Utility.h"

#include "tinyhhg_core/primitives/Face.hpp"
#include "tinyhhg_core/primitivestorage/SetupPrimitiveStorage.hpp"

#include "GeometryMap.hpp"

namespace hhg {

class CircularMap : public GeometryMap
{
 public:
   CircularMap( const Face& face, const SetupPrimitiveStorage& storage, const Point3D& center, real_t radius )
   : center_( center )
   , radius_( radius )
   {
      // Get edge on boundary
      // TODO: ATTENTION - ONLY ONE EDGE MAY LIE ON THE BOUNDARY
      WALBERLA_ASSERT_EQUAL( face.hasBoundaryEdge(), true );
      WALBERLA_ASSERT_EQUAL( face.edgesOnBoundary.size(), 1 );

      const Edge&   edge   = *storage.getEdge( face.edgesOnBoundary[0] );
      const Vertex& vertex = *storage.getVertex( face.get_vertex_opposite_to_edge( edge.getID() ) );

      Point3D x2, x3;

      x1_ = edge.getCoordinates()[0];
      x2  = vertex.getCoordinates();
      x3  = edge.getCoordinates()[1];

      x2bar_ = x2 - x1_;
      x3bar_ = x3 - x1_;

      s1_       = std::atan2( ( x1_ - center )[1], ( x1_ - center )[0] );
      real_t s3 = std::atan2( ( x3 - center )[1], ( x3 - center )[0] );
      s3bar_    = s3 - s1_;

      if( s3bar_ < -0.5 * walberla::math::PI )
      {
         s3bar_ += 2.0 * walberla::math::PI;
      } else if( s3bar_ > 0.5 * walberla::math::PI )
      {
         s3bar_ -= 2.0 * walberla::math::PI;
      }

      invDet_ = 1.0 / ( x2bar_[0] * x3bar_[1] - x3bar_[0] * x2bar_[1] );
   }

   CircularMap( walberla::mpi::RecvBuffer& recvBuffer )
   {
      recvBuffer >> x1_;
      recvBuffer >> x2bar_;
      recvBuffer >> x3bar_;
      recvBuffer >> center_;
      recvBuffer >> radius_;
      recvBuffer >> s1_;
      recvBuffer >> s3bar_;
      recvBuffer >> invDet_;
   }

   void evalF( const Point3D& x, Point3D& Fx ) const
   {
      real_t tmp0  = -x1_[0];
      real_t tmp1  = 1.0 / ( x2bar_[0] * x3bar_[1] - x3bar_[0] * x2bar_[1] );
      real_t tmp2  = tmp1 * ( tmp0 + x[0] );
      real_t tmp3  = tmp2 * x3bar_[1];
      real_t tmp4  = -x1_[1];
      real_t tmp5  = tmp1 * ( tmp4 + x[1] );
      real_t tmp6  = tmp5 * x3bar_[0];
      real_t tmp7  = tmp3 - tmp6;
      real_t tmp8  = tmp5 * x2bar_[0];
      real_t tmp9  = tmp2 * x2bar_[1];
      real_t tmp10 = tmp8 - tmp9;
      real_t tmp11 = tmp10 * x3bar_[0];
      real_t tmp12 = s1_ + s3bar_ * tmp10;
      real_t tmp13 = -tmp8 + tmp9 + 1;
      real_t tmp14 = ( tmp13 - tmp3 + tmp6 ) / tmp13;
      real_t tmp15 = tmp10 * x3bar_[1];
      Fx[0]        = tmp11 + tmp14 * ( center_[0] + radius_ * cos( tmp12 ) + tmp0 - tmp11 ) + tmp7 * x2bar_[0] + x1_[0];
      Fx[1]        = tmp14 * ( center_[1] + radius_ * sin( tmp12 ) - tmp15 + tmp4 ) + tmp15 + tmp7 * x2bar_[1] + x1_[1];
   }

   void evalDF( const Point3D& x, Matrix2r& DFx ) const
   {
      real_t tmp0  = x2bar_[0] * x3bar_[1];
      real_t tmp1  = x3bar_[0] * x2bar_[1];
      real_t tmp2  = 1.0 / ( tmp0 - tmp1 );
      real_t tmp3  = tmp0 * tmp2;
      real_t tmp4  = -tmp1 * tmp2 + tmp3;
      real_t tmp5  = tmp2 * x2bar_[1];
      real_t tmp6  = tmp2 * x3bar_[1];
      real_t tmp7  = -x1_[0];
      real_t tmp8  = tmp7 + x[0];
      real_t tmp9  = tmp5 * tmp8;
      real_t tmp10 = -x1_[1];
      real_t tmp11 = tmp10 + x[1];
      real_t tmp12 = tmp2 * x2bar_[0];
      real_t tmp13 = tmp11 * tmp12;
      real_t tmp14 = -tmp13 + tmp9 + 1;
      real_t tmp15 = 1.0 / tmp14;
      real_t tmp16 = tmp15 * ( tmp5 - tmp6 );
      real_t tmp17 = tmp13 - tmp9;
      real_t tmp18 = s1_ + s3bar_ * tmp17;
      real_t tmp19 = radius_ * cos( tmp18 );
      real_t tmp20 = center_[0] - tmp17 * x3bar_[0] + tmp19 + tmp7;
      real_t tmp21 = s3bar_ * tmp2 * x2bar_[1];
      real_t tmp22 = radius_ * sin( tmp18 );
      real_t tmp23 = tmp2 * x3bar_[0];
      real_t tmp24 = tmp11 * tmp23 + tmp14 - tmp6 * tmp8;
      real_t tmp25 = tmp15 * tmp24;
      real_t tmp26 = pow( tmp14, -2 );
      real_t tmp27 = tmp2 * tmp24 * tmp26 * x2bar_[1];
      real_t tmp28 = tmp15 * ( -tmp12 + tmp23 );
      real_t tmp29 = s3bar_ * tmp2 * x2bar_[0];
      real_t tmp30 = tmp2 * tmp24 * tmp26 * x2bar_[0];
      real_t tmp31 = center_[1] + tmp10 - tmp17 * x3bar_[1] + tmp22;
      DFx( 0, 0 )  = tmp16 * tmp20 - tmp20 * tmp27 + tmp25 * ( tmp2 * x3bar_[0] * x2bar_[1] + tmp21 * tmp22 ) + tmp4;
      DFx( 0, 1 )  = tmp20 * tmp28 + tmp20 * tmp30 + tmp25 * ( -tmp12 * x3bar_[0] - tmp22 * tmp29 );
      DFx( 1, 0 )  = tmp16 * tmp31 + tmp25 * ( -tmp19 * tmp21 + tmp5 * x3bar_[1] ) - tmp27 * tmp31;
      DFx( 1, 1 )  = tmp25 * ( tmp19 * tmp29 - tmp3 ) + tmp28 * tmp31 + tmp30 * tmp31 + tmp4;
   }

   void evalDFinv( const Point3D& x, Matrix2r& DFxInv ) const
   {
      Matrix2r tmp;
      evalDF( x, tmp );
      real_t invDet = 1.0 / tmp.det();
      DFxInv        = tmp.adj();
      DFxInv *= invDet;
   }

   void serializeSubClass( walberla::mpi::SendBuffer& sendBuffer ) const
   {
      sendBuffer << Type::CIRCULAR;
      sendBuffer << x1_;
      sendBuffer << x2bar_;
      sendBuffer << x3bar_;
      sendBuffer << center_;
      sendBuffer << radius_;
      sendBuffer << s1_;
      sendBuffer << s3bar_;
      sendBuffer << invDet_;
   }

 private:
   Point3D x1_;
   Point3D x2bar_;
   Point3D x3bar_;

   Point3D center_;
   real_t  radius_;
   real_t  s1_;
   real_t  s3bar_;

   real_t invDet_;
};

} // namespace hhg

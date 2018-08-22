#ifndef _MATRIX4X4_H_
#define _MATRIX4X4_H_

#include "vector.h"

namespace dmg { namespace math {

    class matrix4x4
    {
    public:
        matrix4x4() { identity(); }
        ~matrix4x4() {}

        matrix4x4(float m00, float m01, float m02, float m03, 
                  float m10, float m11, float m12, float m13, 
                  float m20, float m21, float m22, float m23, 
                  float m30, float m31, float m32, float m33);

        matrix4x4(const matrix4x4& m);
        float*      get();
        float*      getLinear();

        void        identity();

        matrix4x4   transposed() const; 
        matrix4x4   inversed(); const

        float       determinant();
        vector3     operator*(const vector3& v);
        matrix4x4   operator*(float scalar) const;
    
        matrix4x4   operator*(const matrix4x4 p_m) const;

        void        setTranslate(vector3& vecPos);
        void        setTranslate(float xPos, 
                                 float yPos, 
                                 float zPos);

        void        setRotate(vector3& vecAxis);
        void        setRotate(float xAxis, 
                              float yAxis, 
                              float zAxis);

        void        setScale(vector3& vecScale);
        void        setScale(float xScale, 
                             float yScale, 
                             float zScale);

        vector3     getTranslate();
        vector3     getScale();

        matrix4x4   projectionPerspective(float p_fov, 
                                          float p_aspectRatio, 
                                          float p_near, 
                                          float p_far);

        void        createCameraView(const vector3& p_position, 
                                     const vector3& p_direction, 
                                     const vector3& p_upVector);

    public:
        float       m[4][4];
        float       mat[16];

    };

} }

#endif //_MATRIX4X4_H_
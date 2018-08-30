#ifndef _DMGMATH_H_
#define _DMGMATH_H_

#include <cmath>

namespace dmg { namespace math {

    class vector2
    {
    public:
        vector2() { zero(); }
        ~vector2() {}

        vector2(float p_x, float p_y) : x(p_x), y(p_y) {}
        vector2(const vector2 &v) : x(v.x), y(v.y) {}

        vector2     operator-() const;

        vector2     operator+(const vector2& v) const;
        vector2     operator-(const vector2& v) const;

        float       length() const;
        float       lengthsqr() const;

        vector2     normalized() const;
        void        normalize();

        void        zero();
        float       dot(const vector2& vecA, const vector2& vecB) const;
        float       operator*(const vector2& v) const;

        vector2     operator*(float scalar) const;
        vector2     operator/(float scalar) const;

    public:
        float       x, y;
    };

    class vector3
    {
    public:
        vector3() { zero(); }
        ~vector3() {}

        vector3(float p_x, float p_y, float p_z) : x(p_x), y(p_y), z(p_z) {}
        vector3(const vector3 &v) : x(v.x), y(v.y), z(v.z) {}

        vector3     operator-() const;

        vector3     operator+(const vector3& v) const;
        vector3     operator-(const vector3& v) const;

        float       length() const;
        float       lengthsqr() const;

        vector3     normalized() const; 
        void        normalize(); 

        void        zero();
        float       dot(const vector3& vecA, const vector3& vecB) const; 
        float       operator*(const vector3& v) const;
        vector3     cross(const vector3& v) const;

        vector3     operator*(float scalar) const;
        vector3     operator/(float scalar) const;

        float       x, y, z;
    };

    class vector4
    {
    public:
        vector4() { zero(); }
        ~vector4() {}

        vector4(float p_x, float p_y, float p_z, float p_a) : x(p_x), y(p_y), z(p_z), a(p_a) {}
        vector4(const vector4 &v) : x(v.x), y(v.y), z(v.z), a(v.a) {}

        vector4     operator-() const; //negative

        vector4     operator+(const vector4& v) const;
        vector4     operator-(const vector4& v) const;

        float       length() const;
        float       lengthsqr() const;

        vector4     normalized() const;
        void        normalize();

        void        zero();
        float       dot(const vector4& vecA, const vector4& vecB) const;
        float       operator*(const vector4& v) const;
        vector4     cross(const vector4& v) const;

        vector4     operator*(float scalar) const;
        vector4     operator/(float scalar) const;

        float       x, y, z, a;
    };

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
        const float*      getElements() const;

        void        identity();

        matrix4x4   getTranspose() const; 
        matrix4x4   getInverse() const;

        const float determinant() const;
        vector3     operator*(const vector3& v);
        matrix4x4   operator*(float scalar) const;
    
        matrix4x4   operator*(const matrix4x4 p_m) const;

        void        setTranslate(const vector3& vecPos);
        void        setTranslate(float xPos, 
                                 float yPos, 
                                 float zPos);

        void        setRotate(const vector3& vecAxis);
        void        setRotate(float xAxis, 
                              float yAxis, 
                              float zAxis);

        void        setScale(const vector3& vecScale);
        void        setScale(float xScale, 
                             float yScale, 
                             float zScale);

        vector3     getTranslate();
        vector3     getScale();

        matrix4x4   getProjectionPerspective(float p_fov, 
                                             float p_aspectRatio, 
                                             float p_near, 
                                             float p_far);

        matrix4x4   getProjectionOrthographic(float p_left,   float p_right, 
                                              float p_bottom, float p_top, 
                                              float p_near,   float p_far);

        void        createCameraView(const vector3& p_position, 
                                     const vector3& p_direction, 
                                     const vector3& p_upVector);

        //TODO matrix handling local and world coord AKA attaching to parent
        //TODO matrix handle for EulerAngles rotation
        //TODO matrix handle for Quaternions
        //TODO check all const correctness of every math class

    public:
        float       m[4][4];
        float       mat[16];

    };

#ifndef M_PI
#define M_PI 3.14159265358979323846f
#endif



#define DMG_VEC2 dmg::math::vector2
#define DMG_VEC3 dmg::math::vector3
#define DMG_VEC4 dmg::math::vector4
#define DMG_MAT4 dmg::math::matrix4x4



} }
#endif //_DMGMATH_H_
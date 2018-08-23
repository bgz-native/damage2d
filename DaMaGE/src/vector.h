#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <cmath>

namespace dmg { namespace math {

    class vector2
    {
    public:
        vector2() { zero(); }
        ~vector2() {}

        vector2(float p_x, float p_y) : x(p_x), y(p_y) {}
        vector2(const vector2 &v) : x(v.x), y(v.y) {}

        vector2     operator-() const; //negative,

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

        vector3     operator-() const; //negative

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


#define DMG_VEC2 dmg::math::vector2
#define DMG_VEC3 dmg::math::vector3
#define DMG_VEC4 dmg::math::vector4


#ifndef M_PI
#define M_PI 3.14159265358979323846f
#endif

} }
#endif //_VECTOR_H_
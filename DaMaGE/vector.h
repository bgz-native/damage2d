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

#ifndef M_PI
#define M_PI 3.14159265358979323846f
#endif

} }
#endif //_VECTOR_H_
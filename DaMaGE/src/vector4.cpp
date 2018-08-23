#include "vector.h"

namespace dmg { namespace math {

    vector4 vector4::operator-() const
    {
        return vector4(-x, -y, -z, -a);
    }

    vector4 vector4::operator+(const vector4 & v) const
    {
        return vector4(x + v.x, y + v.y, z + v.z, a + v.a);
    }

    vector4 vector4::operator-(const vector4 & v) const
    {
        return vector4(x - v.x, y - v.y, z - v.z, a - v.a);
    }

    float vector4::length() const
    {
        return sqrt(x*x + y*y + z*z + a*a);
    }

    float vector4::lengthsqr() const
    {
        return x*x + y*y + z*z + a*a;
    }

    vector4 vector4::normalized() const
    {
        vector4 normalized;

        normalized.x = x / length();
        normalized.y = y / length();
        normalized.z = z / length();
        normalized.a = a / length();

        return normalized;
    }

    void vector4::normalize()
    {
        x = x / length();
        y = y / length();
        z = z / length();
        a = a / length();
    }

    void vector4::zero()
    {
        x = y = z = a = 0;
    }

    float vector4::dot(const vector4& vecA, const vector4& vecB) const
    {
        float scalar = 0;
        scalar = (vecA.x * vecB.x) + (vecA.y * vecB.y) + (vecA.z * vecB.z) + (vecA.a * vecB.a);

        return scalar;
    }

    float vector4::operator*(const vector4 & v) const
    {
        float scalar = 0;
        scalar = x*v.x + y*v.y + z*v.z + a*v.a;

        return scalar;
    }

    vector4 vector4::cross(const vector4& v) const
    {
        vector4 c;
        // TODO uninmplemented
        //c.x = (y*v.z) + (z*v.y);
        //c.y = (z*v.x) + (x*v.z);
        //c.z = (x*v.y) + (y*v.x);

        return c;
    }

    vector4 vector4::operator*(float scalar) const
    {
        vector4 scaled;

        scaled.x = x * scalar;
        scaled.y = y * scalar;
        scaled.z = z * scalar;
        scaled.a = a * scalar;

        return scaled;
    }

    vector4 vector4::operator/(float scalar) const
    {
        vector4 scaled;

        scaled.x = x / scalar;
        scaled.y = y / scalar;
        scaled.z = z / scalar;
        scaled.a = a / scalar;

        return scaled;
    }
} }
#include "vector.h"

namespace dmg { namespace math {

    vector3 vector3::operator-() const
    {
        return vector3(-x, -y, -z);
    }

    vector3 vector3::operator+(const vector3 & v) const
    {
        return vector3(x + v.x, y + v.y, z + v.z);
    }

    vector3 vector3::operator-(const vector3 & v) const
    {
        return vector3(x - v.x, y - v.y, z - v.z);
    }

    float vector3::length() const
    {
        return sqrt(x*x + y*y + z*z);
    }

    float vector3::lengthsqr() const
    {
        return x*x + y*y + z*z;
    }

    vector3 vector3::normalized() const
    {
        vector3 normalized;

        normalized.x = x / length();
        normalized.y = y / length();
        normalized.z = z / length();

        return normalized;
    }

    void vector3::normalize()
    {
        x = x / length();
        y = y / length();
        z = z / length();
    }

    void vector3::zero()
    {
        x = y = z = 0;
    }

    float vector3::dot(const vector3& vecA, const vector3& vecB) const
    {
        float scalar = 0;
        scalar = (vecA.x * vecB.x) + (vecA.y * vecB.y) + (vecA.z * vecB.z);

        return scalar;

    }

    float vector3::operator*(const vector3 & v) const
    {
        float scalar = 0;
        scalar = x*v.x + y*v.y + z*v.z;

        return scalar;
    }

    vector3 vector3::cross(const vector3& v) const
    {
        vector3 c;

        //xyzzy 
        c.x = (y*v.z) + (z*v.y);
        c.y = (z*v.x) + (x*v.z);
        c.z = (x*v.y) + (y*v.x);

        return c;
    }

    vector3 vector3::operator*(float scalar) const
    {
        vector3 scaled;

        scaled.x = x * scalar;
        scaled.y = y * scalar;
        scaled.z = z * scalar;

        return scaled;
    }

    vector3 vector3::operator/(float scalar) const
    {
        vector3 scaled;

        scaled.x = x / scalar;
        scaled.y = y / scalar;
        scaled.z = z / scalar;

        return scaled;
    }

} }
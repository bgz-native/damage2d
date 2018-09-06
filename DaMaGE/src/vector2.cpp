#include "dmgmath.h"

namespace dmg { namespace math {

    vector2 vector2::operator-() const
    {
        return vector2(-x, -y);
    }

    vector2 vector2::operator+(const vector2 & v) const
    {
        return vector2(x + v.x, y + v.y);
    }

    vector2 vector2::operator-(const vector2 & v) const
    {
        return vector2(x - v.x, y - v.y);
    }

    float vector2::length() const
    {
        return sqrt(x*x + y*y);
    }

    float vector2::lengthsqr() const
    {
        return (x*x + y*y);
    }

    vector2 vector2::normalized() const
    {
        vector2 normalized;

        normalized.x = x / length();
        normalized.y = y / length();

        return normalized;
    }

    void vector2::normalize()
    {
        x = x / length();
        y = y / length();
    }

    void vector2::zero()
    {
        x = y = 0;
    }

    float vector2::dot(const vector2& vecA, const vector2& vecB) const
    {
        float scalar = 0;
        scalar = (vecA.x * vecB.x) + (vecA.y * vecB.y);

        return scalar;
    }

    float vector2::operator*(const vector2 & v) const
    {
        float scalar = 0;
        scalar = x*v.x + y*v.y;

        return scalar;
    }

    vector2 vector2::operator*(float scalar) const
    {
        vector2 scaled;

        scaled.x = x * scalar;
        scaled.y = y * scalar;

        return scaled;
    }

    vector2 vector2::operator/(float scalar) const
    {
        vector2 scaled;

        scaled.x = x / scalar;
        scaled.y = y / scalar;

        return scaled;
    }

} }


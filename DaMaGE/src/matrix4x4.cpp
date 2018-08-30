#include "DMGMath.h"
#include <cstring>

#define DEGREES_TO_RADIANS(degrees)((M_PI * degrees)/180)

namespace dmg { namespace math {

    matrix4x4::matrix4x4(float m00, float m01, float m02, float m03, 
                         float m10, float m11, float m12, float m13, 
                         float m20, float m21, float m22, float m23, 
                         float m30, float m31, float m32, float m33)
    {
        m[0][0] = m00; m[0][1] = m01; m[0][2] = m02; m[0][3] = m03;
        m[1][0] = m10; m[1][1] = m11; m[1][2] = m12; m[1][3] = m13;
        m[2][0] = m20; m[2][1] = m21; m[2][2] = m22; m[2][3] = m23;
        m[3][0] = m30; m[3][1] = m31; m[3][2] = m32; m[3][3] = m33;
    }

    matrix4x4::matrix4x4(const matrix4x4& p_m)
    {
        memcpy(&m[0][0], &p_m.m[0][0], sizeof(float) * 16); 
    }

    const float* matrix4x4::getElements() const
    {
        return m[0];
    }

    void matrix4x4::identity()
    {
        memset(m, 0, sizeof(m));
        m[0][0] = m[1][1] = m[2][2] = m[3][3] = 1.0f;
    }

    matrix4x4 matrix4x4::getTranspose() const
    {
        matrix4x4 t;

        t.m[0][0] = m[0][0]; t.m[1][0] = m[0][1]; t.m[2][0] = m[0][2]; t.m[3][0] = m[0][3];
        t.m[0][1] = m[1][0]; t.m[1][1] = m[1][1]; t.m[2][1] = m[1][2]; t.m[3][1] = m[1][3];
        t.m[0][2] = m[2][0]; t.m[1][2] = m[2][1]; t.m[2][2] = m[2][2]; t.m[3][2] = m[2][3];
        t.m[0][3] = m[3][0]; t.m[1][3] = m[3][1]; t.m[2][3] = m[3][2]; t.m[3][3] = m[3][3];

        return t;
    }

    matrix4x4 matrix4x4::getInverse() const
    {
        matrix4x4 iv;

        float dm = determinant();

        if (dm != 0)
        {
            float dmInv = 1 / dm;

            iv.m[0][0] =    m[1][1] * m[2][2] * m[3][3] -
                            m[1][1] * m[2][3] * m[3][2] -
                            m[2][1] * m[1][2] * m[3][3] +
                            m[2][1] * m[1][3] * m[3][2] +
                            m[3][1] * m[1][2] * m[2][3] -
                            m[3][1] * m[1][3] * m[2][2] ;

            iv.m[1][0] =   -m[1][0] * m[2][2] * m[3][3] +
                            m[1][0] * m[2][3] * m[3][2] +
                            m[2][0] * m[1][2] * m[3][3] -
                            m[2][0] * m[1][3] * m[3][2] -
                            m[3][0] * m[1][2] * m[2][3] +
                            m[3][0] * m[1][3] * m[2][2] ;

            iv.m[2][0] =    m[1][0] * m[2][1] * m[3][3] -
                            m[1][0] * m[2][3] * m[3][1] -
                            m[2][0] * m[1][1] * m[3][3] +
                            m[2][0] * m[1][3] * m[3][1] +
                            m[3][0] * m[1][1] * m[2][3] -
                            m[3][0] * m[1][3] * m[2][1] ;

            iv.m[3][0] =   -m[1][0] * m[2][1] * m[3][2] +
                            m[1][0] * m[2][2] * m[3][1] +
                            m[2][0] * m[1][1] * m[3][2] -
                            m[2][0] * m[1][2] * m[3][1] -
                            m[3][0] * m[1][1] * m[2][2] +
                            m[3][0] * m[1][2] * m[2][1] ;

            iv.m[0][1] =   -m[0][1] * m[2][2] * m[3][3] +
                            m[0][1] * m[2][3] * m[3][2] +
                            m[2][1] * m[0][2] * m[3][3] -
                            m[2][1] * m[0][3] * m[3][2] -
                            m[3][1] * m[0][2] * m[2][3] +
                            m[3][1] * m[0][3] * m[2][2] ;

            iv.m[1][1] =    m[0][0] * m[2][2] * m[3][3] -
                            m[0][0] * m[2][3] * m[3][2] -
                            m[2][0] * m[0][2] * m[3][3] +
                            m[2][0] * m[0][3] * m[3][2] +
                            m[3][0] * m[0][2] * m[2][3] -
                            m[3][0] * m[0][3] * m[2][2];

            iv.m[2][1] =   -m[0][0] * m[2][1] * m[3][3] +
                            m[0][0] * m[2][3] * m[3][1] +
                            m[2][0] * m[0][1] * m[3][3] -
                            m[2][0] * m[0][3] * m[3][1] -
                            m[3][0] * m[0][1] * m[2][3] +
                            m[3][0] * m[0][3] * m[2][1] ;

            iv.m[3][1] =    m[0][0] * m[2][1] * m[3][2] -
                            m[0][0] * m[2][2] * m[3][1] -
                            m[2][0] * m[0][1] * m[3][2] +
                            m[2][0] * m[0][2] * m[3][1] +
                            m[3][0] * m[0][1] * m[2][2] -
                            m[3][0] * m[0][2] * m[2][1] ;

            iv.m[0][2] =    m[0][1] * m[1][2] * m[3][3] -
                            m[0][1] * m[1][3] * m[3][2] -
                            m[1][1] * m[0][2] * m[3][3] +
                            m[1][1] * m[0][3] * m[3][2] +
                            m[3][1] * m[0][2] * m[1][3] -
                            m[3][1] * m[0][3] * m[1][2] ;

            iv.m[1][2] =   -m[0][0] * m[1][2] * m[3][3] +
                            m[0][0] * m[1][3] * m[3][2] +
                            m[1][0] * m[0][2] * m[3][3] -
                            m[1][0] * m[0][3] * m[3][2] -
                            m[3][0] * m[0][2] * m[1][3] +
                            m[3][0] * m[0][3] * m[1][2] ;

            iv.m[2][2] =    m[0][0] * m[1][1] * m[3][3] -
                            m[0][0] * m[1][3] * m[3][1] -
                            m[1][0] * m[0][1] * m[3][3] +
                            m[1][0] * m[0][3] * m[3][1] +
                            m[3][0] * m[0][1] * m[1][3] -
                            m[3][0] * m[0][3] * m[1][1] ;

            iv.m[3][2] =   -m[0][0] * m[1][1] * m[3][2] +
                            m[0][0] * m[1][2] * m[3][1] +
                            m[1][0] * m[0][1] * m[3][2] -
                            m[1][0] * m[0][2] * m[3][1] -
                            m[3][0] * m[0][1] * m[1][2] +
                            m[3][0] * m[0][2] * m[1][1] ;

            iv.m[0][3] =   -m[0][1] * m[1][2] * m[2][3] +
                            m[0][1] * m[1][3] * m[2][2] +
                            m[1][1] * m[0][2] * m[2][3] -
                            m[1][1] * m[0][3] * m[2][2] -
                            m[2][1] * m[0][2] * m[1][3] +
                            m[2][1] * m[0][3] * m[1][2] ;

            iv.m[1][3] =    m[0][0] * m[1][2] * m[2][3] -
                            m[0][0] * m[1][3] * m[2][2] -
                            m[1][0] * m[0][2] * m[2][3] +
                            m[1][0] * m[0][3] * m[2][2] +
                            m[2][0] * m[0][2] * m[1][3] -
                            m[2][0] * m[0][3] * m[1][2] ;

            iv.m[2][3] =   -m[0][0] * m[1][1] * m[2][3] +
                            m[0][0] * m[1][3] * m[2][1] +
                            m[1][0] * m[0][1] * m[2][3] -
                            m[1][0] * m[0][3] * m[2][1] -
                            m[2][0] * m[0][1] * m[1][3] +
                            m[2][0] * m[0][3] * m[1][1] ;

            iv.m[3][3] =    m[0][0] * m[1][1] * m[2][2] -
                            m[0][0] * m[1][2] * m[2][1] -
                            m[1][0] * m[0][1] * m[2][2] +
                            m[1][0] * m[0][2] * m[2][1] +
                            m[2][0] * m[0][1] * m[1][2] -
                            m[2][0] * m[0][2] * m[1][1] ;

            for (int row = 0; row < 4; row++)
            {
                for (int column = 0; column < 4; column++)
                {
                    iv.m[row][column] = iv.m[row][column] * dmInv;
                }
            }

        }

        return iv;
    }

    const float matrix4x4::determinant() const
    {
        return  m[0][0] * ( m[1][1] * ((m[2][2] * m[3][3]) - (m[2][3] * m[3][2])) + m[1][2] * ((m[2][3] * m[3][1]) - (m[2][1] * m[3][3])) + m[1][3] * ((m[2][1] * m[3][2]) - (m[2][2] * m[3][1])))
              - m[0][1] * ( m[1][0] * ((m[2][2] * m[3][3]) - (m[2][3] * m[3][2])) + m[1][2] * ((m[2][3] * m[3][0]) - (m[2][0] * m[3][3])) + m[1][3] * ((m[2][0] * m[3][2]) - (m[2][2] * m[3][0])))
              + m[0][2] * ( m[1][0] * ((m[2][1] * m[3][3]) - (m[2][3] * m[3][1])) + m[1][1] * ((m[2][3] * m[3][0]) - (m[2][0] * m[3][3])) + m[1][3] * ((m[2][0] * m[3][1]) - (m[2][1] * m[3][0])))
              - m[0][3] * ( m[1][0] * ((m[2][1] * m[3][2]) - (m[2][2] * m[3][1])) + m[1][1] * ((m[2][2] * m[3][0]) - (m[2][0] * m[3][2])) + m[1][2] * ((m[2][0] * m[3][1]) - (m[2][1] * m[3][0])));
    }


    vector3 matrix4x4::operator*(const vector3& v)
    {
        vector3 result;
    
        float vw = 1.0f;

        result.x = (m[0][0] * v.x) + (m[0][1] * v.y) + (m[0][2] * v.z) + (m[0][3] * vw);
        result.y = (m[1][0] * v.x) + (m[1][1] * v.y) + (m[1][2] * v.z) + (m[1][3] * vw);
        result.z = (m[2][0] * v.x) + (m[2][1] * v.y) + (m[2][2] * v.z) + (m[2][3] * vw);
        //rv.w = 1;

        return result;
    }


    matrix4x4 matrix4x4::operator*(float scalar) const
    {
        matrix4x4 result;

        for (int row = 0; row < 4; row++)
        {
            for (int column = 0; column < 4; column++)
            {
                result.m[row][column] = m[row][column] * scalar;
            }
        }

        return result;
    }

    matrix4x4 matrix4x4::operator*(const matrix4x4 p_m) const
    {
        matrix4x4 result;

        for (int row = 0; row < 4; row++) 
        {
            for (int column = 0; column < 4; column++)
            {
                result.m[row][column] = (m[row][0] * p_m.m[0][column]) + 
                                        (m[row][1] * p_m.m[1][column]) +
                                        (m[row][2] * p_m.m[2][column]) +
                                        (m[row][3] * p_m.m[3][column]) ;
            }
        }

        return result;
    }

    void matrix4x4::setTranslate(const vector3& vecPos)
    {
        setTranslate(vecPos.x, vecPos.y, vecPos.z);
    }

    void matrix4x4::setTranslate(float xPos, float yPos, float zPos)
    {
        m[3][0] = xPos;
        m[3][1] = yPos;
        m[3][2] = zPos;
    }

    void matrix4x4::setRotate(const vector3& vecAxis)
    {
        return setRotate(vecAxis.x, vecAxis.y, vecAxis.z);
    }

    void matrix4x4::setRotate(float xAxis, float yAxis, float zAxis)
    {
        matrix4x4 mrx, mry, mrz;

        float xAxisRad, yAxisRad, zAxisRad;

        xAxisRad = DEGREES_TO_RADIANS(xAxis);
        yAxisRad = DEGREES_TO_RADIANS(yAxis);
        zAxisRad = DEGREES_TO_RADIANS(zAxis);

        mrx.m[1][1] =     cosf(xAxisRad);        mrx.m[1][2] =      sinf(xAxisRad);
        mrx.m[2][1] = 0 - sinf(xAxisRad);        mrx.m[2][2] =      cosf(xAxisRad);


        mry.m[0][0] =     cosf(yAxisRad);        mry.m[0][2] =  0 - sinf(yAxisRad);
        mry.m[2][0] =     sinf(yAxisRad);        mry.m[2][2] =      cosf(yAxisRad);


        mrz.m[0][0] =     cosf(zAxisRad);        mrz.m[0][1] =      sinf(zAxisRad);
        mrz.m[1][0] = 0 - sinf(zAxisRad);        mrz.m[1][1] =      cosf(zAxisRad);

        *this = *this * mrx * mry * mrz;
    }

    void matrix4x4::setScale(const vector3& vecScale)
    {
        setScale(vecScale.x, vecScale.y, vecScale.z);
    }

    void matrix4x4::setScale(float xScale, float yScale, float zScale)
    {
        m[0][0] = xScale;
        m[1][1] = yScale;
        m[2][2] = zScale;
    }

    vector3 matrix4x4::getTranslate()
    {
        return vector3(m[3][0], m[3][1], m[3][2]);
    }

    vector3 matrix4x4::getScale()
    {
        return vector3(m[0][0], m[1][1], m[2][2]);
    }

    matrix4x4 matrix4x4::getProjectionPerspective(float p_fov, float p_aspectRatio, float p_near, float p_far)
    {
        matrix4x4 proj;

        float fovRads = DEGREES_TO_RADIANS(p_fov);

        // X and Y 
        proj.m[0][0] = p_aspectRatio / tanf(fovRads * 0.5f);
        proj.m[1][1] = 1.0f / tanf(fovRads * 0.5f);

        // Z coordinates -1 near, +1 far
        proj.m[2][2] = (p_near + p_far) / (p_near - p_far);
        proj.m[3][2] = (2 * p_near * p_far) / (p_near - p_far);

        // [x, y, z, -z] division becomes [-x/z -y/z -1] 
        proj.m[2][3] = -1.0f;

        //the identity has it as 1.
        proj.m[3][3] = 0.0f;

        return proj;
    }

    matrix4x4 matrix4x4::getProjectionOrthographic(float p_left, float p_right, float p_bottom, float p_top, float p_near, float p_far)
    {
        matrix4x4 ortho;

        ortho.m[0][0] = 2.0f / (p_right - p_left  );
        ortho.m[1][1] = 2.0f / (p_top   - p_bottom);
        ortho.m[2][2] = 2.0f / (p_far   - p_near  );

        ortho.m[3][0] = -(p_right + p_left  ) / (p_right - p_left  );
        ortho.m[3][1] = -(p_top   + p_bottom) / (p_top   - p_bottom);
        ortho.m[3][2] = -(p_far   + p_near  ) / (p_far   - p_near  );
        ortho.m[3][3] = 1.0f;

        return ortho;
    }

    void matrix4x4::createCameraView(const vector3& p_position, const vector3& p_view, const vector3& p_upVector)
    {
#if 0 //disabling temporarily until proven working
        vector3 cameraR, cameraU;

        cameraR = p_view.cross(p_upVector).normalized();
        cameraU = cameraR.cross(p_view);

        m[0][0] = cameraR.x; m[0][1] = cameraR.y; m[0][2] = cameraR.z; m[0][3] = 0;
        m[1][0] = cameraU.x; m[1][1] = cameraU.y; m[1][2] = cameraU.z; m[1][3] = 0;
        m[2][0] = p_view.x;  m[2][1] = p_view.y;  m[2][2] = p_view.z;  m[2][3] = 0;
        m[3][0] = 0;         m[3][1] = 0;         m[3][2] = 0;         m[3][3] = 1.0f;
#endif
    }


} }









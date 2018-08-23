#ifndef _SHADER_H_
#define _SHADER_H_

#include "file.h"
#include "matrix4x4.h"
#include <GL/glew.h>

namespace dmg { namespace graphics {

    class Shader
    {
    public:
        Shader(const char* vertPath, const char* fragPath);
        ~Shader();

        void enable() const;
        void disable() const;


        void setUniform1f(const GLchar* name, float value);
        void setUniform1i(const GLchar* name, int value);

        void setUniform2f(const GLchar* name, const DMG_VEC2& vector);
        void setUniform3f(const GLchar* name, const DMG_VEC3& vector);
        void setUniform4f(const GLchar* name, const DMG_VEC4& vector);

        void setUniformMat4(const GLchar* name, const DMG_MAT4& mat4);

    private:
        GLuint load();
        GLint getUniformLocation(const GLchar* name);

        GLuint getID() { return m_ShaderID; }

    private:
        GLuint m_ShaderID;
        const char *m_VertPath, *m_FragPath;

    };

} }

#endif //_SHADER_H_
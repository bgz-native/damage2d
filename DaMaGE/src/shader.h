#ifndef _SHADER_H_
#define _SHADER_H_

#include "file.h"
#include <GL/glew.h>

namespace dmg { namespace graphics {

    class Shader
    {
    public:
        Shader(const char* vertPath, const char* fragPath);
        ~Shader();

        void enable() const;
        void disable() const;

    private:
        GLuint load();

    private:
        GLuint m_ShaderID;
        const char *m_VertPath, *m_FragPath;

    };

} }

#endif //_SHADER_H_
#ifndef _BUFFER_H_
#define _BUFFER_H_

#include <GL/glew.h>

namespace dmg { namespace graphics {

    class Buffer
    {
    public:
        Buffer(GLfloat* data, GLsizei count, GLuint componentCount);
        ~Buffer();

        void bind() const;
        void unbind() const;

        GLuint getComponentCount() const { return m_ComponentCount; }

    private:
        GLuint m_BufferID;
        GLuint m_ComponentCount;
    };

} }
#endif //_BUFFER_H_
#ifndef _INDEXBUFFER_H_
#define _INDEXBUFFER_H_

#include <GL/glew.h>

namespace dmg { namespace graphics {

    class IndexBuffer
    {
    public:
        IndexBuffer(GLushort* data, GLsizei count);

        void bind() const;
        void unbind() const;

        GLuint getCount() const { return m_Count; }

    private:
        GLuint m_BufferID;
        GLuint m_Count;
    };

} }
#endif //_INDEXBUFFER_H_
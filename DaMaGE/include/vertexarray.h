#ifndef _VERTEXARRAT_H_
#define _VERTEXARRAT_H_

#include <GL/glew.h>
#include <vector>
#include "buffer.h"

namespace dmg { namespace graphics {

    class VertexArray
    {
    public:
        VertexArray();
        ~VertexArray();

        void addBuffer(Buffer* buffer, GLuint index);
        void bind() const;
        void unbind() const;

    private:
        GLuint m_ArrayID;
        std::vector<Buffer*> m_Buffers;

    };

} }
#endif// _VERTEXARRAT_H_
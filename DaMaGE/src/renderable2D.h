#ifndef _RENDERABLE2D_H_
#define _RENDERABLE2D_H_

#include "DMGMath.h"
#include "buffer.h"
#include "indexbuffer.h"
#include "vertexarray.h"
#include "shader.h"

namespace dmg { namespace graphics {

    class Renderable2D
    {
    public:
        Renderable2D(DMG_VEC3 position, DMG_VEC2 size, DMG_VEC4 color, Shader& shader);
        virtual ~Renderable2D();

        const VertexArray* getVao()   const { return m_vao;    }
        const IndexBuffer* getIbo()   const { return m_ibo;    }

        const DMG_VEC3& getPosition() const { return m_Pos;    }
        const DMG_VEC2& getSize()     const { return m_Size;   }
        const DMG_VEC4& getColor()    const { return m_Color;  }

        Shader& getShader()           const { return m_Shader; }
        
    protected:
        VertexArray* m_vao;
        IndexBuffer* m_ibo;

        DMG_VEC3 m_Pos;
        DMG_VEC2 m_Size;
        DMG_VEC4 m_Color;

        Shader& m_Shader;

    };


} }
#endif //_RENDERABLE2D_H_
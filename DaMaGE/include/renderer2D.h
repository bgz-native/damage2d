#ifndef _RENDERER2D_H_
#define _RENDERER2D_H_

#include <deque>

#include "DMGMath.h"
#include "buffer.h"
#include "indexbuffer.h"
#include "vertexarray.h"
#include "shader.h"

namespace dmg { namespace graphics {

    class Renderable2D
    {
    public:
        Renderable2D(DMG_VEC3 position, 
                     DMG_VEC2 size, 
                     DMG_VEC4 color, 
                     Shader& shader);

        virtual ~Renderable2D();

        const VertexArray* getVao()   const { return m_vao;    }
        const IndexBuffer* getIbo()   const { return m_ibo;    }
                                                              
        const DMG_VEC3& getPosition() const { return m_Pos;    }
        const DMG_VEC2& getSize()     const { return m_Size;   }
        const DMG_VEC4& getColor()    const { return m_Color;  }

        Shader& getShader()           const { return m_Shader; }

    protected:
        VertexArray* m_vao;
        IndexBuffer*  m_ibo;

        DMG_VEC3 m_Pos;
        DMG_VEC2 m_Size;
        DMG_VEC4 m_Color;

        Shader& m_Shader;
    };


    class Renderer2D
    {
    protected:
        virtual void submit(const Renderable2D* renderable) = 0;
        virtual void flush() = 0;
    };


    class SimpleRenderer2D : public Renderer2D
    {
    public:
        void submit(const Renderable2D* renderable) override;
        void flush() override;

    private:
        std::deque<const Renderable2D*> m_RenderQueue;
        DMG_MAT4 m_ModelMat;
    };


    class DefaultRenderer2D : public Renderer2D
    {
    public:
        void submit(const Renderable2D* renderable) override;
        void flush() override;

    private:
        VertexArray m_vao;
        IndexBuffer* m_ibo;
        GLsizei m_IndexCount;
        GLuint m_BufferObject;
    };



    struct VertexData
    {
        DMG_VEC3 vertex;
        DMG_VEC4 color;
    };

}}

#define RENDERER_MAX_SPRITES    10000
#define RENDERER_VERTEX_SIZE    sizeof(VertexData)
#define RENDERER_SPRITE_SIZE    RENDERER_VERTEX_SIZE * 4
#define RENDERER_BUFFER_SIZE    RENDERER_SPRITE_SIZE * RENDERER_MAX_SPRITES
#define RENDERER_INDICES_SIZE   RENDERER_MAX_SPRITES * 6

#endif //_RENDERER2D_H_
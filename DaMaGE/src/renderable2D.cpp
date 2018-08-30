#include "Renderable2D.h"

#define LOCATION_0 0
#define LOCATION_1 1

namespace dmg { namespace graphics {

    Renderable2D::Renderable2D(DMG_VEC3 position, DMG_VEC2 size, DMG_VEC4 color, Shader& shader)
        : m_Pos(position), m_Size(size), m_Color(color), m_Shader(shader)
    {
        m_vao = new VertexArray();

        GLfloat vertices[] =
        {
            0, 0, 0,
            0, size.y, 0,
            size.x, size.y, 0,
            size.x, 0, 0
        };

        GLushort indices[] = 
        { 
            0, 1, 2, 
            2, 3, 0 
        };

  
        GLfloat colors[] = 
        {
            color.x, color.y, color.z, color.a,
            color.x, color.y, color.z, color.a,
            color.x, color.y, color.z, color.a,
            color.x, color.y, color.z, color.a
        };

        GLfloat fixedVertices[] =
        {
            0, 0, 0,
            0, 3, 0,
            8, 3, 0,
            8, 0, 0
        };

        GLfloat fixedColor[] =
        {
            1, 0, 1, 1,
            1, 1, 0, 1,
            0, 1, 1, 1,
            1, 0, 1, 1
        };

        m_ibo = new IndexBuffer(indices, 6);

        m_vao->addBuffer(new Buffer(vertices, 4 * 3, 3), LOCATION_0);
        m_vao->addBuffer(new Buffer(colors, 4 * 4, 4), LOCATION_1);

    }

    Renderable2D::~Renderable2D()
    {
        delete m_ibo;
        delete m_vao;
    }

}}

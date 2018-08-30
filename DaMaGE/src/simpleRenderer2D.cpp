#include "simpleRenderer2D.h"
#include "DMGMath.h"

namespace dmg { namespace graphics {

    void SimpleRenderer2D::submit(const Renderable2D* renderable)
    {
        m_RenderQueue.push_back(renderable);
    }

    void SimpleRenderer2D::flush()
    {
        while (!m_RenderQueue.empty())
        {
            const Renderable2D* renderable = m_RenderQueue.front();
            renderable->getVao()->bind();
            renderable->getIbo()->bind();

            m_ModelMat.setTranslate(renderable->getPosition());
            renderable->getShader().setUniformMat4("u_ModelMat", m_ModelMat);

            glDrawElements(GL_TRIANGLES, renderable->getIbo()->getCount(), GL_UNSIGNED_SHORT, nullptr);

            renderable->getIbo()->unbind();
            renderable->getVao()->unbind();

            m_RenderQueue.pop_front();
        }
    }

}}
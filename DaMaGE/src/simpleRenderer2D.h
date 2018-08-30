#ifndef _SIMPLERENDERER2D_H_
#define _SIMPLERENDERER2D_H_

#include <deque>
#include "renderer2D.h"

namespace dmg { namespace graphics {

    class SimpleRenderer2D : public Renderer2D
    {
    public:
        void submit(const Renderable2D* renderable) override;
        void flush() override;

    private:
        std::deque<const Renderable2D*> m_RenderQueue;
        DMG_MAT4 m_ModelMat;
    };

}}
#endif //_SIMPLERENDERER2D_H_
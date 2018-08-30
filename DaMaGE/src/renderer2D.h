#ifndef _RENDERER2D_H_
#define _RENDERER2D_H_

#include "renderable2D.h"

namespace dmg { namespace graphics {

    class Renderer2D
    {
    protected:
        virtual void submit(const Renderable2D* renderable) = 0;
        virtual void flush() = 0;

    };

}}
#endif //_RENDERER2D_H_
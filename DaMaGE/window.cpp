#include "window.h"

namespace dmg
{
	namespace graphics
	{
		Window::Window(const char* name, int width, int height)
		{
			m_name = name;
			m_width = width;
			m_height = height;
		}

		Window::~Window()
		{

		}

		void Window::update() const
		{

		}

	}
}
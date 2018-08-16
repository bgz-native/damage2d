#ifndef _WINDOW_H_
#define _WINDOW_H_

#include "common.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>


namespace dmg
{
	namespace graphics
	{
		class Window
		{
		public:
			Window(const char* name, int width, int height);
			~Window();
			void update();
			int isRunning() const;
			void clear() const;

		private:
			int start();

		private:
			const char* m_name;
			int m_width, m_height;

			GLFWwindow* m_window;
			bool m_isRunning;

		};
	}
}


#endif //_WINDOW_H_
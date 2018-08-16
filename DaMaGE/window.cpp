#include "window.h"

namespace dmg
{
	namespace graphics
	{
		void windowResize(GLFWwindow* window, int width, int height);

		Window::Window(const char* name, int width, int height)
		{
			m_name = name;
			m_width = width;
			m_height = height;
			m_isRunning = true;

			if (start() == -1)
			{
				glfwTerminate();
			}
		}

		Window::~Window()
		{
			glfwTerminate();
		}

		int Window::start()
		{
			if (!glfwInit())
			{
				printf("GLFW Init Error");
				return -1;
			}

			m_window = glfwCreateWindow(m_width, m_height, m_name, 0, 0);

			if (!m_window)
			{
				printf("Failed Windows Init");
				return -1;
			}

			glfwMakeContextCurrent(m_window);
			glfwSetWindowSizeCallback(m_window, windowResize);



            // context must be created before initializing glew
            if (glewInit() != GLEW_OK)
            {
                printf("Failed GLEW Init");
                return -1;
            }

            printf("OpenGL %s", glGetString(GL_VERSION));
			return 0;

		}

		void Window::update()
		{
			glfwPollEvents();
			glfwGetFramebufferSize(m_window, &m_width, &m_height);
			glViewport(0, 0, m_width, m_height);
			glfwSwapBuffers(m_window);
		}

		int Window::isRunning() const
		{
			return (!glfwWindowShouldClose(m_window));
		}

		void Window::clear() const
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		void windowResize(GLFWwindow* window, int width, int height)
		{
			glViewport(0, 0, width, height);
		}

	}
}
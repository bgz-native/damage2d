#include "window.h"

namespace dmg { namespace graphics {
	
    // CALLBACKS
    void window_resize(GLFWwindow* window, int width, int height)
    {
        glViewport(0, 0, width, height);
    }

    void key_callback(GLFWwindow * window, int key, int scancode, int action, int mods)
    {
        Window* thisWindow = (Window*)glfwGetWindowUserPointer(window);
        thisWindow->m_Keys[key] = action != GLFW_RELEASE;
    }

    static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
    {
        Window* thisWindow = (Window*)glfwGetWindowUserPointer(window);
        thisWindow->m_MouseButtons[button] = action != GLFW_RELEASE;
    }

    static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
    {
        Window* thisWindow = (Window*)glfwGetWindowUserPointer(window);
        thisWindow->mx = xpos;
        thisWindow->my = ypos;
    }

    // MAIN FUNCTIONS
	Window::Window(const char* name, int width, int height)
	{
		m_Name = name;
		m_Width = width;
		m_Height = height;
		m_isRunning = true;

		if (start() == DMG_ERROR)
		{
			glfwTerminate();
		}

        for (int i = 0; i < MAX_KEYS; i++)
        {
            m_Keys[i] = false;
        }

        for (int i = 0; i < MAX_MOUSEBUTTONS; i++)
        {
            m_MouseButtons[i] = false;
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
			printf("GLFW Init Error\n");
			return DMG_ERROR;
		}

		m_Window = glfwCreateWindow(m_Width, m_Height, m_Name, 0, 0);

		if (!m_Window)
		{
			printf("Failed Windows Init\n");
			return DMG_ERROR;
		}

		glfwMakeContextCurrent(m_Window);
        glfwSetWindowUserPointer(m_Window, this);

		glfwSetWindowSizeCallback(m_Window, window_resize);
        glfwSetKeyCallback(m_Window, key_callback);
        glfwSetMouseButtonCallback(m_Window, mouse_button_callback);
        glfwSetCursorPosCallback(m_Window, cursor_position_callback);

        // context must be created before initializing glew
        if (glewInit() != GLEW_OK)
        {
            printf("Failed GLEW Init\n");
            return DMG_ERROR;
        }

        printf("OpenGL %s\n", glGetString(GL_VERSION));

		return 0;
	}

	void Window::update()
	{
#ifdef _DEBUG
        GLenum error = glGetError();
        if (error != GL_NO_ERROR)
        {
            printf("OpenGL Error!! Code %d", error);
        }
#endif

		glfwPollEvents();
		glfwGetFramebufferSize(m_Window, &m_Width, &m_Height);
		glViewport(0, 0, m_Width, m_Height);
		glfwSwapBuffers(m_Window);
	}

	bool Window::isRunning() const
	{
		return (!glfwWindowShouldClose(m_Window));
	}

	void Window::clear() const
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

    bool Window::isKeyPressed(unsigned int keyCode) const
    {
        if (keyCode >= MAX_KEYS)
        {
            printf("Key Press Error!\n");
            return false;
        }

        return m_Keys[keyCode];
    }

    bool Window::isMouseButtonPressed(unsigned int mouseBtnCode) const
    {
        if (mouseBtnCode >= MAX_MOUSEBUTTONS)
        {
            printf("Mouse Press Error!\n");
            return false;
        }

        return m_MouseButtons[mouseBtnCode];
    }

    void Window::getMousePosition(double & x, double & y) const
    {
        x = mx;
        y = my;
    }



} }
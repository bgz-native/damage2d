#ifndef _APPLICATION_H_
#define _APPLICATION_H_

#include "damage.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define MAX_KEYS            1024
#define MAX_MOUSEBUTTONS    32

namespace dmg { namespace graphics {

	class Application
	{
	public:
		Application(const char* name, int width, int height);
		~Application();
		void update();
		bool isRunning() const;
		void clear() const;

        inline int getWidth() const { return m_Width; }
        inline int getHeight() const { return m_Height; }

        bool isKeyPressed(unsigned int keyCode) const;
        bool isMouseButtonPressed(unsigned int mouseBtnCode) const;
        void getMousePosition(double& x, double& y) const;

	private:
		int start();

        // TODO refactor this, remove friend callbacks
        friend static void key_callback(GLFWwindow * window, int key, int scancode, int action, int mods);
        friend static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
        friend static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);

	private:
        friend struct GLFWwindow;

		const char* m_Name;
		int m_Width, m_Height;

		GLFWwindow* m_Window;
		bool m_isRunning;

        bool m_Keys[MAX_KEYS];
        bool m_MouseButtons[MAX_MOUSEBUTTONS];
        double mx, my;

	};
} }


#endif //_APPLICATION_H_
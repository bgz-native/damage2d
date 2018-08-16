#include "common.h"
#include "damage.h"
#include "window.h"



using namespace dmg;
using namespace graphics;


#define RGBA_COLORED 0.75f, 0.75f, 0.75f, 1.0f

int main()
{
	Window window("MyTitle", 800, 600);
	glClearColor(RGBA_COLORED);

    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);


	while (window.isRunning())
	{
        window.clear();
#if 0
        if (window.isKeyPressed(GLFW_KEY_A))
        {
            printf("A pressed");
        }

        if (window.isMouseButtonPressed(GLFW_MOUSE_BUTTON_LEFT))
        {
            printf("Mouse Pressed\n");
        }

        double x, y;
        window.getMousePosition(x, y);
        printf("xPos: %f , yPos: %f\n", x, y);



        glBegin(GL_TRIANGLES);
        glVertex2f(-0.5f, -0.5f);
        glVertex2f(0, 0.5f);
        glVertex2f(0.5f, -0.5f);
        glEnd();
#endif

        glDrawArrays(GL_ARRAY_BUFFER, 0, 6);

		window.update();
	}

	return 0;
}

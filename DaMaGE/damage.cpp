#include "common.h"
#include "damage.h"
#include "window.h"



using namespace dmg;
using namespace graphics;


#define RGBA_COLORED 1.0f, 0, 0, 1.0f

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

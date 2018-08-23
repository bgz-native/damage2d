#include "common.h"
#include "damage.h"
#include "window.h"
#include "shader.h"
#include "matrix4x4.h"


using namespace dmg;
using namespace graphics;
using namespace math;


int main()
{
	Window window("MyTitle", 800, 480);
	//glClearColor(0.75f, 0.75f, 0.75f, 1.0f);

#if 0 // test file file read work
    const char* testfile = read_file("damage.cpp");
    printf("%s", testfile);
#endif

#if 0 // initial test if opengl work
    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
#endif

#if 0
    GLfloat vertices[] =
    {
        -0.5f, -0.5f, 0.0f,
        -0.5f,  0.5f, 0.0f,
         0.5f,  0.5f, 0.0f,
         0.5f,  0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f
    };

#endif

    GLfloat vertices[] =
    {
        4, 3, 0,
        12, 3, 0,
        4, 6, 0,
        4, 6, 0,
        12, 6, 0,
        12, 3, 0
    };

    GLuint vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(0);

    Shader shader("shaders/basic.vert", "shaders/basic.frag");
    shader.enable();

    DMG_MAT4 orthoSample = orthoSample.getProjectionOrthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);
    shader.setUniformMat4("u_ProjMat", orthoSample);

    DMG_MAT4 modelMat;
    modelMat.setRotate(2.0f, 2.0f, 0);
    shader.setUniformMat4("u_ModelMat", modelMat);

    shader.setUniform2f("u_LightPos", DMG_VEC2(8.0f, 4.5f));

    shader.setUniform4f("u_Color", DMG_VEC4(0.2f, 0.3f, 0.8f, 1.0f));



	while (window.isRunning())
	{
        window.clear();

#if 0 // test if input work
        if (window.isKeyPressed(GLFW_KEY_A))
        {
            printf("A pressed\n");
        }

        if (window.isMouseButtonPressed(GLFW_MOUSE_BUTTON_LEFT))
        {
            printf("Mouse Pressed\n");
        }

        double x, y;
        window.getMousePosition(x, y);
        printf("xPos: %f , yPos: %f\n", x, y);
#endif

#if 0 // test ogl immediate mode (old school)
        glBegin(GL_TRIANGLES);
        glVertex2f(-0.5f, -0.5f);
        glVertex2f(0, 0.5f);
        glVertex2f(0.5f, -0.5f);
        glEnd();
#endif

        glDrawArrays(GL_TRIANGLES, 0, 6);

		window.update();
	}

	return 0;
}

#include "damage.h"

using namespace dmg::graphics;

int main()
{
    // CREATE WINDOW
    Application game("MyTitle", 800, 480);
    //glClearColor(0.75f, 0.75f, 0.75f, 1.0f);

    // LOAD SHADERS
    Shader shader("shaders/basic.vert", "shaders/basic.frag");
    shader.enable();

    // SET PROJECTION
    DMG_MAT4 orthoSample = orthoSample.getProjectionOrthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);
    shader.setUniformMat4("u_ProjMat", orthoSample);

    // CREATE RENDERER
    SimpleRenderer2D renderer;

    // CREATE TEST SPRITES
    Renderable2D sprite(
        DMG_VEC3(4.0f, 3.0f, 0),
        DMG_VEC2(8.0f, 3.0f),
        DMG_VEC4(1.0f, 0, 1.0f, 1.0f),
        shader);

    Renderable2D sprite2(
        DMG_VEC3(0.0f, 0.0f, 0),
        DMG_VEC2(8.0f, 3.0f),
        DMG_VEC4(0.0f, 0, 1.0f, 1.0f),
        shader);


    // UPDATE LOOP
    while (game.isRunning())
    {
        game.clear();

#if 0 // BUTTON CONTROL
        if (window.isKeyPressed(GLFW_KEY_A)) { printf("A pressed\n"); }
        if (window.isMouseButtonPressed(GLFW_MOUSE_BUTTON_LEFT)) { printf("Mouse Pressed\n"); }
#endif

        // MOUSE CONTROL
        double x, y;
        game.getMousePosition(x, y);

        // LIGHTING
        shader.setUniform2f("u_LightPos", DMG_VEC2((float)x * 0.02f, (480.0f - (float)y) * 0.01875f));

        // RENDER
        renderer.submit(&sprite);
        renderer.submit(&sprite2);
        renderer.flush();

        game.update();
    }

    shader.disable();

    return 0;
}
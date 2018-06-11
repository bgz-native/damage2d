#include <GLFW/glfw3.h>
#include "common.h"
#include "damage.h"
#include "window.h"

using namespace dmg;
using namespace graphics;

int main()
{
	Window window("MyTitle", 800, 600);
	glClearColor(1.0f, 0, 0, 1.0f);

	while (window.isRunning())
	{
		window.clear();
		
		window.update();
	}

	return 0;
}

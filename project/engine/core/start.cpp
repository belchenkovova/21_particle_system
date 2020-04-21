#include "core.h"
#include "engine/callback/callback.h"

using namespace		engine;

void 				core::start()
{
	while (not glfwWindowShouldClose(window))
	{
		event.reset_if_needed();
		glfwPollEvents();
		launch_callbacks();
		launch_timers();
		launch_timeouts();
		if (should_render)
		{
			if (print_fps)
				calculate_fps();

			glClearColor(background.x, background.y, background.z, 1.f);
			glClear(GL_COLOR_BUFFER_BIT);
			glClear(GL_DEPTH_BUFFER_BIT);

			renderer->render();

			glfwSwapBuffers(window);

			should_render = false;
		}
	}
}
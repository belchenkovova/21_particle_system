#include "core.h"
#include "engine/callback/callback.h"

using namespace		engine;

void 				core::calculate_fps()
{
	static int		number_of_frames = 0;

	static double	last = 0;
	static double	now = 0;

	int				fps;

	now = time();
	number_of_frames++;

	if (now - last >= 1.)
	{
		fps = (int)(number_of_frames / (now - last));
		number_of_frames = 0;
		last = now;

		glfwSetWindowTitle(window, (window_name + " (FPS : " + to_string(fps) + ")").c_str());
	}
}
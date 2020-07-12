#include "core.h"
#include "engine/callback/callback.h"

using namespace		engine;

void 				core::calculate_fps()
{
	static int		number_of_frames = 0;

	static int 		fps_sum = 0;
	static double	fps_count = 0;

	static double	last = 0;
	static double	now = 0;

	if (reset_fps)
	{
		fps_sum = 0;
		fps_count = 0;
		reset_fps = false;
	}

	now = time();
	number_of_frames++;

	if (now - last >= 1.)
	{
		auto		fps = (int)(number_of_frames / (now - last));
		auto		average_fps = 0.f;

		fps_sum += fps;
		fps_count++;

		average_fps = (float)fps_sum / fps_count;

		cout << "\33[2K\r" << "FPS : " << fps << ", Average : " << average_fps << flush;
		number_of_frames = 0;
		last = now;
	}
}
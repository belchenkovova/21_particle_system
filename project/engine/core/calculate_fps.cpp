#include "core.h"
#include "engine/callback/callback.h"

using namespace		engine;

void 				core::calculate_fps()
{
	static int		number_of_frames = 0;
	static double	last = 0;
	static double	now = 0;

	now = time();
	number_of_frames++;
	if (now - last >= 1.)
	{
		std::cerr << (double)number_of_frames / (now - last) << " frames/second" << std::endl;
		number_of_frames = 0;
		last = now;
	}
}
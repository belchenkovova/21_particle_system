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
		cout
			<< "\33[2K\r"
			<< "FPS : "
			<< (int)(number_of_frames / (now - last))
			<< flush;
		number_of_frames = 0;
		last = now;
	}
}
#include "core.h"

using namespace		engine;

void 				core::launch_callbacks()
{
	for (auto &callback : callbacks)
		callback.test(event.read_type());
}

void 				core::launch_timers()
{
	const float		time = glfwGetTime();

	for (auto &timer : timers)
		timer.test(time);
}
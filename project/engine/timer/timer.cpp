#include "timer.h"

using namespace		engine;

void 				timer::test(float new_time)
{
	if (period <= 0.f)
		throw (common::exception("Engine, Timer : Bad period value"));
	if (new_time - old_time >= period)
	{
		functor::run();
		old_time = new_time;
	}
}
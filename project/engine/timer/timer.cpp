#include "timer.h"

using namespace		engine;

					timer::timer(float period, std::function<void()> &function) :
					callback(function),
					period(period)
{}

void 				timer::test(float new_time)
{
	if (period <= 0.f)
		throw (common::exception("Engine, Timer : Bad period value"));
	if (new_time - old_time >= period)
	{
		callback::run();
		old_time = new_time;
	}
}
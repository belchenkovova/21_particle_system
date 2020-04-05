#include "system.h"

using namespace		gui;

void 				system::functor_press()
{
	auto			point = core.receive_event().read_mouse();

	for (const auto &space : spaces)
		if (space->functors.pressed.has_value() and space->test_point(point.value()))
			space->functors.pressed->run();
}

void 				system::functor_release()
{

}
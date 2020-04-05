#include "system.h"

using namespace		gui;

void 				system::functor_press()
{
	auto 			event = core.receive_event();
	auto			mouse = event.read_mouse();
	auto			point = (class point)(mouse->first, mouse->second);

	for (const auto &space : spaces)
		if (space->functors.pressed.has_value() and space->test_point(point))
			space->functors.pressed->run();
}

void 				system::functor_release()
{

}
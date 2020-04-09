#include "system.h"

using namespace		gui;

void 				system::functor_press()
{
	auto			point = core.receive_event().read_mouse();

	for (const auto &object : render_objects)
		if (object->have_press_functor() and object->test_point(point))
			object->functors.pressed->run();
}

void 				system::functor_release()
{

}
#include "system.h"

using namespace			gui;

						system::system(engine::core &core) :
						core(core),
						renderer(render_objects)
{
	label::start(core);
	button::start(core);

	core.generate_callback(event::type::mouse_press, &system::functor_press, this);
	core.generate_callback(event::type::mouse_release, &system::functor_release, this);
}

const engine::renderer	&system::receive_renderer()
{
	return (renderer);
}

void 					system::functor_press()
{
	auto				point = core.receive_event().read_mouse();

	for (const auto &object : render_objects)
		if (object->test_point(point))
			object->invoke_press_functors();
}

void 					system::functor_release()
{
	for (const auto &object : render_objects)
		object->invoke_release_functors();
}
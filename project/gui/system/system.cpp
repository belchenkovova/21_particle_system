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
		if (object->have_press_functors() and object->test_point(point))
			for_each(
				object->functors.press.begin(), object->functors.press.end(),
				[](const functor &functor){ functor.run(); });
}

void 					system::functor_release()
{
	for (const auto &object : render_objects)
		if (object->have_release_functors())
			for_each(
				object->functors.release.begin(), object->functors.release.end(),
				[](const functor &functor){ functor.run(); });
}
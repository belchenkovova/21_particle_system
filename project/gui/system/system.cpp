#include "system.h"
#include "gui/renderers/renderers.h"

using namespace			gui;

renderers_type			gui::renderers;

						system::system(engine::core &core) :
						core(core),
						renderer(objects)
{
	renderers = make_unique<class renderers>();

	core.generate_callback(event::type::mouse_press, &system::functor_press, this);
	core.generate_callback(event::type::mouse_release, &system::functor_release, this);
}

engine::renderer		&system::receive_renderer()
{
	return (renderer);
}

void 					system::functor_press()
{
	auto				point = core.receive_event().read_mouse();

	for (const auto &object : objects)
		if (object->test_point(point))
			object->invoke_press_functors();
}

void 					system::functor_release()
{
	for (const auto &object : objects)
		object->invoke_release_functors();
}
#include "system.h"

using namespace				gui;

							system::system(engine::core &core) :
							core(core),
							renderer(spaces)
{
	label::start(core);
	button::start(core);

	core.generate_callback(event::type::mouse_press, &system::functor_press, this);
}

const engine::renderer::pure	&system::receive_renderer()
{
	return (renderer);
}
#include "system.h"

using namespace				gui;

							system::system(engine::core &core) :
							core(core),
							renderer(spaces)
{
	engine::core::should_render = true;
	//core.attach_renderer(text_renderer);
	core.generate_callback(engine::event::type::key_press, &system::callback, this);

	label::start(core);
}

void						system::callback()
{
	engine::event			&event = core.receive_event();

	if (event.read_key() == GLFW_KEY_ESCAPE)
		core.finish();
	else if (event.read_key() == GLFW_KEY_1)
	{
		glClearColor(0.2f, 0.2f, 0.2f, 1.f);
		glClear(GL_COLOR_BUFFER_BIT);
		glClear(GL_DEPTH_BUFFER_BIT);

		//label.render();

		glfwSwapBuffers(core.read_window());
	}
}

const engine::renderer::pure	&system::receive_renderer()
{
	return (renderer);
}
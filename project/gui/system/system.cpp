#include "system.h"

using namespace		gui;

					system::system(engine::core &engine) :
					engine(engine),
					text_renderer(engine),
					font("project/resources/HelveticaNeue.ttc", 12)
{
	engine::core::should_render = true;
	//engine.attach_renderer(text_renderer);
	engine.generate_callback(engine::event::type::key_press, &system::callback, this);
}

void				system::callback()
{
	engine::event	&event = engine.receive_event();

	if (event.read_key() == GLFW_KEY_ESCAPE)
		engine.finish();
	else if (event.read_key() == GLFW_KEY_1)
	{
		glClearColor(0.2f, 0.2f, 0.2f, 1.f);
		glClear(GL_COLOR_BUFFER_BIT);
		glClear(GL_DEPTH_BUFFER_BIT);

		auto &symbol = font.find_symbol('7');

		float			raw_points[] =
			{
				100 + (float)symbol.read_size().first, 100,
				100, 100,
				100, 100 + (float)symbol.read_size().second,
				100 + (float)symbol.read_size().first, 100 + (float)symbol.read_size().second,
			};

		for (int i = 0; i < 8; i++)
			text_renderer.points->at(i) = raw_points[i];
		text_renderer.points->save();

		symbol.read_texture().bind(true);
		text_renderer.render();
		symbol.read_texture().bind(false);

		glfwSwapBuffers(engine.read_window());
	}
}
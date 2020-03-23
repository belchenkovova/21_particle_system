#include "renderer.h"

using namespace		engine;

					renderer::renderer()
{
	program::attach(shader(shader::type::vertex, vertex_source));
	program::attach(shader(shader::type::fragment, fragment_source));
	program::link();
}

engine::buffer		&renderer::receive_buffer()
{
	return (*this);
}

void				renderer::loop()
{
	while (!glfwWindowShouldClose(core::window))
	{
		glfwPollEvents();
		if (render_request)
			render();
	}
}

void				renderer::request_render()
{
	render_request = true;
}

void				renderer::render()
{
	program::use(true);
	buffer::bind(true);

	glClearColor(background.r, background.g, background.b, 1.f);
	glClear(GL_COLOR_BUFFER_BIT);
	glClear(GL_DEPTH_BUFFER_BIT);
	glDrawArrays(GL_POINTS, 0, buffer::local_size / 3);
	glfwSwapBuffers(core::window);

	program::use(false);
	buffer::bind(false);
}

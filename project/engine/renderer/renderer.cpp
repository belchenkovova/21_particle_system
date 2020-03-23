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

	glUniformMatrix4fv(
		glGetUniformLocation(program::read_object(), "uniform_projection"),
		1, GL_FALSE, glm::value_ptr(receive_projection_matrix()));
	glUniformMatrix4fv(
		glGetUniformLocation(program::read_object(), "uniform_view"),
		1, GL_FALSE, glm::value_ptr(receive_view_matrix()));

	glClearColor(background.r, background.g, background.b, 1.f);
	glClear(GL_COLOR_BUFFER_BIT);
	glClear(GL_DEPTH_BUFFER_BIT);
	glDrawArrays(GL_TRIANGLES, 0, buffer::local_size / 3);
	glfwSwapBuffers(core::window);

	program::use(false);
	buffer::bind(false);
}

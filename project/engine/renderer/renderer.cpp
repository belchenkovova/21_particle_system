#include "renderer.h"

using namespace		engine;

//					PUBLIC

					renderer::renderer() :
					engine::core(),
					engine::program(),
					engine::buffer(),
					engine::camera()
{
	program::attach(shader(shader::type::vertex, vertex_source));
	program::attach(shader(shader::type::fragment, fragment_source));
	program::link();

	glfwSetWindowUserPointer(window, this);
	glfwSetKeyCallback(window, glfw_callback);
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

//					PRIVATE

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
	glDrawArrays(GL_POINTS, 0, buffer::local_size / 3);
	glfwSwapBuffers(core::window);

	program::use(false);
	buffer::bind(false);
}

void				renderer::glfw_callback(GLFWwindow* window, int key, int code, int action, int mode)
{
	auto			*renderer = (engine::renderer *)glfwGetWindowUserPointer(window);

	if (action != GLFW_PRESS and action != GLFW_REPEAT)
		return ;
	if (key == GLFW_KEY_ESCAPE)
		glfwSetWindowShouldClose(renderer->window, GLFW_TRUE);
	else if (key == GLFW_KEY_A)
		renderer->move(axis::x, sign::negative);
	else if (key == GLFW_KEY_D)
		renderer->move(axis::x, sign::positive);
	else if (key == GLFW_KEY_W)
		renderer->move(axis::z, sign::negative);
	else if (key == GLFW_KEY_S)
		renderer->move(axis::z, sign::positive);
	else if (key == GLFW_KEY_Q)
		renderer->move(axis::y, sign::positive);
	else if (key == GLFW_KEY_E)
		renderer->move(axis::y, sign::negative);
	else if (key == GLFW_KEY_LEFT)
		renderer->rotate(axis::y, sign::positive);
	else if (key == GLFW_KEY_RIGHT)
		renderer->rotate(axis::y, sign::negative);
	else if (key == GLFW_KEY_UP)
		renderer->rotate(axis::x, sign::positive);
	else if (key == GLFW_KEY_DOWN)
		renderer->rotate(axis::x, sign::negative);
	else
		return ;
	renderer->request_render();
}
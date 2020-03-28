#include "renderer.h"
#include "engine/buffers/vao.h"
#include "engine/program/shader.h"
#include "engine/buffers/buffer.h"

//					PUBLIC


using namespace		engine;

					renderer::renderer() :
					engine::core(),
					engine::program(),
					engine::camera()
{
	program::attach(shader(shader::type::vertex, vertex_source));
	program::attach(shader(shader::type::fragment, fragment_source));
	program::link();

	glfwSetWindowUserPointer(window, this);
	glfwSetKeyCallback(window, glfw_callback);
}

void				renderer::loop()
{
	while (!glfwWindowShouldClose(core::window))
	{
		for (auto &timer : timers)
			timer->test(glfwGetTime());
		glfwPollEvents();
		if (is_rendering_requested)
			render();
	}
}

class				test
{
public :

					test(int i) :
					i(i)
	{}

	void			callback()
	{
		std::cout << "hi" << std::endl;
	}

	int i = 0;

};

static void			say_hi()
{
	std::cout << "hi" << std::endl;
}


void				renderer::request_rendering()
{
	is_rendering_requested = true;
}

void				renderer::define_target(const buffer *target)
{
	add_timer(2, say_hi);
	rendering_target = target;
}


//					PRIVATE


void				renderer::render()
{
	if (not rendering_target)
		throw (common::exception("Engine, Renderer : Target is not defined"));
	program::use(true);
	rendering_target->bind(true);

	glUniformMatrix4fv(
		glGetUniformLocation(program::read_object(), "uniform_projection"),
		1, GL_FALSE, glm::value_ptr(receive_projection_matrix()));
	glUniformMatrix4fv(
		glGetUniformLocation(program::read_object(), "uniform_view"),
		1, GL_FALSE, glm::value_ptr(receive_view_matrix()));

	glClearColor(background.r, background.g, background.b, 1.f);
	glClear(GL_COLOR_BUFFER_BIT);
	glClear(GL_DEPTH_BUFFER_BIT);
	glDrawArrays(GL_POINTS, 0, rendering_target->read_size() / 3);
	glfwSwapBuffers(core::window);

	program::use(false);
	rendering_target->bind(false);

	is_rendering_requested = false;
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
	renderer->request_rendering();
}
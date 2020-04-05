#include "core.h"
#include "engine/callback/callback.h"

using namespace		engine;

					core::core()
{
	if (++instance_count > 1)
		throw (common::exception("Engine, Core : Can't have more, than one instance"));

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	if (use_multisampling)
		glfwWindowHint(GLFW_SAMPLES, 4);

	window = glfwCreateWindow(window_width, window_height, window_name.c_str(), nullptr, nullptr);
	if (window == nullptr)
		throw (common::exception("Engine, Core : GLFW error"));
	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
		throw (common::exception("Engine, Core : GLEW error"));

	glfwGetFramebufferSize(window, &final_width, &final_height);
	glViewport(0, 0, final_width, final_height);

	if (use_blending)
	{
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	}
	if (use_multisampling)
		glEnable(GL_MULTISAMPLE);

	glfwSetWindowUserPointer(window, this);
	glfwSetKeyCallback(window, glfw_callback_key);
	glfwSetMouseButtonCallback(window, glfw_callback_mouse_key);
	glfwSetCursorPosCallback(window, glfw_callback_mouse_movement);
}

					core::~core()
{
	glfwTerminate();
}

void 				core::attach_renderer(const engine::renderer::pure &renderer)
{
	renderers.emplace_back(renderer);
}

void 				core::start()
{
	while (not glfwWindowShouldClose(window))
	{
		event.reset_if_needed();
		glfwPollEvents();
		launch_callbacks();
		launch_timers();
		if (should_render)
		{
			glClearColor(background.x, background.y, background.z, 1.f);
			glClear(GL_COLOR_BUFFER_BIT);
			glClear(GL_DEPTH_BUFFER_BIT);

			for (auto &renderer : renderers)
				renderer.get().render();

			glfwSwapBuffers(window);

			should_render = false;
		}
	}
}

void 				core::finish()
{
	glfwSetWindowShouldClose(window, GLFW_TRUE);
}

event				&core::receive_event()
{
	return (event);
}

void 				core::draw(draw_mode mode, const buffer &buffer)
{
	buffer.bind(true);
	if (buffer.uses_indexing)
		glDrawElements(static_cast<GLuint>(mode), buffer.ebo->read_size(), GL_UNSIGNED_INT, nullptr);
	else
		glDrawArrays(static_cast<GLuint>(mode), 0, buffer.size);
	buffer.bind(false);
}

int 				core::read_width() const
{
	return (final_width);
}

int 				core::read_height() const
{
	return (final_height);
}

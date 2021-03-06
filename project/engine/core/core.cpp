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
		glfwWindowHint(GLFW_SAMPLES, number_of_samples);

	window = glfwCreateWindow(initial_window_size.x, initial_window_size.y, window_name.c_str(), nullptr, nullptr);
	if (window == nullptr)
		throw (common::exception("Engine, Core : GLFW error"));
	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
		throw (common::exception("Engine, Core : GLEW error"));

	glfwGetFramebufferSize(window, &window_size.x, &window_size.y);
	glViewport(0, 0, window_size.x, window_size.y);

	if (use_blending)
	{
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	}

	if (use_multisampling)
		glEnable(GL_MULTISAMPLE);

	if (use_depth_test)
		glEnable(GL_DEPTH_TEST);

	glPointSize(point_size);

	glfwSetWindowUserPointer(window, this);
	glfwSetKeyCallback(window, glfw_callback_key);
	glfwSetMouseButtonCallback(window, glfw_callback_mouse_key);
	glfwSetCursorPosCallback(window, glfw_callback_mouse_movement);
	glfwSetScrollCallback(window, glfw_callback_mouse_scroll);
}

					core::~core()
{
	glfwTerminate();
}
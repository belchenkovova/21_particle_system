#include "core.h"

using namespace		engine;

void 				core::glfw_callback_key(GLFWwindow *window, int key, int code, int action, int mode)
{
	auto			*core = (engine::core *)glfwGetWindowUserPointer(window);

	if (action == GLFW_PRESS)
		core->event.type_value = event::type::key_press;
	else if (action == GLFW_RELEASE)
		core->event.type_value = event::type::key_release;
	else if (action == GLFW_REPEAT)
		core->event.type_value = event::type::key_hold;
	else
		return ;
	core->event.key_value = static_cast<event::key>(key);
}

void 				core::glfw_callback_mouse_movement(GLFWwindow *window, double x, double y)
{
	auto			*core = (engine::core *)glfwGetWindowUserPointer(window);

	core->event.mouse_value = point(static_cast<int>(x), static_cast<int>(y));
	core->event.type_value = event::type::mouse_move;
}

void 				core::glfw_callback_mouse_key(GLFWwindow *window, int key, int action, int mode)
{
	auto			*core = (engine::core *)glfwGetWindowUserPointer(window);
	core->event.reset();
	if (key != GLFW_MOUSE_BUTTON_LEFT)
		return ;
	if (action == GLFW_PRESS)
		core->event.type_value = event::type::mouse_press;
	else if (action == GLFW_RELEASE)
		core->event.type_value = event::type::mouse_release;
	else if (action == GLFW_REPEAT)
		core->event.type_value = event::type::mouse_hold;
}
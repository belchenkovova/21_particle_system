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
	core->event.key_value = static_cast<enum key>(key);
}

void 				core::glfw_callback_mouse_movement(GLFWwindow *window, double x, double y)
{
	auto			*core = (engine::core *)glfwGetWindowUserPointer(window);
	vec2			value;

	value = vec2(x / initial_window_size.x, y / initial_window_size.y);
	value -= vec2(0.5f, 0.5f);
	value.y *= -1.f;

	core->event.mouse_position = value;
	core->event.type_value = event::type::mouse_move;
}

void 				core::glfw_callback_mouse_key(GLFWwindow *window, int key, int action, int mode)
{
	auto			*core = (engine::core *)glfwGetWindowUserPointer(window);

	core->event.reset_if_needed();
	if (action == GLFW_PRESS)
		core->event.type_value = event::type::mouse_press;
	else if (action == GLFW_RELEASE)
		core->event.type_value = event::type::mouse_release;
	else if (action == GLFW_REPEAT)
		core->event.type_value = event::type::mouse_hold;
	core->event.key_value = static_cast<enum key>(key);
}

void				core::glfw_callback_mouse_scroll(GLFWwindow* window, double x, double y)
{
	auto			*core = (engine::core *)glfwGetWindowUserPointer(window);

	core->event.mouse_scroll = vec2(x, y);
	core->event.type_value = event::type::mouse_scroll;
}

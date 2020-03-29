#include "renderer.h"

using namespace		engine;

//	glfwSetWindowUserPointer(window, this);
//	glfwSetKeyCallback(window, glfw_callback);

//void				renderer::glfw_callback(GLFWwindow* window, int key, int code, int action, int mode)
//{
//	auto			*renderer = (engine::renderer *)glfwGetWindowUserPointer(window);
//
//	if (action != GLFW_PRESS and action != GLFW_REPEAT)
//		return ;
//	if (key == GLFW_KEY_ESCAPE)
//		glfwSetWindowShouldClose(renderer->window, GLFW_TRUE);
//	else if (key == GLFW_KEY_A)
//		renderer->move(axis::x, sign::negative);
//	else if (key == GLFW_KEY_D)
//		renderer->move(axis::x, sign::positive);
//	else if (key == GLFW_KEY_W)
//		renderer->move(axis::z, sign::negative);
//	else if (key == GLFW_KEY_S)
//		renderer->move(axis::z, sign::positive);
//	else if (key == GLFW_KEY_Q)
//		renderer->move(axis::y, sign::positive);
//	else if (key == GLFW_KEY_E)
//		renderer->move(axis::y, sign::negative);
//	else if (key == GLFW_KEY_LEFT)
//		renderer->rotate(axis::y, sign::positive);
//	else if (key == GLFW_KEY_RIGHT)
//		renderer->rotate(axis::y, sign::negative);
//	else if (key == GLFW_KEY_UP)
//		renderer->rotate(axis::x, sign::positive);
//	else if (key == GLFW_KEY_DOWN)
//		renderer->rotate(axis::x, sign::negative);
//	else
//		return ;
//	renderer->request_rendering();
//}
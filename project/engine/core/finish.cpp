#include "core.h"
#include "engine/callback/callback.h"

using namespace		engine;

void 				core::finish()
{
	glfwSetWindowShouldClose(window, GLFW_TRUE);
}
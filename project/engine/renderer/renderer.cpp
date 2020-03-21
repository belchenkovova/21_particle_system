#include "renderer.h"

using namespace		engine;

					renderer::renderer()
{
	program.attach(shader(shader::type::vertex, vertex_source));
	program.attach(shader(shader::type::fragment, fragment_source));
	program.link();
}


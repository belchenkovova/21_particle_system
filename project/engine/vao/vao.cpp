#include "vao.h"

using namespace	engine;

				vao::vao() : object_wrapper()
{
	glGenVertexArrays(1, &object);
}

				vao::~vao()
{
	glDeleteVertexArrays(1, &object);
}

void 			vao::bind(bool state) const
{
	glBindVertexArray(state ? object : 0);
}
#include "vao.h"

using namespace	engine;

				vao::vao()
{
	glGenVertexArrays(1, &object);
}

				vao::~vao()
{
	glDeleteVertexArrays(1, &object);
}

void 			vao::bind(const bool& state)
{
	glBindVertexArray(state ? object : 0);
}

void 			vao::add_attribute(const reference<vbo::abstract> &vbo)
{
	bind(true);
	vbo.get().bind(true);
	glVertexAttribPointer(
		attributes.size(),
		vbo.get().read_group(),
		vbo.get().read_type(),
		GL_FALSE,
		vbo.get().read_step(),
		nullptr);
	glEnableVertexAttribArray(attributes.size());
	vbo.get().bind(false);
	bind(false);
	attributes.push_back(vbo);
}

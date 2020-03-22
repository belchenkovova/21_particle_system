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

void 			vao::add_attribute(const a_vbo_ptr &vbo)
{
	bind(true);
	vbo->bind(true);
	glVertexAttribPointer(
		attributes.size(),
		vbo->read_group(),
		vbo->read_type(),
		GL_FALSE,
		vbo->read_size(),
		nullptr);
	glEnableVertexAttribArray(attributes.size());
	vbo->bind(false);
	bind(false);
	attributes.push_back(vbo);
}

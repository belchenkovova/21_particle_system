#include "vao.h"
#include "vbo.h"

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

void 			vao::add_attribute(const shared_ptr<vbo::abstract> &vbo)
{
	bind(true);
	vbo->bind(true);
	glVertexAttribPointer(
		attributes.size(),
		vbo->read_group(),
		vbo->read_type(),
		GL_FALSE,
		vbo->read_step(),
		nullptr);
	glEnableVertexAttribArray(attributes.size());
	vbo->bind(false);
	bind(false);
	attributes.push_back(vbo);
}

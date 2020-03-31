#include "vao.h"

using namespace				engine;

							vao::vao() : object_wrapper()
{
	glGenVertexArrays(1, &object);
}

							vao::~vao()
{
	glDeleteVertexArrays(1, &object);
}

void 						vao::bind(bool state) const
{
	glBindVertexArray(state ? object : 0);
}

vbo::abstract				&vao::receive_attribute(int index)
{
	return (*attributes[index]);
}

shared_ptr<vbo::abstract>	vao::receive_attribute_as_pointer(int index)
{
	return (attributes[index]);
}
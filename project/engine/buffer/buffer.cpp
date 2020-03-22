#include "buffer.h"

using namespace			engine;

						buffer::buffer() :
						vao()
{
	points = a_vbo_point_ptr(new a_vbo_point);
	vao::add_attribute(std::dynamic_pointer_cast<a_vbo_interface>(points));
}

std::vector<GLfloat>	&buffer::read_points()
{
	return (points->as_vector());
}

void					buffer::upload_points()
{
	points->upload();
}

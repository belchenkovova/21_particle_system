#include "buffer.h"

using namespace			engine;

						buffer::buffer() :
						vao(),
						local_size(size)
{
	points = alias_vbo_point_ptr(new alias_vbo_point);
	points->resize(local_size);
	vao::add_attribute(std::dynamic_pointer_cast<alias_vbo_interface>(points));
}

buffer::alias_vbo_point	&buffer::receive_points()
{
	return (*points);
}

#include "buffer.h"

using namespace			engine;

						buffer::buffer() :
						vao(),
						local_size(size)
{
	points.resize(local_size);
	vao::add_attribute(reference<vbo::abstract>(points));
}

buffer::vbo_point		&buffer::receive_points()
{
	return (points);
}

#include "engine/buffer/buffer.h"

using namespace			engine;

						buffer::buffer(int size) :
						vao(),
						size(300)
{
	points.resize(size);
	vao::add_attribute(reference<vbo::abstract>(points));
}

buffer::vbo_point		*buffer::receive_points()
{
	return (&points);
}

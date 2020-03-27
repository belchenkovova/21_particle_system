#include "engine/buffer/buffer.h"

using namespace			engine;

						buffer::buffer(int size) :
						vao(),
						size(size)
{
	points = make_shared<vbo::real<>>();
	points->resize(size);
	vao::add_attribute(points);
}
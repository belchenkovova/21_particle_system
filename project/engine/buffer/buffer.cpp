#include "buffer.h"

using namespace			engine;

void					buffer::resize(int size)
{
	if (is_ready_to_use)
		throw (common::exception("Engine, Buffer : Can't resize buffer"));
	for (auto &attribute : attributes)
		attribute->resize(size);
	this->size = size;
	is_ready_to_use = true;
}

void					buffer::save()
{
	for (auto &attribute : attributes)
		attribute->save();
}

void					buffer::bind(bool state) const
{
	if (not is_ready_to_use)
		throw (common::exception("Engine, Buffer : Can't use buffer"));
	vao::bind(state);
}
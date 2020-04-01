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
	if (uses_indexing)
		ebo->save();
}

void					buffer::bind(bool state) const
{
	if (not is_ready_to_use)
		throw (common::exception("Engine, Buffer : Can't use buffer"));
	if (uses_indexing)
		ebo->bind(state);
	vao::bind(state);
}

void					buffer::use_indexing(int size)
{
	if (uses_indexing)
		throw (common::exception("Engine, Buffer : Can't have more than one index buffer"));
	uses_indexing = true;
	ebo = make_shared<engine::ebo>();
	ebo->resize(size);
}

ebo						&buffer::receive_indices()
{
	if (not uses_indexing)
		throw (common::exception("Engine, Buffer : Indexes are not used"));
	return (*ebo);
}
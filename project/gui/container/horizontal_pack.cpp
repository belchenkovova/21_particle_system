#include "horizontal_pack.h"

using namespace		gui;

					horizontal_pack::horizontal_pack(const point &position)
{
	this->position = position;
}

void				horizontal_pack::reload()
{
	auto			item_size = point();

	for (const auto &item : items)
		item_size = std::max(item->read_required_size(), item_size);

	required_size->x = item_size.x * (int)items.size() + spacing * ((int)items.size() - 1);
	required_size->y = item_size.y;

	const auto		position_step = item_size.x + spacing;
	auto			position_iter = position.value_or(point());

	for (const auto &item : items)
	{
		open_current_size(*item) = item_size;
		if (have_position())
		{
			open_position(*item) = position_iter;
			position_iter.x += position_step;
		}
		item->reload();
	}
}
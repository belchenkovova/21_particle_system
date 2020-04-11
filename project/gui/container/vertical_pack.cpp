#include "vertical_pack.h"

using namespace		gui;

					vertical_pack::vertical_pack()
{
	is_latent = true;
}

					vertical_pack::vertical_pack(const point &position)
{
	this->position = position;
}

void				vertical_pack::reload()
{
	auto			item_size = point();

	for (const auto &item : items)
		item_size = point::max(item->read_required_size(), item_size);

	required_size = indent * 2;
	required_size->x += item_size.x;
	required_size->y += item_size.y * (int)items.size() + spacing * ((int)items.size() - 1);

	if (current_size >= required_size)
		item_size += (*current_size - *required_size) / (int)items.size();
	else
		current_size = required_size;

	const auto		position_step = item_size.y + spacing;
	auto			position_iter = position.value_or(point()) + indent;

	for (const auto &item : items)
	{
		open_current_size(*item) = item_size;
		if (have_position())
		{
			open_position(*item) = position_iter;
			position_iter.y += position_step;
		}
		editor::reload(*item);
	}
}

void				vertical_pack::render() const
{
	rectangle::render();
	for (const auto &item : items)
		editor::render(*item);
}
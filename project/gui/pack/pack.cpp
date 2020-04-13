#include "pack.h"

using namespace		gui;

					pack::pack(enum orientation orientation, bool align_size) :
					orientation(orientation),
					align_size(align_size)
{
	is_latent = true;
}

					pack::pack(enum orientation orientation, bool align_size, const point &position) :
					orientation(orientation),
					align_size(align_size)
{
	this->position = position;
}

property			&pack::add_item(const shared_ptr<object> &item)
{
	auto			&result = container::add_item(item);

	pack::reload_virtual();
	return (result);
}

void				pack::reload_virtual()
{
	//				Calculating maximum size for all items

	point			size_common;
	point			size_sum;

	for (const auto &[ignore, item] : items)
	{
		size_common = point::max(item.read_required_size(), size_common);
		size_sum += item.read_required_size();
	}

	//				Calculating own size

	const auto		number_of_items = (int)items.size();
	const auto		size_spaces = point(spacing * (number_of_items - 1));

	required_size = indent * 2;
	switch (orientation)
	{
		case orientation::horizontal :
			required_size->x += align_size ? number_of_items * size_common.x : size_sum.x;
			required_size->y += size_common.y;
			break ;
		case orientation::vertical :
			required_size->x += size_common.x;
			required_size->y += align_size ? number_of_items * size_common.y : size_sum.y;
			break ;
	}

	*required_size += size_spaces;

	//				If own size is given by owner, recalculate item size

	if (current_size >= required_size)
		size_common += (*current_size - *required_size) / (int)items.size();
	else
		current_size = required_size;

	//				Applying changes to items

	point			position_iter = position.value_or(point()) + indent;

	for (auto &[ignore, item] : items)
	{
		auto		&current_size = item.open_current_size();
		auto		required_size = item.read_required_size();

		current_size = point();
		switch (orientation)
		{
			case orientation::horizontal :
				current_size->y = size_common.y;
				current_size->x = align_size ? size_common.x : required_size.x;
				break ;
			case orientation::vertical :
				current_size->x = size_common.x;
				current_size->y = align_size ? size_common.y : required_size.y;
				break ;
		}

		item.open_position() = position_iter;
		item.reload();

		switch (orientation)
		{
			case orientation::horizontal :
				position_iter.x += align_size ? size_common.x : current_size->x;
				position_iter.x += spacing;
				break ;
			case orientation::vertical :
				position_iter.y += align_size ? size_common.y : current_size->y;
				position_iter.y += spacing;
				break ;
		}
	}
}

void				pack::render_virtual() const
{
	rectangle::render_virtual();
	for (const auto &[ignore, item] : items)
		item.render();
}
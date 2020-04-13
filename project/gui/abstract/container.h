#pragma once

#include "gui/namespace.h"
#include "gui/abstract/property.h"

class				gui::container
{
public :
					container() = default;
	virtual			~container() = default;

	virtual auto	add_item(const shared_ptr<object> &item) -> property &
	{
		auto		result = items.emplace(
			piecewise_construct,
			forward_as_tuple(item),
			forward_as_tuple(item));
		if (not result.second)
			throw (common::exception("GUI, Container : Can't add item to container"));
		return (result.first->second);
	}

protected :

	using			propeties_type = map<shared_ptr<object>, property>;
	propeties_type	items;
};

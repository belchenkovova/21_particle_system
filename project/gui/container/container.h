#pragma once

#include "gui/namespace.h"
#include "gui/abstract/editor.h"

class				gui::container : public gui::editor, public gui::object
{
public :
					container() = default;
					~container() override = default;

	void			add_item(const shared_ptr<object> &item)
	{
		if (items.count(item))
			throw (common::exception("GUI, Container : Item already exist in container"));
		items.emplace(item);
		reload();
	}

protected :

	using			items_type = set<shared_ptr<object>>;
	items_type		items;
};

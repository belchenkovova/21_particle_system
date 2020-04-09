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
		if (not items.count(item))
		{
			items.emplace(item);
			reload();
		}
	}

protected :

	using			items_type = set<shared_ptr<object>>;
	items_type		items;
};

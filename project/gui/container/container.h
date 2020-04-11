#pragma once

#include "gui/namespace.h"
#include "gui/abstract/editor.h"
#include "gui/rectangle/rectangle.h"

class				gui::container : public gui::editor, public gui::rectangle
{
public :
					container() = default;
					~container() override = default;

	void			add_item(const shared_ptr<object> &item)
	{
		if (items.count(item))
			throw (common::exception("GUI, Container : Item already exist in container"));
		items.emplace(item);
		declare_latent(*item);
		reload();
	}

protected :

	using 			rectangle::reload;

	using			items_type = set<shared_ptr<object>>;
	items_type		items;
};

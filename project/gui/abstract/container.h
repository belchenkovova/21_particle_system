#pragma once

#include "gui/namespace.h"
#include "gui/abstract/property.h"

class					gui::container : private map<shared_ptr<object>, property>
{
public :
						container() = default;
	virtual				~container() = default;

	virtual property	&add_item(const shared_ptr<object> &item)
	{
		auto			result = emplace(piecewise_construct, forward_as_tuple(item), forward_as_tuple(item));
		if (not result.second)
			throw (common::exception("GUI, Container : Can't add item to container"));
		return (result.first->second);
	}

	using 				map<shared_ptr<object>, property>::begin;
	using 				map<shared_ptr<object>, property>::end;
	using 				map<shared_ptr<object>, property>::size;
};

#pragma once

#include "gui/namespace.h"
#include "gui/abstract/property.h"

class						gui::owner : private vector<property>
{
public :

	template 		<typename ...args_type>
	explicit				owner(args_type &&...args)
	{
		(emplace_back(args), ...);
	}
	virtual					~owner() = default;

	[[nodiscard]]
	class property			&property()
	{
		return (vector<class property>::at(selected_index));
	}

	[[nodiscard]]
	const class property	&property() const
	{
		return (vector<class property>::at(selected_index));
	}

	class property			&select(int index)
	{
		selected_index = index;
		return (property());
	}

private :

	int 					selected_index = 0;
};

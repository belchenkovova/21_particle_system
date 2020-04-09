#pragma once

#include "gui/namespace.h"
#include "gui/abstract/object.h"

class						gui::editor
{
public :

							editor() = default;
	virtual					~editor() = default;

protected :

	static optional<point>	&open_current_size(object &object)
	{
		return (object.current_size);
	}

	static optional<point>	&open_position(object &object)
	{
		return (object.position);
	}
};
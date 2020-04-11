#pragma once

#include "gui/namespace.h"
#include "gui/abstract/object.h"

class						gui::editor
{
public :

							editor() = default;
	virtual					~editor() = default;

protected :

	static void 			declare_latent(object &object)
	{
		object.is_latent = true;
	}

	static void 			reload(object &object)
	{
		object.reload();
	}

	static void 			render(object &object)
	{
		object.render();
	}

	static void				invoke_press_functors(object &object)
	{
		object.invoke_press_functors();
	}

	static void				invoke_release_functors(object &object)
	{
		object.invoke_release_functors();
	}

	static optional<point>	&open_current_size(object &object)
	{
		return (object.current_size);
	}

	static optional<point>	&open_position(object &object)
	{
		return (object.position);
	}
};
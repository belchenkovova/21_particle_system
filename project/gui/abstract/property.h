#pragma once

#include "gui/namespace.h"
#include "gui/abstract/object.h"

class					gui::property
{
public :

	explicit			property(const shared_ptr<gui::object> &target) :
						target(target)
	{}
						~property() = default;

	void 				declare_latent()
	{
		target->is_latent = true;
	}

	void 				declare_locked()
	{
		target->is_locked = true;
	}

	void 				reload()
	{
		target->reload();
	}

	void				render() const
	{
		target->render();
	}

	[[nodiscard]]
	point				read_required_size() const
	{
		if (not target->required_size)
			throw (common::exception("GUI, Property : Target doesn't have required size"));
		return (*target->required_size);
	}


	optional<point>		&open_current_size()
	{
		return (target->current_size);
	}

	optional<point>		&open_position()
	{
		return (target->position);
	}

	void				invoke_press_functors() const
	{
		target->invoke_press_functors();
	}

	void				invoke_release_functors() const
	{
		target->invoke_release_functors();
	}

private :

	using				target_type = shared_ptr<object>;
	const target_type	target;
};

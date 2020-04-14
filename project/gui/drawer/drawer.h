#pragma once

#include "gui/namespace.h"
#include "gui/abstract/container.h"

class						gui::drawer final : public gui::object, public gui::container
{
	friend class			gui::system;

public :

	explicit				drawer(const shared_ptr<object> &target, float relative_position = 0.5f);
							~drawer() override = default;

	void					show(bool state);

private :

	shared_ptr<icon>		icon;
	shared_ptr<button>		button;


	struct
	{
		property			*button;
		property			*target;
	}						property;

	void					render_virtual() const override;
};



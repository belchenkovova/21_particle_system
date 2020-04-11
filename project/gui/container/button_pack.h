#pragma once

#include "gui/namespace.h"
#include "gui/container/horizontal_pack.h"

class						gui::button_pack : public gui::horizontal_pack
{
public :

	enum class				activation_type
	{
		one,
		many
	};

	explicit				button_pack(enum activation_type type);
							button_pack(const point &position, enum activation_type type);
							~button_pack() override = default;

	void					add_button(const shared_ptr<button> &button);

private :

	const activation_type	type;

	using					buttons_type = vector<shared_ptr<button>>;
	buttons_type			buttons;
};



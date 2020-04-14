#pragma once

#include "gui/namespace.h"
#include "gui/pack/pack.h"

class						gui::button_pack final : public gui::pack
{
public :

	explicit				button_pack(enum orientation orientation, bool align_size);
							button_pack(enum orientation orientation, bool align_size, const point &position);
							~button_pack() override = default;

	void					add_button(const shared_ptr<button> &new_button);

private :

	using					buttons_type = std::map<shared_ptr<button>, reference_wrapper<property>>;
	buttons_type			buttons;
};



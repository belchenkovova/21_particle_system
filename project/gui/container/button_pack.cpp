#include "button_pack.h"

#include "gui/button/button.h"

using namespace		gui;

					button_pack::button_pack(enum type type) :
					type(type)
{}

					button_pack::button_pack(const point &position, enum type type) :
					horizontal_pack(position),
					type(type)
{}

void				button_pack::add_button(const shared_ptr<button> &button)
{
	auto			functor = [this, button]()
	{
		static bool	block;

		if (block)
			return ;
		block = true;
		for (auto &iter : buttons)
			if (iter != button and iter->is_pressed)
				iter->invoke_press_functors();
		block = false;
	};

	button->is_toggle = true;
	button->functors.press.emplace_back(functor);
	add_item(static_pointer_cast<object>(button));
	buttons.push_back(button);
}

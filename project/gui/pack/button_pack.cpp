#include "button_pack.h"

#include "gui/button/button.h"

using namespace		gui;

					button_pack::button_pack(enum orientation orientation, bool align_size) :
					pack(orientation, align_size)
{}

					button_pack::button_pack(
					enum orientation orientation, bool align_size, const point &position) :
					pack(orientation, align_size, position)
{}

void				button_pack::add_button(const shared_ptr<button> &new_button)
{
	auto			&property = add_item(static_pointer_cast<object>(new_button));

	auto			functor = [this, new_button]()
	{
		static bool	block;

		if (block)
			return ;
		block = true;
		for (auto &[button, property] : buttons)
			if (button != new_button and button->is_pressed)
				property.get().invoke_press_functors();
		block = false;
	};

	new_button->make_toggle();
	new_button->functors.press.emplace_back(functor);
	buttons.emplace(
		piecewise_construct,
		forward_as_tuple(new_button),
		forward_as_tuple(property));
}

#include "button_with_label.h"

using namespace		gui;

					button_with_label::button_with_label(
					const class functor &functor,
					const point &center,
					const class font &font,
					const string &text) :
					button(functor),
					label(center, font, text)
{
	reload_space();
}

void				button_with_label::replace_text(const string &new_text)
{
	label.replace_text(new_text);
	reload_space();
}

void				button_with_label::reload_space()
{
	min = label.receive_min() - point(1);
	max = label.receive_max() + point(1);
}

void				button_with_label::render() const
{
	label.render();
	button::render();
}

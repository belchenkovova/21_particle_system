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
	reload();
}

void				button_with_label::replace_text(const string &new_text)
{
	label.replace_text(new_text);
	reload();
}

void				button_with_label::reload()
{
	min = label.receive_min() - indent;
	max = label.receive_max() + indent;
}

void				button_with_label::render() const
{
	button::render();
	label.render();
}

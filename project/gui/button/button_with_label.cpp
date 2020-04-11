#include "button_with_label.h"

using namespace		gui;

					button_with_label::button_with_label(
					const class functor &functor,
					const string &text,
					const shared_ptr<font> &font) :
					button(functor),
					label(text, font)
{
	button_with_label::reload();
}

void				button_with_label::render() const
{
	button::render();
	label.render();
}

void				button_with_label::reload()
{
	auto 			final_indent = indent + point(frame_width);

	required_size = label.read_required_size() + final_indent * 2;
	open_current_size(label) = *current_size - final_indent * 2;
	open_position(label) = *position + final_indent;
}

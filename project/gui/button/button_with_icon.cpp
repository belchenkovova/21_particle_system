#include "button_with_icon.h"

using namespace		gui;

					button_with_icon::button_with_icon(
					const class functor &functor,
					const string &source) :
					button(functor),
					icon(source)
{
	button_with_icon::reload();
}

void				button_with_icon::render() const
{
	button::render();
	icon.render();
}

void				button_with_icon::reload()
{
	auto 			final_indent = indent + point(frame_width);

	required_size = icon.read_required_size() + final_indent * 2;
	open_current_size(icon) = *current_size - final_indent * 2;
	open_position(icon) = *position + final_indent;
}

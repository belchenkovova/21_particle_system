#include "button.h"
#include "gui/renderers/renderers.h"

using namespace		gui;

void				button::make_toggle()
{
	is_toggle = true;
}

void				button::reload_virtual()
{
	auto			final_indent = indent + point(frame_width);

	required_size = property().read_required_size() + final_indent * 2;
	property().open_current_size() = *current_size - final_indent * 2;
	property().open_position() = *position + final_indent;
}

void				button::render_virtual() const
{
	assert(renderers);

	rectangle::render_virtual();
	if (is_pressed)
		renderers->rectangle.render(*position, *current_size, active_color);
	property().render();
}

void				button::functor_press()
{
	engine::core::should_render = true;
	is_pressed = is_toggle ? not is_pressed : true;
}

void				button::functor_release()
{
	engine::core::should_render = true;
	is_pressed = false;
}

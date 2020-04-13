#include "button.h"
#include "gui/renderers/renderers.h"

using namespace		gui;

					button::button(
					const class functor &functor,
					const shared_ptr<object> &content,
					bool is_toggle) :
					owner(content),
					is_toggle(is_toggle)
{
	button::reload_virtual();
	is_latent = true;
	functors.press.emplace_back(&gui::button::functor_press, this);
	if (not is_toggle)
		functors.release.emplace_back(&gui::button::functor_release, this);
	functors.press.push_back(functor);
}

void				button::reload_virtual()
{
	auto			final_indent = indent + point(frame_width);

	required_size = property.read_required_size() + final_indent * 2;
	property.open_current_size() = *current_size - final_indent * 2;
	property.open_position() = *position + final_indent;
}

void				button::render_virtual() const
{
	assert(renderers);

	rectangle::render_virtual();
	if (is_pressed)
		renderers->rectangle.render(*position, *current_size, active_color);
	property.render();
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

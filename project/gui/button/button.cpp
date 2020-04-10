#include "button.h"
#include "gui/renderers/renderers.h"

using namespace		gui;

					button::button(const class functor &functor, bool is_toggle) :
					is_toggle(is_toggle)
{
	functors.press.emplace_back(&gui::button::functor_press, this);
	if (not is_toggle)
		functors.release.emplace_back(&gui::button::functor_release, this);
	functors.press.push_back(functor);
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

void				button::render() const
{
	revise_self();
	assert(renderers);

	renderers->rectangle.render(
		*position,
		*current_size,
		frame_color);
	renderers->rectangle.render(
		*position + point(frame_width),
		*current_size - point(2 * frame_width),
		body_color);
	if (is_pressed)
		renderers->rectangle.render(
			*position,
			*current_size,
			active_mask);
}

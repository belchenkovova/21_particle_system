#include "rectangle.h"
#include "gui/renderers/renderers.h"

using namespace		gui;

void				rectangle::render() const
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
}
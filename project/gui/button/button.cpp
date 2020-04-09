#include "button.h"

using namespace		gui;

					button::button(const class functor &functor)
{
	functors.pressed = functor;
}

void				button::render() const
{
	revise_self();
	assert(renderer);

	auto 			draw_rectangle = [](
					const point &position,
					const point &size,
					glm::vec3 &color)
	{
		float		data[] =
		{
			(float)(position.x + size.x),	(float)position.y,
			(float)position.x,				(float)position.y,
			(float)position.x,				(float)(position.y + size.y),
			(float)(position.x + size.x),	(float)(position.y + size.y)
		};

		for (int i = 0; i < 8; i++)
			renderer->points->at(i) = data[i];
		renderer->points->save();

		renderer->program->upload_uniform("uniform_color", color);
		renderer->render();
	};

	draw_rectangle(
		*position,
		*current_size,
		frame_color);
	draw_rectangle(
		*position + point(frame_width),
		*current_size - point(2 * frame_width),
		body_color);
}

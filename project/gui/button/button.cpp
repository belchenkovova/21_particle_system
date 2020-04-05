#include "button.h"

using namespace		gui;

					button::button(const class functor &functor) :
					space(true)
{
	functors.pressed = functor;
}

void				button::render() const
{
	assert(renderer);

	auto 			draw_rectangle = [](
					const point &min,
					const point &max,
					glm::vec3 &color)
	{
		float		data[] =
			{
				(float)max.x, (float)min.y,
				(float)min.x, (float)min.y,
				(float)min.x, (float)max.y,
				(float)max.x, (float)max.y
			};

		for (int i = 0; i < 8; i++)
			renderer->points->at(i) = data[i];
		renderer->points->save();

		renderer->program.upload_uniform("uniform_color", color);
		renderer->render();
	};

	draw_rectangle(min - point(frame_width), max + point(frame_width), frame_color);
	draw_rectangle(min, max, body_color);
}

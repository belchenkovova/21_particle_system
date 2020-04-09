#include "button.h"

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
	assert(renderers.first);
	assert(renderers.second);

	auto 			draw_first = [](
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
			renderers.first->points->at(i) = data[i];
		renderers.first->points->save();

		renderers.first->program->upload_uniform("uniform_color", color);
		renderers.first->render();
	};

	auto 			draw_second = [](
					const point &position,
					const point &size)
	{
		float		data[] =
			{
				(float)(position.x + size.x),	(float)position.y,
				(float)position.x,				(float)position.y,
				(float)position.x,				(float)(position.y + size.y),
				(float)(position.x + size.x),	(float)(position.y + size.y)
			};

		for (int i = 0; i < 8; i++)
			renderers.second->points->at(i) = data[i];
		renderers.second->points->save();

		renderers.second->render();
	};

	draw_first(
		*position,
		*current_size,
		frame_color);
	draw_first(
		*position + point(frame_width),
		*current_size - point(2 * frame_width),
		body_color);
	if (is_pressed)
		draw_second(*position, *current_size);
}

#include "drawer.h"
#include "gui/icon/icon.h"
#include "gui/button/button.h"

using namespace		gui;

					drawer::drawer(const shared_ptr<object> &target, float relative_position) :
					relative_position(relative_position),
					property{}
{
	auto 			functor = [this]()
	{
		assert(transition_timer);
		transition_timer->block = false;
	};

	icon = make_shared<class icon>("project/resources/GUI/right.png");
	button = make_shared<class button>((class functor)(functor), icon);

	property.button = &container::add_item(button);
	property.target = &container::add_item(target);

	current_shift = 0;
	max_shift = property.target->read_required_size().x;

	drawer::reload_virtual();
}

void				drawer::reload_virtual()
{
	const auto		window_size = engine::core::read_window_size();
	const auto		window_edge = point(window_size.x - 1, (int)((float)window_size.y * relative_position));

//					Target

	const auto		&target_size = property.target->read_required_size();
	auto			&target_position = property.target->open_position();

	target_position = window_edge;
	target_position->x += -1 * target_size.x + current_shift;
	target_position->y -= target_size.y / 2;
	property.target->open_current_size() = target_size;
	property.target->reload();

//					Button

	const auto		&button_size = property.button->read_required_size();
	auto			&button_position = property.button->open_position();

	button_position = window_edge;
	button_position->x += -1 * (target_size.x + button_size.x) + current_shift;
	button_position->y -= button_size.y / 2;
	property.button->open_current_size() = button_size;
	property.button->reload();

//					Self

	required_size = target_size + button_size;
	current_size = required_size;
	position = point();
}

void				drawer::transition_function()
{
	assert(transition_timer);

	current_shift += transition_step * static_cast<int>(current_direction);
	switch (current_direction)
	{
		case sign::minus :
			if (current_shift <= min_shift)
			{
				current_direction = sign::plus;
				transition_timer->block = true;
			}
			break ;
		case sign::plus :
			if (current_shift >= max_shift)
			{
				current_direction = sign::minus;
				transition_timer->block = true;
			}
			break ;
	}
	drawer::reload_virtual();
	engine::core::should_render = true;
}

void				drawer::render_virtual() const
{
	property.button->render();
	property.target->render();
}
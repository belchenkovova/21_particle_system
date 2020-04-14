#include "drawer.h"
#include "gui/icon/icon.h"
#include "gui/button/button.h"

using namespace		gui;

					drawer::drawer(const shared_ptr<object> &target, float relative_position) :
					relative_position(relative_position),
					icons{},
					properties{}
{
	auto 			functor = [this]()
	{
		assert(transition_timer);
		transition_timer->block = false;
	};

	icons.left = make_shared<class icon>("project/resources/GUI/left.png");
	icons.right = make_shared<class icon>("project/resources/GUI/right.png");
	button = make_shared<class button>((class functor)(functor), icons.left, icons.right);
	button->select(1);

	properties.button = &container::add_item(button);
	properties.target = &container::add_item(target);

	current_shift = 0;
	max_shift = properties.target->read_required_size().x;

	drawer::reload_virtual();
}

void				drawer::reload_virtual()
{
	const auto		window_size = engine::core::read_window_size();
	const auto		window_edge = point(window_size.x - 1, (int)((float)window_size.y * relative_position));

//					Target

	const auto		&target_size = properties.target->read_required_size();
	auto			&target_position = properties.target->open_position();

	target_position = window_edge;
	target_position->x += -1 * target_size.x + current_shift;
	target_position->y -= target_size.y / 2;
	properties.target->open_current_size() = target_size;
	properties.target->reload();

//					Button

	const auto		&button_size = properties.button->read_required_size();
	auto			&button_position = properties.button->open_position();

	button_position = window_edge;
	button_position->x += -1 * (target_size.x + button_size.x) + current_shift;
	button_position->y -= button_size.y / 2;
	properties.button->open_current_size() = button_size;
	properties.button->reload();

//					Self

	required_size = target_size + button_size;
	current_size = required_size;
	position = point();
}

void				drawer::transition_function()
{
	bool			is_end = false;
	assert(transition_timer);

	current_shift += transition_step * static_cast<int>(current_direction);
	switch (current_direction)
	{
		case sign::minus :
			if (current_shift <= min_shift)
			{
				is_end = true;
				current_direction = sign::plus;
				button->select(1);
			}
			break ;
		case sign::plus :
			if (current_shift >= max_shift)
			{
				is_end = true;
				current_direction = sign::minus;
				button->select(0);
			}
			break ;
	}
	if (is_end)
	{
		transition_timer->block = true;
		properties.button->reload();
	}
	drawer::reload_virtual();
	engine::core::should_render = true;
}

void				drawer::render_virtual() const
{
	properties.button->render();
	properties.target->render();
}
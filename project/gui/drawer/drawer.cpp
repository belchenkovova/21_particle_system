#include "drawer.h"
#include "gui/icon/icon.h"
#include "gui/button/button.h"

using namespace		gui;

					drawer::drawer(const shared_ptr<object> &target, float relative_position) :
					property{}
{
	icon = make_shared<class icon>("project/resources/GUI/right.png");
	button = make_shared<class button>(functor([](){std::cout << "Drawer" << std::endl;}), icon);

	property.button = &container::add_item(button);
	property.target = &container::add_item(target);

	const auto		window_size = engine::core::read_window_size();
	const auto		window_edge = point(window_size.x - 1, (int)((float)window_size.y * relative_position));

//					Target

	const auto		&target_size = property.target->read_required_size();
	auto			&target_position = property.target->open_position();

	target_position = window_edge;
	target_position->x -= target_size.x;
	target_position->y -= target_size.y / 2;
	property.target->open_current_size() = target_size;
	property.target->reload();

//					Button

	const auto		&button_size = property.button->read_required_size();
	auto			&button_position = property.button->open_position();

	button_position = window_edge;
	button_position->x -= target_size.x + button_size.x;
	button_position->y -= button_size.y / 2;
	property.button->open_current_size() = button_size;
	property.button->reload();

//					Self

	required_size = target_size + button_size;
	current_size = required_size;
	position = point();
}

void				drawer::render_virtual() const
{
	property.button->render();
	property.target->render();
}
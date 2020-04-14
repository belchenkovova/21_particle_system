#pragma once

#include "gui/namespace.h"
#include "gui/abstract/container.h"

class						gui::drawer final : public gui::object, public gui::container
{
	friend class			gui::system;

public :

	explicit				drawer(const shared_ptr<object> &target, float relative_position = 0.5f);
							~drawer() override = default;

private :

	const float				relative_position;
	sign					current_direction = sign::plus;
	int 					current_shift;
	const int 				min_shift = 0;
	int 					max_shift;

	struct
	{
		shared_ptr<icon>	left;
		shared_ptr<icon>	right;
	}						icons;
	shared_ptr<button>		button;

	static inline int 		transition_step = 12;
	static inline float		transition_period = 1 / 60.f;
	void					transition_function();
	timer					*transition_timer = nullptr;

	struct
	{
		property			*button;
		property			*target;
	}						properties;

	void					reload_virtual() override;
	void					render_virtual() const override;
};



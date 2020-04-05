#pragma once

#include "gui/namespace.h"
#include "gui/point/point.h"

class				gui::space : public engine::renderer::pure
{
	friend class 	gui::system;

public :

	explicit		space(bool is_dynamic) : is_dynamic(is_dynamic) {}
					~space() override = default;

	[[nodiscard]]
	const point		&receive_min() const
	{
		return (min);
	}

	[[nodiscard]]
	const point		&receive_max() const
	{
		return (max);
	}

protected :

	const bool			is_dynamic;

	point				min;
	point				max;

	using 				functor_type = optional<functor>;
	struct
	{
		functor_type	pressed;
		functor_type	released;
	}					functors;

private :

	[[nodiscard]]
	bool 				test_point(const class point &point)
	{
		return (point > min and point < max);
	}
};



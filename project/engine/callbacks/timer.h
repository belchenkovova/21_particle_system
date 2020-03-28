#pragma once

#include "engine/namespace.h"
#include "engine/callbacks/callback.h"

class				engine::timer : private engine::callback
{
public :

	explicit		timer(float period, std::function<void()> &function);

	template		<typename t_function, typename... t_args >
	explicit		timer(float period, t_function function, t_args ...args) :
					callback(function, args...),
					period(period)
	{}
					~timer() = default;

	void 			test(float new_time);

private :

	const float		period{0.f};
	float			old_time{0.f};
};



#pragma once

#include "engine/namespace.h"
#include "engine/callback/callback.h"

class				engine::timer final : private engine::functor
{
public :

	template		<typename t_function, typename... t_args >
					timer(float period, t_function function, t_args ...args) :
					functor(function, args...),
					period(period)
	{}
					~timer() override = default;

	void 			test(float new_time);

private :

	const float		period{0.f};
	float			old_time{0.f};
};



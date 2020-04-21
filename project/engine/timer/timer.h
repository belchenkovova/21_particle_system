#pragma once

#include "engine/namespace.h"
#include "engine/callback/callback.h"

class				engine::timer final : public engine::functor
{
public :

	template		<typename t_function, typename... t_args >
					timer(float period, t_function function, t_args ...args) :
					functor(function, args...),
					period(period)
	{}
					~timer() override = default;

	void 			test(float now)
	{
		if (is_blocked())
			return ;
		if (period <= 0.f)
			throw (common::exception("Engine, Timer : Bad period value"));
		if (now - last >= period)
		{
			functor::run();
			last = now;
		}
	}

private :

	const float		period = 0.f;
	float			last = 0.f;
};



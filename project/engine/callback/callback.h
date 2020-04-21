#pragma once

#include "engine/namespace.h"
#include "engine/functor/functor.h"
#include "engine/event/event.h"


class					engine::callback final : public engine::functor
{
public :

	template			<typename t_function, typename... t_args >
						callback(event::type type, t_function function, t_args ...args) :
						engine::functor(function, args...), type(type) {}
						~callback() override = default;

	void				test(event::type type)
	{
		if (not is_blocked() and this->type == type)
			functor::run();
	}

private :

	const event::type	type;
};



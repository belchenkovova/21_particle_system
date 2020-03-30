#pragma once

#include "engine/namespace.h"

class						engine::functor
{
public :

	explicit				functor(std::function<void()> &function);

	template				<typename t_function, typename... t_args >
	explicit				functor(t_function function, t_args ...args)
	{
		this->function = std::bind(function, args...);
	}
	virtual					~functor() = default;

	void 					run() const;

private :

	std::function<void()>	function;
};



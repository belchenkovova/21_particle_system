#pragma once

#include "engine/namespace.h"

class						engine::callback
{
public :

	explicit				callback(std::function<void()> &function);

	template				<typename t_function, typename... t_args >
	explicit				callback(t_function function, t_args ...args)
	{
		this->function = std::bind(function, args...);
	}
							~callback() = default;

	void 					run() const;

private :

	std::function<void()>	function;
};



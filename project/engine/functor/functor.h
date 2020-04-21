#pragma once

#include "engine/namespace.h"

class						engine::functor
{
public :

	template				<typename function_type, typename... args_type >
	explicit				functor(function_type function, args_type ...args)
	{
		this->function = std::bind(function, args...);
	}
	virtual					~functor() = default;

	void 					run() const
	{
		if (not block_value)
			function();
	}

	void					block(bool state)
	{
		block_reserved(state);
		block_value = state;
	}

	void					block_reserved(bool state)
	{
		if (state and not is_using_reserved_block)
		{
			reserve_value = block_value;
			block_value = true;
			is_using_reserved_block = true;
		}
		else if (not state)
		{
			block_value = reserve_value;
			is_using_reserved_block = false;
		}
	}

	[[nodiscard]]
	bool					is_blocked() const
	{
		return (block_value);
	}

private :

	std::function<void()>	function;
	bool					block_value = false;
	bool					reserve_value = false;
	bool					is_using_reserved_block = false;
};



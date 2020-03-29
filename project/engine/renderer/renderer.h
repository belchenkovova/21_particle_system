#pragma once

#include "engine/namespace.h"
#include "engine/program/program.h"
#include "engine/buffer/buffer.h"

class								engine::renderer
{
public :

									renderer() = default;
	virtual							~renderer() = default;

	virtual void					render() = 0;

protected :

	program							program;
	buffer							buffer;

	inline void						render_prefix()
	{
		program.use(true);
		buffer.bind(true);
	}

	inline void						render_suffix()
	{
		program.use(false);
		buffer.bind(false);
	}
};


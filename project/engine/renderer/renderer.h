#pragma once

#include "engine/namespace.h"
#include "engine/program/program.h"
#include "engine/buffer/buffer.h"

class					engine::renderer
{
public :

	explicit			renderer(bool should_initialize = true)
	{
		if (should_initialize)
		{
			program.emplace();
			buffer.emplace();
		}
	}
	virtual				~renderer() = default;

	virtual void		render() const = 0;

protected :

	optional<program>	program;
	optional<buffer>	buffer;
};
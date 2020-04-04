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
};


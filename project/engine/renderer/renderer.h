#pragma once

#include "engine/namespace.h"
#include "engine/program/program.h"

class							engine::renderer
{
public :

	inline static std::string	vertex_source;
	inline static std::string	fragment_source;

								renderer();
								~renderer() = default;

private :

	program						program;
};



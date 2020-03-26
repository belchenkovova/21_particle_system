#pragma once

#include "common/common.h"
#include "engine/engine.h"
#include "common/cl_wrapper.hpp"
#include <optional>
#include <vector>

namespace			computer
{
	template 		<typename t_type>
	using			unique = std::unique_ptr<t_type>;
	template 		<typename t_type>
	using			vector = std::vector<t_type>;

	class 			core;
	class 			kernel;
	enum class		memory_management : unsigned int;
	class 			argument;
}

#pragma once

#include "common/common.h"
#include "engine/engine.h"
#include "external/cl_wrapper.hpp"
#include <optional>
#include <vector>

namespace			computer
{
	using			std::string;
	using			std::vector;
	using			std::shared_ptr;
	using			std::make_shared;

	class 			core;
	class 			kernel;
	enum class		memory_management : unsigned int;
	class 			argument;
}

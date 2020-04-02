#pragma once

#include <ft2build.h>
#include FT_FREETYPE_H
#include <map>

#include "engine/engine.h"

namespace			gui
{
	using			std::string;
	using			std::map;
	using			std::shared_ptr;
	using			std::make_shared;
	using			std::optional;

	class 			point;

	class			symbol;
	class			font;

	class 			label;
	class 			button;

	class			system;
}
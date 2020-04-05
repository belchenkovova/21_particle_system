#pragma once

#include <ft2build.h>
#include FT_FREETYPE_H
#include <map>

#include "engine/engine.h"

namespace			gui
{
	using			std::forward;
	using			std::string;
	using			std::map;
	using			std::vector;
	using			std::static_pointer_cast;
	using			std::dynamic_pointer_cast;
	using			std::shared_ptr;
	using			std::make_shared;
	using			std::unique_ptr;
	using			std::make_unique;
	using			std::optional;

	using 			engine::functor;
	using 			engine::event;
	using 			engine::callback;

	class 			point;

	class			symbol;
	class			font;

	class			space;
	class 			label;
	class 			button;
	class 			button_with_label;

	class			system;
}
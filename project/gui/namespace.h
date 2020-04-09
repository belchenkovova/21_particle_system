#pragma once

#include <ft2build.h>
#include FT_FREETYPE_H
#include <set>
#include <map>

#include "engine/engine.h"

namespace			gui
{
	using			std::string;
	using			std::set;
	using			std::map;
	using			std::vector;
	using			std::reference_wrapper;
	using			std::static_pointer_cast;
	using			std::dynamic_pointer_cast;
	using			std::shared_ptr;
	using			std::make_shared;
	using			std::unique_ptr;
	using			std::make_unique;
	using			std::optional;
	using			std::numeric_limits;
	using 			std::min;
	using 			std::max;

	using			engine::point;
	using 			engine::functor;
	using 			engine::event;
	using 			engine::callback;

	template		<typename type>
	void 			revise_optional(const optional<type> &data)
	{
		if (not data.has_value())
			throw (common::exception("GUI : Optional doesn't have value"));
	}

	class			symbol;
	class			font;

	class			object;
	class			editor;
	class 			label;
	class 			button;
	class 			button_with_label;
	class			container;
	class			free_container;
	class			horizontal_pack;

	class			system;
}
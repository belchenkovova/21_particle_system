#pragma once

#include <ft2build.h>
#include FT_FREETYPE_H

#include <set>
#include <map>
#include <list>

#include "engine/engine.h"

#include "debug.h"

namespace					gui
{
	using					std::is_same_v;
	using					std::is_base_of_v;
	using					std::for_each;
	using					std::piecewise_construct;
	using					std::forward_as_tuple;

	using					std::string;
	using					std::set;
	using					std::map;
	using					std::list;
	using					std::vector;
	using					std::pair;
	using					std::optional;
	using					std::numeric_limits;

	using					std::reference_wrapper;
	using					std::static_pointer_cast;
	using					std::dynamic_pointer_cast;
	using					std::shared_ptr;
	using					std::make_shared;
	using					std::unique_ptr;
	using					std::make_unique;

	using					engine::point;
	using 					engine::event;
	using 					engine::functor;
	using 					engine::callback;
	using 					engine::timer;
	using 					engine::sign;

	template				<typename type>
	void 					revise_optional(const optional<type> &data)
	{
		if (not data)
			throw (common::exception("GUI : Optional doesn't have value"));
	}

	class					symbol;
	class					font;

	class					renderers;

	using					renderers_type = unique_ptr<renderers>;
	extern renderers_type	renderers;

	class					object;
	class					property;
	class					owner;
	class					container;

	enum class				orientation
	{
		horizontal,
		vertical
	};

	class					rectangle;
	class 					label;
	class 					icon;
	class 					button;
	class					container;
	class					pack;
	class					button_pack;
	class					drawer;

	class					system;
}
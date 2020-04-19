#pragma once

#include "particle_system/namespace.h"

#include "particle_system/object/object.h"

class					particle_system::map : private vector<object>
{
public :

	explicit 			map(const string &source);
						~map() = default;

	using				vector<object>::at;
	using				vector<object>::size;

	object::type		string_to_object_type(const string &string);

	optional<string>	parse_string(const nlohmann::json &json);
	optional<float>		parse_float(const nlohmann::json &json);
	optional<vec3>		parse_vec3(const nlohmann::json &json);
};



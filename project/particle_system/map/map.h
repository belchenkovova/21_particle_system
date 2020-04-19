#pragma once

#include "particle_system/namespace.h"

#include "particle_system/object/object.h"

class						particle_system::map
{
public :

	explicit 				map(const string &source);
							~map() = default;

	const settings			&receive_settings()
	{
		return (settings);
	}

	const vector<object>	&receive_objects()
	{
		return (objects);
	}

private :

	settings				settings;
	vector<object>			objects;

	void					parse_settings(const nlohmann::json &json);
	void					parse_objects(const nlohmann::json &json);

	static object::type		string_to_object_type(const string &string);
	static vec3				string_to_color(const string &string);

	static optional<int>	parse_int(const nlohmann::json &json);
	static optional<float>	parse_float(const nlohmann::json &json);
	static optional<string>	parse_string(const nlohmann::json &json);
	static optional<vec3>	parse_vec3(const nlohmann::json &json);
};



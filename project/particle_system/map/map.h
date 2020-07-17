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

	template				<typename type>
	bool					parse_and_write(const nlohmann::json &source, const string &name, type &target)
	{
		auto				iterator = source.find(name);
		if (iterator == source.end())
			return (false);

		auto				value = parse<type>(iterator.value());
		if (not value)
			return (false);

		target = *value;
		return (true);
	}

	template				<typename type>
	static optional<type>	parse(const nlohmann::json &json)
	{
		return {};
	}

	template				<>
	optional<int>			parse<int>(const nlohmann::json &json)
	{
		return (json.is_number_integer() ? make_optional(json.get<int>()) : nullopt);
	}

	template				<>
	optional<float>			parse<float>(const nlohmann::json &json)
	{
		return (json.is_number_float() ? make_optional(json.get<float>()) : nullopt);
	}

	template				<>
	optional<string>		parse<string>(const nlohmann::json &json)
	{
		return (json.is_string() ? make_optional(json.get<string>()) : nullopt);

	}

	template				<>
	optional<ivec2>			parse<ivec2>(const nlohmann::json &json)
	{
		ivec2				result;

		for (int i = 0; i < 2; i++)
			if (auto value = parse<int>(json.at(i)); not value)
				return {};
			else
				result[i] = *value;
		return (result);
	}

	template				<>
	optional<vec3>			parse<vec3>(const nlohmann::json &json)
	{
		vec3				result;

		for (int i = 0; i < 3; i++)
			if (auto value = parse<float>(json.at(i)); not value)
				return {};
			else
				result[i] = *value;
		return (result);
	}

	template				<>
							optional<initialization>
							parse<initialization>(const nlohmann::json &json)
	{
		const auto			string = parse<particle_system::string>(json);

		if (not string)
			return {};
		if (*string == "null")
			return (initialization::null);
		else if (*string == "sphere")
			return (initialization::sphere);
		else if (*string == "cube")
			return (initialization::cube);
		else if (*string == "tetrahedron")
			return (initialization::tetrahedron);
		return {};
	}

	template				<>
							optional<object::type>
							parse<object::type>(const nlohmann::json &json)
	{
		const auto			string = parse<particle_system::string>(json);

		if (not string)
			return {};
		if (*string == "empty")
			return (object::type::empty);
		else if (*string == "attractor")
			return (object::type::attractor);
		else if (*string == "repeller")
			return (object::type::repeller);
		else if (*string == "emitter")
			return (object::type::emitter);
		else if (*string == "consumer")
			return (object::type::consumer);
		return {};
	}

	template				<>
	optional<color>			parse<color>(const nlohmann::json &json)
	{
		const auto			string = parse<particle_system::string>(json);

		if (not string)
			return {};

		if (*string == "white")
			return (color(1.f, 1.f, 1.f));
		else if (*string == "silver")
			return (color(0.75f, 0.75f, 0.75f));
		else if (*string == "gray")
			return (color(0.5f, 0.5f, 0.5f));
		else if (*string == "dark gray")
			return (color(0.1f, 0.1f, 0.1f));
		else if (*string == "black")
			return (color(0.0f, 0.0f, 0.0f));
		else if (*string == "red")
			return (color(1.0f, 0.0f, 0.0f));
		else if (*string == "maroon")
			return (color(0.5f, 0.0f, 0.0f));
		else if (*string == "yellow")
			return (color(1.0f, 1.0f, 0.0f));
		else if (*string == "olive")
			return (color(0.5f, 0.5f, 0.0f));
		else if (*string == "lime")
			return (color(0.0f, 1.0f, 0.0f));
		else if (*string == "green")
			return (color(0.0f, 0.5f, 0.0f));
		else if (*string == "aqua")
			return (color(0.0f, 1.0f, 1.0f));
		else if (*string == "teal")
			return (color(0.0f, 0.5f, 0.5f));
		else if (*string == "blue")
			return (color(0.0f, 0.0f, 1.0f));
		else if (*string == "navy")
			return (color(0.0f, 0.0f, 0.5f));
		else if (*string == "fuchsia")
			return (color(1.0f, 0.0f, 1.0f));
		else if (*string == "fuchsia")
			return (color(0.5f, 0.0f, 0.5f));
		return {};
	}
};



#include "map.h"

using namespace			particle_system;

						map::map(const string &source)
{
	auto				stream = ifstream(source);
	json				json;

	stream >> json;

	for (const auto& [key, value] : json.items())
	{
		auto			type_iterator = value.find("type");
		auto			position_iterator = value.find("position");
		auto			power_iterator = value.find("power");

		if (type_iterator == value.end())
			throw (common::exception("Particle System, Map : Object type is not defined"));
		if (position_iterator == value.end())
			throw (common::exception("Particle System, Map : Object position is not defined"));

		auto			type = parse_string(type_iterator.value());
		auto			position = parse_vec3(position_iterator.value());
		optional<float>	power;

		if (not type)
			throw (common::exception("Particle System, Map : Bad object type"));
		if (not position)
			throw (common::exception("Particle System, Map : Bad object position"));

		if (power_iterator != value.end())
			power = parse_float(power_iterator.value());

		emplace_back(string_to_object_type(*type), *position, power.value_or(1.f));
	}
}

object::type		map::string_to_object_type(const string &string)
{
	if (string == "empty")
		return (object::type::empty);
	else if (string == "attractor")
		return (object::type::attractor);
	else if (string == "repeller")
		return (object::type::repeller);
	else if (string == "emitter")
		return (object::type::emitter);
	else if (string == "consumer")
		return (object::type::consumer);
	else
		throw (common::exception("Particle System, Map : Bad object type"));
}

optional<string>	map::parse_string(const nlohmann::json &json)
{
	if (json.is_string())
		return (json.get<string>());
	else
		return {};
}

optional<float>		map::parse_float(const nlohmann::json &json)
{
	if (json.is_number_float())
		return (json.get<float>());
	else
		return {};
}

optional<vec3>		map::parse_vec3(const nlohmann::json &json)
{
	vec3			result;

	for (int i = 0; i < 3; i++)
		if (auto value = parse_float(json.at(i)); not value)
			return {};
		else
			result[i] = *value;

	return (result);
}
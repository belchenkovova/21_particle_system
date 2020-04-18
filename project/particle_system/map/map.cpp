#include "map.h"

using namespace			particle_system;

						map::map(const string &source)
{
	auto				stream = ifstream(source);
	json				json;

	auto				parse_type = [](const json::iterator &iterator) -> object::type
	{
		if (not iterator.value().is_string())
			throw (common::exception("Particle System, Map : Object type is not a string"));

		auto			value = iterator.value().get<string>();

		if (value == "attractor")
			return (object::type::attractor);
		else if (value == "repeller")
			return (object::type::repeller);
		else if (value == "emitter")
			return (object::type::emitter);
		else if (value == "consumer")
			return (object::type::consumer);
		else
			throw (common::exception("Particle System, Map : Bad object type"));
	};

	auto				parse_position = [](const json::iterator &iterator) -> vec3
	{
		auto			parse_float = [](const nlohmann::json &json) -> optional<float>
		{
			if (not json.is_number_float())
				return nullopt;
			return (json.get<float>());
		};

		if (not iterator.value().is_array())
			throw (common::exception("Particle System, Map : Object position is not an array"));

		vec3			result;

		for (int i = 0; i < 3; i++)
			if (auto	value = parse_float(iterator->at(i)); not value)
				throw (common::exception("Particle System, Map : Object position has bad content"));
			else
				result[i] = *value;

		return (result);
	};

	stream >> json;

	for (const auto& [key, value] : json.items())
	{
		auto			type_iterator = value.find("type");
		auto			position_iterator = value.find("position");

		if (type_iterator == value.end())
			throw (common::exception("Particle System, Map : Object type is not defined"));
		if (position_iterator == value.end())
			throw (common::exception("Particle System, Map : Object position is not defined"));

		auto			type = parse_type(type_iterator);
		auto			position = parse_position(position_iterator);

		emplace_back(type, position);
	}
}

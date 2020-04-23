#include "map.h"

using namespace			particle_system;

						map::map(const string &source)
{
	auto				stream = ifstream(source);
	json				json;

	stream >> json;

	auto				settings = json.find("settings");
	auto				objects = json.find("objects");

	if (objects == json.end())
		throw (common::exception("Particle System, Map : Object array is not present"));

	if (settings != json.end())
		parse_settings(settings.value());
	parse_objects(objects.value());
}

void					map::parse_settings(const nlohmann::json &json)
{
	parse_and_write(json, "number_of_particles", settings.number_of_particles);
	parse_and_write(json, "start_color", settings.start_color);
	parse_and_write(json, "finish_color", settings.finish_color);
	parse_and_write(json, "background", settings.background);
	parse_and_write(json, "initialization", settings.initialization);
}

void					map::parse_objects(const nlohmann::json &json)
{
	for (const auto &[key, value] : json.items())
	{
		auto			type_iterator = value.find("type");
		auto			position_iterator = value.find("position");
		auto			power_iterator = value.find("power");

		if (type_iterator == value.end())
			throw (common::exception("Particle System, Map : Object type is not defined"));
		if (position_iterator == value.end())
			throw (common::exception("Particle System, Map : Object position is not defined"));

		auto			type = parse<object::type>(type_iterator.value());
		auto			position = parse<vec3>(position_iterator.value());
		optional<float>	power;

		if (not type)
			throw (common::exception("Particle System, Map : Bad object type"));
		if (not position)
			throw (common::exception("Particle System, Map : Bad object position"));

		if (power_iterator != value.end())
			power = parse<float>(power_iterator.value());

		objects.emplace_back(*type, *position, power.value_or(1.f));
	}
}

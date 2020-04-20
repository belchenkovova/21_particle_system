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
	for (;;)
	{
		auto			iterator = json.find("number_of_particles");
		if (iterator == json.end())
			break ;

		auto			value = parse_int(iterator.value());
		if (not value)
			break ;

		settings.number_of_particles = *value;
		break ;
	}

	for (;;)
	{
		auto			iterator = json.find("start_color");
		if (iterator == json.end())
			break ;

		auto			value = parse_string(iterator.value());
		if (not value)
			break ;

		settings.start_color = string_to_color(*value);
		break ;
	}

	for (;;)
	{
		auto			iterator = json.find("finish_color");
		if (iterator == json.end())
			break ;

		auto			value = parse_string(iterator.value());
		if (not value)
			break ;

		settings.finish_color = string_to_color(*value);
		break ;
	}

	for (;;)
	{
		auto			iterator = json.find("initialization");
		if (iterator == json.end())
			break ;

		auto			value = parse_string(iterator.value());
		if (not value)
			break ;

		settings.initialization = string_to_initialization(*value);
		break ;
	}
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

		auto			type = parse_string(type_iterator.value());
		auto			position = parse_vec3(position_iterator.value());
		optional<float>	power;

		if (not type)
			throw (common::exception("Particle System, Map : Bad object type"));
		if (not position)
			throw (common::exception("Particle System, Map : Bad object position"));

		if (power_iterator != value.end())
			power = parse_float(power_iterator.value());

		objects.emplace_back(string_to_object_type(*type), *position, power.value_or(1.f));
	}
}

initialization		map::string_to_initialization(const string &string)
{
	if (string == "null")
		return (initialization::null);
	else if (string == "sphere")
		return (initialization::sphere);
	else if (string == "cube")
		return (initialization::cube);
	else if (string == "tetrahedron")
		return (initialization::tetrahedron);
	else
		throw (common::exception("Particle System, Map : Bad initialization method"));
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

vec3				map::string_to_color(const string &string)
{
	vec3			result_in_255;

	if (string == "white")
		result_in_255 = vec3(255, 255, 255);
	else if (string == "silver")
		result_in_255 = vec3(192, 192, 192);
	else if (string == "gray")
		result_in_255 = vec3(128, 128, 128);
	else if (string == "black")
		result_in_255 = vec3(0, 0, 0);
	else if (string == "red")
		result_in_255 = vec3(255, 0, 0);
	else if (string == "maroon")
		result_in_255 = vec3(128, 0, 0);
	else if (string == "yellow")
		result_in_255 = vec3(255, 255, 0);
	else if (string == "olive")
		result_in_255 = vec3(128, 128, 0);
	else if (string == "lime")
		result_in_255 = vec3(0, 255, 0);
	else if (string == "green")
		result_in_255 = vec3(0, 128, 0);
	else if (string == "aqua")
		result_in_255 = vec3(0, 255, 255);
	else if (string == "teal")
		result_in_255 = vec3(0, 128, 128);
	else if (string == "blue")
		result_in_255 = vec3(0, 0, 255);
	else if (string == "navy")
		result_in_255 = vec3(0, 0, 128);
	else if (string == "fuchsia")
		result_in_255 = vec3(255, 0, 255);
	else if (string == "purple")
		result_in_255 = vec3(128, 0, 128);
	else
		throw (common::exception("Particle System, Map : Bad color"));
	return (result_in_255 / 255.f);
}

optional<int>		map::parse_int(const nlohmann::json &json)
{
	if (json.is_number_integer())
		return (json.get<int>());
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

optional<string>	map::parse_string(const nlohmann::json &json)
{
	if (json.is_string())
		return (json.get<string>());
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
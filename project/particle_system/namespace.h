#pragma once

#include "engine/engine.h"
#include "computer/computer.h"

#include "external/json.hpp"


namespace				particle_system
{
	using				std::string;
	using				std::vector;
	using				std::make_optional;
	using				std::optional;
	using				std::nullopt;
	using				std::ifstream;
	using				std::move;
	using				std::fill;
	using				std::filesystem::exists;
	using				std::function;
	using				std::is_null_pointer;
	using				std::is_same;

	using				glm::vec3;

	using				json = nlohmann::json;

	enum class			initialization
	{
		null,
		sphere,
		cube,
		tetrahedron
	};

	class				color : public vec3
	{
	public :

		template		<typename ...args_type>
						color(args_type ...args) : vec3(args...) {}
	};

	class				settings
	{
	public:
		int				number_of_particles = 10000;
		color			start_color = color(1.f, 1.f, 1.f);
		color			finish_color = color(1.f, 1.f, 1.f);
		color			background = color(0.f, 0.f, 0.f);
		initialization	initialization = initialization::sphere;
	};

	class				object;
	class				map;
	class				manager;
}
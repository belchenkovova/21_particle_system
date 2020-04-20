#pragma once

#include "engine/engine.h"
#include "computer/computer.h"

#include "external/json.hpp"


namespace				particle_system
{
	using				std::string;
	using				std::vector;
	using				std::optional;
	using				std::nullopt;
	using				std::ifstream;
	using				std::move;
	using				std::fill;

	using				glm::vec3;

	using				json = nlohmann::json;

	enum class			initialization
	{
		null,
		sphere,
		cube,
		tetrahedron
	};

	class				settings
	{
	public:
		int				number_of_particles = 10000;
		vec3			start_color = vec3(1.f, 1.f, 1.f);
		vec3			finish_color = vec3(1.f, 1.f, 1.f);
		initialization	initialization = initialization::sphere;
	};

	class				object;
	class				map;
	class				manager;
}
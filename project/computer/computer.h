#pragma once

#include "engine/engine.h"
#include <limits>
#include <array>
#include <random>

class				particle
{
public :

					particle() = default;
	explicit		particle(const glm::vec3 &position);
					~particle() = default;

	void			invert_speed();
	void			update(const float &new_timestamp);
	bool 			is_alive();

	glm::vec3		read_position();
	void			write_power(const glm::vec3 &value);

private :

	glm::vec3		position{0.f, 0.f, 0.f};
	glm::vec3		gravity{0.f, -9.8f, 0.f};
	glm::vec3		power{0.f, 0.f, 0.f};
	glm::vec3		speed{0.f, 0.f, 0.f};
	float 			attenuation{3.33f};
	float			lifetime{std::numeric_limits<float>::infinity()};
	float			last_timestamp{0.f};
};

class				explosion
{
private :

	using			alias_particles = std::array<particle, 100>;

public :

					explosion(const glm::vec3 &position, const float &power);
					~explosion() = default;

	void			update();
	void			draw();

private :

	glm::vec2		construct_bounds{-5.f, +5.f};
	glm::vec2		position_bounds{-100.f, +100.f};

	glm::vec3		position{0.f, 0.f, 0.f};
	float			power{0.f};

	alias_particles	particles{};
	engine::buffer	buffer;
};

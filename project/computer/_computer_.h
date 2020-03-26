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
	glm::vec3		gravity{0.f, -5.0f, 0.f};
	glm::vec3		power{0.f, 0.f, 0.f};
	glm::vec3		speed{0.f, 0.f, 0.f};
	float 			attenuation{0.f};
	float			lifetime{std::numeric_limits<float>::infinity()};
	float			last_timestamp{0.f};
};

class				explosion
{
public :

#define M1			10000

					explosion(engine::buffer &buffer, const glm::vec3 &position, const float &power);
					~explosion() = default;

	void			upload();

	static void 	functor(void *ptr);

private :

	glm::vec2		construct_bounds{-1.f, +1.f};
	glm::vec2		construct_dead_zone{-0.05f, +.05f};
	glm::vec2		position_bounds{-100.f, +100.f};

	glm::vec3		position{0.f, 0.f, 0.f};
	float			power{0.f};

	using			particles_ = std::array<particle, M1>;
	particles_		particles{};
	engine::buffer	&buffer;
};

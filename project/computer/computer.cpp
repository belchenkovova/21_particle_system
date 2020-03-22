#include "computer.h"


//				PARTICLE


				particle::particle(const glm::vec3 &position) :
				position(position)
{}

void			particle::invert_speed()
{
	speed *= -1 * attenuation;
}

void			particle::update(const float &new_timestamp)
{
	const float	delta = new_timestamp - last_timestamp;

	lifetime -= delta;
	last_timestamp = new_timestamp;

	for (int i = 0; i < 3; i++)
	{
		if (power[i] > 0)
		{
			power[i] -= attenuation * delta;
			if (power[i] <= 0)
				power[i] = 0;
		}

		position[i] += speed[i] * delta + (gravity[i] + power[i]) * delta * delta;
		speed[i] += (gravity[i] + power[i]) * delta;
	}
}

bool 			particle::is_alive()
{
	return (lifetime > 0);
}

glm::vec3		particle::read_position()
{
	return (position);
}

void			particle::write_power(const glm::vec3 &value)
{
	power = value;
}


//				EXPLOSION


				explosion::explosion(const glm::vec3 &position, const float &power) :
				position(position),
				power(power)
{
	std::default_random_engine			engine;
	std::uniform_real_distribution 		distribution(construct_bounds[0], construct_bounds[1]);
	glm::vec3	random_position;

	for (auto &particle : particles)
	{
		for (int i = 0; i < 3; i++)
			random_position[i] = distribution(engine);
		particle = ::particle(random_position);
		particle.write_power(random_position - position);
	}
}

void 			explosion::update()
{

}
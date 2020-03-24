#include "computer.h"


//				PARTICLE


				particle::particle(const glm::vec3 &position) :
				position(position)
{}

void			particle::invert_speed()
{
	speed.y *= -1 * 2.;
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
	power = glm::normalize(value);
}


//				EXPLOSION


				explosion::explosion(engine::buffer &buffer, const glm::vec3 &position, const float &power) :
				buffer(buffer),
				position(position),
				power(power)
{
	std::default_random_engine			engine;
	std::uniform_int_distribution		distribution(0, 1);
	std::uniform_real_distribution 		distribution_left(construct_bounds[0], construct_dead_zone[0]);
	std::uniform_real_distribution 		distribution_right(construct_bounds[1], construct_dead_zone[1]);
	glm::vec3	random_position;

	for (auto &particle : particles)
	{
		for (int i = 0; i < 3; i++)
		{
			if (distribution(engine) == 0)
				random_position[i] = distribution_left(engine);
			else
				random_position[i] = distribution_right(engine);
		}
		particle = ::particle(random_position);
		particle.write_power(random_position - position);
	}
}

void 			explosion::functor(void *ptr)
{
	static float	time = 0.f;
	auto		explosion = (class explosion *)ptr;

	time += .1f;
	for (auto &particle : explosion->particles)
	{
		particle.update(time);
		if (particle.read_position().y < -50)
			particle.invert_speed();
	}
	explosion->upload();
}

void 			explosion::upload()
{
	for (int i = 0; i < M1; i++)
		for (int j = 0; j < 3; j++)
			buffer.receive_points()[i * 3 + j] = particles[i].read_position()[j];
	buffer.receive_points().upload();
}
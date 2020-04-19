#pragma once

#include "particle_system/namespace.h"

class 				particle_system::object
{
public :

	enum class		type
	{
		empty,
		attractor,
		repeller,
		emitter,
		consumer
	};

					object(type type, const vec3 &position, float power = 1.f) :
					type_value(type), position(position), power(power) {}
					~object() = default;

	[[nodiscard]]
	type			read_type() const
	{
		return (type_value);
	}

	[[nodiscard]]
	vec3			read_position() const
	{
		return (position);
	}

	[[nodiscard]]
	float		read_power() const
	{
		return (power);
	}

private :

	const enum type	type_value;
	const vec3		position;
	const float		power;
};
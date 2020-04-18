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

					object(type type, const glm::vec3 &position) :
					type_(type), position(position) {}
					~object() = default;

	[[nodiscard]]
	type			read_type() const
	{
		return (type_);
	}

	[[nodiscard]]
	glm::vec3		read_position() const
	{
		return (position);
	}

private :

	const enum type	type_;
	const glm::vec3	position;
};
#pragma once

#include "engine/namespace.h"

class					engine::camera
{
public :

	static inline float		movement_speed = 0.f;
	static inline float		rotation_speed = 0.f;
	static inline auto		start_position = vec3(0.f, 0.f, 0.f);
	static inline float		start_yaw = -90.f;
	static inline float		start_pitch = 0.f;
	static inline float		near_plane = 0.1f;
	static inline float		far_plane = 100.f;

							camera();
							~camera() = default;

	void					move(const axis &axis, const sign &sign);
	void					rotate(const axis &axis, const sign &sign);

	[[nodiscard]]
	mat4					receive_projection_matrix() const;
	[[nodiscard]]
	mat4					receive_view_matrix() const;

	[[nodiscard]]
	float					distance_to_point(const vec3 &point)
	{
		return (glm::dot(point - position, front));
	}

	[[nodiscard]] vec3		read_position() const
	{
		return (position);
	}

	[[nodiscard]] vec3		read_front() const
	{
		return (front);
	}

	[[nodiscard]] vec3		read_up() const
	{
		return (up);
	}

	[[nodiscard]] vec3		read_right() const
	{
		return (right);
	}

private :

	const vec3				up_const = vec3(0.f, 1.f, 0.f);
	vec3					position = start_position;
	vec3					front = vec3(0.f, 0.f, -1.f);
	vec3					up = up_const;
	vec3					right = vec3(0.f, 0.f, 0.f);

	float					yaw = start_yaw;
	float					pitch = start_pitch;

	void					update();
};

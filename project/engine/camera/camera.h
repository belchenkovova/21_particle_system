#pragma once

#include "engine/namespace.h"
#include "engine/core/core.h"

class					engine::camera
{
public :

	static inline float		movement_speed{0.f};
	static inline float		rotation_speed{0.f};
	static inline glm::vec3	start_position{0.f, 0.f, 0.f};
	static inline float		start_yaw{-90.f};
	static inline float		start_pitch{0.f};
	static inline float		near_plane{0.1f};
	static inline float		far_plane{100.f};

							camera();
							~camera() = default;

	void					move(const axis &axis, const sign &sign);
	void					rotate(const axis &axis, const sign &sign);

	[[nodiscard]]
	glm::mat4				receive_projection_matrix();
	[[nodiscard]]
	glm::mat4				receive_view_matrix();

private :

	const glm::vec3			up_const{0.f, 1.f, 0.f};
	glm::vec3				position{start_position};
	glm::vec3				front{0.f, 0.f, -1.f};
	glm::vec3				up{up_const};
	glm::vec3				right{0.f, 0.f, 0.f};

	float					yaw{start_yaw};
	float					pitch{start_pitch};

	float					zoom{1.f};

	void					update();
};

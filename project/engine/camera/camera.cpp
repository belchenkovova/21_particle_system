#include "camera.h"

using namespace		engine;

					camera::camera()
{
	update();
}

void				camera::move(const axis &axis, const sign &sign)
{
	if (axis == axis::x)
		position += right * movement_speed * (float)sign;
	else if (axis == axis::y)
		position += up * movement_speed * (float)sign;
	else if (axis == axis::z)
		position += front * movement_speed * -1.f * (float)sign;
}

void				camera::rotate(const axis &axis, const sign &sign)
{
	if (axis == axis::x)
		pitch += (float)sign * rotation_speed;
	else if (axis == axis::y)
		yaw += -1.f * (float)sign * rotation_speed;
	update();
}

glm::mat4			camera::receive_projection_matrix()
{
	return (glm::perspective(
		glm::radians(45.f),
		(float)core::window_width / (float)core::window_height,
		near_plane, far_plane));
}

glm::mat4			camera::receive_view_matrix()
{
	return (glm::lookAt(position, position + front, up));
}

void				camera::update()
{
	glm::vec3		local_front;

	local_front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	local_front.y = sin(glm::radians(pitch));
	local_front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	front = glm::normalize(local_front);
	right = glm::normalize(glm::cross(front, up_const));
	up = glm::normalize(glm::cross(right, front));
}

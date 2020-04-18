#include "camera.h"
#include "engine/core/core.h"

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

mat4				camera::receive_projection_matrix() const
{
	return (perspective(
		radians(45.f),
		(float)core::read_window_size().x / (float)core::read_window_size().y,
		near_plane, far_plane));
}

mat4				camera::receive_view_matrix() const
{
	return (lookAt(position, position + front, up));
}

void				camera::update()
{
	vec3			local_front;

	local_front.x = cos(radians(yaw)) * cos(radians(pitch));
	local_front.y = sin(radians(pitch));
	local_front.z = sin(radians(yaw)) * cos(radians(pitch));
	front = normalize(local_front);
	right = normalize(cross(front, up_const));
	up = normalize(cross(right, front));
}

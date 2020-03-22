#pragma once

#include "engine/namespace.h"
#include "engine/OpenGL_objects/vbo.h"
#include "engine/OpenGL_objects/vao.h"

class						engine::buffer : private engine::vao
{
private :

	using 					a_memory_management = engine::vbo::memory_management;

	using 					a_vbo_interface = engine::vbo::interface;

	template				<typename t_type, int t_group, a_memory_management t_management>
	using					a_vbo = engine::vbo::implementation<t_type, t_group, t_management>;
	template				<typename t_type, int t_group, a_memory_management t_management>
	using					a_vbo_ptr = std::shared_ptr<a_vbo<t_type, t_group, t_management>>;

	using					a_vbo_point = a_vbo<GLfloat, 3, a_memory_management::stream>;
	using					a_vbo_point_ptr = a_vbo_ptr<GLfloat, 3, a_memory_management::stream>;

public :

							buffer();
							~buffer() = default;

	using					vao::bind;

	std::vector<GLfloat>	&read_points();

	void					upload_points();

private :

	a_vbo_point_ptr			points{nullptr};
	vao						vao;
};



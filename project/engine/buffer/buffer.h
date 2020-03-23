#pragma once

#include "engine/namespace.h"
#include "engine/OpenGL_objects/vbo.h"
#include "engine/OpenGL_objects/vao.h"

class						engine::buffer : private engine::vao
{
private :

	using 					alias_memory_management = engine::vbo::memory_management;

	using 					alias_vbo_interface = engine::vbo::interface;

	template				<typename t_type, int t_group, alias_memory_management t_management>
	using					alias_vbo = engine::vbo::implementation<t_type, t_group, t_management>;
	template				<typename t_type>
	using					alias_ptr = std::shared_ptr<t_type>;

	using					alias_vbo_point = alias_vbo<GLfloat, 3, alias_memory_management::stream>;
	using					alias_vbo_point_ptr = alias_ptr<alias_vbo_point>;

public :

	inline static int		size{0};

							buffer();
	virtual					~buffer() = default;

	using					vao::bind;

	[[nodiscard]]
	alias_vbo_point			&receive_points();

protected :

	int 					local_size{0};

private :

	alias_vbo_point_ptr		points{nullptr};
	vao						vao;
};



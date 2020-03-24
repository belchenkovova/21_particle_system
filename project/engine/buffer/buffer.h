#pragma once

#include "engine/namespace.h"
#include "vbo.h"
#include "vao.h"

class						engine::buffer : private engine::vao
{
	using					vbo_point = vbo::real<GLfloat, 3, vbo::memory_management::stream>;

public :

	inline static int		size{0};

							buffer();
	virtual					~buffer() = default;

	using					vao::bind;

	[[nodiscard]]
	vbo_point				&receive_points();

protected :

	int 					local_size{0};

private :

	vbo_point				points;
	vao						vao;
};



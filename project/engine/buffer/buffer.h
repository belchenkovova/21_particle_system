#pragma once

#include "engine/namespace.h"
#include "vbo.h"
#include "vao.h"

class					engine::buffer : private engine::vao
{
public :

	using				vbo_point = vbo::real<GLfloat, 3, vbo::memory_management::stream>;

	explicit			buffer(int size);
	virtual				~buffer() = default;

	using				vao::bind;

	[[nodiscard]]
	vbo_point			*receive_points();

protected :

	int 				size{0};

private :

	vbo_point			points;
	vao					vao;
};



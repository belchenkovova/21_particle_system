#pragma once

#include "engine/namespace.h"
#include "vbo.h"
#include "vao.h"

class						engine::buffer : private engine::vao
{
public :

	explicit				buffer(int size);
	virtual					~buffer() = default;

	using					vao::bind;

	[[nodiscard]]
	inline vbo::real<>		&receive_points()
	{
		return (*points);
	}

	[[nodiscard]]
	inline int 				read_size() const
	{
		return (size);
	}

private :

	int 					size{0};
	shared_ptr<vbo::real<>>	points;
};



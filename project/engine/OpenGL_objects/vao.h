#pragma once

#include "engine/namespace.h"
#include "vbo.h"

class 				engine::vao
{
private :

	using			a_vbo = engine::vbo::interface;
	using			a_vbo_ptr = std::shared_ptr<a_vbo>;
	using			a_vbo_vector = std::vector<a_vbo_ptr>;

public :

					vao();
					~vao();

	void 			bind(const bool& state);
	void 			add_attribute(const a_vbo_ptr &vbo);

private :

	GLuint			object{0};
	a_vbo_vector	attributes;
};
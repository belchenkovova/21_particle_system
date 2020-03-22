#pragma once

#include "engine/namespace.h"
#include "vbo.h"

class 				engine::vao
{
private :

	using				alias_vbo = engine::vbo::interface;
	using				alias_vbo_ptr = std::shared_ptr<alias_vbo>;
	using				alias_vbo_vector = std::vector<alias_vbo_ptr>;

public :

						vao();
						~vao();

	void 				bind(const bool& state);
	void 				add_attribute(const alias_vbo_ptr &vbo);

private :

	GLuint				object{0};
	alias_vbo_vector	attributes;
};
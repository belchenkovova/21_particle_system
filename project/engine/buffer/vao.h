#pragma once

#include "engine/namespace.h"
#include "vbo.h"

class 									engine::vao
{
public :

										vao();
										~vao();

	void 								bind(const bool& state);
	void 								add_attribute(const reference<vbo::abstract> &vbo);

private :

	GLuint								object{0};
	vector<reference<vbo::abstract>>	attributes;
};
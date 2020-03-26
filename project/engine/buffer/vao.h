#pragma once

#include "engine/namespace.h"
#include "vbo.h"

class 									engine::vao : public engine::object_wrapper
{
public :

										vao();
										~vao();

	void 								bind(const bool& state);
	void 								add_attribute(const reference<vbo::abstract> &vbo);

private :

	vector<reference<vbo::abstract>>	attributes;
};
#pragma once

#include "engine/namespace.h"

class 									engine::vao : public engine::object_wrapper
{
public :

										vao();
										~vao();

	void 								bind(bool state) const;
	void 								add_attribute(const shared_ptr<vbo::abstract> &vbo);

	[[nodiscard]]
	shared_ptr<vbo::abstract>			receive_vbo(int index)
	{
		return (attributes[index]);
	}

private :

	vector<shared_ptr<vbo::abstract>>	attributes;
};
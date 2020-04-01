#pragma once

#include "engine/namespace.h"
#include "engine/vbo/vbo.h"

class 									engine::vao : public engine::object_wrapper<GLuint>
{
public :

										vao();
										~vao() override;

	void 								bind(bool state) const;


	template							<typename t_type = float,
										int t_group = 3,
										memory_management t_management = memory_management::stream>
	vbo::abstract						&generate_attribute()
	{
		shared_ptr<vbo::abstract>		vbo = make_shared<vbo::real<t_type, t_group, t_management>>();

		bind(true);
		vbo->bind(true);
		glVertexAttribPointer(
			attributes.size(),
			vbo->read_group(),
			vbo->read_type(),
			GL_FALSE,
			vbo->read_step(),
			nullptr);
		glEnableVertexAttribArray(attributes.size());
		vbo->bind(false);
		bind(false);
		attributes.push_back(vbo);

		return (*vbo);
	}

	[[nodiscard]]
	vbo::abstract						&receive_attribute(int index);
	[[nodiscard]]
	shared_ptr<vbo::abstract>			receive_attribute_as_pointer(int index);

protected :

	vector<shared_ptr<vbo::abstract>>	attributes;
};
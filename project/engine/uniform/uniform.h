#pragma once

#include "engine/namespace.h"

class				engine::uniform final : private engine::object_wrapper<GLint>
{
public :

	explicit		uniform(const string &name);
					~uniform() override = default;

	void 			connect(GLuint program);

	void 			upload(int data);
	void 			upload(float data);
	void 			upload(const glm::vec3 &data);
	void 			upload(const glm::mat4 &data);

private :

	const string	name;
	bool			is_connected{false};

	void			check_connection();
};



#pragma once

#include "engine/namespace.h"

class				engine::uniform final : private engine::object_wrapper<GLint>
{
public :

	explicit		uniform(const string &name);
					~uniform() override = default;

	void 			connect(GLuint program);

	void 			upload(int data) const;
	void 			upload(float data) const;
	void 			upload(const glm::vec3 &data) const;
	void 			upload(const glm::mat4 &data) const;

private :

	const string	name;
	bool			is_connected{false};

	void			check_connection() const;
};



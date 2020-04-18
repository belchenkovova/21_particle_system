#pragma once

#include "engine/namespace.h"

class				engine::uniform final : private engine::object_wrapper<GLint>
{
public :

					uniform(const string &name, GLuint program);
					~uniform() override = default;

	void 			upload(int data) const;
	void 			upload(float data) const;
	void 			upload(const vec3 &data) const;
	void 			upload(const vec4 &data) const;
	void 			upload(const mat4 &data) const;

	template 		<typename type>
	void 			upload(type) const = delete;

private :

	const string	name;
};



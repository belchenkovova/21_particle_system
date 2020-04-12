#pragma once

#include "engine/namespace.h"
#include "engine/point/point.h"

class				engine::texture : private object_wrapper<GLuint>
{
public :

	explicit		texture(
					const point &size,
					GLuint internal_format = GL_RGB,
					GLuint format = GL_RGB,
					GLuint type = GL_UNSIGNED_BYTE,
					const void *data = nullptr);
	explicit		texture(const string &source);
					~texture() override;

	void			bind(bool state) const;

	[[nodiscard]]
	auto 			read_size() const
	{
		return (size);
	}

private :

	point			size;
};



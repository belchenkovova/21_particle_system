#pragma once

#include "engine/namespace.h"

class				engine::texture : private object_wrapper<GLuint>
{
public :

					texture(
					int width,
					int height,
					GLuint internal_format = GL_RGB,
					GLuint format = GL_RGB,
					GLuint type = GL_UNSIGNED_BYTE,
					const void *data = nullptr);
					~texture();

	void			bind(bool state) const;

private :

	const int 		width;
	const int		height;
};



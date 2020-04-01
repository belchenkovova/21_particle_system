#include "texture.h"

using namespace		engine;

					texture::texture(
					int width,
					int height,
					GLuint internal_format,
					GLuint format,
					GLuint type,
					const void *data) :
					width(width),
					height(height)
{
	glGenTextures(1, &object);

	bind(true);

	glTexImage2D(GL_TEXTURE_2D, 0, internal_format, width, height, 0, format, type, data);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	bind(false);
}

					texture::~texture()
{
	glDeleteTextures(1, &object);
}

void				texture::bind(bool state) const
{
	glBindTexture(GL_TEXTURE_2D, state ? object : 0);
}
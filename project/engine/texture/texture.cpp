#include "texture.h"

using namespace		engine;

					texture::texture(
					const point &size,
					GLuint internal_format,
					GLuint format,
					GLuint type,
					const void *data) :
					size(size)
{
	glGenTextures(1, &object);

	bind(true);

	glTexImage2D(GL_TEXTURE_2D, 0, internal_format, size.x, size.y, 0, format, type, data);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	bind(false);
}

					texture::texture(const string &source)
{
	auto			data = SOIL_load_image(source.c_str(), &size.x, &size.y, nullptr, SOIL_LOAD_RGBA);

	if (data == nullptr)
		throw (common::exception("Engine, Texture : Can't create texture from given source"));

	glGenTextures(1, &object);

	bind(true);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, size.x, size.y, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	bind(false);

	SOIL_free_image_data(data);
}

					texture::~texture()
{
	glDeleteTextures(1, &object);
}

void				texture::bind(bool state) const
{
	glBindTexture(GL_TEXTURE_2D, state ? object : 0);
}
#include "ebo.h"

using namespace		engine;

					ebo::ebo() : object_wrapper()
{
	glGenBuffers(1, &object);
}

					ebo::~ebo()
{
	glDeleteBuffers(1, &object);
}

void				ebo::bind(bool state) const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, state ? object : 0);
}

void				ebo::resize(int size)
{
	vector<unsigned int>::resize(size);
}

GLuint				ebo::read_size() const
{
	return (vector<unsigned int>::size());
}


void				ebo::save()
{
	bind(true);
	glBufferData(
		GL_ELEMENT_ARRAY_BUFFER,
		sizeof(unsigned int) * read_size(),
		std::vector<unsigned int>::data(),
		GL_STATIC_DRAW);
	bind(false);
}
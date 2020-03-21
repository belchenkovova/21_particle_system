#include "program.h"

using namespace		engine;

					program::program()
{
	object = glCreateProgram();
}

					program::~program()
{
	glDeleteProgram(object);
}

void				program::attach(const shader &shader)
{
	glAttachShader(object, shader.object);
}

void				program::link()
{
	GLint			success;
	GLchar			infoLog[512];

	glLinkProgram(object);
	glGetProgramiv(object, GL_LINK_STATUS, &success);
	if (not success)
	{
		glGetProgramInfoLog(object, 512, nullptr, infoLog);
		throw (tools::exception("Engine, Program : Compilation error"));
	}
}


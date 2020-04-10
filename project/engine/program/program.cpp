#include "program.h"

using namespace		engine;

					program::program() : object_wrapper()
{
	object = glCreateProgram();
}

					program::~program()
{
	glDeleteProgram(object);
}

void				program::attach_shader(shader::type type, const string &source)
{
	attach_shader(temporary_shaders.emplace_back(type, source));
}

void				program::attach_shader(const shader &shader)
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
		throw (common::exception("Engine, Program : Compilation error"));
	}
}

void				program::use(const bool &state) const
{
	glUseProgram(state ? object : 0);
}
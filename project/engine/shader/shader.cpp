#include "shader.h"

using namespace		engine;

					shader::shader(type type, const string &source) :
					object_wrapper()
{
	string		file = common::read_file(source);
	const char		*file_c = file.c_str();

	object = glCreateShader(static_cast<GLuint>(type));
	glShaderSource(object, 1, &file_c, nullptr);
	glCompileShader(object);
	GLint success;
	GLchar infoLog[512];
	glGetShaderiv(object, GL_COMPILE_STATUS, &success);
	if (not success)
	{
		glGetShaderInfoLog(object, 512, nullptr, infoLog);
		throw (common::exception("Engine, Shader : Compilation error"));
	}
}

					shader::~shader()
{
	glDeleteShader(object);
}

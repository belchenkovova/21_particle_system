#pragma once

#pragma message "Debug version only"
static inline const char	*decode_OpenGL_error(GLenum value)
{
	if (value == GL_INVALID_ENUM)
		return ("Invalid enum");
	else if (value == GL_INVALID_VALUE)
		return ("Invalid value");
	else if (value == GL_INVALID_OPERATION)
		return ("Invalid operation");
	else
		return ("Unknown");
}

#define DEBUG_MODE	1

#define DEBUG_GL	if (GLenum x = glGetError(); DEBUG_MODE && x) { printf("%s, %d : %s (%d)\n", __FILE__, __LINE__, decode_OpenGL_error(x), x); exit(1); }
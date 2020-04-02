#include "uniform.h"

using namespace		engine;

					uniform::uniform(const string &name) :
					name(name)
{}

void 				uniform::connect(GLuint program)
{
	object = glGetUniformLocation(program, name.c_str());
	is_connected = object != -1;
}

void				uniform::check_connection()
{
	if (not is_connected)
		throw (common::exception("Engine, Uniform : Object is not connected"));
}

void 			uniform::upload(int data)
{
	check_connection();
	glUniform1i(object, data);
}

void 			uniform::upload(float data)
{
	check_connection();
	glUniform1f(object, data);
}

void 			uniform::upload(const glm::vec3 &data)
{
	check_connection();
	glUniform3f(object, data.x, data.y, data.z);
}

void 			uniform::upload(const glm::mat4 &data)
{
	check_connection();
	glUniformMatrix4fv(object, 1, GL_FALSE, glm::value_ptr(data));
}

#include "uniform.h"

using namespace		engine;

					uniform::uniform(const string &name, GLuint program) :
					name(name)
{
	object = glGetUniformLocation(program, name.c_str());
	if (object == -1)
		throw (common::exception("Engine, Uniform : Can't create object"));
}

void 			uniform::upload(int data) const
{
	glUniform1i(object, data);
}

void 			uniform::upload(float data) const
{
	glUniform1f(object, data);
}

void 			uniform::upload(const glm::vec3 &data) const
{
	glUniform3f(object, data.x, data.y, data.z);
}

void 			uniform::upload(const glm::vec4 &data) const
{
	glUniform4f(object, data.x, data.y, data.z, data.w);
}

void 			uniform::upload(const glm::mat4 &data) const
{
	glUniformMatrix4fv(object, 1, GL_FALSE, glm::value_ptr(data));
}

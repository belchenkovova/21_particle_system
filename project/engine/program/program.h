#pragma once

#include "engine/namespace.h"
#include "engine/shader/shader.h"
#include "engine/uniform/uniform.h"

class						engine::program : public object_wrapper<GLuint>
{
public :
							program();
							~program() override;

	void					attach_shader(shader::type type, const string &source);
	void					attach_shader(const shader &shader);
	void 					link();
	void					use(const bool &state) const;

	template 				<typename type>
	void					upload_uniform(const string &name, type data)
	{
		auto				uniform = uniforms.find(name);

		use(true);
		if (uniform == uniforms.end())
			tie(uniform, ignore) = uniforms.emplace(
				piecewise_construct,
				forward_as_tuple(name),
				forward_as_tuple(name, object));
		uniform->second.upload(data);
		use(false);
	}

private :

	vector<shader>			temporary_shaders;
	map<string, uniform>	uniforms;
};



#pragma once

#include "engine/namespace.h"
#include "engine/shader/shader.h"

class						engine::program : public object_wrapper
{
	friend class			engine::renderer;

public :
							program();
	virtual					~program();

	void					attach_shader(shader::type type, const std::string &source);
	void					attach_shader(const shader &shader);
	void 					link();
	void					use(const bool &state);

	vector<shader>			temporary_shaders;
};



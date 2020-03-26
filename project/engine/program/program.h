#pragma once

#include "engine/namespace.h"
#include "shader.h"

class						engine::program : public object_wrapper
{
	friend class			engine::renderer;

public :
							program();
	virtual					~program();

	void					attach(const shader &shader);
	void 					link();
	void					use(const bool &state);
};



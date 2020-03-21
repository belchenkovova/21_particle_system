#pragma once

#include "engine/namespace.h"
#include "engine/shader/shader.h"

class						engine::program
{
	friend class			engine::renderer;

public :
							program();
							~program();

	void					attach(const shader &shader);
	void 					link();

//private :
public :

	GLuint					object{0};
};



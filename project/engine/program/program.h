#pragma once

#include "engine/namespace.h"
#include "engine/shader/shader.h"

class						engine::program
{
	friend class			engine::renderer;

public :
							program();
	virtual					~program();

	void					attach(const shader &shader);
	void 					link();
	void					use(const bool &state);

	[[deprecated]]
	int 					read_object()
	{
		return (object);
	}

private :

	GLuint					object{0};
};



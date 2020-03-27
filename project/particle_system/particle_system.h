#pragma once

#include "engine/engine.h"
#include "computer/computer.h"

class							particle_system
{
public :

	static inline int			number_of_particles{100};

								particle_system();
								~particle_system() = default;

	void						loop();

private :

	engine::renderer			renderer;
	engine::buffer				buffer;

	computer::core				core;
	computer::kernel			kernel_construct_cube;
	computer::argument			points_cl;

	void						start_OpenGL();
	void						start_OpenCL();
};



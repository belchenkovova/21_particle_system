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

	struct
	{
		computer::kernel		reset;
		computer::kernel		update;
		computer::kernel		physics;
	}							kernels;

	struct
	{
		computer::argument		position;
		computer::argument		velocity;
		computer::argument		acceleration;
	}							arguments;

	void						start_OpenGL();
	void						start_OpenCL();

	void 						timer();
};



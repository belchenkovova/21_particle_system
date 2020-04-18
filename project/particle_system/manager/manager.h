#pragma once

#include "particle_system/namespace.h"
#include "particle_system/map/map.h"
#include "particle_system/renderers/renderers.h"

class						particle_system::manager
{
public :

	static inline int		number_of_particles = 0;

							manager(engine::core &engine, computer::core &computer);
							~manager() = default;

	engine::renderer		&receive_particle_renderer();
	engine::renderer		&receive_cube_renderer();

	void					parse(const string &source);

private :

	engine::core			&engine;
	computer::core			&computer;

	static inline int		number_of_objects = 5;

	class renderers			renderers;
	optional<class map>		map;

	class
	{
	public :
		computer::kernel	xorshift_seed;
		computer::kernel	particle_reset;
		computer::kernel	initialize_as_null;
		computer::kernel	initialize_as_cube;
		computer::kernel	initialize_as_sphere;
		computer::kernel	particle_update;
		computer::kernel	attractor_execute;
		computer::kernel	emitter_start;
		computer::kernel	emitter_finish;
		computer::kernel	emitter_execute;
		computer::kernel	consumer_execute;
	}						kernels;

	class
	{
	public :
		computer::argument	number_of_particles;
		computer::argument	number_of_objects;
		computer::argument	object_type;
		computer::argument	object_position;
		computer::argument	is_alive;
		computer::argument	position;
		computer::argument	velocity;
		computer::argument	acceleration;
		computer::argument	born_by_emitter;
		computer::argument	xorshift_state;
	}						arguments;

	void					initialize_engine();
	void					initialize_computer();

	void 					timer_function();
	void 					callback_function();

	engine::timer			*timer = nullptr;
};



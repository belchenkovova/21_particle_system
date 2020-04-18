#pragma once

#include "particle_system/namespace.h"
#include "particle_system/map/map.h"

class						particle_system::manager
{
public :

	static inline int		number_of_particles = 0;
	static inline int		number_of_objects = 0;

							manager(engine::core &engine, computer::core &computer);
							~manager() = default;

	[[nodiscard]]
	engine::renderer		&receive_renderer()
	{
		return (renderer);
	}

	void					parse(const string &source)
	{
		map.emplace(source);
	}

private :

	engine::core			&engine;
	computer::core			&computer;

	class 					renderer final : public engine::renderer
	{
	public :
							renderer();
							~renderer() override = default;

		void 				render() override;

		using				engine::renderer::program;
		using				engine::renderer::buffer;

		using				points_type = engine::vbo::real<float, 3>;
		using				points_ptr_type = std::shared_ptr<engine::vbo::real<float, 3>>;

		engine::camera		camera;


		points_ptr_type		points;
	}						renderer;

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

	void					engine_start();

	void					computer_start();
	void					computer_build_kernels();
	void					computer_build_arguments();
	void					computer_link_arguments();
	void					computer_fill_arguments();

	void 					timer_function();
	void 					callback_function();

	engine::timer			*timer = nullptr;
};



#pragma once

#include "engine/engine.h"
#include "computer/computer.h"

class						particle_system
{
public :

	static inline int		number_of_particles{1};

							particle_system(engine::core &engine, computer::core &computer);
							~particle_system() = default;

	engine::renderer		&receive_particle_renderer();
	engine::renderer		&receive_cube_renderer();

private :

	engine::core			&engine;
	computer::core			&computer;

	static inline int		number_of_objects = 5;

	class					renderers
	{
	public :
							renderers();
							~renderers() = default;

		engine::camera		camera;

		using				camera_type = const engine::camera;
		using				points_type = engine::vbo::real<float, 3>;
		using				points_ptr_type = std::shared_ptr<engine::vbo::real<float, 3>>;

		class 				particle final : public engine::renderer
		{
		public :

			explicit		particle(camera_type &camera);
			void 			render() override;

			using			engine::renderer::program;
			using			engine::renderer::buffer;

			camera_type		&camera;

			points_ptr_type	points;
		}					particle;

		class 				cube final : public engine::renderer
		{
		public :

			explicit		cube(camera_type &camera);
			void 			render() override;

			camera_type		&camera;
		}					cube;
	}						renderers;

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
		computer::argument	object_id;
		computer::argument	object_position;
		computer::argument	is_alive;
		computer::argument	position;
		computer::argument	velocity;
		computer::argument	acceleration;
		computer::argument	born_by_emitter;
		computer::argument	xorshift_state;
	}						arguments;

	enum class				object_id
	{
		empty,
		attractor,
		repeller,
		emitter,
		consumer
	};

	void					initialize_engine();
	void					initialize_computer();

	void 					timer_function();
	void 					callback_function();

	engine::timer			*timer = nullptr;
};



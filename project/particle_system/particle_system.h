#pragma once

#include "engine/engine.h"
#include "computer/computer.h"

class							particle_system
{
public :

	static inline int			number_of_particles{1};

								particle_system(engine::core &engine, computer::core &computer);
								~particle_system() = default;

private :

	engine::core				&engine;
	computer::core				&computer;

	class						renderers
	{
	public :
								renderers();
								~renderers() = default;

		engine::camera			camera;

		using					camera_type = const engine::camera;
		using					points_type = engine::vbo::real<float, 3>;
		using					points_ptr_type = std::shared_ptr<engine::vbo::real<float, 3>>;

		class 					particle final : public engine::renderer
		{
		public :

			explicit			particle(camera_type &camera);
			void 				render() override;

			using				engine::renderer::program;
			using				engine::renderer::buffer;

			camera_type			&camera;

			points_ptr_type		points;
		}						particle;

		class 					cube final : public engine::renderer
		{
		public :

			explicit			cube(camera_type &camera);
			void 				render() override;

			using				engine::renderer::program;
			using				engine::renderer::buffer;

			camera_type			&camera;
		}						cube;
	}							renderers;

	class
	{
	public :
		computer::kernel		reset;
		computer::kernel		update;
		computer::kernel		physics;
	}							kernels;

	class
	{
	public :
		computer::argument		position;
		computer::argument		velocity;
		computer::argument		acceleration;
	}							arguments;

	void						initialize_engine();
	void						initialize_computer();

	void 						timer();
	void 						callback();
};



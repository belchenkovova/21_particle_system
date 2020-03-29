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

	class 						particle_renderer final : public engine::renderer
	{
	public :

								particle_renderer();
		void 					render() override;

		using					engine::renderer::program;
		using					engine::renderer::buffer;
		engine::camera			camera;

		using					points_type = engine::vbo::real<float, 3>;
		using 					points_ptr_type = std::shared_ptr<points_type>;

		points_ptr_type			points;
	}							particle_renderer;

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

	void						initialize_engine();
	void						initialize_computer();

	void 						timer();
};



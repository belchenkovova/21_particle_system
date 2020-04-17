#pragma once

#include "particle_system/namespace.h"

class					particle_system::renderers
{
public :
						renderers(int number_of_particles);
						~renderers() = default;

	engine::camera		camera;

	using				camera_type = const engine::camera;
	using				points_type = engine::vbo::real<float, 3>;
	using				points_ptr_type = std::shared_ptr<engine::vbo::real<float, 3>>;

	class 				particle final : public engine::renderer
	{
	public :

		explicit		particle(camera_type &camera, int number_of_particles);
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
};
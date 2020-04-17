#include "engine/engine.h"
#include "computer/computer.h"
#include "particle_system/particle_system.h"

class				final
{
public :

					final() = default;
					~final() = default;

	static void		setup_static()
	{
		engine::core::initial_window_size = engine::point(1280, 720);
		engine::core::window_name = "Particle System";
		engine::core::background = glm::vec3(.05f, .05f, .05f);
		engine::core::use_multisampling = true;
		engine::core::number_of_samples = 2;
		engine::core::use_blending = true;

		engine::camera::start_position = glm::vec3(0.f, 0.f, 1500.f);
		engine::camera::movement_speed = 10.f;
		engine::camera::rotation_speed = .5f;
		engine::camera::near_plane = 10.f;
		engine::camera::far_plane = 5000.f;

		computer::core::use_OpenGL = true;

		particle_system::number_of_particles = 10000;
	}

	void			setup()
	{
		engine::core::settings::point_size(1);
		engine::core::should_render = true;

		engine.attach_renderer(system.receive_particle_renderer());
		engine.attach_renderer(system.receive_cube_renderer());
	}

	void			start()
	{
		engine.start();
	}

private :

	engine::core	engine;
	computer::core	computer;
	particle_system	system = particle_system(engine, computer);
};

int					main()
{
	try
	{
		final		*final = nullptr;

		final::setup_static();
		final = new class final;
		final->setup();
		final->start();
		delete final;
		return (0);
	}
	catch (std::exception &exception)
	{
		std::cerr << "Particle System : Exiting with uncaught exception" << std::endl;
		std::cerr << exception.what() << std::endl;
		return (1);
	}
}

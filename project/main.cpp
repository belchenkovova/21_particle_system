#include "engine/engine.h"
#include "computer/computer.h"
#include "particle_system/particle_system.h"

class				final
{
public :
					final() = default;
					~final() = default;

	static void		setup()
	{
		engine::core::initial_window_size = engine::ivec2(1280, 720);
		engine::core::window_name = "Particle System";
		engine::core::background = engine::vec3(.1f, .1f, .1f);
		engine::core::use_multisampling = true;
		engine::core::use_blending = true;
		engine::core::use_depth_test = true;
		engine::core::number_of_samples = 2;
		engine::core::point_size = 1;
		engine::core::should_render = true;

		engine::camera::start_position = engine::vec3(0.f, 0.f, 1500.f);
		engine::camera::movement_speed = 10.f;
		engine::camera::rotation_speed = .3f;
		engine::camera::near_plane = 10.f;
		engine::camera::far_plane = 5000.f;

		computer::core::use_OpenGL = true;

		particle_system::manager::number_of_particles = 50000;
		particle_system::manager::number_of_objects = 5;
		particle_system::manager::particle_color = engine::vec3(1.f, 0.f, 0.f);
	}

	void			start()
	{
		engine.emplace();
		computer.emplace();
		system.emplace(*engine, *computer);

		engine->attach_renderer(system->receive_renderer());

		engine->start();
	}

private :

	using			engine_type = std::optional<engine::core>;
	using			computer_type = std::optional<computer::core>;
	using			system_type = std::optional<particle_system::manager>;

	engine_type		engine;
	computer_type	computer;
	system_type		system;
};

int					main()
{
	try
	{
		final		final;

		final::setup();
		final.start();
		return (0);
	}
	catch (std::exception &exception)
	{
		std::cerr << "Particle System : Exiting with uncaught exception" << std::endl;
		std::cerr << exception.what() << std::endl;
		return (1);
	}
}

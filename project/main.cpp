#include "engine/engine.h"
#include "computer/computer.h"
#include "particle_system/particle_system.h"

void 					setup()
{
	engine::core::window_width = 1280;
	engine::core::window_height = 720;
	engine::core::window_name = "";
	engine::core::use_depth_test = true;
	engine::core::point_size = 3;

	engine::camera::start_position = glm::vec3(0.f, 0.f, 100.f);
	engine::camera::movement_speed = 2.f;
	engine::camera::rotation_speed = 1.f;
	engine::camera::near_plane = .1f;
	engine::camera::far_plane = 2000.f;

	computer::core::use_OpenGL = true;

	particle_system::number_of_particles = 100;
}

void 					start()
{
	engine::core		engine;
	computer::core		computer;
	particle_system		system(engine, computer);

	engine.start();
}

int					main()
{
	try
	{
		setup();
		start();
		return (0);
	}
	catch (std::exception &exception)
	{
		std::cerr << "Particle System : Exiting with uncaught exception" << std::endl;
		std::cerr << exception.what() << std::endl;
		return (1);
	}
}

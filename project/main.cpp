#include "engine/engine.h"
#include "computer/computer.h"
#include "particle_system/particle_system.h"

void 					setup()
{
	engine::core::window_width = 1280;
	engine::core::window_height = 720;
	engine::core::window_name = "";
	engine::core::use_depth_test = false;
	engine::core::point_size = 2;

	engine::camera::start_position = glm::vec3(0.f, 0.f, 10.f);
	engine::camera::movement_speed = 2.f;
	engine::camera::rotation_speed = 1.f;
	engine::camera::near_plane = 1.f;
	engine::camera::far_plane = 1000.f;

	engine::renderer::vertex_source = "project/resources/OpenGL/vertex.glsl";
	engine::renderer::fragment_source = "project/resources/OpenGL/fragment.glsl";
	engine::renderer::background = glm::vec3(0.2f, 0.3f, 0.3f);

	computer::core::use_OpenGL = true;

	particle_system::number_of_particles = 100;
}

void 					start()
{
	particle_system		system;

	system.loop();
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

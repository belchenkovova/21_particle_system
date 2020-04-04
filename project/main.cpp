#include "engine/engine.h"
#include "computer/computer.h"
#include "gui/gui.h"
#include "particle_system/particle_system.h"

void 					setup()
{
	engine::core::window_width = 1280;
	engine::core::window_height = 720;
	engine::core::window_name = "Particle System";

	engine::camera::start_position = glm::vec3(0.f, 0.f, 5.f);
	engine::camera::movement_speed = .1f;
	engine::camera::rotation_speed = .1f;
	engine::camera::near_plane = .1f;
	engine::camera::far_plane = 1000.f;

	computer::core::use_OpenGL = true;

	particle_system::number_of_particles = 100 * 100;
}

void 					start()
{
	engine::core		engine;
	computer::core		computer;
	gui::system			gui(engine);
	particle_system		system(engine, computer);

	engine::core::settings::depth_test(true);
	engine::core::settings::point_size(2);

	engine.attach_renderer(system.receive_particle_renderer());
	engine.attach_renderer(system.receive_cube_renderer());
	engine.attach_renderer(gui.receive_renderer());

	auto font = gui::font("project/resources/HelveticaNeue.ttc", 70);
	auto label = gui.generate_label(gui::point(200, 200), font, std::string("Hello"));

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

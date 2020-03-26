#include "engine/engine.h"
#include "computer/computer.h"

void 					setup()
{
	engine::core::window_width = 1280;
	engine::core::window_height = 720;
	engine::core::window_name = "";
	engine::core::use_depth_test = false;
	engine::core::point_size = 2;

	engine::buffer::size = 9;

	engine::camera::start_position = glm::vec3(0.f, 0.f, 10.f);
	engine::camera::movement_speed = 2.f;
	engine::camera::rotation_speed = 1.f;
	engine::camera::near_plane = 1.f;
	engine::camera::far_plane = 1000.f;

	engine::renderer::vertex_source = "project/resources/OpenGL/vertex.glsl";
	engine::renderer::fragment_source = "project/resources/OpenGL/fragment.glsl";
	engine::renderer::background = glm::vec3(0.2f, 0.3f, 0.3f);

	computer::core::use_OpenGL = true;
}

void 					launch()
{
	engine::renderer	renderer;
	auto 				&buffer = renderer.receive_buffer();
	auto 				&points = buffer.receive_points();

	GLfloat				vertices[] =
		{
			0.f, 0.5f, 0.f,
			0.5f, -0.5f, 0.f,
			-0.5f, -0.5f, 0.f
		};

	for (int i = 0; i < 9; i++)
		points[i] = vertices[i];
	points.upload();

	computer::core		core;
	computer::kernel	kernel = core.generate_kernel();

	kernel.add_source("project/resources/OpenCL/source.txt");
	kernel.build("test", 9);

	computer::argument	argument = kernel.generate_argument(points, computer::memory_management::read_write);

	kernel.link_argument(argument);

	argument.acquire();
	kernel.run();
	argument.release();

	renderer.request_render();
	renderer.loop();
}

int					main()
{
	try
	{
		setup();
		launch();
		return (0);
	}
	catch (std::exception &exception)
	{
		std::cerr << "Particle System : Exiting with uncaught exception" << std::endl;
		std::cerr << exception.what() << std::endl;
		return (1);
	}
}

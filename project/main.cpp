#include "engine/engine.h"
#include "computer/computer.h"

void 					main_unsafe()
{
	engine::core::window_width = 1280;
	engine::core::window_height = 720;
	engine::core::window_name = "";
	engine::core::use_depth_test = false;
	engine::core::point_size = 2;

	engine::buffer::size = M1 * 3;

	engine::camera::start_position = glm::vec3(0.f, 0.f, 100.f);
	engine::camera::movement_speed = 2.f;
	engine::camera::rotation_speed = 1.f;
	engine::camera::near_plane = 1.f;
	engine::camera::far_plane = 1000.f;

	engine::renderer::vertex_source = "project/resources/OpenGL/vertex.glsl";
	engine::renderer::fragment_source = "project/resources/OpenGL/fragment.glsl";
	engine::renderer::background = glm::vec3(0.2f, 0.3f, 0.3f);

	engine::renderer	renderer;
	explosion			explosion(renderer.receive_buffer(), glm::vec3(0.f, 0.f, 0.f), 1.f);

	renderer.functor = explosion::functor;
	renderer.pointer = &explosion;

	explosion.upload();
	renderer.request_render();
	renderer.loop();
}

int					main()
{
	try
	{
		main_unsafe();
		return (0);
	}
	catch (std::exception &exception)
	{
		std::cerr << "Particle System : Exiting with uncaught exception" << std::endl;
		std::cerr << exception.what() << std::endl;
		return (1);
	}
}

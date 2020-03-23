#include "engine/engine.h"

void 					main_unsafe()
{
	engine::core::window_width = 1280;
	engine::core::window_height = 720;
	engine::core::window_name = "";
	engine::core::use_depth_test = false;
	engine::core::point_size = 6;

	engine::renderer::vertex_source = "project/resources/OpenGL/vertex.glsl";
	engine::renderer::fragment_source = "project/resources/OpenGL/fragment.glsl";
	engine::renderer::background = glm::vec3(0.2f, 0.3f, 0.3f);

	engine::buffer::size = 9;

	engine::renderer	renderer;
	auto 				&buffer = renderer.receive_buffer();
	auto 				&points = buffer.receive_points();

	GLfloat				vertices[] =
	{
		0.f, 0.f, 0.f,
		0.5f, 0.f, 0.f,
		-0.5f, 0.f, 0.f
	};

	for (int i = 0; i < 9; i++)
		points[i] = vertices[i];
	points.upload();

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

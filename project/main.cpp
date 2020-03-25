#include "engine/engine.h"
#include "computer/computer.h"

void 					main_unsafe()
{
	engine::renderer	*renderer{nullptr};

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

	renderer = new engine::renderer;

	auto 				&buffer = renderer->receive_buffer();
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
	cl::BufferGL		buffer_gl{core.read_context(), CL_MEM_WRITE_ONLY, static_cast<cl_GLuint>(points.read_object()), nullptr};
	cl::CommandQueue	queue = kernel.read_command_queue();

	kernel.add_source("project/resources/OpenCL/source.txt");
	kernel.build("test", 9);
	kernel.read_object().setArg(0, buffer_gl);

	std::vector<cl::Memory> vector = {buffer_gl};
	queue.enqueueAcquireGLObjects(&vector);
	kernel.run();
	queue.enqueueReleaseGLObjects(&vector);

	renderer->request_render();
	renderer->loop();

	delete renderer;
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

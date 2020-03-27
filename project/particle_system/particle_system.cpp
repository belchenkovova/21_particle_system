#include "particle_system.h"


//					PUBLIC


					particle_system::particle_system() :
					local_number_of_particles(number_of_particles)
{
	start_OpenGL();
	start_OpenCL();
}

void				particle_system::loop()
{
	kernel_construct_cube.run();
	renderer.request_render();
	renderer.loop();
}


//					PRIVATE


void				particle_system::start_OpenGL()
{
	points_gl = renderer.receive_points();

	points_gl->upload();
}

void				particle_system::start_OpenCL()
{
	kernel_construct_cube = core.generate_kernel();
	kernel_construct_cube.add_source("project/resources/OpenCL/construct_cube.txt");
	kernel_construct_cube.build("construct_cube", 100);

	points_cl = kernel_construct_cube.generate_argument(*points_gl);
	kernel_construct_cube.link_argument(points_cl);
}

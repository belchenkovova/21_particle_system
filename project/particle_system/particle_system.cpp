#include "particle_system.h"


//					PUBLIC


					particle_system::particle_system() :
					renderer(),
					buffer(number_of_particles * 3)
{
	start_OpenGL();
	start_OpenCL();
}

void				particle_system::loop()
{
	kernel_construct_cube.run();
	renderer.loop();
}


//					PRIVATE


void				particle_system::start_OpenGL()
{
	buffer.receive_points().upload();
	renderer.define_target(&buffer);
	renderer.request_rendering();
}

void				particle_system::start_OpenCL()
{
	kernel_construct_cube = core.generate_kernel();
	kernel_construct_cube.add_source("project/resources/OpenCL/construct_cube.txt");
	kernel_construct_cube.build("construct_cube", 100);

	points_cl = kernel_construct_cube.generate_argument(buffer.receive_points());
	kernel_construct_cube.link_argument(points_cl);
}

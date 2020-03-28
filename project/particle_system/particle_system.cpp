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
	arguments.position.acquire();
	kernels.reset.run();
	kernels.update.run();

	arguments.position.release();
	renderer.loop();
}


//					PRIVATE


void				particle_system::start_OpenGL()
{
	buffer.receive_points().upload();
	renderer.add_timer(1.f / 60.f, &particle_system::timer, this);
	renderer.define_target(&buffer);
	renderer.request_rendering();
}

void				particle_system::start_OpenCL()
{
	kernels.reset = core.generate_kernel();
	kernels.reset.add_source("project/resources/OpenCL/vector.txt");
	kernels.reset.add_source("project/resources/OpenCL/reset.txt");
	kernels.reset.build("reset", number_of_particles);

	kernels.update = core.generate_kernel();
	kernels.update.add_source("project/resources/OpenCL/vector.txt");
	kernels.update.add_source("project/resources/OpenCL/update.txt");
	kernels.update.build("update", number_of_particles);

	kernels.physics = core.generate_kernel();
	kernels.physics.add_source("project/resources/OpenCL/macros.txt");
	kernels.physics.add_source("project/resources/OpenCL/vector.txt");
	kernels.physics.add_source("project/resources/OpenCL/physics.txt");
	kernels.physics.build("physics", number_of_particles);

	arguments.position = kernels.reset.generate_argument(buffer.receive_points());
	arguments.velocity = kernels.reset.generate_argument<float>(number_of_particles * 3);
	arguments.acceleration = kernels.reset.generate_argument<float>(number_of_particles * 3);

	kernels.reset.link_argument(arguments.position);
	kernels.reset.link_argument(arguments.velocity);
	kernels.reset.link_argument(arguments.acceleration);

	kernels.update.link_argument(arguments.position);
	kernels.update.link_argument(arguments.velocity);
	kernels.update.link_argument(arguments.acceleration);

	kernels.physics.link_argument(arguments.position);
	kernels.physics.link_argument(arguments.velocity);
	kernels.physics.link_argument(arguments.acceleration);
}

void 				particle_system::timer()
{
	arguments.position.acquire();
	kernels.physics.run();
	kernels.update.run();
	arguments.position.release();
	renderer.request_rendering();
}
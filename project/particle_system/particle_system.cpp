#include "particle_system.h"

						particle_system::particle_system(engine::core &engine, computer::core &computer) :
						engine(engine),
						computer(computer)
{
	initialize_engine();
	initialize_computer();
	
	arguments.position.acquire();
	kernels.xorshift_seed.run();
	kernels.reset.run();
	kernels.update.run();
	arguments.position.release();
}

engine::renderer		&particle_system::receive_particle_renderer()
{
	return (renderers.particle);
}

engine::renderer		&particle_system::receive_cube_renderer()
{
	return (renderers.cube);
}

void					particle_system::initialize_engine()
{
	timer = &engine.generate_timer(1.f / 100.f, &particle_system::timer_function, this);
	timer->block = true;

	engine.generate_callback(engine::event::type::key_press, &particle_system::callback_function, this);
	engine.generate_callback(engine::event::type::key_hold, &particle_system::callback_function, this);
}

void					particle_system::initialize_computer()
{
//						KERNELS

	kernels.xorshift_seed = computer.generate_kernel();
	kernels.xorshift_seed.add_source("project/resources/OpenCL/xorshift.txt");
	kernels.xorshift_seed.build("xorshift_seed", number_of_particles);

	kernels.reset = computer.generate_kernel();
	kernels.reset.add_source("project/resources/OpenCL/vector.txt");
	kernels.reset.add_source("project/resources/OpenCL/reset.txt");
	kernels.reset.build("reset", number_of_particles);

	kernels.initialize_as_cube = computer.generate_kernel();
	kernels.initialize_as_cube.add_source("project/resources/OpenCL/xorshift.txt");
	kernels.initialize_as_cube.add_source("project/resources/OpenCL/vector.txt");
	kernels.initialize_as_cube.add_source("project/resources/OpenCL/initialize_as_x.txt");
	kernels.initialize_as_cube.build("initialize_as_cube", number_of_particles);

	kernels.initialize_as_sphere = computer.generate_kernel();
	kernels.initialize_as_sphere.add_source("project/resources/OpenCL/xorshift.txt");
	kernels.initialize_as_sphere.add_source("project/resources/OpenCL/vector.txt");
	kernels.initialize_as_sphere.add_source("project/resources/OpenCL/initialize_as_x.txt");
	kernels.initialize_as_sphere.build("initialize_as_sphere", number_of_particles);

	kernels.update = computer.generate_kernel();
	kernels.update.add_source("project/resources/OpenCL/vector.txt");
	kernels.update.add_source("project/resources/OpenCL/update.txt");
	kernels.update.build("update", number_of_particles);

	kernels.physics = computer.generate_kernel();
	kernels.physics.add_source("project/resources/OpenCL/macros.txt");
	kernels.physics.add_source("project/resources/OpenCL/vector.txt");
	kernels.physics.add_source("project/resources/OpenCL/physics.txt");
	kernels.physics.build("physics", number_of_particles);

	kernels.emitter_start = computer.generate_kernel();
	kernels.emitter_start.add_source("project/resources/OpenCL/xorshift.txt");
	kernels.emitter_start.add_source("project/resources/OpenCL/vector.txt");
	kernels.emitter_start.add_source("project/resources/OpenCL/emitter.txt");
	kernels.emitter_start.build("emitter_start", 1);

	kernels.emitter_finish = computer.generate_kernel();
	kernels.emitter_finish.add_source("project/resources/OpenCL/xorshift.txt");
	kernels.emitter_finish.add_source("project/resources/OpenCL/vector.txt");
	kernels.emitter_finish.add_source("project/resources/OpenCL/emitter.txt");
	kernels.emitter_finish.build("emitter_finish", number_of_particles);

	kernels.emitter_execute = computer.generate_kernel();
	kernels.emitter_execute.add_source("project/resources/OpenCL/xorshift.txt");
	kernels.emitter_execute.add_source("project/resources/OpenCL/vector.txt");
	kernels.emitter_execute.add_source("project/resources/OpenCL/emitter.txt");
	kernels.emitter_execute.build("emitter_execute", number_of_particles);

	kernels.consumer_execute = computer.generate_kernel();
	kernels.consumer_execute.add_source("project/resources/OpenCL/vector.txt");
	kernels.consumer_execute.add_source("project/resources/OpenCL/reset.txt");
	kernels.consumer_execute.add_source("project/resources/OpenCL/consumer.txt");
	kernels.consumer_execute.build("consumer_execute", number_of_particles);

//						ARGUMENTS

	arguments.number_of_particles = kernels.emitter_start.generate_argument<int>(100000);
	arguments.xorshift_state = kernels.xorshift_seed.generate_argument<uint32_t>(number_of_particles);
	arguments.position = kernels.reset.generate_argument(renderers.particle.buffer->receive_attribute(0));
	arguments.velocity = kernels.reset.generate_argument<float>(number_of_particles * 3);
	arguments.acceleration = kernels.reset.generate_argument<float>(number_of_particles * 3);
	arguments.is_alive = kernels.emitter_start.generate_argument<char>(number_of_particles);
	arguments.is_born = kernels.emitter_start.generate_argument<char>(number_of_particles);

	kernels.xorshift_seed.link_argument(arguments.xorshift_state);

	kernels.reset.link_argument(arguments.position);
	kernels.reset.link_argument(arguments.velocity);
	kernels.reset.link_argument(arguments.acceleration);

	kernels.initialize_as_cube.link_argument(arguments.xorshift_state);
	kernels.initialize_as_cube.link_argument(arguments.position);

	kernels.initialize_as_sphere.link_argument(arguments.xorshift_state);
	kernels.initialize_as_sphere.link_argument(arguments.position);

	kernels.update.link_argument(arguments.position);
	kernels.update.link_argument(arguments.velocity);
	kernels.update.link_argument(arguments.acceleration);

	kernels.physics.link_argument(arguments.position);
	kernels.physics.link_argument(arguments.velocity);
	kernels.physics.link_argument(arguments.acceleration);

	kernels.emitter_start.link_argument(arguments.number_of_particles);
	kernels.emitter_start.link_argument(arguments.is_alive);
	kernels.emitter_start.link_argument(arguments.is_born);

	kernels.emitter_finish.link_argument(arguments.is_alive);
	kernels.emitter_finish.link_argument(arguments.is_born);

	kernels.emitter_execute.link_argument(arguments.xorshift_state);
	kernels.emitter_execute.link_argument(arguments.position);
	kernels.emitter_execute.link_argument(arguments.velocity);
	kernels.emitter_execute.link_argument(arguments.acceleration);
	kernels.emitter_execute.link_argument(arguments.is_born);

	kernels.consumer_execute.link_argument(arguments.position);
	kernels.consumer_execute.link_argument(arguments.velocity);
	kernels.consumer_execute.link_argument(arguments.acceleration);
	kernels.consumer_execute.link_argument(arguments.is_alive);

	arguments.number_of_particles.write(&number_of_particles);
}

void 					particle_system::timer_function()
{
	arguments.position.acquire();

//						Emitter
	kernels.emitter_start.run();
	kernels.emitter_execute.run();
	kernels.emitter_finish.run();

//						Consumer
	kernels.consumer_execute.run();

//						Physics
#pragma message "Divide to attractor and repulsor"
	kernels.physics.run();

//						Update particle
#pragma message "Rename to particle_update"
	kernels.update.run();

	arguments.position.release();
	engine::core::should_render = true;
}

void 					particle_system::callback_function()
{
	engine::event		&event = engine.receive_event();

	if (event.read_key() == engine::event::key::escape)
		engine.finish();
	else if (event.read_key() == engine::event::key::letter_a)
		renderers.camera.move(engine::axis::x, engine::sign::minus);
	else if (event.read_key() == engine::event::key::letter_d)
		renderers.camera.move(engine::axis::x, engine::sign::plus);
	else if (event.read_key() == engine::event::key::letter_w)
		renderers.camera.move(engine::axis::z, engine::sign::minus);
	else if (event.read_key() == engine::event::key::letter_s)
		renderers.camera.move(engine::axis::z, engine::sign::plus);
	else if (event.read_key() == engine::event::key::letter_q)
		renderers.camera.move(engine::axis::y, engine::sign::plus);
	else if (event.read_key() == engine::event::key::letter_e)
		renderers.camera.move(engine::axis::y, engine::sign::minus);
	else if (event.read_key() == engine::event::key::left)
		renderers.camera.rotate(engine::axis::y, engine::sign::plus);
	else if (event.read_key() == engine::event::key::right)
		renderers.camera.rotate(engine::axis::y, engine::sign::minus);
	else if (event.read_key() == engine::event::key::up)
		renderers.camera.rotate(engine::axis::x, engine::sign::plus);
	else if (event.read_key() == engine::event::key::down)
		renderers.camera.rotate(engine::axis::x, engine::sign::minus);
	else if (event.read_key() == engine::event::key::enter)
		timer->block = not timer->block;
	else
		return ;
	engine::core::should_render = true;
}
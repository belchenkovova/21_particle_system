#include "particle_system/manager/manager.h"

using namespace			particle_system;

void					manager::computer_build()
{
	computer_build_kernels();
	computer_build_arguments();
	computer_link_arguments();
	computer_fill_arguments();

	arguments.position.acquire();
	kernels.xorshift_seed.run();
	kernels.particle_reset.run();
	arguments.position.release();
}

void					manager::computer_build_kernels()
{
	kernels.xorshift_seed = computer.generate_kernel();
	kernels.xorshift_seed.add_source("project/resources/OpenCL/macros.txt");
	kernels.xorshift_seed.add_source("project/resources/OpenCL/xorshift.txt");
	kernels.xorshift_seed.build("xorshift_seed", number_of_particles);

	kernels.particle_reset = computer.generate_kernel();
	kernels.particle_reset.add_source("project/resources/OpenCL/macros.txt");
	kernels.particle_reset.add_source("project/resources/OpenCL/xorshift.txt");
	kernels.particle_reset.add_source("project/resources/OpenCL/vector3.txt");
	kernels.particle_reset.add_source("project/resources/OpenCL/vector4.txt");
	kernels.particle_reset.add_source("project/resources/OpenCL/particle_x.txt");
	kernels.particle_reset.build("particle_reset", number_of_particles);

	kernels.particle_update = computer.generate_kernel();
	kernels.particle_update.add_source("project/resources/OpenCL/macros.txt");
	kernels.particle_update.add_source("project/resources/OpenCL/xorshift.txt");
	kernels.particle_update.add_source("project/resources/OpenCL/vector3.txt");
	kernels.particle_update.add_source("project/resources/OpenCL/vector4.txt");
	kernels.particle_update.add_source("project/resources/OpenCL/particle_x.txt");
	kernels.particle_update.build("particle_update", number_of_particles);

	kernels.initialize_as_null = computer.generate_kernel();
	kernels.initialize_as_null.add_source("project/resources/OpenCL/macros.txt");
	kernels.initialize_as_null.add_source("project/resources/OpenCL/xorshift.txt");
	kernels.initialize_as_null.add_source("project/resources/OpenCL/vector3.txt");
	kernels.initialize_as_null.add_source("project/resources/OpenCL/vector4.txt");
	kernels.initialize_as_null.add_source("project/resources/OpenCL/particle_x.txt");
	kernels.initialize_as_null.add_source("project/resources/OpenCL/initialize_as_x.txt");
	kernels.initialize_as_null.build("initialize_as_null", number_of_particles);

	kernels.initialize_as_sphere = computer.generate_kernel();
	kernels.initialize_as_sphere.add_source("project/resources/OpenCL/macros.txt");
	kernels.initialize_as_sphere.add_source("project/resources/OpenCL/xorshift.txt");
	kernels.initialize_as_sphere.add_source("project/resources/OpenCL/vector3.txt");
	kernels.initialize_as_sphere.add_source("project/resources/OpenCL/vector4.txt");
	kernels.initialize_as_sphere.add_source("project/resources/OpenCL/particle_x.txt");
	kernels.initialize_as_sphere.add_source("project/resources/OpenCL/initialize_as_x.txt");
	kernels.initialize_as_sphere.build("initialize_as_sphere", number_of_particles);

	kernels.initialize_as_cube = computer.generate_kernel();
	kernels.initialize_as_cube.add_source("project/resources/OpenCL/macros.txt");
	kernels.initialize_as_cube.add_source("project/resources/OpenCL/xorshift.txt");
	kernels.initialize_as_cube.add_source("project/resources/OpenCL/vector3.txt");
	kernels.initialize_as_cube.add_source("project/resources/OpenCL/vector4.txt");
	kernels.initialize_as_cube.add_source("project/resources/OpenCL/particle_x.txt");
	kernels.initialize_as_cube.add_source("project/resources/OpenCL/initialize_as_x.txt");
	kernels.initialize_as_cube.build("initialize_as_cube", number_of_particles);

	kernels.initialize_as_tetrahedron = computer.generate_kernel();
	kernels.initialize_as_tetrahedron.add_source("project/resources/OpenCL/macros.txt");
	kernels.initialize_as_tetrahedron.add_source("project/resources/OpenCL/xorshift.txt");
	kernels.initialize_as_tetrahedron.add_source("project/resources/OpenCL/vector3.txt");
	kernels.initialize_as_tetrahedron.add_source("project/resources/OpenCL/vector4.txt");
	kernels.initialize_as_tetrahedron.add_source("project/resources/OpenCL/particle_x.txt");
	kernels.initialize_as_tetrahedron.add_source("project/resources/OpenCL/initialize_as_x.txt");
	kernels.initialize_as_tetrahedron.build("initialize_as_tetrahedron", number_of_particles);

	kernels.attractor_execute = computer.generate_kernel();
	kernels.attractor_execute.add_source("project/resources/OpenCL/macros.txt");
	kernels.attractor_execute.add_source("project/resources/OpenCL/vector3.txt");
	kernels.attractor_execute.add_source("project/resources/OpenCL/vector4.txt");
	kernels.attractor_execute.add_source("project/resources/OpenCL/object.txt");
	kernels.attractor_execute.add_source("project/resources/OpenCL/attractor_x.txt");
	kernels.attractor_execute.build("attractor_execute", number_of_particles);

	kernels.repeller_execute = computer.generate_kernel();
	kernels.repeller_execute.add_source("project/resources/OpenCL/macros.txt");
	kernels.repeller_execute.add_source("project/resources/OpenCL/vector3.txt");
	kernels.repeller_execute.add_source("project/resources/OpenCL/vector4.txt");
	kernels.repeller_execute.add_source("project/resources/OpenCL/object.txt");
	kernels.repeller_execute.add_source("project/resources/OpenCL/repeller_x.txt");
	kernels.repeller_execute.build("repeller_execute", number_of_particles);

	kernels.emitter_start = computer.generate_kernel();
	kernels.emitter_start.add_source("project/resources/OpenCL/macros.txt");
	kernels.emitter_start.add_source("project/resources/OpenCL/xorshift.txt");
	kernels.emitter_start.add_source("project/resources/OpenCL/vector3.txt");
	kernels.emitter_start.add_source("project/resources/OpenCL/vector4.txt");
	kernels.emitter_start.add_source("project/resources/OpenCL/object.txt");
	kernels.emitter_start.add_source("project/resources/OpenCL/emitter_x.txt");
	kernels.emitter_start.build("emitter_start", 1);

	kernels.emitter_finish = computer.generate_kernel();
	kernels.emitter_finish.add_source("project/resources/OpenCL/macros.txt");
	kernels.emitter_finish.add_source("project/resources/OpenCL/xorshift.txt");
	kernels.emitter_finish.add_source("project/resources/OpenCL/vector3.txt");
	kernels.emitter_finish.add_source("project/resources/OpenCL/vector4.txt");
	kernels.emitter_finish.add_source("project/resources/OpenCL/object.txt");
	kernels.emitter_finish.add_source("project/resources/OpenCL/emitter_x.txt");
	kernels.emitter_finish.build("emitter_finish", number_of_particles);

	kernels.emitter_execute = computer.generate_kernel();
	kernels.emitter_execute.add_source("project/resources/OpenCL/macros.txt");
	kernels.emitter_execute.add_source("project/resources/OpenCL/xorshift.txt");
	kernels.emitter_execute.add_source("project/resources/OpenCL/vector3.txt");
	kernels.emitter_execute.add_source("project/resources/OpenCL/vector4.txt");
	kernels.emitter_execute.add_source("project/resources/OpenCL/object.txt");
	kernels.emitter_execute.add_source("project/resources/OpenCL/emitter_x.txt");
	kernels.emitter_execute.build("emitter_execute", number_of_particles);

	kernels.consumer_execute = computer.generate_kernel();
	kernels.consumer_execute.add_source("project/resources/OpenCL/macros.txt");
	kernels.consumer_execute.add_source("project/resources/OpenCL/xorshift.txt");
	kernels.consumer_execute.add_source("project/resources/OpenCL/vector3.txt");
	kernels.consumer_execute.add_source("project/resources/OpenCL/vector4.txt");
	kernels.consumer_execute.add_source("project/resources/OpenCL/object.txt");
	kernels.consumer_execute.add_source("project/resources/OpenCL/particle_x.txt");
	kernels.consumer_execute.add_source("project/resources/OpenCL/consumer_x.txt");
	kernels.consumer_execute.build("consumer_execute", number_of_particles);
}

void					manager::computer_build_arguments()
{
	arguments.number_of_particles = kernels.initialize_as_null.generate_argument<int>(1, computer::memory_management::read);
	arguments.number_of_objects = kernels.initialize_as_null.generate_argument<int>(1, computer::memory_management::read);
	arguments.start_color = kernels.initialize_as_null.generate_argument<float, 3>(1, computer::memory_management::read);
	arguments.finish_color = kernels.initialize_as_null.generate_argument<float, 3>(1, computer::memory_management::read);
	arguments.life_duration_min = kernels.initialize_as_null.generate_argument<int>(1, computer::memory_management::read);
	arguments.life_duration_max = kernels.initialize_as_null.generate_argument<int>(1, computer::memory_management::read);
	arguments.object_type = kernels.initialize_as_null.generate_argument<int>(number_of_objects, computer::memory_management::read);
	arguments.object_position = kernels.initialize_as_null.generate_argument<float, 3>(number_of_objects, computer::memory_management::read);
	arguments.object_power = kernels.initialize_as_null.generate_argument<float>(number_of_objects, computer::memory_management::read);
	arguments.is_alive = kernels.initialize_as_null.generate_argument<char>(number_of_particles);
	arguments.life_timer = kernels.initialize_as_null.generate_argument<int>(number_of_particles);
	arguments.position = kernels.initialize_as_null.generate_argument(renderer.buffer.receive_attribute(0));
	arguments.velocity = kernels.initialize_as_null.generate_argument<float, 3>(number_of_particles);
	arguments.acceleration = kernels.initialize_as_null.generate_argument<float, 3>(number_of_particles);
	arguments.color = kernels.initialize_as_null.generate_argument(renderer.buffer.receive_attribute(1));
	arguments.xorshift_state = kernels.initialize_as_null.generate_argument<uint32_t>(number_of_particles);
	arguments.born_by_emitter = kernels.initialize_as_null.generate_argument<int>(number_of_particles);
}

void					manager::computer_link_arguments()
{
	kernels.xorshift_seed.link_argument(arguments.xorshift_state);

	kernels.initialize_as_null.link_argument(arguments.start_color);
	kernels.initialize_as_null.link_argument(arguments.life_duration_min);
	kernels.initialize_as_null.link_argument(arguments.life_duration_max);
	kernels.initialize_as_null.link_argument(arguments.is_alive);
	kernels.initialize_as_null.link_argument(arguments.life_timer);
	kernels.initialize_as_null.link_argument(arguments.position);
	kernels.initialize_as_null.link_argument(arguments.velocity);
	kernels.initialize_as_null.link_argument(arguments.acceleration);
	kernels.initialize_as_null.link_argument(arguments.color);
	kernels.initialize_as_null.link_argument(arguments.xorshift_state);
	kernels.initialize_as_null.link_argument(arguments.born_by_emitter);

	kernels.initialize_as_sphere.link_argument(arguments.start_color);
	kernels.initialize_as_sphere.link_argument(arguments.life_duration_min);
	kernels.initialize_as_sphere.link_argument(arguments.life_duration_max);
	kernels.initialize_as_sphere.link_argument(arguments.is_alive);
	kernels.initialize_as_sphere.link_argument(arguments.life_timer);
	kernels.initialize_as_sphere.link_argument(arguments.position);
	kernels.initialize_as_sphere.link_argument(arguments.velocity);
	kernels.initialize_as_sphere.link_argument(arguments.acceleration);
	kernels.initialize_as_sphere.link_argument(arguments.color);
	kernels.initialize_as_sphere.link_argument(arguments.xorshift_state);
	kernels.initialize_as_sphere.link_argument(arguments.born_by_emitter);

	kernels.initialize_as_cube.link_argument(arguments.start_color);
	kernels.initialize_as_cube.link_argument(arguments.life_duration_min);
	kernels.initialize_as_cube.link_argument(arguments.life_duration_max);
	kernels.initialize_as_cube.link_argument(arguments.is_alive);
	kernels.initialize_as_cube.link_argument(arguments.life_timer);
	kernels.initialize_as_cube.link_argument(arguments.position);
	kernels.initialize_as_cube.link_argument(arguments.velocity);
	kernels.initialize_as_cube.link_argument(arguments.acceleration);
	kernels.initialize_as_cube.link_argument(arguments.color);
	kernels.initialize_as_cube.link_argument(arguments.xorshift_state);
	kernels.initialize_as_cube.link_argument(arguments.born_by_emitter);

	kernels.initialize_as_tetrahedron.link_argument(arguments.start_color);
	kernels.initialize_as_tetrahedron.link_argument(arguments.life_duration_min);
	kernels.initialize_as_tetrahedron.link_argument(arguments.life_duration_max);
	kernels.initialize_as_tetrahedron.link_argument(arguments.is_alive);
	kernels.initialize_as_tetrahedron.link_argument(arguments.life_timer);
	kernels.initialize_as_tetrahedron.link_argument(arguments.position);
	kernels.initialize_as_tetrahedron.link_argument(arguments.velocity);
	kernels.initialize_as_tetrahedron.link_argument(arguments.acceleration);
	kernels.initialize_as_tetrahedron.link_argument(arguments.color);
	kernels.initialize_as_tetrahedron.link_argument(arguments.xorshift_state);
	kernels.initialize_as_tetrahedron.link_argument(arguments.born_by_emitter);

	kernels.particle_reset.link_argument(arguments.start_color);
	kernels.particle_reset.link_argument(arguments.life_duration_min);
	kernels.particle_reset.link_argument(arguments.life_duration_max);
	kernels.particle_reset.link_argument(arguments.is_alive);
	kernels.particle_reset.link_argument(arguments.life_timer);
	kernels.particle_reset.link_argument(arguments.position);
	kernels.particle_reset.link_argument(arguments.velocity);
	kernels.particle_reset.link_argument(arguments.acceleration);
	kernels.particle_reset.link_argument(arguments.color);
	kernels.particle_reset.link_argument(arguments.xorshift_state);
	kernels.particle_reset.link_argument(arguments.born_by_emitter);

	kernels.particle_update.link_argument(arguments.start_color);
	kernels.particle_update.link_argument(arguments.finish_color);
	kernels.particle_update.link_argument(arguments.life_duration_min);
	kernels.particle_update.link_argument(arguments.life_duration_max);
	kernels.particle_update.link_argument(arguments.is_alive);
	kernels.particle_update.link_argument(arguments.life_timer);
	kernels.particle_update.link_argument(arguments.position);
	kernels.particle_update.link_argument(arguments.velocity);
	kernels.particle_update.link_argument(arguments.acceleration);
	kernels.particle_update.link_argument(arguments.color);
	kernels.particle_update.link_argument(arguments.xorshift_state);
	kernels.particle_update.link_argument(arguments.born_by_emitter);

	kernels.attractor_execute.link_argument(arguments.number_of_objects);
	kernels.attractor_execute.link_argument(arguments.object_type);
	kernels.attractor_execute.link_argument(arguments.object_position);
	kernels.attractor_execute.link_argument(arguments.object_power);
	kernels.attractor_execute.link_argument(arguments.position);
	kernels.attractor_execute.link_argument(arguments.velocity);
	kernels.attractor_execute.link_argument(arguments.acceleration);

	kernels.repeller_execute.link_argument(arguments.number_of_objects);
	kernels.repeller_execute.link_argument(arguments.object_type);
	kernels.repeller_execute.link_argument(arguments.object_position);
	kernels.repeller_execute.link_argument(arguments.object_power);
	kernels.repeller_execute.link_argument(arguments.position);
	kernels.repeller_execute.link_argument(arguments.velocity);
	kernels.repeller_execute.link_argument(arguments.acceleration);

	kernels.emitter_start.link_argument(arguments.number_of_particles);
	kernels.emitter_start.link_argument(arguments.number_of_objects);
	kernels.emitter_start.link_argument(arguments.object_type);
	kernels.emitter_start.link_argument(arguments.object_position);
	kernels.emitter_start.link_argument(arguments.object_power);
	kernels.emitter_start.link_argument(arguments.is_alive);
	kernels.emitter_start.link_argument(arguments.born_by_emitter);

	kernels.emitter_finish.link_argument(arguments.is_alive);
	kernels.emitter_finish.link_argument(arguments.born_by_emitter);

	kernels.emitter_execute.link_argument(arguments.object_position);
	kernels.emitter_execute.link_argument(arguments.position);
	kernels.emitter_execute.link_argument(arguments.velocity);
	kernels.emitter_execute.link_argument(arguments.acceleration);
	kernels.emitter_execute.link_argument(arguments.born_by_emitter);
	kernels.emitter_execute.link_argument(arguments.xorshift_state);

	kernels.consumer_execute.link_argument(arguments.number_of_objects);
	kernels.consumer_execute.link_argument(arguments.start_color);
	kernels.consumer_execute.link_argument(arguments.life_duration_min);
	kernels.consumer_execute.link_argument(arguments.life_duration_max);
	kernels.consumer_execute.link_argument(arguments.object_type);
	kernels.consumer_execute.link_argument(arguments.object_position);
	kernels.consumer_execute.link_argument(arguments.object_power);
	kernels.consumer_execute.link_argument(arguments.is_alive);
	kernels.consumer_execute.link_argument(arguments.life_timer);
	kernels.consumer_execute.link_argument(arguments.position);
	kernels.consumer_execute.link_argument(arguments.velocity);
	kernels.consumer_execute.link_argument(arguments.acceleration);
	kernels.consumer_execute.link_argument(arguments.color);
	kernels.consumer_execute.link_argument(arguments.xorshift_state);
	kernels.consumer_execute.link_argument(arguments.born_by_emitter);
}

void					manager::computer_fill_arguments()
{
	arguments.number_of_particles.write(&number_of_particles);
	arguments.number_of_objects.write(&number_of_objects);
	arguments.start_color.write(&start_color.x);
	arguments.finish_color.write(&finish_color.x);
	arguments.life_duration_min.write(&life_duration_min);
	arguments.life_duration_max.write(&life_duration_max);

	object::type		type_data[number_of_objects];
	float				position_data[number_of_objects * 3];
	float				power_data[number_of_objects * 3];

	fill(type_data, type_data + number_of_objects, object::type::empty);
	fill(position_data, position_data + number_of_objects, 0.f);
	fill(power_data, power_data + number_of_objects, 1.f);

	const auto			&objects = map->receive_objects();

	for (int i = 0; i < objects.size(); i++)
		type_data[i] = objects.at(i).read_type();

	for (int i = 0; i < objects.size(); i++)
		for (int j = 0; j < 3; j++)
			position_data[i * 3 + j] = objects.at(i).read_position()[j];

	for (int i = 0; i < objects.size(); i++)
			power_data[i] = objects.at(i).read_power();

	arguments.object_type.write(&type_data);
	arguments.object_position.write(&position_data);
	arguments.object_power.write(&power_data);
}

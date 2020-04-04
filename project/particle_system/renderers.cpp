#include "particle_system/particle_system.h"


//					////////////////////////////////////////////////////////////
//					RENDERERS
//					////////////////////////////////////////////////////////////


					particle_system::renderers::renderers() :
					particle(camera),
					cube(camera)
{}


//					////////////////////////////////////////////////////////////
//					PARTICLE RENDERER
//					////////////////////////////////////////////////////////////

					particle_system::renderers::particle::particle(camera_type &camera) :
					camera(camera)
{
	program.attach_shader(engine::shader::type::vertex, "project/resources/OpenGL/particle.vertex.glsl");
	program.attach_shader(engine::shader::type::fragment, "project/resources/OpenGL/particle.fragment.glsl");
	program.link();

	buffer.generate_attribute<float, 3>();
	buffer.resize(number_of_particles);

	points = std::dynamic_pointer_cast<points_type>(buffer.receive_attribute_as_pointer(0));
	assert(points != nullptr);
	points->save();

	program.build_uniform("uniform_projection");
	program.build_uniform("uniform_view");
}

void				particle_system::renderers::particle::render()
{
	program.upload_uniform("uniform_projection", camera.receive_projection_matrix());
	program.upload_uniform("uniform_view", camera.receive_view_matrix());

	program.use(true);
	engine::core::draw(engine::draw_mode::point, buffer);
	program.use(false);
}


//					////////////////////////////////////////////////////////////
//					CUBE RENDERER
//					////////////////////////////////////////////////////////////


					particle_system::renderers::cube::cube(camera_type &camera) :
					camera(camera)
{
	program.attach_shader(engine::shader::type::vertex, "project/resources/OpenGL/particle.vertex.glsl");
	program.attach_shader(engine::shader::type::fragment, "project/resources/OpenGL/particle.fragment.glsl");
	program.link();

	program.build_uniform("uniform_projection");
	program.build_uniform("uniform_view");

	buffer.generate_attribute<float, 3>();
	buffer.resize(8);
	buffer.use_indexing(24);

	float			points_data[] =
	{
		-1.f, -1.f, -1.f,
		-1.f, +1.f, -1.f,
		+1.f, -1.f, -1.f,
		+1.f, +1.f, -1.f,
		-1.f, -1.f, +1.f,
		-1.f, +1.f, +1.f,
		+1.f, -1.f, +1.f,
		+1.f, +1.f, +1.f
	};

	unsigned int	indices_data[] =
	{
		//			Back
		0, 1,
		1, 3,
		3, 2,
		2, 0,
		//			Front
		4, 5,
		5, 7,
		7, 6,
		6, 4,
		//			Left-lower
		0, 4,
		//			Left-upper
		1, 5,
		//			Right-upper
		3, 7,
		//			Right-lower
		2, 6
	};

	auto points = std::dynamic_pointer_cast<points_type>(buffer.receive_attribute_as_pointer(0));
	assert(points != nullptr);

	for (int i = 0; i < sizeof(points_data) / sizeof(float); i++)
		points->at(i) = points_data[i];

	for (int i = 0; i < sizeof(indices_data) / sizeof(unsigned int); i++)
		buffer.receive_indices().at(i) = indices_data[i];

	buffer.save();
}

void				particle_system::renderers::cube::render()
{

	program.upload_uniform("uniform_projection", camera.receive_projection_matrix());
	program.upload_uniform("uniform_view", camera.receive_view_matrix());

	program.use(true);
	engine::core::draw(engine::draw_mode::triangle, buffer);
	program.use(false);
}
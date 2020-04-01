#include "particle_system/particle_system.h"

//					////////////////////////////////////////////////////////////
//					PARTICLE RENDERER
//					////////////////////////////////////////////////////////////


					particle_system::particle_renderer::particle_renderer()
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

void				particle_system::particle_renderer::render()
{
	render_prefix();

	program.upload_uniform("uniform_projection", camera.receive_projection_matrix());
	program.upload_uniform("uniform_view", camera.receive_view_matrix());

	engine::core::draw(engine::draw_mode::point, buffer);

	render_suffix();
}
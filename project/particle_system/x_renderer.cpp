#include "particle_system/particle_system.h"

//					////////////////////////////////////////////////////////////
//					PARTICLE RENDERER
//					////////////////////////////////////////////////////////////


					particle_system::particle_renderer::particle_renderer()
{
	program.attach_shader(engine::shader::type::vertex, "project/resources/OpenGL/vertex.glsl");
	program.attach_shader(engine::shader::type::fragment, "project/resources/OpenGL/fragment.glsl");
	program.link();

	buffer.generate_attribute<float, 3>();
	buffer.resize(number_of_particles);

	points = std::dynamic_pointer_cast<points_type>(buffer.receive_attribute(0));
	assert(points != nullptr);

	for (int y = 0; y < 1; y++)
		for (int x = 0; x < 10; x++)
		{
			(*points)[3 * (10 * y + x) + 0] = x;
			(*points)[3 * (10 * y + x) + 1] = y;
			(*points)[3 * (10 * y + x) + 2] = 0;
		}
	points->save();
}

void				particle_system::particle_renderer::render()
{
	render_prefix();

	glUniformMatrix4fv(
		glGetUniformLocation(program.read_object(), "uniform_projection"),
		1, GL_FALSE, glm::value_ptr(camera.receive_projection_matrix()));
	glUniformMatrix4fv(
		glGetUniformLocation(program.read_object(), "uniform_view"),
		1, GL_FALSE, glm::value_ptr(camera.receive_view_matrix()));

	engine::core::draw(engine::draw_mode::point, buffer.read_size());

	render_suffix();
}
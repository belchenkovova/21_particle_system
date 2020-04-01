#include "system.h"

using namespace		gui;

					system::text_renderer::text_renderer(engine::core &engine)
{
	program.attach_shader(engine::shader::type::vertex, "project/resources/OpenGL/text.vertex.glsl");
	program.attach_shader(engine::shader::type::fragment, "project/resources/OpenGL/text.fragment.glsl");
	program.link();

	buffer.generate_attribute<float, 2>();
//	buffer.generate_attribute<float, 2>();
	buffer.resize(4);

	points = std::dynamic_pointer_cast<points_type>(buffer.receive_attribute_as_pointer(0));
//	texture = std::dynamic_pointer_cast<texture_type>(buffer.receive_attribute_as_pointer(1));
//	assert(points != nullptr and texture != nullptr);

	program.build_uniform("uniform_projection");
	program.upload_uniform("uniform_projection",
		glm::ortho(0.f, (float)engine.read_width(), (float)engine.read_height(), 0.f));

#pragma message("Connect texture. Activate texture?")

	float			raw_points[] =
	{
		200, 100,
		100, 100,
		100, 200,
		200, 200,
	};

	float			raw_texture[] = {
		0.f, 1.f,
		0.f, 0.f,
		1.f, 1.f,
		1.f, 0.f
	};

	unsigned int indices[] = {0, 1, 2, 0, 2, 3};

	for (int i = 0; i < sizeof(raw_points) / sizeof(float); i++)
		points->at(i) = raw_points[i];

//	for (int i = 0; i < sizeof(raw_texture) / sizeof(float); i++)
//		(*texture)[i] = raw_texture[i];

	buffer.use_indexing(sizeof(indices) / sizeof(unsigned int));
	for (int i = 0; i < sizeof(indices) / sizeof(unsigned int); i++)
		buffer.receive_indices().at(i) = indices[i];

	buffer.save();
//	texture->save();
}

void				system::text_renderer::render()
{
	render_prefix();
	engine::core::draw(engine::draw_mode::triangle, buffer);
	render_suffix();
}
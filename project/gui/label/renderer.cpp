#include "gui/label/label.h"

using namespace		gui;

					label::renderer::renderer(const engine::core &core)
{
	program->attach_shader(engine::shader::type::vertex, "project/resources/OpenGL/label.vertex.glsl");
	program->attach_shader(engine::shader::type::fragment, "project/resources/OpenGL/label.fragment.glsl");
	program->link();

	buffer->generate_attribute<float, 2>();
	buffer->generate_attribute<float, 2>();
	buffer->resize(4);

	points = dynamic_pointer_cast<points_type>(buffer->receive_attribute_as_pointer(0));
	texture = dynamic_pointer_cast<texture_type>(buffer->receive_attribute_as_pointer(1));
	assert(points != nullptr and texture != nullptr);

	program->build_uniform("uniform_projection");
	program->upload_uniform("uniform_projection",
		glm::ortho(0.f, (float)core.read_width(), (float)core.read_height(), 0.f));
	program->build_uniform("uniform_color");

	float			raw_texture[] =
	{
		1.f, 0.f,
		0.f, 0.f,
		0.f, 1.f,
		1.f, 1.f
	};

	unsigned int indices[] =
	{
		0, 1, 2,
		0, 2, 3
	};

	for (int i = 0; i < sizeof(raw_texture) / sizeof(float); i++)
		texture->at(i) = raw_texture[i];
	buffer->use_indexing(sizeof(indices) / sizeof(unsigned int));
	for (int i = 0; i < sizeof(indices) / sizeof(unsigned int); i++)
		buffer->receive_indices().at(i) = indices[i];

	buffer->save();
}

void				label::renderer::render() const
{
	program->use(true);
	engine::core::draw(engine::draw_mode::triangle, *buffer);
	program->use(false);
}

void				label::start(const engine::core &core)
{
	renderer = make_unique<class label::renderer>(core);
}
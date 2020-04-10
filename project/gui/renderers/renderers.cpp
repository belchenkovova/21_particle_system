#include "renderers.h"


//					////////////////////////////////////////////////////////////
//					RENDERERS
//					////////////////////////////////////////////////////////////


using namespace		gui;

					renderers::renderers(const engine::core &core) :
					projection(glm::ortho(0.f, (float)core.read_width(), (float)core.read_height(), 0.f)),
					text(projection),
					rectangle(projection)
{}


//					////////////////////////////////////////////////////////////
//					TEXT
//					////////////////////////////////////////////////////////////


					renderers::text::text(const glm::mat4 &projection)
{
	program->attach_shader(engine::shader::type::vertex, "project/resources/OpenGL/gui.text.vertex.glsl");
	program->attach_shader(engine::shader::type::fragment, "project/resources/OpenGL/gui.text.fragment.glsl");
	program->link();

	buffer->generate_attribute<float, 2>();
	buffer->generate_attribute<float, 2>();
	buffer->resize(4);

	vertex = dynamic_pointer_cast<vertex_type>(buffer->receive_attribute_as_pointer(0));
	UV = dynamic_pointer_cast<UV_type>(buffer->receive_attribute_as_pointer(1));
	assert(vertex != nullptr and UV != nullptr);

	program->upload_uniform("uniform_projection", projection);

	float			raw_UV[] =
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

	for (int i = 0; i < sizeof(raw_UV) / sizeof(float); i++)
		UV->at(i) = raw_UV[i];

	buffer->use_indexing(sizeof(indices) / sizeof(unsigned int));
	for (int i = 0; i < sizeof(indices) / sizeof(unsigned int); i++)
		buffer->receive_indices().at(i) = indices[i];

	buffer->save();
}

void				renderers::text::render()
{
	program->use(true);
	engine::core::draw(engine::draw_mode::triangle, *buffer);
	program->use(false);
}

void 				renderers::text::render(
					const point &position,
					const point &size,
					const glm::vec3 &color,
					const engine::texture &target)
{
	program->upload_uniform("uniform_color", color);

	int				raw_vertex[] =
	{
		position.x + size.x,	position.y,
		position.x,				position.y,
		position.x,				position.y + size.y,
		position.x + size.x,	position.y + size.y
	};

	for (int i = 0; i < 8; i++)
		vertex->at(i) = static_cast<float>(raw_vertex[i]);
	vertex->save();

	target.bind(true);
	render();
	target.bind(false);
}


//					////////////////////////////////////////////////////////////
//					RECTANGLE
//					////////////////////////////////////////////////////////////


					renderers::rectangle::rectangle(const glm::mat4 &projection)
{
	program->attach_shader(engine::shader::type::vertex, "project/resources/OpenGL/gui.rectangle.vertex.glsl");
	program->attach_shader(engine::shader::type::fragment, "project/resources/OpenGL/gui.rectangle.fragment.glsl");
	program->link();

	buffer->generate_attribute<float, 2>();
	buffer->resize(4);

	vertex = dynamic_pointer_cast<vertex_type>(buffer->receive_attribute_as_pointer(0));
	assert(vertex != nullptr);

	program->upload_uniform("uniform_projection", projection);

	unsigned int indices[] =
	{
		0, 1, 2,
		0, 2, 3
	};

	buffer->use_indexing(sizeof(indices) / sizeof(unsigned int));
	for (int i = 0; i < sizeof(indices) / sizeof(unsigned int); i++)
		buffer->receive_indices().at(i) = indices[i];

	buffer->save();
}

void				renderers::rectangle::render()
{
	program->use(true);
	engine::core::draw(engine::draw_mode::triangle, *buffer);
	program->use(false);
}

void 				renderers::rectangle::render(
					const point &position,
					const point &size,
					const glm::vec3 &color)
{
	render(position, size, glm::vec4(color, 1.f));
}

void				renderers::rectangle::render(
					const point &position,
					const point &size,
					const glm::vec4 &color)
{
	program->upload_uniform("uniform_color", color);

	int				raw_vertex[] =
	{
		position.x + size.x,	position.y,
		position.x,				position.y,
		position.x,				position.y + size.y,
		position.x + size.x,	position.y + size.y
	};

	for (int i = 0; i < 8; i++)
		vertex->at(i) = raw_vertex[i];
	vertex->save();

	render();
}
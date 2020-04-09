#include "button.h"


//					////////////////////////////////////////////////////////////
//					RENDERERS
//					////////////////////////////////////////////////////////////


using namespace		gui;

void				button::start(const engine::core &core)
{
	renderers.first = make_unique<class button::renderers::first>(core);
	renderers.second = make_unique<class button::renderers::second>(core);
}


//					////////////////////////////////////////////////////////////
//					FIRST
//					////////////////////////////////////////////////////////////


					button::renderers::first::first(const engine::core &core)
{
	program->attach_shader(engine::shader::type::vertex, "project/resources/OpenGL/button.first.vertex.glsl");
	program->attach_shader(engine::shader::type::fragment, "project/resources/OpenGL/button.first.fragment.glsl");
	program->link();

	buffer->generate_attribute<float, 2>();
	buffer->resize(4);

	points = dynamic_pointer_cast<points_type>(buffer->receive_attribute_as_pointer(0));
	assert(points != nullptr);

	program->build_uniform("uniform_projection");
	program->upload_uniform("uniform_projection",
		glm::ortho(0.f, (float)core.read_width(), (float)core.read_height(), 0.f));
	program->build_uniform("uniform_color");

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

void				button::renderers::first::render() const
{
	program->use(true);
	engine::core::draw(engine::draw_mode::triangle, *buffer);
	program->use(false);
}


//					////////////////////////////////////////////////////////////
//					SECOND
//					////////////////////////////////////////////////////////////


					button::renderers::second::second(const engine::core &core)
{
	program->attach_shader(engine::shader::type::vertex, "project/resources/OpenGL/button.second.vertex.glsl");
	program->attach_shader(engine::shader::type::fragment, "project/resources/OpenGL/button.second.fragment.glsl");
	program->link();

	buffer->generate_attribute<float, 2>();
	buffer->resize(4);

	points = dynamic_pointer_cast<points_type>(buffer->receive_attribute_as_pointer(0));
	assert(points != nullptr);

	program->build_uniform("uniform_projection");
	program->upload_uniform("uniform_projection",
		glm::ortho(0.f, (float)core.read_width(), (float)core.read_height(), 0.f));

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

void				button::renderers::second::render() const
{
	program->use(true);
	engine::core::draw(engine::draw_mode::triangle, *buffer);
	program->use(false);
}
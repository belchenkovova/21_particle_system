#include "engine/engine.h"

void 					main_unsafe()
{
	engine::core::window_width = 1280;
	engine::core::window_height = 720;
	engine::core::window_name = "";

	engine::renderer::vertex_source = "";
	engine::renderer::fragment_source = "";

	engine::core		core;
//	engine::renderer	renderer;

	GLfloat				vertices[] =
	{
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.0f,  0.5f, 0.0f
	};

	GLuint VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	GLuint VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), nullptr);
	glEnableVertexAttribArray(0);

	glBindVertexArray(0);

	engine::shader vertex_shader{engine::shader::type::vertex, "project/resources/OpenGL/vertex.glsl"};
	engine::shader fragment_shader{engine::shader::type::fragment, "project/resources/OpenGL/fragment.glsl"};

	engine::program	program;
	program.attach(vertex_shader);
	program.attach(fragment_shader);
	program.link();

	glPointSize(5);
	glDisable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_MULTISAMPLE);

	glUseProgram(program.object);

	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glBindVertexArray(VAO);
	glDrawArrays(GL_POINTS, 0, 3);
	glBindVertexArray(0);

	int i = 0;
	while (!glfwWindowShouldClose(core.window))
	{
		glfwPollEvents();
		if (not i++)
			glfwSwapBuffers(core.window);
	}
}

int					main()
{
	try
	{
		main_unsafe();
		return (0);
	}
	catch (std::exception &exception)
	{
		std::cerr << "Particle System : Exiting with uncaught exception" << std::endl;
		std::cerr << exception.what() << std::endl;
		return (1);
	}
}

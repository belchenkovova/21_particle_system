#include "common/OpenGL.h"

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

GLFWwindow 			*init()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	glfwWindowHint(GLFW_SAMPLES, 4);

	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", nullptr, nullptr);
	if (window == nullptr)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		exit(1);
	}
	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		std::cout << "Failed to initialize GLEW" << std::endl;
		exit(1);
	}

	int width, height;
	glfwGetFramebufferSize(window, &width, &height);

	glViewport(0, 0, width, height);

	return (window);
}

std::string				read_file(const char *path)
{
	std::ifstream		file;
	std::stringstream	stream;
	std::string			string;

	file.open(path);

	if (!file.is_open())
	{
		std::cout << "Can't read file" << std::endl;
		exit(1);
	}

	stream << file.rdbuf();

	file.close();
	string = stream.str();

	return (string);
}

GLuint				create_shader(GLuint type, const std::string &file)
{
	std::string		file_content = read_file(file.c_str());
	const char		*c_string = file_content.c_str();

	GLuint shader;
	shader = glCreateShader(type);
	glShaderSource(shader, 1, &c_string, NULL);
	glCompileShader(shader);
	GLint success;
	GLchar infoLog[512];
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if(!success)
	{
		glGetShaderInfoLog(shader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	}
	return (shader);
}

GLuint 				create_program(const GLuint &vertex, const GLuint &fragment)
{
	GLint success;
	GLchar infoLog[512];
	GLuint program;
	program = glCreateProgram();
	glAttachShader(program, vertex);
	glAttachShader(program, fragment);
	glLinkProgram(program);
	glGetProgramiv(program, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(program, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	}
	return (program);
}

int					main()
{
	GLFWwindow		*window = init();

	GLfloat vertices[] = {
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

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

//	glBindBuffer(GL_ARRAY_BUFFER, 0); ?
	glBindVertexArray(0);

	GLuint vertex_shader = create_shader(GL_VERTEX_SHADER, "project/OpenGL/vertex.glsl");
	GLuint fragment_shader = create_shader(GL_FRAGMENT_SHADER, "project/OpenGL/fragment.glsl");

	GLuint program = create_program(vertex_shader, fragment_shader);

	glPointSize(5);
	glDisable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_MULTISAMPLE);

	glUseProgram(program);

	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glBindVertexArray(VAO);
	glDrawArrays(GL_POINTS, 0, 3);
	glBindVertexArray(0);

	int i = 0;
	while(!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		if (not i++)
			glfwSwapBuffers(window);
	}
}

#pragma once

#define GLEW_STATIC
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "glm/gtx/euler_angles.hpp"
#include <vector>

#include "tools/tools.h"

#define GL_TEST if (glGetError()) std::cerr << "We have a problem, captain" << std::endl;

namespace			engine
{
	class 			core;

	class 			shader;
	class 			program;

	namespace		vbo
	{
		enum class	memory_management : GLuint;
		template	<typename t_type, int t_group, memory_management t_management>
		class		implementation;
		class		interface;
	};
	class 			vao;
	class 			buffer;

	enum class		axis
	{
		x,
		y,
		z
	};

	enum class		sign : int
	{
		negative = -1,
		positive = 1
	};

	class			camera;

	class 			renderer;
};
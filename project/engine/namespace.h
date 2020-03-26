#pragma once

#define GLEW_STATIC
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "glm/gtx/euler_angles.hpp"
#include <OpenGL/OpenGL.h>
#include <vector>
#include "common/common.h"

namespace			engine
{
	template		<typename t_type>
	using			vector = std::vector<t_type>;
	template		<typename t_type>
	using			reference = std::reference_wrapper<t_type>;

	class 			core;

	class 			shader;
	class 			program;

	namespace		vbo
	{
		enum class	memory_management : GLuint;
		class		abstract;
		template	<typename t_type, int t_group, memory_management t_management>
		class		real;
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

	namespace		callback
	{
		class		abstract;
		template	<auto t_functor, typename t_type>
		class		real;
	}
	template		<auto t_functor, typename t_type>
	class			timer;

	class 			renderer;
}
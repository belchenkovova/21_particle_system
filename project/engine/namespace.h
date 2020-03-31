#pragma once

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/euler_angles.hpp>
#include <OpenGL/OpenGL.h>
#include <vector>
#include <optional>
#include <tuple>

#include "common/common.h"

namespace			engine
{
	using			std::vector;
	using			std::shared_ptr;
	using 			std::make_shared;
	using 			std::reference_wrapper;
	using 			std::optional;
	using 			std::tuple;
	using 			std::make_tuple;

	class 			object_wrapper
	{
	public :

					object_wrapper() = default;
					~object_wrapper() = default;

		[[nodiscard]]
		GLuint		read_object() const
		{
			return (object);
		}

	protected :

		GLuint		object{0};
	};

	enum class		draw_mode : GLuint
	{
		point = GL_POINTS
	};

	class 			core;

	class 			shader;
	class 			program;

	enum class		memory_management : GLuint
	{
		static_ = GL_STATIC_DRAW,
		dynamic = GL_DYNAMIC_DRAW,
		stream = GL_STREAM_DRAW
	};

	namespace		vbo
	{
		class		abstract;
		template	<typename t_type, int t_group, memory_management t_management>
		class		real;
	}
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

	class 			functor;
	class			timer;
	class			event;
	class			callback;

	class 			renderer;
}
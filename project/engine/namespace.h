#pragma once

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/euler_angles.hpp>
#include <OpenGL/OpenGL.h>
#include <string>
#include <vector>
#include <optional>
#include <tuple>
#include <map>

#include "common/common.h"

namespace						engine
{
	using						std::string;
	using						std::vector;
	using						std::shared_ptr;
	using 						std::make_shared;
	using 						std::reference_wrapper;
	using 						std::optional;
	using 						std::pair;
	using 						std::make_pair;
	using						std::map;

	template					<typename type>
	class 						object_wrapper
	{
	public :

								object_wrapper() = default;
		virtual					~object_wrapper() = default;

		[[nodiscard]]
		type					read_object() const
		{
			return (object);
		}

		object_wrapper<type>	&operator = (const object_wrapper<type> &other) = delete;

	protected :

		type					object{0};
	};

	enum class					draw_mode : GLuint
	{
		point = GL_POINTS,
		line = GL_LINES,
		triangle = GL_TRIANGLES,
	};

	class 						core;

	class 						shader;
	class 						uniform;
	class 						program;

	enum class					memory_management : GLuint
	{
		static_ = GL_STATIC_DRAW,
		dynamic = GL_DYNAMIC_DRAW,
		stream = GL_STREAM_DRAW
	};

	namespace					vbo
	{
		class					abstract;
		template				<typename t_type, int t_group, memory_management t_management>
		class					real;
	}
	class						ebo;
	class 						vao;
	class 						buffer;

	enum class					axis
	{
		x,
		y,
		z
	};

	enum class					sign
	{
		negative = -1,
		positive = 1
	};

	class						camera;

	class 						functor;
	class						timer;
	class						event;
	class						callback;

	class						texture;

	class 						renderer;
}
#pragma once

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/euler_angles.hpp>
#include <OpenGL/OpenGL.h>
#include <SOIL/SOIL.h>

#include <string>
#include <vector>
#include <optional>
#include <tuple>
#include <map>
#include <list>

#include "common/common.h"

#include "debug.h"

namespace						engine
{
	using						std::string;
	using						std::vector;
	using						std::list;
	using						std::shared_ptr;
	using 						std::make_shared;
	using 						std::reference_wrapper;
	using 						std::optional;
	using 						std::pair;
	using 						std::make_pair;
	using						std::map;
	using						std::ostream;
	using						std::tie;
	using						std::ignore;
	using						std::piecewise_construct;
	using						std::forward_as_tuple;
	using						std::min;
	using						std::max;
	using						std::cerr;
	using						std::cout;
	using						std::endl;
	using						std::flush;

	using						glm::lookAt;
	using						glm::perspective;
	using						glm::radians;
	using						glm::normalize;
	using						glm::cross;
	using						glm::value_ptr;
	using						glm::vec2;
	using						glm::ivec2;
	using						glm::vec3;
	using						glm::vec4;
	using						glm::mat4;

	template					<typename type>
	void 						revise_optional(const optional<type> &data)
	{
		if (not data)
			throw (common::exception("Engine: Optional doesn't have value"));
	}

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
		triangle = GL_TRIANGLES
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
		minus = -1,
		plus = 1
	};

	class						camera;

	enum class					key
	{
		letter_a = GLFW_KEY_A,
		letter_b = GLFW_KEY_B,
		letter_c = GLFW_KEY_C,
		letter_d = GLFW_KEY_D,
		letter_e = GLFW_KEY_E,
		letter_f = GLFW_KEY_F,
		letter_g = GLFW_KEY_G,
		letter_h = GLFW_KEY_H,
		letter_i = GLFW_KEY_I,
		letter_j = GLFW_KEY_J,
		letter_k = GLFW_KEY_K,
		letter_l = GLFW_KEY_L,
		letter_m = GLFW_KEY_M,
		letter_n = GLFW_KEY_N,
		letter_o = GLFW_KEY_O,
		letter_p = GLFW_KEY_P,
		letter_q = GLFW_KEY_Q,
		letter_r = GLFW_KEY_R,
		letter_s = GLFW_KEY_S,
		letter_t = GLFW_KEY_T,
		letter_u = GLFW_KEY_U,
		letter_v = GLFW_KEY_V,
		letter_w = GLFW_KEY_W,
		letter_x = GLFW_KEY_X,
		letter_y = GLFW_KEY_Y,
		letter_z = GLFW_KEY_Z,
		number_1 = GLFW_KEY_1,
		number_2 = GLFW_KEY_2,
		number_3 = GLFW_KEY_3,
		number_4 = GLFW_KEY_4,
		number_5 = GLFW_KEY_5,
		number_6 = GLFW_KEY_6,
		number_7 = GLFW_KEY_7,
		number_8 = GLFW_KEY_8,
		number_9 = GLFW_KEY_9,
		number_0 = GLFW_KEY_0,
		escape = GLFW_KEY_ESCAPE,
		enter = GLFW_KEY_ENTER,
		left = GLFW_KEY_LEFT,
		up = GLFW_KEY_UP,
		right = GLFW_KEY_RIGHT,
		down = GLFW_KEY_DOWN
	};

	class 						functor;
	class						timer;
	class						event;
	class						callback;
	class						timeout;

	class						renderer;
}
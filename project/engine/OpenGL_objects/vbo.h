#pragma once

#include "engine/namespace.h"

namespace							engine::vbo
{
	enum class						memory_management : GLuint
	{
		static_ = GL_STATIC_DRAW,
		dynamic = GL_DYNAMIC_DRAW,
		stream = GL_STREAM_DRAW
	};

	class							interface
	{
		friend class 				engine::vao;

	public :
									interface()
		{
			glGenBuffers(1, &object);
		}

		virtual						~interface()
		{
			glDeleteBuffers(1, &object);
		}

	protected :

		void						bind(const bool &state)
		{
			glBindBuffer(GL_ARRAY_BUFFER, state ? object : 0);
		}

		virtual GLuint				read_group() = 0;
		virtual GLuint				read_type() = 0;
		virtual GLuint				read_size() = 0;

		GLuint						object{0};
	};

	template						<typename t_type, int t_group, memory_management t_management>
	class							implementation final : public interface, private std::vector<t_type>
	{
	public :
									implementation() = default;
									~implementation() override = default;

		std::vector<t_type>			&as_vector()
		{
			return (*this);
		}

		GLuint						read_group() override
		{
			return (group);
		}

		GLuint						read_type() override
		{

			if (std::is_same<t_type, unsigned int>::value)
				 return (GL_UNSIGNED_INT);
			else if (std::is_same<t_type, float>::value)
				 return (GL_FLOAT);
			else
				throw (tools::exception("Engine, VBO : Bad data type"));
		}

		GLuint						read_size() override
		{
			return (sizeof(t_type) * std::vector<t_type>::size());
		}

		void						upload()
		{
			bind(true);
			glBufferData(
				GL_ARRAY_BUFFER,
				sizeof(t_type) * std::vector<t_type>::size(),
				std::vector<t_type>::data(),
				static_cast<GLuint>(memory_management));
			bind(false);
		}

		using						std::vector<t_type>::push_back;
		using						std::vector<t_type>::operator[];

	private :

		const memory_management		memory_management{t_management};
		const int					group{t_group};
	};
};
#pragma once

#include "engine/namespace.h"

namespace							engine::vbo
{
	class							abstract : public object_wrapper<GLuint>
	{
		friend class 				engine::vao;
		friend class 				engine::buffer;

	public :
									abstract() : object_wrapper()
		{
			glGenBuffers(1, &object);
		}

									~abstract() override
		{
			glDeleteBuffers(1, &object);
		}

		virtual void				save() = 0;


	protected :

		virtual void				bind(bool state) const
		{
			glBindBuffer(GL_ARRAY_BUFFER, state ? object : 0);
		}

		[[nodiscard]]
		virtual GLuint				read_group() const = 0;
		[[nodiscard]]
		virtual GLuint				read_type() const = 0;
		[[nodiscard]]
		virtual GLuint				read_size() const = 0;
		[[nodiscard]]
		virtual GLuint				read_step() const = 0;

		virtual void 				resize(int size) = 0;
	};

	template						<typename t_type = float,
	    							int t_group = 3,
	    							memory_management t_management = memory_management::stream>
	class							real final : public abstract, private vector<t_type>
	{
	public :
									real() = default;
									~real() override = default;

		t_type						&at(int index)
		{
			return (vector<t_type>::at(index));
		}

		t_type						&at_group(int index)
		{
			return (vector<t_type>::at(index * group));
		}


		void						save() override
		{
			bind(true);
			glBufferData(
				GL_ARRAY_BUFFER,
				read_size(),
				std::vector<t_type>::data(),
				static_cast<GLuint>(memory_management));
			bind(false);
		}

	private :

		GLuint						read_group() const override
		{
			return (group);
		}

		GLuint						read_type() const override
		{

			if (std::is_same<t_type, unsigned int>::value)
				return (GL_UNSIGNED_INT);
			else if (std::is_same<t_type, float>::value)
				return (GL_FLOAT);
			else
				throw (common::exception("Engine, VBO : Bad data type"));
		}

		GLuint						read_size() const override
		{
			return (sizeof(t_type) * vector<t_type>::size());
		}

		GLuint						read_step() const override
		{
			return (sizeof(t_type) * t_group);
		}

		void 						resize(int size) override
		{
			vector<t_type>::resize(size * group);
		}

		const memory_management		memory_management{t_management};
		const int					group{t_group};
	};
};
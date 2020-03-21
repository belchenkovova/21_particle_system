#pragma once

#include "engine/namespace.h"
#include "engine/buffer/vbo.h"

class 				engine::vao
{
private :

	using			vbo = engine::vbo::interface;
	using			vbo_ptr = std::shared_ptr<vbo>;
	using			vbo_vector = std::vector<vbo_ptr>;

public :

					vao()
	{
		glGenVertexArrays(1, &object);
	}
					~vao()
	{
		glDeleteVertexArrays(1, &object);
	}

	void 			bind(const bool& state = true)
	{
		glBindVertexArray(state ? object : 0);
	}

	void 			add_attribute(const vbo_ptr &vbo)
	{
		bind(true);
		vbo->bind(true);
		glVertexAttribPointer(
			attributes.size(),
			vbo->read_group(),
			vbo->read_size(),
			GL_FALSE,
			vbo->read_size(),
			nullptr);
		glEnableVertexAttribArray(attributes.size());
		vbo->bind(false);
		bind(false);
		attributes.push_back(vbo);
	}

//	template			<typename type>
//	vbo					*attribute(
//
//		const int &element_size,
//		const buffer<type> &buffer,
//		const bool &is_dynamic = false)
//	{
//		attribute_vector.push_back(new vbo);
//
//		vbo				*vbo = attribute_vector.back();
//		GLenum			data_type;
//
//
//		bind();
//
//		vbo->buffer(buffer, is_dynamic);
//		vbo->bind();
//		glVertexAttribPointer(
//			attribute_count,
//			element_size,
//			data_type,
//			GL_FALSE,
//			element_size * sizeof(type),
//			nullptr);
//		glEnableVertexAttribArray(attribute_count++);
//		vbo::unbind();
//		unbind();
//
//		return (vbo);
//	}

private :

	GLuint			object{0};
	vbo_vector		attributes;
};
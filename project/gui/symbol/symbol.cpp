#include "symbol.h"

using namespace		gui;

					symbol::symbol(FT_Face &face)
{
	size = make_tuple(face->glyph->bitmap.width, face->glyph->bitmap.rows);
	bearing = make_tuple(face->glyph->bitmap_left, face->glyph->bitmap_top);
	advance = (int)((unsigned int)face->glyph->advance.x >> 6u);

//	MOD1_INTERNAL(texture) = new mod1_engine_gl::texture(
//		mod1_engine_gl::texture_type::custom,
//		MOD1_INTERNAL(size).x, MOD1_INTERNAL(size).y);
//
//	MOD1_INTERNAL(texture)->bind();
//	glTexImage2D(
//		GL_TEXTURE_2D, 0, GL_RED,
//		face->glyph->bitmap.width, face->glyph->bitmap.rows,
//		0, GL_RED, GL_UNSIGNED_BYTE, face->glyph->bitmap.buffer);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

tuple<int, int>		symbol::read_size() const
{
	return (size);
}

tuple<int, int>		symbol::read_bearing() const
{
	return (bearing);
}

int 				symbol::read_advance() const
{
	return (advance);
}

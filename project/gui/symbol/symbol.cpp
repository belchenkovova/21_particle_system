#include "symbol.h"

using namespace		gui;

					symbol::symbol(FT_Face &face)
{
	size = make_pair(face->glyph->bitmap.width, face->glyph->bitmap.rows);
	bearing = make_pair(face->glyph->bitmap_left, face->glyph->bitmap_top);
	advance = (int)((unsigned int)face->glyph->advance.x >> 6u);

	texture = make_shared<engine::texture>(
		size.first, size.second,
		GL_RED, GL_RED, GL_UNSIGNED_BYTE,
		face->glyph->bitmap.buffer);
}

pair<int, int>		symbol::read_size() const
{
	return (size);
}

pair<int, int>		symbol::read_bearing() const
{
	return (bearing);
}

int 				symbol::read_advance() const
{
	return (advance);
}

engine::texture		&symbol::read_texture() const
{
	return (*texture);
}
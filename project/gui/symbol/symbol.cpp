#include "symbol.h"

using namespace		gui;

					symbol::symbol(FT_Face &face)
{
	size = point((int)face->glyph->bitmap.width, (int)face->glyph->bitmap.rows);
	bearing = point(face->glyph->bitmap_left, face->glyph->bitmap_top);
	advance = (int)((unsigned int)face->glyph->advance.x >> 6u);

	texture = make_shared<engine::texture>(
		size.x, size.y, GL_RED, GL_RED, GL_UNSIGNED_BYTE, face->glyph->bitmap.buffer);
}

point				symbol::read_size() const
{
	return (size);
}

point				symbol::read_bearing() const
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
#pragma once

#include "gui/namespace.h"

class				gui::symbol
{
	friend class	font;

private :

	explicit		symbol(FT_Face &face);

public :
					~symbol() = default;

	[[nodiscard]]
	point			read_size() const;
	[[nodiscard]]
	point			read_bearing() const;
	[[nodiscard]]
	int 			read_advance() const;
	[[nodiscard]]
	engine::texture	&read_texture() const;

private :

	point			size;
	point			bearing;
	int 			advance;

	using			texture_type = shared_ptr<engine::texture>;
	texture_type	texture;
};



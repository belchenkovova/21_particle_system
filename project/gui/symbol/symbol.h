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
	pair<int, int>	read_size() const;
	[[nodiscard]]
	pair<int, int>	read_bearing() const;
	[[nodiscard]]
	int 			read_advance() const;
	[[nodiscard]]
	engine::texture	&read_texture() const;

private :

	pair<int, int>	size;
	pair<int, int>	bearing;
	int 			advance;

	using			texture_type = shared_ptr<engine::texture>;
	texture_type	texture;
};



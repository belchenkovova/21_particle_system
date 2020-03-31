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
	tuple<int, int>	read_size() const;
	[[nodiscard]]
	tuple<int, int>	read_bearing() const;
	[[nodiscard]]
	int 			read_advance() const;

private :

	tuple<int, int>	size;
	tuple<int, int>	bearing;
	int 			advance;

};



#pragma once

#include "gui/namespace.h"

class				gui::point
{
public :

					point() = default;
	explicit		point(int value);
					point(int x, int y);
					~point() = default;

	point			operator + (const point& other) const;
	point			operator - (const point& other) const;

	int 			x{0};
	int 			y{0};
};



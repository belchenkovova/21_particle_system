#pragma once

#include "engine/namespace.h"

class				engine::point
{
public :

					point() = default;
	explicit		point(int value);
					point(int x, int y);
					~point() = default;

	point			operator + (const point& other) const;
	point			operator - (const point& other) const;
	point			operator * (int value) const;
	point			operator / (int value) const;

	void			operator += (const point& other);
	void			operator -= (const point& other);
	void			operator *= (int value);
	void			operator /= (int value);

	bool			operator > (const point &other) const;
	bool			operator < (const point &other) const;
	bool			operator >= (const point &other) const;
	bool			operator <= (const point &other) const;

	bool			operator == (const point &other) const;
	bool			operator != (const point &other) const;

	int 			x{0};
	int 			y{0};
};



#pragma once

#include "engine/namespace.h"

class				engine::point
{
public :

					point() = default;
	explicit		point(int value);
					point(int x, int y);
					~point() = default;

	point			operator + (const point& that) const;
	point			operator - (const point& that) const;
	point			operator * (int value) const;
	point			operator / (int value) const;

	void			operator += (const point& that);
	void			operator -= (const point& that);
	void			operator *= (int value);
	void			operator /= (int value);

	static point	min(const point &left, const point &right);
	static point	max(const point &left, const point &right);

	bool			operator > (const point &that) const;
	bool			operator < (const point &that) const;
	bool			operator >= (const point &that) const;
	bool			operator <= (const point &that) const;

	bool			operator == (const point &that) const;
	bool			operator != (const point &that) const;

	int 			x = 0;
	int 			y = 0;
};

engine::ostream		&operator << (engine::ostream& stream, const engine::point &point);
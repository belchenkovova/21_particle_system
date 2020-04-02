#include "point.h"

using namespace		gui;

					point::point(int value) :
					x{value}, y{value}
{}

					point::point(int x, int y) :
					x{x}, y{y}
{}

point				point::operator + (const point& other) const
{
	return (point(this->x + other.x, this->y + other.y));
}

point				point::operator - (const point& other) const
{
	return (point(this->x - other.x, this->y - other.y));
}

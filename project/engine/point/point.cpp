#include "point.h"

using namespace		engine;

					point::point(int value) :
					x{value}, y{value}
{}

					point::point(int x, int y) :
					x{x}, y{y}
{}

point				point::operator + (const point& that) const
{
	return (point(this->x + that.x, this->y + that.y));
}

point				point::operator - (const point& that) const
{
	return (point(this->x - that.x, this->y - that.y));
}

point				point::operator * (int value) const
{
	return (point(this->x * value, this->y * value));
}

point				point::operator / (int value) const
{
	return (point(this->x / value, this->y / value));
}

void				point::operator += (const point& that)
{
	this->x += that.x;
	this->y += that.y;
}

void				point::operator -= (const point& that)
{
	this->x -= that.x;
	this->y -= that.y;
}

void				point::operator *= (int value)
{
	this->x *= value;
	this->y *= value;
}

void				point::operator /= (int value)
{
	this->x /= value;
	this->y /= value;
}

bool				point::operator > (const point &that) const
{
	return (this->x > that.x and this->y > that.y);
}

bool				point::operator < (const point &that) const
{
	return (this->x < that.x and this->y < that.y);
}

bool				point::operator >= (const point &that) const
{
	return (this->x >= that.x and this->y >= that.y);
}

bool				point::operator <= (const point &that) const
{
	return (this->x <= that.x and this->y <= that.y);
}

bool				point::operator == (const point &that) const
{
	return (this->x == that.x and this->y == that.y);
}
bool				point::operator != (const point &that) const
{
	return (this->x != that.x or this->y != that.y);
}

point				point::min(const point &left, const point &right)
{
	return {std::min(left.x, right.x), std::min(left.y, right.y)};
}

point				point::max(const point &left, const point &right)
{
	return {std::max(left.x, right.x), std::max(left.y, right.y)};
}

ostream				&operator << (ostream& stream, const point &point)
{
	stream << "{";
	stream << point.x;
	stream << ", ";
	stream << point.y;
	stream << "}";

	return (stream);
}
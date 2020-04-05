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

point				point::operator * (int value) const
{
	return (point(this->x * value, this->y * value));
}

point				point::operator / (int value) const
{
	return (point(this->x / value, this->y / value));
}

void				point::operator += (const point& other)
{
	this->x += other.x;
	this->y += other.y;
}

void				point::operator -= (const point& other)
{
	this->x -= other.x;
	this->y -= other.y;
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

bool				point::operator > (const point &other) const
{
	return (this->x > other.x and this->y > other.y);
}

bool				point::operator < (const point &other) const
{
	return (this->x < other.x and this->y < other.y);
}

bool				point::operator >= (const point &other) const
{
	return (this->x >= other.x and this->y >= other.y);
}

bool				point::operator <= (const point &other) const
{
	return (this->x <= other.x and this->y <= other.y);
}

bool				point::operator == (const point &other) const
{
	return (this->x == other.x and this->y == other.y);
}
bool				point::operator != (const point &other) const
{
	return (this->x != other.x or this->y != other.y);
}
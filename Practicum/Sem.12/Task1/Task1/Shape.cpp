#include "Shape.h"

void Shape::copy(const Shape& other)
{
	point.x = other.point.x;
	point.y = other.point.y;

	color = new char[strlen(other.color) + 1];
	strcpy(color, other.color);
}

void Shape::free()
{
	delete[] color;
}

Shape::Shape()
{
	color = new char[1];
	color[0] = '\0';

	point.x = 0;
	point.y = 0;
}

Shape::Shape(const Point& point, char* color)
{
	this->point.x = point.x;
	this->point.y = point.y;

	this->color = new char[strlen(color) + 1];
	strcpy(this->color, color);
}

Shape::Shape(const Shape& other)
{
	copy(other);
}

Shape& Shape::operator=(const Shape& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}

	return *this;
}

Shape::~Shape()
{
	free();
}

void Shape::setColor(char* color)
{
	this->color = new char[strlen(color) + 1];
	strcpy(this->color, color);
}

void Shape::setPoint(const Point& point)
{
	this->point.x = point.x;
	this->point.y = point.y;
}

Point Shape::getPoint() const
{
	return point;
}

const char* Shape::getColor() const
{
	return color;
}
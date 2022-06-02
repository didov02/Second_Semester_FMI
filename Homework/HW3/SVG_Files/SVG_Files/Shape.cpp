#include "Shape.h"

Shape::Shape()
{
	points = nullptr;
	pointsCount = 0;
	color = new char[1];
	color[0] = '\0';
}

Shape::Shape(size_t pointsCount, char* color)
{
	t = UNKNOWN;

	this->color = new char[strlen(color) + 1];
	strcpy(this->color, color);

	this->pointsCount = pointsCount;

	points = new Point[pointsCount];
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

void Shape::setPoint(size_t pointIndex, double x, double y)
{
	if (pointIndex >= pointsCount)
		throw "Unavailable operation!";

	points[pointIndex] = Point(x, y);
}
void Shape::setColor(const char* color)
{
	this->color = new char[strlen(color) + 1];
	strcpy(this->color, color);
}

Point Shape::getPoint(size_t index) const
{
	if (index > pointsCount)
		throw "Unavailable operation!";

	return points[index];
}

const char* Shape::getColor() const
{
	return color;
}

void Shape::copy(const Shape& other)
{
	color = new char[strlen(other.color) + 1];
	strcpy(color, other.color);

	points = new Point[other.pointsCount];

	for (int i = 0; i < other.pointsCount; i++)
		points[i] = other.points[i];

	pointsCount = other.pointsCount;
}

void Shape::free()
{
	delete[] color;
	delete[] points;
}
#include "Circle.h"

Circle::Circle() : Shape()
{
	r = 0;
}

Circle::Circle(char* color, double r , double x, double y) : Shape(ONE, color)
{
	t = CIRCLE;

	this->r = r;
	setPoint(NULL, x, y);
}

void Circle::setR(double r)
{
	this->r = r;
}

double Circle::getR() const
{
	return r;
}

Shape* Circle::clone() const
{
	return new Circle(*this);
}

double Circle::getArea() const
{
	return PI * r * r;
}

double Circle::getPer() const
{
	return 2 * PI * r;
}

bool Circle::isPointIn(double x, double y) const
{
	Point p(x, y);
	return p.getDist(getPoint(NULL)) <= r;
}
Type Circle::getType() const
{
	return t;
}

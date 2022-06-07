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

void Circle::print() const
{
	std::cout << "Figure: Circle" << std::endl;
	std::cout << "CX= " << this->getPoint(NULL).getX() << std::endl;
	std::cout << "CY= " << this->getPoint(NULL).getY() << std::endl;
	std::cout << "R= " << this->getR() << std::endl;
	std::cout << "Fill: " << this->getColor() << std::endl;
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

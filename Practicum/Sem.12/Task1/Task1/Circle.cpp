#include "Circle.h"

Circle::Circle() : Shape()
{
	this->d = 0;
}

Circle::Circle(const Point& point, char* color, double d) : Shape(point, color)
{
	this->d = d;
}

Shape* Circle::clone() const
{
	return new Circle(*this);
}

double Circle::getR() const
{
	return d;
}

void Circle::setR(double d)
{
	this->d = d;
}

void Circle::displayArea() const
{
	double area = PI * (d / 4);
	std::cout << "Area: " << area << std::endl;
}

void Circle::displayInfo() const
{
	std::cout << "Object: Circle" << std::endl;
	std::cout << "Color: " << this->getColor() << std::endl;
	std::cout << "Diameter: " << d << std::endl;
	std::cout << "Point's x: " << this->getPoint().x << std::endl;
	std::cout << "Point's y: " << this->getPoint().y << std::endl;
	this->displayArea();
}

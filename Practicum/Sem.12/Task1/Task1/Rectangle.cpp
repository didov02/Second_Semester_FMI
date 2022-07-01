#include "Rectangle.h"

Rectangle::Rectangle() : Shape()
{
	this->a = 0;
	this->b = 0;
}

Rectangle::Rectangle(const Point& point, char* color, double a, double b) : Shape(point,color)
{
	this->a = a;
	this->b = b;
}

void Rectangle::setA(double a)
{
	this->a = a;
}

void Rectangle::setB(double b)
{
	this->b = b;
}

double Rectangle::getA() const
{
	return a;
}

double Rectangle::getB() const
{
	return b;
}

Shape* Rectangle::clone() const
{
	return new Rectangle(*this);
}

void Rectangle::displayArea() const
{
	double area = a * b;
	std::cout << "Area: " << area << std::endl;
}

void Rectangle::displayInfo() const
{
	std::cout << "Object: Rectangle" << std::endl;
	std::cout << "Color: " << this->getColor() << std::endl;
	std::cout << "Side a: " << a << std::endl;
	std::cout << "Side b: " << b << std::endl;
	std::cout << "Point's x: " << this->getPoint().x << std::endl;
	std::cout << "Point's y: " << this->getPoint().y << std::endl;
	this->displayArea();
}
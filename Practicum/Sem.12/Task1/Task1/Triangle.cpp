#include "Triangle.h"

Triangle::Triangle() : Shape()
{
	this->a = 0;
	this->b = 0;
	this->c = 0;
}

Triangle::Triangle(const Point& point, char* color, double a, double b, double c, double degreesInSin) : Shape(point,color)
{
	this->a = a;
	this->b = b;
	this->c = c;
	this->degreesInSin = degreesInSin;
}

void Triangle::setA(double a)
{
	this->a = a;
}

void Triangle::setB(double b)
{
	this->b = b;
}

void Triangle::setC(double c)
{
	this->c = c;
}

void Triangle::setDegreesInSin(double degreesInSin)
{
	this->degreesInSin = degreesInSin;
}

double Triangle::getA() const
{
	return a;
}

double Triangle::getB() const
{
	return b;
}

double Triangle::getC() const
{
	return c;
}

double Triangle::getDegreesInSin() const
{
	return degreesInSin;
}

Shape* Triangle::clone() const
{
	return new Triangle(*this);
}

void Triangle::displayArea() const
{
	double area = 0.5 * a * b * degreesInSin;
	std::cout << "Area: " << area << std::endl;
}

void Triangle::displayInfo() const
{
	std::cout << "Object: Triangle" << std::endl;
	std::cout << "Color: " << this->getColor() << std::endl;
	std::cout << "Side a: " << a << std::endl;
	std::cout << "Side b: " << b << std::endl;
	std::cout << "Side c: " << c << std::endl;
	std::cout << "Degrees in sin: " << degreesInSin << std::endl;
	std::cout << "Point's x: " << this->getPoint().x << std::endl;
	std::cout << "Point's y: " << this->getPoint().y << std::endl;
	this->displayArea();
}

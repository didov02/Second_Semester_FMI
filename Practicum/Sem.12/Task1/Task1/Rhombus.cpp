#include "Rhombus.h"

Rhombus::Rhombus() : Shape()
{
	side = 0;
	degreesInSin = 0;
}

Rhombus::Rhombus(const Point& point, char* color, double side, double degreesInSin) : Shape(point, color)
{
	this->side = side;
	this->degreesInSin = degreesInSin;
}

Shape* Rhombus::clone() const
{
	return new Rhombus(*this);
}

double Rhombus::getSide() const
{
	return side;
}

double Rhombus::getDegreesInSin() const
{
	return degreesInSin;
}

void Rhombus::setSide(double side)
{
	this->side = side;
}

void Rhombus::setDegreesInSin(double degreesInSin)
{
	this->degreesInSin = degreesInSin;
}

void Rhombus::displayArea() const
{
	double area = side * side * degreesInSin;
	std::cout << "Area: " << area << std::endl;
}

void Rhombus::displayInfo() const
{
	std::cout << "Object: Rhombus" << std::endl;
	std::cout << "Color: " << this->getColor() << std::endl;
	std::cout << "Side: " << side << std::endl;
	std::cout << "Degrees in sin: " << degreesInSin << std::endl;
	std::cout << "Point's x: " << this->getPoint().x << std::endl;
	std::cout << "Point's y: " << this->getPoint().y << std::endl;
	this->displayArea();
}

#include "Rectangle.h"

Rectangle::Rectangle() : Shape()
{
	width = 0;
	height = 0;
}

Rectangle::Rectangle(char* color, double x, double y, double width, double height) : Shape(FOUR, color)
{
	t = RECTANGLE;

	setPoint(NULL, x, y);
	setPoint(ONE, x, y+height);
	setPoint(TWO, x+width, y+height);
	setPoint(THREE, x+width, y);

	this->width = width;
	this->height = height;
}

void Rectangle::setWidth(double width)
{
	this->width = width;
}

void Rectangle::setHeight(double height)
{
	this->height = height;
}

double Rectangle::getWidth() const
{
	return width;
}

double Rectangle::getHeight() const
{
	return height;
}

Shape* Rectangle::clone() const
{
	return new Rectangle(*this);
}

double Rectangle::getArea() const
{
	Point firstPoint = getPoint(NULL);
	Point secondPoint = getPoint(ONE);
	Point fourthPoint = getPoint(THREE);

	return (firstPoint.getDist(secondPoint) * firstPoint.getDist(fourthPoint));
}

double Rectangle::getPer() const
{
	Point firstPoint = getPoint(NULL);
	Point secondPoint = getPoint(ONE);
	Point fourthPoint = getPoint(THREE);

	return 2 * (firstPoint.getDist(secondPoint) + firstPoint.getDist(fourthPoint));
}

void Rectangle::print() const
{
	std::cout << "Figure: Rectangle" << std::endl;
	std::cout << "X= " << this->getPoint(NULL).getX() << std::endl;
	std::cout << "Y= " << this->getPoint(NULL).getY() << std::endl;
	std::cout << "Width= " << this->getWidth() << std::endl;
	std::cout << "Height= " << this->getHeight() << std::endl;
	std::cout << "Fill: " << this->getColor() << std::endl;
}

bool Rectangle::isPointIn(double x, double y) const
{
	return (x >= getPoint(NULL).getX() && y >= getPoint(ONE).getX() &&
		x <= getPoint(TWO).getY() && y <= getPoint(TWO).getY());
}

Type Rectangle::getType() const
{
	return t;
}

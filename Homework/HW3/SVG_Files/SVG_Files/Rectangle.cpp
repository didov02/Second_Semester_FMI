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
bool Rectangle::isPointIn(double x, double y) const
{
	Point p(x, y);

	return (p.getX() >= getPoint(NULL).getX() && p.getY() >= getPoint(ONE).getX() &&
		p.getX() <= getPoint(ONE).getY() && p.getY() >= getPoint(TWO).getY());
}

Type Rectangle::getType() const
{
	return t;
}

#include "Point.h"

Point::Point()
{
	x = 0;
	y = 0;
}

Point::Point(double x, double y)
{
	this->x = x;
	this->y = y;
}

void Point::setX(double x)
{
	this->x = x;
}

void Point::setY(double y)
{
	this->y = y;
}

double Point::getX() const
{
	return x;
}

double Point::getY() const
{
	return y;
}

double Point::getDist(const Point& other) const
{
	double temp1 = x - other.x;
	double temp2 = y - other.y;

	return sqrt(temp1 * temp1 + temp2 * temp2);
}

void Point::translatePoint(double vertical, double horizontal)
{
	this->x += horizontal;
	this->y += vertical;
}

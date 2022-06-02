#include "Line.h"

Line::Line() : Shape()
{
	
}
Line::Line(char* color, double x1, double y1, double x2, double y2) : Shape(TWO,color)
{
	t = LINE;

	setPoint(NULL, x1, y1);
	setPoint(ONE, x2, y2);
}


Shape* Line::clone() const
{
	return new Line(*this);
}

double Line::getArea() const
{
	return 0;
}

double Line::getPer() const
{
	return 0;
}

bool Line::isPointIn(double x, double y) const//actually is point on
{
	double temp1 = x * getPoint(NULL).getY() * ONE + getPoint(NULL).getX() * getPoint(ONE).getY() * ONE +
		y * ONE * getPoint(ONE).getX();

	double temp2 = ONE * getPoint(NULL).getY() * getPoint(ONE).getX() +
		getPoint(ONE).getY() * ONE * x + getPoint(NULL).getX() * y * ONE;

	return (temp1 - temp2 == 0);
}

Type Line::getType() const
{
	return t;
}
#pragma once
#include <cmath>

class Point
{
private:
	double x;
	double y;
public:
	Point();
	Point(double, double);

	void setX(double);
	void setY(double);

	double getX() const;
	double getY() const;

	double getDist(const Point&) const;

	void translatePoint(double, double);
};


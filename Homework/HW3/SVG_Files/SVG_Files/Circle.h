#pragma once
#include "Shape.h"

const double PI = 3.14;

class Circle: public Shape
{
private:
	double r;
public:
	Circle();
	Circle(char*, double, double, double);

	void setR(double);
	double getR() const;

	Shape* clone() const override;

	double getArea() const override;
	double getPer() const override;
	void print() const override;
	bool isPointIn(double x, double y) const override;

	Type getType() const override;
};


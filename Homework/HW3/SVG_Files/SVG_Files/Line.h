#pragma once
#include "Shape.h"

class Line: public Shape
{
public:
	Line();
	Line(char*, double, double, double, double);

	Shape* clone() const override;
	
	double getArea() const override;
	double getPer() const override;
	void print() const override;
	bool isPointIn(double x, double y) const override;

	Type getType() const override;
};


#pragma once
#include "Shape.h"

class Rectangle: public Shape
{
private:
	double width;
	double height;
public:
	Rectangle();
	Rectangle(char*, double, double, double, double);

	void setWidth(double);
	void setHeight(double);

	double getWidth() const;
	double getHeight() const;

	Shape* clone() const override;

	double getArea() const override;
	double getPer() const override;
	bool isPointIn(double x, double y) const override;

	Type getType() const override;
};


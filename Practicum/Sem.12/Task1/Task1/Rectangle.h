#pragma once
#include "Shape.h"

class Rectangle : public Shape
{
private:
	double a;
	double b;
public:
	Rectangle();
	Rectangle(const Point&, char*, double, double);

	void setA(double);
	void setB(double);

	double getA() const;
	double getB() const;

	Shape* clone() const override;
	void displayArea() const override;
	void displayInfo() const override;
};


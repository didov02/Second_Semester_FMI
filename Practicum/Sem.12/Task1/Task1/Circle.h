#pragma once
#include "Shape.h"

const double PI = 3.14;

class Circle : public Shape
{
private:
	double d;
public:
	Circle();
	Circle(const Point&, char*, double);

	Shape* clone() const override;

	double getR() const;
	void setR(double);

	void displayArea() const override;
	void displayInfo() const override;
};


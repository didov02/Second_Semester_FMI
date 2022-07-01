#pragma once
#include "Shape.h"

class Rhombus : public Shape
{
private:
	double side;
	double degreesInSin;
public:
	Rhombus();
	Rhombus(const Point&, char*, double, double);

	Shape* clone() const override;

	double getSide() const;
	double getDegreesInSin() const;

	void setSide(double);
	void setDegreesInSin(double);
	
	void displayArea() const override;
	void displayInfo() const override;
};


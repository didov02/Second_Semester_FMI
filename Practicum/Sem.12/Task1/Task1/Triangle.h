#pragma once
#include "Shape.h"

class Triangle : public Shape
{
private:
	double a;
	double b;
	double c;
	double degreesInSin;
public:
	Triangle();
	Triangle(const Point&, char*, double, double, double, double);
	
	void setA(double);
	void setB(double);
	void setC(double);
	void setDegreesInSin(double);

	double getA() const;
	double getB() const;
	double getC() const;
	double getDegreesInSin() const;

	Shape* clone() const override;
	void displayArea() const override;
	void displayInfo() const override;
};


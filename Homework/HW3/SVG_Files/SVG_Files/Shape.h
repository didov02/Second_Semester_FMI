#pragma once
#include "Point.h"
#include <iostream>
#include <cstring>

#pragma warning (disable : 4996)

const int ONE = 1;
const int TWO = 2;
const int THREE = 3;
const int FOUR = 4;

enum Type
{
	CIRCLE,
	RECTANGLE,
	LINE,
	UNKNOWN
};

class Shape
{
protected:
	Type t;
private:
	Point* points;
	size_t pointsCount;
	char* color;
public:
	Shape();
	Shape(size_t, char*);
	Shape(const Shape&);
	Shape& operator=(const Shape&);
	virtual ~Shape();

	void setPoint(size_t pointIndex, double x, double y);
	void setColor(const char*);

	Point getPoint(size_t) const;
	const char* getColor() const;

	virtual Shape* clone() const = 0;

	virtual double getArea() const = 0;
	virtual double getPer() const = 0;
	virtual bool isPointIn(double x, double y) const = 0;
	virtual Type getType() const = 0;
private:
	void copy(const Shape&);
	void free();
};


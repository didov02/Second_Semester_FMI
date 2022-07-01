#pragma once
#include <iostream>
#include <cstring>

#pragma warning (disable:4996)

struct Point
{
	int x;
	int y;
};

class Shape
{
private:
	Point point;
	char* color;
public:
	Shape();
	Shape(const Point&, char*);
	Shape(const Shape&);
	Shape& operator=(const Shape&);
	virtual ~Shape();

	virtual Shape* clone() const = 0;

	void setColor(char*);
	void setPoint(const Point&);

	Point getPoint() const;
	const char* getColor() const;

	virtual void displayArea() const = 0;
	virtual void displayInfo() const = 0;

private:
	void copy(const Shape&);
	void free();
};


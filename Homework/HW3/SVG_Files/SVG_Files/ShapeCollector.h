#pragma once
#include "Vector.hpp"
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Line.h"
#include <fstream>

void ClearSyncIgnore();

class ShapeCollector
{
private:
	Vector<Shape*> list;
public:
	ShapeCollector() = default;
	ShapeCollector(Vector<Shape*>);
	ShapeCollector(const ShapeCollector&);
	ShapeCollector& operator=(const ShapeCollector&);
	~ShapeCollector();

	void print() const;
	void createRectangle(char*, double, double, double, double);
	void createCircle(char*, double, double, double);
	void createLine(char*, double, double, double, double);
	void erase(size_t);
	void translateAllFigures(double, double);
	bool translateFigure(size_t, double, double);
	void withinRectangle(double, double, double, double) const;
	void withinCircle(double, double, double) const;
	void pointIn(double, double);
	void areas() const;
	void pers() const;
	void save() const;
private:
	void copy(const ShapeCollector&);
	void free();
};


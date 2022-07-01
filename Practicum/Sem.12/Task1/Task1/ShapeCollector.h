#pragma once
#include "Shape.h"

class ShapeCollector
{
private:
	Shape** list;
	size_t capacity;
	size_t size;
public:
	ShapeCollector();
	ShapeCollector(const ShapeCollector&);
	ShapeCollector& operator=(const ShapeCollector&);
	~ShapeCollector();

	void addItem(const Shape&);
	void displayInfo() const;
	void displayAreas() const;

private:
	void copy(const ShapeCollector&);
	void free();
	void resize();
};


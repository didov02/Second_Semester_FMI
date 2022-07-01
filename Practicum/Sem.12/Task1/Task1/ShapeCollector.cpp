#include "ShapeCollector.h"

void ShapeCollector::copy(const ShapeCollector& other)
{
	capacity = other.capacity;
	size = other.size;

	list = new Shape * [capacity];

	for (int i = 0; i < size; i++)
		list[i] = other.list[i]->clone();
}

void ShapeCollector::free()
{
	for (int i = 0; i < size; i++)
		delete[] list[i];

	delete[] list;
}

void ShapeCollector::resize()
{
	Shape** temp = new Shape * [capacity *= 2];

	for (int i = 0; i < size; i++)
	{
		temp[i] = list[i];
	}

	delete[] list;
	list = temp;
	temp = nullptr;
}

ShapeCollector::ShapeCollector()
{
	capacity = 2;
	size = 0;

	list = new Shape * [capacity];
}

ShapeCollector::ShapeCollector(const ShapeCollector& other)
{
	copy(other);
}

ShapeCollector& ShapeCollector::operator=(const ShapeCollector& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}

	return *this;
}

ShapeCollector::~ShapeCollector()
{
	free();
}

void ShapeCollector::addItem(const Shape& figure)
{
	if (size + 1 >= capacity)
		resize();

	list[size++] = figure.clone();
}

void ShapeCollector::displayInfo() const
{
	for (int i = 0; i < size; i++)
		list[i]->displayInfo();
}

void ShapeCollector::displayAreas() const
{
	for (int i = 0; i < size; i++)
	{
		std::cout << i + 1 << ". ";
		list[i]->displayArea();
	}
}

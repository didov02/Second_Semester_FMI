#include "Vegetable.h"

void Vegetable::copy(const Vegetable& other)
{
	sort = new char[strlen(other.sort) + 1];
	strcpy(sort, other.sort);
}

void Vegetable::free()
{
	delete[] sort;
}

Vegetable::Vegetable() : Item()
{
	sort = new char[1];
	sort[0] = '\0';
}

Vegetable::Vegetable(double calories, double price, char* sort) : Item(calories,price)
{
	this->sort = new char[strlen(sort) + 1];
	strcpy(this->sort, sort);
}

Vegetable::Vegetable(const Vegetable& other)
{
	copy(other);
}

Vegetable& Vegetable::operator=(const Vegetable& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}

	return *this;
}

Vegetable::~Vegetable()
{
	free();
}

void Vegetable::setSort(char* sort)
{
	this->sort = new char[strlen(sort) + 1];
	strcpy(this->sort, sort);
}

const char* Vegetable::getSort() const
{
	return sort;
}

Item* Vegetable::clone() const
{
	return new Vegetable(*this);
}

void Vegetable::displayInfo() const
{
	std::cout << "Item: Vegetable" << std::endl;
	std::cout << "Sort: " << sort << std::endl;
	std::cout << "Calories: " << this->getCalories() << std::endl;
	std::cout << "Price" << this->getPrice() << std::endl;
}

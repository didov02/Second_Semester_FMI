#include "Fruit.h"

void Fruit::copy(const Fruit& other)
{
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
}

void Fruit::free()
{
	delete[] name;
}

Fruit::Fruit() : Item()
{
	name = new char[1];
	name[0] = '\0';
}

Fruit::Fruit(double calories, double price, char* name) : Item(calories,price)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

Fruit::Fruit(const Fruit& other) : Item(other)
{
	copy(other);
}

Fruit& Fruit::operator=(const Fruit& other)
{
	if (this != &other)
	{
		free();
		Item::operator=(other);
		copy(other);
	}

	return *this;
}

Fruit::~Fruit()
{
	free();
}

void Fruit::setName(char* name)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

const char* Fruit::getName() const
{
	return name;
}

Item* Fruit::clone() const
{
	return new Fruit(*this);
}

void Fruit::displayInfo() const
{
	std::cout << "Item: Fruit" << std::endl;
	std::cout << "Name: "<< name << std::endl;
	std::cout << "Calories: "<< this->getCalories() << std::endl;
	std::cout << "Price"<< this->getPrice() << std::endl;
}

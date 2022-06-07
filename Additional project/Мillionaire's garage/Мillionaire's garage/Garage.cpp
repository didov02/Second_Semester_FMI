#include "Garage.h"

void Garage::copy(const Garage& other)
{
	maxSpeed = other.maxSpeed;
	yearCreated = other.yearCreated;
	t = other.t;

	color = new char[strlen(other.color) + 1];
	strcpy(color, other.color);
}

void Garage::free()
{
	delete[] color;
}

Garage::Garage()
{
	maxSpeed = 0;
	yearCreated = 0;
	color = nullptr;

	t = UNKNOWN;
}

Garage::Garage(char* color, size_t maxSpeed, size_t yearCreated)
{
	this->maxSpeed = maxSpeed;
	this->yearCreated = yearCreated;

	this->color = new char[strlen(color) + 1];
	strcpy(this->color, color);
}

Garage::Garage(const Garage& other)
{
	copy(other);
}

Garage& Garage::operator=(const Garage& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}

	return *this;
}

Garage::~Garage()
{
	free();
}

void Garage::setColor(char* color)
{
	this->color = new char[strlen(color) + 1];
	strcpy(this->color, color);
}

void Garage::setMaxSpeed(size_t maxSpeed)
{
	this->maxSpeed = maxSpeed;
}

void Garage::setYear(size_t yearCreated)
{
	this->yearCreated = yearCreated;
}

const char* Garage::getColor() const
{
	return color;
}

size_t Garage::getMaxSpeed() const
{
	return maxSpeed;
}

size_t Garage::getYearCreated() const
{
	return yearCreated;
}

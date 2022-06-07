#include "Car.h"

void Car::copy(const Car& other)
{
	brand = new char[strlen(other.brand) + 1];
	strcpy(brand, other.brand);

	model = new char[strlen(other.model) + 1];
	strcpy(model, other.model);

	fuelType = new char[strlen(other.fuelType) + 1];
	strcpy(fuelType, other.fuelType);
}

void Car::free()
{
	delete[] brand;
	delete[] model;
	delete[] fuelType;
}

Car::Car() : Garage()
{
	t = CAR;
	brand = nullptr;
	model = nullptr;
	fuelType = nullptr;
}

Car::Car(char* color, size_t maxSpeed, size_t yearCreated, char* brand, char* model, char* fuelType) : Garage(color,maxSpeed,yearCreated)
{
	this->brand = new char[strlen(brand) + 1];
	strcpy(this->brand, brand);

	this->model = new char[strlen(model) + 1];
	strcpy(this->model, model);

	this->fuelType = new char[strlen(fuelType) + 1];
	strcpy(this->fuelType, fuelType);
}

Car::Car(const Car& other)
{
	copy(other);
}

Car& Car::operator=(const Car& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}

	return *this;
}

Car::~Car()
{
	free();
}

Garage* Car::clone() const
{
	return new Car(*this);
}

Type Car::getType() const
{
	return t;
}

void Car::setBrand(char* brand)
{
	this->brand = new char[strlen(brand) + 1];
	strcpy(this->brand, brand);
}

void Car::setModel(char* model)
{
	this->model = new char[strlen(model) + 1];
	strcpy(this->model, model);
}

void Car::setFuelType(char* fuelType)
{
	this->fuelType = new char[strlen(fuelType) + 1];
	strcpy(this->fuelType, fuelType);
}

const char* Car::getBrand() const
{
	return brand;
}

const char* Car::getModel() const
{
	return model;
}

const char* Car::getFuelType() const
{
	return fuelType;
}

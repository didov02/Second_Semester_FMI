#include "Vehicle.h"

Vehicle::Vehicle()
{

}

Vehicle::Vehicle(int maxPassengers, int maxSpeed, const MyString& name, VehicleType type, int year)
{
	this->maxPassengers = maxPassengers;
	this->maxSpeed = maxSpeed;
	this->name = name;
	this->type = type;
	this->year = year;
}

VehicleType Vehicle::getType() const
{
	return type;
}

void Vehicle::setType(VehicleType type)
{
	this->type = type;
}

int Vehicle::getMaxPassengers() const
{
	return maxPassengers;
}

void Vehicle::setMaxPassengers(int maxPassengers)
{
	this->maxPassengers = maxPassengers;
}

int Vehicle::getMaxSpeed() const
{
	return maxSpeed;
}

void Vehicle::setMaxSpeed(int maxSpeed)
{
	this->maxSpeed = maxSpeed;
}

const MyString& Vehicle::getName() const
{
	return name;
}

void Vehicle::setName(const MyString& name)
{
	this->name = name;
}

int Vehicle::getYear() const
{
	return year;
}

void Vehicle::setYear(int year)
{
	this->year = year;
}

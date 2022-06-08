#include "Ground.h"


Ground::Ground() : Vehicle()
{
	color = nullptr;
	doorsCount = 0;

	t = UNKNOWN;
}

Ground::Ground(int maxPassengers, int maxSpeed, const MyString& name, VehicleType type, int year, MyString color, size_t doorsCount) : 
	Vehicle(maxPassengers,maxSpeed,name,type,year)
{
	this->color = color;
}

void Ground::setColor(const MyString& color)
{
	this->color = color;
}

const MyString& Ground::getColor() const
{
	return color;
}
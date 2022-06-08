#include "Ground.h"
#include <iostream>


Ground::Ground() : Vehicle()
{
	doorsCount = 0;
	t = GroundType::UNKNOWN;
}

Ground::Ground(int maxPassengers, int maxSpeed, const MyString& name, VehicleType type, int year, const MyString& color, size_t doorsCount) : 
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
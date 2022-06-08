#pragma once
#include <iostream>
#include "MyString.h"
#include "Vehicle.h"

enum Type
{
	CAR,
	MOTORCYCLE,
	TRUCK,
	UNKNOWN
};

class Ground : public Vehicle
{
protected:
	Type t;
private:
	MyString color;
	size_t doorsCount;
public:
	Ground();
	Ground(int, int , const MyString& , VehicleType, int, MyString, size_t);

	void setColor(const MyString&);

	const MyString& getColor() const;

	virtual Vehicle* clone() const = 0;
	virtual Type getType() const = 0;

	virtual void display() const = 0;
};


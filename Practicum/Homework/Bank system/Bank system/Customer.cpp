#include "Customer.h"

void Customer::copy(const Customer& other)
{
	this->id = other.id;

	this->name = new char[strlen(other.name) + 1];
	strcpy(this->name, other.name);

	this->address = new char[strlen(other.address) + 1];
	strcpy(this->address, other.address);
}

void Customer::free()
{
	delete[] name;
	delete[] address;
	id = 0;
}

Customer::Customer()
{
	id = 0;
	address = nullptr;
	name = nullptr;
}

Customer::Customer(size_t newID, char* newName, char* newAddress)
{
	this->id = newID;

	this->name = new char[strlen(newName) + 1];
	strcpy(this->name, newName);

	this->address = new char[strlen(newAddress) + 1];
	strcpy(this->address, newAddress);
}

Customer::Customer(const Customer& other)
{
	copy(other);
}

Customer& Customer::operator=(const Customer& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}

	return *this;
}

Customer::~Customer()
{
	free();
}

size_t Customer::getID() const
{
	return id;
}

const char* Customer::getName() const
{
	return name;
}

const char* Customer::getAddress() const
{
	return address;
}

void Customer::setID(size_t newID)
{
	this->id = newID;
}

void Customer::setName(char* newName)
{
	this->name = new char[strlen(newName) + 1];
	strcpy(this->name, newName);
}

void Customer::setAddress(char* newAddress)
{
	this->address = new char[strlen(newAddress) + 1];
	strcpy(this->address, newAddress);
}

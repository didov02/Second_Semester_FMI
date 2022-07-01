#include "Offers.h"

void Offers::copy(const Offers& other)
{
	programersCount = other.programersCount;
	daysOff = other.daysOff;
	payment = other.payment;

	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
}

void Offers::free()
{
	delete[] name;
}

Offers::Offers()
{
	name = new char[1];
	name[0] = '\0';

	programersCount = 0;
	daysOff = 0;
	payment = 0;
}

Offers::Offers(char* name, size_t programersCount, size_t daysOff, double payment)
{
	this->programersCount = programersCount;
	this->daysOff = daysOff;
	this->payment = payment;

	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

Offers::Offers(const Offers& other)
{
	copy(other);
}

Offers& Offers::operator=(const Offers& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}

	return *this;
}

Offers::~Offers()
{
	free();
}

void Offers::setName(char* name)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

void Offers::setProgramersCount(size_t programersCount)
{
	this->programersCount = programersCount;
}

void Offers::setDaysOff(size_t daysOff)
{
	this->daysOff = daysOff;
}

void Offers::setPayment(double payment)
{
	this->payment = payment;
}

const char* Offers::getName() const
{
	return name;
}

size_t Offers::getProgramersCount() const
{
	return programersCount;
}

size_t Offers::getDaysOff() const
{
	return daysOff;
}

double Offers::getPayment() const
{
	return payment;
}

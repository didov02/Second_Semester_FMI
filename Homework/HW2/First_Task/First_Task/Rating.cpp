#include "Rating.h"


void Rating::copy(const Rating& other)
{
	personWhoRates = new char[strlen(other.personWhoRates) + 1];
	strcpy(personWhoRates, other.personWhoRates);

	rating = other.rating;
}

void Rating::free()
{
	delete[] personWhoRates;
}

Rating::Rating()
{
	personWhoRates = new char[1];
	personWhoRates[0] = '\0';

	rating = 0;
}

Rating::Rating(char* personWhoRates, size_t rating)
{
	this->personWhoRates = new char[strlen(personWhoRates) + 1];
	strcpy(this->personWhoRates, personWhoRates);

	this->rating = rating;
}

Rating::Rating(const Rating& other)
{
	copy(other);
}

Rating& Rating::operator=(const Rating& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}

	return *this;
}

Rating::~Rating()
{
	free();
}

const char* Rating::getPersonsName() const
{
	return personWhoRates;
}

size_t Rating::getRating() const
{
	return rating;
}

void Rating::setName(char* userName)
{
	this->personWhoRates = new char[strlen(userName) + 1];
	strcpy(personWhoRates, userName);
}

void Rating::setRating(size_t rating)
{
	this->rating = rating;
}

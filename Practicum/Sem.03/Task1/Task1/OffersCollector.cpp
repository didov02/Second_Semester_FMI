#include "OffersCollector.h"

void OffersCollector::copy(const OffersCollector& other)
{
	size = other.size;
	capacity = other.capacity;

	offers = new Offers[capacity];

	for (int i = 0; i < size; i++)
	{
		offers[i] = other.offers[i];
	}
}
void OffersCollector::free()
{
	delete[] offers;
}

void OffersCollector::resize()
{
	Offers* temp = new Offers[capacity *= 2];

	for (int i = 0; i < size; i++)
		temp[i] = offers[i];

	delete[] offers;
	offers = temp;
	temp = nullptr;
}

OffersCollector::OffersCollector()
{
	capacity = 2;
	size = 0;

	offers = new Offers[capacity];
}

OffersCollector::OffersCollector(const OffersCollector& other)
{
	copy(other);
}

OffersCollector& OffersCollector::operator=(const OffersCollector& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}

	return *this;
}

OffersCollector::~OffersCollector()
{
	free();
}

void OffersCollector::addOffer(const Offers& offer)
{
	if (size + 1 >= capacity)
		resize();

	offers[size++] = offer;
}

void OffersCollector::showAllOffers() const
{
	for (int i = 0; i < size; i++)
		offers[i].print();
}

bool OffersCollector::firmExisting(char* name) const
{
	for (int i = 0; i < size; i++)
	{
		if (strcmp(offers[i].getName(),name)==0)
		{
			std::cout << "Yes this company exists!" << std::endl;
			return true;
		}
	}

	std::cout << "No this company doesn't exist!" << std::endl;
	return false;
}

void OffersCollector::printOffersWithGreaterPayment(double wantedPayment) const
{
	for (int i = 0; i < size; i++)
	{
		if (offers[i].getPayment() >= wantedPayment)
		{
			offers[i].print();
		}
	}
}

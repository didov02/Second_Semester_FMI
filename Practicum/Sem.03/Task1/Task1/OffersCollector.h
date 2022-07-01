#pragma once
#include "Offers.h"

class OffersCollector
{
private:
	Offers* offers;
	size_t size;
	size_t capacity;
public:
	OffersCollector();
	OffersCollector(const OffersCollector&);
	OffersCollector& operator=(const OffersCollector&);
	~OffersCollector();

	void addOffer(const Offers&);
	void showAllOffers() const;
	bool firmExisting(char*) const;
	void printOffersWithGreaterPayment(double) const;
private:
	void copy(const OffersCollector&);
	void free();
	void resize();
};


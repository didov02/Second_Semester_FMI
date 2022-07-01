#pragma once
#include <iostream>
#include <cstring>

#pragma warning (disable:4996)

class Offers
{
private:
	char* name;
	size_t programersCount;
	size_t daysOff;
	double payment;
public:
	Offers();
	Offers(char*, size_t, size_t, double);
	Offers(const Offers&);
	Offers& operator=(const Offers&);
	~Offers();

	void setName(char*);
	void setProgramersCount(size_t);
	void setDaysOff(size_t);
	void setPayment(double);

	const char* getName() const;
	size_t getProgramersCount() const;
	size_t getDaysOff() const;
	double getPayment() const;

	void print() const;
private:
	void copy(const Offers&);
	void free();
};


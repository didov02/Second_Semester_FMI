#pragma once
#include <iostream>
#include <cstring>

#pragma warning (disable : 4996)

class Item
{
private:
	double calories;
	double price;
public:
	Item();
	Item(double, double);
	Item(const Item&) = default;
	Item& operator=(const Item&) = default;
	virtual ~Item() = default;

	virtual Item* clone() const = 0;
	virtual void displayInfo() const = 0;

	double getCalories() const;
	double getPrice() const;

	void setCalories(double);
	void setPrice(double);
};


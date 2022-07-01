#include "Item.h"

Item::Item()
{
	calories = 0;
	price = 0;
}

Item::Item(double calories, double price)
{
	this->calories = calories;
	this->price = price;
}

double Item::getCalories() const
{
	return calories;
}

double Item::getPrice() const
{
	return price;
}

void Item::setCalories(double calories)
{
	this->calories = calories;
}

void Item::setPrice(double price)
{
	this->price = price;
}




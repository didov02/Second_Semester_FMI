#include "RestaurantItem.h"

RestaurantItem::RestaurantItem()
{
	typeOfProduct = Type::UNKNOWN;
	inStock = 0;
	price = 0;
}

RestaurantItem::RestaurantItem(size_t inStock, double price)
{
	this->inStock = inStock;
	this->price = price;
}

const Type& RestaurantItem::getType() const
{
	return typeOfProduct;
}

size_t RestaurantItem::getInStock() const
{
	return inStock;
}

double RestaurantItem::getPrice() const
{
	return price;
}

void RestaurantItem::setInStock(size_t inStock)
{
	this->inStock = inStock;
}

void RestaurantItem::setPrice(double price)
{
	this->price = price;
}

void RestaurantItem::display() const
{

}

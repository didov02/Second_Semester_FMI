#pragma once

enum Type
{
	FOOD,
	DRINK,
	UNKNOWN
};

class RestaurantItem
{
private:
	Type typeOfProduct;
	size_t inStock;
	double price;
public:
	RestaurantItem();
	RestaurantItem(size_t, double);
	RestaurantItem(const RestaurantItem&) = default;
	RestaurantItem& operator=(const RestaurantItem&) = default;
	virtual ~RestaurantItem() = default;

	virtual RestaurantItem* clone() const = 0;
	virtual void display() const;
	virtual void changeName(char*) const = 0;

	const Type& getType() const;
	size_t getInStock() const;
	double getPrice() const;

	void setInStock(size_t);
	void setPrice(double);
};


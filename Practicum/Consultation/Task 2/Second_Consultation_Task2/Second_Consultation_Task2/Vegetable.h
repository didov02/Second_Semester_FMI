#pragma once
#include "Item.h"

class Vegetable : public Item
{
private:
	char* sort;
public:
	Vegetable();
	Vegetable(double, double, char*);
	Vegetable(const Vegetable&);
	Vegetable& operator=(const Vegetable&);
	~Vegetable();

	void setSort(char*);
	const char* getSort() const;

	Item* clone() const override;
	void displayInfo() const override;
private:
	void copy(const Vegetable&);
	void free();
};


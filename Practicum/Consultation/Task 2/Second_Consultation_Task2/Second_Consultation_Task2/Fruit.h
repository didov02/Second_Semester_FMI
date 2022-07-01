#pragma once
#include "Item.h"

class Fruit : public Item
{
private:
	char* name;
public:
	Fruit();
	Fruit(double, double, char*);
	Fruit(const Fruit&);
	Fruit& operator=(const Fruit&);
	~Fruit();

	void setName(char*);
	const char* getName() const;

	Item* clone() const override;
	void displayInfo() const override;
private:
	void copy(const Fruit&);
	void free();
};


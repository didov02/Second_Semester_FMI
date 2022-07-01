#pragma once
#include "Item.h"

class Shop
{
private:
	Item** list;
	size_t capacity;
	size_t size;
public:
	Shop();
	Shop(const Shop&);
	Shop& operator=(const Shop&);
	~Shop();

	void addItem(const Item&);
	void deleteItem(size_t index);
	void changePrice(size_t index, double price);
	void print();
private:
	void copy(const Shop&);
	void free();
	void resize();
};


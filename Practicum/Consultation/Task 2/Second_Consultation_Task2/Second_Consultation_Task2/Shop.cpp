#include "Shop.h"

void Shop::copy(const Shop& other)
{
	capacity = other.capacity;
	size = other.size;

	list = new Item * [capacity];

	for (int i = 0; i < size; i++)
		list[i] = other.list[i]->clone();
}

void Shop::free()
{
	for (int i = 0; i < size; i++)
		delete list[i];

	delete[] list;
}

void Shop::resize()
{
	Item** temp = new Item * [capacity *= 2];

	for (int i = 0; i < size; i++)
		temp[i] = list[i];

	delete[] list;
	list = temp;
	temp = nullptr;
}

Shop::Shop()
{
	capacity = 2;
	size = 0;

	list = new Item * [capacity];
}

Shop::Shop(const Shop& other)
{
	copy(other);
}

Shop& Shop::operator=(const Shop& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}

	return *this;
}

Shop::~Shop()
{
	free();
}

void Shop::addItem(const Item& item)
{
	if (size + 1 >= capacity)
		resize();

	list[size++] = item.clone();
}

void Shop::deleteItem(size_t index)
{
	if (index >= size)
		throw "Unavaible index";

	delete list[index];
	list[index] = list[size - 1];
	list[size - 1] = nullptr;
	size--;
}

void Shop::changePrice(size_t index, double price)
{
	if (index >= size)
		throw "Unavaible index";

	list[index]->setPrice(price);
}

void Shop::print()
{
	for (int i = 0; i < size; i++)
		list[i]->displayInfo();
}

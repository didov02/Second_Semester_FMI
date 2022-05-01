#include "Assistant.h"
#include <cstring>

#pragma warning (disable : 4996)

void Assistant::copy(const Assistant& other)
{
	this->assistantName = new char[strlen(other.assistantName) + 1];
	strcpy(this->assistantName, other.assistantName);
}

void Assistant::free()
{
	delete[] assistantName;
}

Assistant::Assistant()
{
	assistantName = nullptr;
}

Assistant::Assistant(const char* name)
{
	this->assistantName = new char[strlen(name) + 1];
	strcpy(assistantName, name);
}

Assistant::Assistant(const Assistant& other)
{
	copy(other);
}

Assistant& Assistant::operator=(const Assistant& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}

	return *this;
}

const char* Assistant:: getName() const
{
	return assistantName;
}

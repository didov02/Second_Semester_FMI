#include "Student.h"
#include <cstring>

#pragma warning (disable : 4996)

void Student::copy(const Student& other)
{
	this->fn = other.fn;

	this->name = new char[strlen(other.name) + 1];
	strcpy(this->name, other.name);

	this->gradesCount = other.gradesCount;

	for (int i = 0; i < MAX_GRADES; i++)
	{
		this->grades[i] = other.grades[i];
	}
}

void Student::free()
{
	delete[] name;
}

Student::Student()
{
	this->fn = NULL;
	this->name = nullptr;
	this->gradesCount = NULL;
}

Student::Student(int fn, const char* name)
{
	this->fn = fn;

	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

Student::Student(const Student& other)
{
	copy(other);
}

Student& Student::operator=(const Student& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}

	return *this;
}

Student::~Student()
{
	free();
}

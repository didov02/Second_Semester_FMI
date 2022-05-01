#include "Lecturer.h"
#include <cstring>

#pragma warning (disable : 4996)

void Lecturer::copy(const Lecturer& other)
{
	this->lecturerName = new char[strlen(other.lecturerName) + 1];
	strcpy(this->lecturerName, other.lecturerName);
}

void Lecturer::free()
{
	delete[] lecturerName;
}

Lecturer::Lecturer()
{
	lecturerName = nullptr;
}

Lecturer::Lecturer(const char* name)
{
	this->lecturerName = new char[strlen(name) + 1];
	strcpy(this->lecturerName, name);
}

Lecturer::Lecturer(const Lecturer& other)
{
	copy(other);
}

Lecturer& Lecturer::operator=(const Lecturer& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}

	return *this;
}

Lecturer::~Lecturer()
{
	free();
}

const char* Lecturer::getName() const
{
	return lecturerName;
}
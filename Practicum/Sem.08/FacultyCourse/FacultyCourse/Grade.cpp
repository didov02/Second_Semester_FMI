#include "Grade.h"
#include <cstring>

#pragma warning (disable : 4996)

void Grade::copy(const Grade& other)
{
	this->grade = other.grade;

	this->task = new char[strlen(other.task) + 1];
	strcpy(this->task, other.task);

	this->from = new char[strlen(other.from) + 1];
	strcpy(this->from, other.from);
}

void Grade::free()
{
	delete[] from;
	delete[] task;
}

Grade::Grade()
{
	this->grade = NULL;
	this->from = nullptr;
	this->task = nullptr;
}

Grade::Grade(const double grade, const char* from, const char* task)
{
	this->grade = grade;
	
	this->task = new char[strlen(task) + 1];
	strcpy(this->task, task);
	
	this->from = new char[strlen(from) + 1];
	strcpy(this->from, from);
}

Grade::Grade(const Grade& other)
{
	copy(other);
}

Grade& Grade::operator=(const Grade& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}

	return *this;
}

Grade::~Grade()
{
	free();
}

double Grade::getGrade() const
{
	return this->grade;
}

const char* Grade::getFrom() const
{
	return this->from;
}

const char* Grade::getTask() const
{
	return this->task;
}

void Grade::setGrade(const double grade)
{
	this->grade = grade;
}

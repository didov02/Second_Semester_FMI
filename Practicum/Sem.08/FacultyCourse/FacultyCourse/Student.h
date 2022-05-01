#pragma once
#include "Grade.h"

const int MAX_GRADES = 7;
class Student
{
private:
	int fn;
	char* name;
	Grade grades[MAX_GRADES];
	short gradesCount;

public:
	Student();
	Student(int, const char*);
	Student(const Student&);
	Student& operator=(const Student&);
	~Student();

	int getFn() const;
	const char* getName() const;
	const Grade* getGrades() const;
	short getGradesCount() const;

	bool addGrade(const Grade& grade);
	bool editGrade(const Grade& grade);
private:
	void copy(const Student&);
	void free();
};


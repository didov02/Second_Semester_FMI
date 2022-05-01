#pragma once
#include "Lecturer.h"
#include "Assistant.h"
#include "Student.h"

const int MAX_ASSISTANTS = 3;
const int MAX_STUDENTS = 50;//could be modified

class OOPcourse
{
private:
	Lecturer lecturer;
	Assistant assistants[MAX_ASSISTANTS];
	Student students[MAX_STUDENTS];
	size_t studentsCount = 0;

public:
	OOPcourse() = default;
	OOPcourse(const char*, const char*);
	OOPcourse(const char*, const char*, const char*);
	OOPcourse(const char*, const char*, const char*, const char*);
	OOPcourse(const OOPcourse&) = default;
	OOPcourse& operator=(const OOPcourse&) = default;
	~OOPcourse() = default;

	bool addStudent(const char*, int);
	bool removeStudent(int);
	bool addGrade(int, const char*, double, const char*);
	bool editGrade(int, const char*, double, const char*);
	double getAvarageFromCourse() const;
	double getAvaragePerTask(const char*) const;
	double getAvarageFromTeacher(const char*) const;

private:
	Student* getStudentByFn(const int fn) const;

};


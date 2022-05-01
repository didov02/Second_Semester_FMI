#include "OOPcourse.h"
#include <cstring>

#pragma warning (disable : 4996)

Student* OOPcourse::getStudentByFn(int fn) const
{
	
}

OOPcourse::OOPcourse(const char* lecturer, const char* firstAssistant)
{
	this->lecturer = Lecturer(lecturer);
	this->assistants[0] = Assistant(firstAssistant);
}

OOPcourse::OOPcourse(const char* lecturer, const char* firstAssistant, const char* secondAssistant)
{
	this->assistants[1] = Assistant(secondAssistant);
	OOPcourse(lecturer, firstAssistant);
}

OOPcourse::OOPcourse(const char* lecturer, const char* firstAssistant, const char* secondAssistant, const char* thirdAssistant)
{
	this->assistants[2] = Assistant(thirdAssistant);
	OOPcourse(lecturer, firstAssistant, secondAssistant);
}

bool OOPcourse::addStudent(const char* name, int fn)
{
	if (this->studentsCount >= MAX_STUDENTS)
		return false;

	this->students[studentsCount++] = Student(fn, name);
	return true;
}

bool OOPcourse::removeStudent(int fn)
{

}

bool OOPcourse::addGrade(int fn, const char* task, double grade, const char* from)
{

}

bool OOPcourse::editGrade(int fn, const char* task, double grade, const char* from)
{

}

double OOPcourse::getAvarageFromCourse() const
{

}

double OOPcourse::getAvaragePerTask(const char*) const
{

}

double OOPcourse::getAvarageFromTeacher(const char*) const
{

}

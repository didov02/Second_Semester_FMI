#pragma once

class Grade
{
private:
	double grade;
	char* from;
	char* task;
public:
	Grade();
	Grade(const double, const char*, const char*);
	Grade(const Grade&);
	Grade& operator=(const Grade&);
	~Grade();

	double getGrade() const;
	const char* getFrom() const;
	const char* getTask() const;

	void setGrade(const double);
private:
	void copy(const Grade&);
	void free();
};


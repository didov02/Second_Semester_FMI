#pragma once

class Lecturer
{
private:
	char* lecturerName;
public:
	Lecturer();
	Lecturer(const char*);
	Lecturer(const Lecturer&);
	Lecturer& operator=(const Lecturer&);
	~Lecturer();

	const char* getName() const;
private:
	void copy(const Lecturer&);
	void free();
};


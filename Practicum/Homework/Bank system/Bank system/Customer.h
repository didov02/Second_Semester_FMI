#pragma once
#include <cstring>

#pragma warning (disable : 4996)

class Customer
{
private:
	size_t id;
	char* name;
	char* address;
public:
	Customer();
	Customer(size_t, char*, char*);
	Customer(const Customer&);
	Customer& operator=(const Customer&);
	~Customer();

	size_t getID() const;
	const char* getName() const;
	const char* getAddress() const;

	void setID(size_t);
	void setName(char*);
	void setAddress(char*);
private:
	void copy(const Customer&);
	void free();
};


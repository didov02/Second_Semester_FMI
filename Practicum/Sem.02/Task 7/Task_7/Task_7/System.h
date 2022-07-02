#pragma once
#include "User.h"
#include <fstream>

class System
{
private:
	User* users;
	size_t capacity;
	size_t size;
public:
	System();
	System(const System&);
	System& operator=(const System&);
	~System();

	void addUser(const User&);
	void removeUser(char*);//remove by email
	void printUsers() const;
	void login(const User&) const;
	void save(std::ofstream&);
private:
	void copy(const System&);
	void free();
	void resize();
};


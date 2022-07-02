#pragma once
#include <iostream>
#include <cstring>

#pragma warning (disable : 4996)

class User
{
private:
	char* name;
	char* email;
	char* password;
public:
	User();
	User(char*, char*, char*);
	User(const User&);
	User& operator=(const User&);

	void setName(char*);
	void setEmail(char*);
	void setPassword(char*);

	const char* getName() const;
	const char* getEmail() const;
	const char* getPassword() const;

	bool isUserAlreadyRegistrated(char*) const;
	void print() const;
	void deleteCurrentUser();
private:
	void copy(const User&);
	void free();
};


#pragma once
#include "User.h"

class Kindle
{
private:
	User* users;
	size_t usersCount;
	Book* booksToRead;
	size_t booksToReadCount;
public:
	Kindle();
	Kindle(User*, size_t, Book*, size_t);
	Kindle(const Kindle&);
	Kindle& operator=(const Kindle&);
	~Kindle();

	bool getInSystem(char*, char*) const;
	bool logOut() const;
private:
	void copy(const Kindle&);
	void free();
};


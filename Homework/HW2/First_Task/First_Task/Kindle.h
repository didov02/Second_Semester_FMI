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
	void logOut() const;

	void addUser(char*, char*, size_t) const;
	User getUser(char*, char*) const;
	User getUserByCount(size_t) const;
	size_t getUsersCount() const;

	Book getBook(char*);

	void setUsersCount(size_t);
	void setBooksToRead(Book*);
	void setBooksToReadCount(size_t);
	void setUser(User, size_t);
	void setBook(const Book&, size_t);
	void addBook(char*, char*, size_t, Page*);
private:
	void copy(const Kindle&);
	void free();
};


#pragma once
#include "Book.h"

class User
{
private:
	char* username;
	char* password;
	size_t readBooksCount;
	size_t writenBooksCount;
	size_t readBookCapacity;
	size_t writenBooksCapacity;
	Book* readBooks;
	Book* writenBooks;	
public:
	User();
	User(char*, char*, Book*, size_t, Book*, size_t);
	User(const User&);
	User& operator=(const User&);
	~User();

	void readBook(const Book&);
	void writeBook(char*, char*, size_t, Page*);
	void getPage(const Book&, size_t) const;
	void leaveComment(Book&, Comment) const;
	void readComments(const Book&) const;
	void rateBook(Book&, size_t);
	void changeRating(Book&, size_t);

	void setUsername(char*);
	void setPassword(char*);
	void setReadBooksCount(size_t);
	void setReadBooks(Book*);
	void setWritenBooksCount(size_t);
	void setWritenBooks(Book*);
	void addWritenBook(char*, char*, Rating*, size_t, size_t, size_t, Page*, Comment*, size_t);
	void addReadBook(char*, char*, Rating*, size_t, size_t, size_t, Page*, Comment*, size_t);

	bool isBookRead(const char*) const;

	char* getName() const;
	const char* getPassword() const;

	size_t resize(const size_t);

private:
	void copy(const User&);
	void free();
};


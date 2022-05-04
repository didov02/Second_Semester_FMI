#pragma once
#include "Book.h"

class User
{
private:
	char* username;
	char* password;
	size_t readBooksCount;
	size_t writenBooksCount;
	Book* readBooks;
	Book* writenBooks;	
public:
	User();
	User(char*, char*, Book*, size_t, Book*, size_t);
	User(const User&);
	User& operator=(const User&);
	~User();

	bool readBook(char*);//reads books name
	void writeBook(char*, int);//add new book with new name and pages
	void getPage() const;
	void leaveComment() const;
	void readComments() const;
	void changeWritenBook(char*);
	void rateBook(char*, size_t);
	void changeRating(char*, size_t);

	void setUsername(char*);
	void setPassword(char*);
	void setReadBooksCount(size_t);
	void setWritenBooksCount(size_t);

private:
	void copy(const User&);
	void free();
};


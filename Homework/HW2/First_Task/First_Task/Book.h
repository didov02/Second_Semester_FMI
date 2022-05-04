#pragma once
#include "Page.h"

struct Comment
{
	char* comment;
};

class Book
{
private:
	char* bookName;
	char* authorName;
	size_t rating;
	size_t pagesCount;
	size_t commentsCount;
	Page* pages;
	Comment* comments;
public:
	Book();
	Book(char*, char*, size_t, Page*, size_t, Comment*, size_t);
	Book(const Book&);
	Book& operator=(const Book&);
	~Book();
private:
	void copy(const Book&);
	void free();
};


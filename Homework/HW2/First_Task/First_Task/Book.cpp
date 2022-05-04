#include "Book.h"
#include <cstring>

#pragma warning (disable : 4996)

size_t GetSize(char* input)
{
	size_t counter = 0;

	while (input[counter] != '\0')
	{
		counter++;
	}

	return counter;
}

void CopyName(char* input1, char* input2, size_t size)
{
	for (int i = 0; i < size; i++)
	{
		input1[i] = input2[i];
	}

	input1[size + 1] = '\0';
}

void CopyComments(Comment* comments1, Comment* comments2, size_t size)
{
	for (int i = 0; i < size; i++)
	{
		strcpy(comments1[i].comment, comments2[i].comment);
	}
}

void CopyPages(Page* pages1, Page* pages2, size_t size)
{
	for (int i = 0; i < size; i++)
	{
		pages1[i] = pages2[i];
	}
}


void Book::free()
{
	delete[] bookName;
	delete[] authorName;
	delete[] pages;
	delete[] comments;
}

void Book::copy(const Book& other)
{
	bookName = new char[strlen(other.bookName) + 1];
	strcpy(bookName, other.bookName);

	authorName = new char[strlen(other.authorName) + 1];
	strcpy(authorName, other.authorName);

	rating = other.rating;

	comments = new Comment[other.commentsCount];
	CopyComments(comments, other.comments, other.commentsCount);

	commentsCount = other.commentsCount;

	pages = new Page[other.pagesCount];
	CopyPages(pages, other.pages, other.pagesCount);

	pagesCount = other.pagesCount;

}

Book::Book()
{
	bookName = new char[1];
	bookName[0] = '\0';

	authorName = new char[1];
	authorName[0] = '\0';

	rating = 0;

	pages = nullptr;
	pagesCount = 0;

	comments = nullptr;
	commentsCount = 0;
}

Book::Book(char* bookName, char* authorName, size_t rating, Page* pages, size_t pagesCount, Comment* comments, size_t commentsCount)
{
	this->bookName = new char[strlen(bookName) + 1];
	strcpy(this->bookName, bookName);

	this->authorName = new char[strlen(authorName) + 1];
	strcpy(this->authorName, authorName);

	this->rating = rating;

	this->pagesCount = pagesCount;

	this->commentsCount = commentsCount;

	this->comments = new Comment[commentsCount];
	CopyComments(this->comments, comments, commentsCount);

	this->pages = new Page[pagesCount];
	CopyPages(this->pages, pages, pagesCount);
	
}

Book::Book(const Book& other)
{
	copy(other);
}

Book& Book::operator=(const Book& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}

	return *this;
}

Book::~Book()
{
	free();
}

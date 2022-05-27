#include "Comment.h"
#include <cstring>

#pragma warning (disable : 4996)

void Comment::copy(const Comment& other)
{
	this->content = new char[strlen(other.content) + 1];
	strcpy(this->content, other.content);

	this->author = new char[strlen(other.author) + 1];
	strcpy(this->author, other.author);
}

void Comment::free()
{
	delete[] content;
	delete[] author;
}

Comment::Comment()
{
	content = nullptr;
	author = nullptr;
}

Comment::Comment(char* content, char* author)
{
	this->content = new char[strlen(content) + 1];
	strcpy(this->content, content);

	this->author = new char[strlen(author) + 1];
	strcpy(this->author, author);
}

Comment::Comment(const Comment& other)
{
	copy(other);
}

Comment& Comment::operator=(const Comment& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}

	return *this;
}

char* Comment::getContent() const
{
	return content;
}

char* Comment::getAuthor() const
{
	return author;
}

void Comment::setContent(char* content)
{
	delete[] this->content;
	this->content = new char[strlen(content) + 1];
	strcpy(this->content, content);
}

void Comment::setAuthor(char* author)
{
	delete[] this->author;
	this->author = new char[strlen(author) + 1];
	strcpy(this->author, author);
}


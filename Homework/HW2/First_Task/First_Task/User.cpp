#include "User.h"
#include <cstring>

#pragma warning (disable : 4996)

void CopyBooks(Book* readBooks1, Book* readBooks2, size_t size)
{
	for (int i = 0; i < size; i++)
	{
		readBooks1[i] = readBooks2[i];
	}
}

void User::copy(const User& other)
{
	username = new char[strlen(other.username) + 1];
	strcpy(username, other.username);

	password = new char[strlen(other.password) + 1];
	strcpy(password, other.password);

	readBooks = new Book[other.readBooksCount];
	CopyBooks(readBooks, other.readBooks, other.readBooksCount);

	writenBooks = new Book[other.writenBooksCount];
	CopyBooks(writenBooks, other.writenBooks, other.writenBooksCount);
}

void User::free()
{
	delete[] username;
	delete[] password;
	delete[] readBooks;
	delete[] writenBooks;
}

User::User()
{
	username = new char[1];
	username[0] = '\0';

	password = new char[1];
	password[0] = '\0';

	readBooks = nullptr;
	readBooksCount = 0;

	writenBooks = nullptr;
	writenBooksCount = 0;
}

User::User(char* username, char* password, Book* readBooks, size_t readBooksCount, Book* writenBooks, size_t writenBooksCount)
{
	this->username = new char[strlen(username) + 1];
	strcpy(this->username, username);

	this->password = new char[strlen(password) + 1];
	strcpy(this->password, password);

	this->readBooksCount = readBooksCount;
	this->writenBooksCount = writenBooksCount;

	this->readBooks = new Book[readBooksCount];
	CopyBooks(this->readBooks, readBooks, readBooksCount);

	this->writenBooks = new Book[writenBooksCount];
	CopyBooks(this->writenBooks, writenBooks, writenBooksCount);
}

User::User(const User& other)
{
	copy(other);
}

User& User::operator=(const User& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}

	return *this;
}

User::~User()
{
	free();
}

void User::setUsername(char* username)
{
	delete[] this->username;
	this->username = new char[strlen(username) + 1];
	strcpy(this->username, username);
}

void User::setPassword(char* password)
{
	delete[] this->password;
	this->password = new char[strlen(password) + 1];
	strcpy(this->password, password);
}

void User::setReadBooksCount(size_t newCount)
{
	readBooksCount = newCount;
}

void User::setWritenBooksCount(size_t newCount)
{
	writenBooksCount = newCount;
}

bool User::readBook(char* bookName)
{
	
}

void User::writeBook(char* bookName, int pagesCount)
{

}

void User::getPage() const
{

}

void User::leaveComment() const
{

}

void User::readComments() const
{

}

void User::changeWritenBook(char* bookName)
{

}

void User::rateBook(char* bookName, size_t rating)
{

}

void User::changeRating(char* bookName, size_t newRating)
{

}
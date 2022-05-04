#include "Kindle.h"
#include <cstring>
#include <fstream>
#include <iostream>

#pragma warning (disable : 4996)

const int MAX_OPTION = 100;
const int MAX_SIZE = 1024;

void CopyBooks(Book* readBooks1, Book* readBooks2, size_t size)
{
	for (int i = 0; i < size; i++)
	{
		readBooks1[i] = readBooks2[i];
	}
}

void CopyUsers(User* users1, User* users2, size_t size)
{
	for (int i = 0; i < size; i++)
	{
		users1[i] = users2[i];
	}
}

void Kindle::free()
{
	delete[] users;
	delete[] booksToRead;
}

void Kindle::copy(const Kindle& other)
{
	users = new User[other.usersCount];
	CopyUsers(users, other.users, other.usersCount);

	booksToRead = new Book[other.booksToReadCount];
	CopyBooks(booksToRead, other.booksToRead, other.booksToReadCount);
}

Kindle::Kindle()
{
	std::ifstream file("Users.txt");

	if (!file.is_open())
	{
		std::cout << "You have no data in your txt file." << std::endl;

		usersCount = 0;
		users = nullptr;

		booksToReadCount = 0;
		booksToRead = nullptr;
	}

	file >> usersCount;
	users = new User[usersCount];

	for (int i = 0; i < usersCount; i++)
	{
		char* currentUserUsername = new char[MAX_SIZE];
		file.getline(currentUserUsername, MAX_SIZE);

		char* currentUserPassword = new char[MAX_SIZE];
		file.getline(currentUserPassword, MAX_SIZE);

		size_t currentUserReadBooksCount;
		file >> currentUserReadBooksCount;

		size_t currentUserWritenBooksCount;
		file >> currentUserWritenBooksCount;

		users[i].setUsername(currentUserUsername);
		users[i].setPassword(currentUserPassword);
		users[i].setReadBooksCount(currentUserReadBooksCount);
		users[i].setWritenBooksCount(currentUserWritenBooksCount);
	}

}

Kindle::Kindle(User* users, size_t usersCount, Book* booksToRead, size_t booksToReadCount)
{
	this->usersCount = usersCount;
	this->booksToReadCount = booksToReadCount;

	this->users = new User[usersCount];
	CopyUsers(this->users, users, usersCount);

	this->booksToRead = new Book[booksToReadCount];
	CopyBooks(this->booksToRead, booksToRead, booksToReadCount);
}

Kindle::Kindle(const Kindle& other)
{
	copy(other);
}

Kindle& Kindle::operator=(const Kindle& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}

	return *this;
}

Kindle::~Kindle()
{
	free();
}

bool Kindle::getInSystem(char* username, char* password) const
{

}

bool Kindle::logOut() const
{

}

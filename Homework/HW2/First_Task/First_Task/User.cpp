#include "User.h"
#include <cstring>
#include <iostream>

#pragma warning (disable : 4996)

const int MAX_BUFF = 1024;

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

	readBookCapacity = 0;
	writenBooksCapacity = 0;
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

size_t User::resize(size_t checkingNum)
{
	size_t resizingNum = 4;

	while (resizingNum < checkingNum)
		resizingNum *= 2;

	return resizingNum;
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

void User::setReadBooks(Book* other)
{
	this->readBooks = other;
}

void User::setWritenBooks(Book* other)
{
	this->writenBooks = other;
}

void User::setWritenBooksCount(size_t newCount)
{
	writenBooksCount = newCount;
}

void User::readBook(const Book& book)
{
	if (readBooksCount + 1 > readBookCapacity)
	{
		readBookCapacity = resize(readBooksCount);
		Book* temp = new Book[readBooksCount];
		for (int i = 0; i < readBooksCount; i++)
		{
			temp[i] = readBooks[i];
		}

		delete[] readBooks;
		readBooks = new Book[readBookCapacity];
		readBooks = temp;
	}

	Book* pointer = new Book[readBooksCount+1];
	for (size_t i = 0; i < readBooksCount; i++)
	{
		pointer[i] = readBooks[i];
	}

	pointer[readBooksCount++] = book;

	delete[] readBooks;
	readBooks = new Book[readBooksCount];
	readBooks = pointer;
}

void User::writeBook(char* bookName, char* authorName, size_t pagesCount, Page* pages)
{
	if (writenBooksCount + 1 > writenBooksCapacity)
	{
		writenBooksCapacity = resize(writenBooksCount);
		Book* temp = new Book[writenBooksCount];
		for (int i = 0; i < writenBooksCount; i++)
		{
			temp[i] = writenBooks[i];
		}

		delete[] writenBooks;
		writenBooks = new Book[writenBooksCapacity];
		writenBooks = temp;
	}

	Book* pointer = new Book[writenBooksCount];
	for (size_t i = 0; i < writenBooksCount; i++)
	{
		pointer[i] = writenBooks[i];
	}

	writenBooksCount++;
	pointer[writenBooksCount].setBookName(bookName);
	pointer[writenBooksCount].setAuthorName(authorName);
	pointer[writenBooksCount].setPagesCount(pagesCount);
	pointer[writenBooksCount].setPages(pages);
	pointer[writenBooksCount].setCommentsCount(0);
	pointer[writenBooksCount].setComments(nullptr);
	pointer[writenBooksCount].setRatingsCount(0);
	pointer[writenBooksCount].setRatings(nullptr);

	delete[] writenBooks;
	writenBooks = new Book[writenBooksCount];

	writenBooks = pointer;

}

bool User::isBookRead(const char* name) const
{
	for (int i = 0; i < readBooksCount; i++)
	{
		if (strcmp(readBooks[i].getBookName(), name))
		{
			return true;
		}
	}

	return false;
}

void User::getPage(const Book& wantedBook, size_t pageNum) const
{
	if (!isBookRead(wantedBook.getBookName()))
	{
		std::cout << "This book hasn't been read!" << std::endl;
		
	}
	else
	{
		char* buffer = new char[MAX_BUFF];
		strcpy(buffer, wantedBook.getPage(pageNum).getPageContent());

		std::cout << buffer << std::endl;

		delete[] buffer;

	}
}

void User::leaveComment(Book& wantedBook, Comment comment) const
{
	if (!isBookRead(wantedBook.getBookName()))
	{
		std::cout << "This book hasn't been read!" << std::endl;
	}
	else
	{
		wantedBook.setComment(comment);
	}
}

void User::readComments(const Book& wantedBook) const
{
	if (!isBookRead(wantedBook.getBookName()))
		std::cout << "This book hasn't been read!" << std::endl;
	else
	{
		wantedBook.printComments();
	}
}

void User::rateBook(Book& wantedBook, size_t rating)
{
	if (!isBookRead(wantedBook.getBookName()))
		std::cout << "This book hasn't been read!" << std::endl;
	else
	{
		for (int i = 0; i < readBooksCount; i++)
		{
			if (strcmp(readBooks[i].getBookName(), wantedBook.getBookName()))
			{
				Rating currentRating;
				currentRating.setRating(rating);
				currentRating.setName(this->username);
				readBooks[i].setRating(currentRating);
			}
		}
	}
}

void User::changeRating(Book& wantedBook, size_t newRating)
{
	if (!isBookRead(wantedBook.getBookName()))
		std::cout << "This book hasn't been read!" << std::endl;
	else
	{
		for (int i = 0; i < readBooksCount; i++)
		{
			if (strcmp(readBooks[i].getBookName(), wantedBook.getBookName()))
			{
				Rating* rating = wantedBook.getRatings();
				for (int j = 0; j < wantedBook.getRatingsCount(); j++)
				{
					if (strcmp(rating[j].getPersonsName(), this->username))
					{
						rating[j].setRating(newRating);
					}
				}
			}
		}
	}
}

char* User::getName() const
{
	return username;
}

const char* User::getPassword() const
{
	return password;
}

void User::addWritenBook(char* bookName, char* authorName, Rating* ratings, size_t ratingsCount, size_t pagesCount, size_t commentsCount,
	Page* pages, Comment* comments, size_t count)
{
	writenBooks[count].setBookName(bookName);
	writenBooks[count].setAuthorName(authorName);
	writenBooks[count].setRatings(ratings);
	writenBooks[count].setRatingsCount(ratingsCount);
	writenBooks[count].setPagesCount(pagesCount);
	writenBooks[count].setCommentsCount(commentsCount);
	writenBooks[count].setPages(pages);
	writenBooks[count].setComments(comments);
}

void User::addReadBook(char* bookName, char* authorName, Rating* ratings, size_t ratingsCount, size_t pagesCount, size_t commentsCount,
	Page* pages, Comment* comments, size_t count)
{
	readBooks[count].setBookName(bookName);
	readBooks[count].setAuthorName(authorName);
	readBooks[count].setRatings(ratings);
	readBooks[count].setRatingsCount(ratingsCount);
	readBooks[count].setPagesCount(pagesCount);
	readBooks[count].setCommentsCount(commentsCount);
	readBooks[count].setPages(pages);
	readBooks[count].setComments(comments);
}

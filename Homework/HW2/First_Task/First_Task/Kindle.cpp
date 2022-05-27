#include "Kindle.h"

#pragma warning (disable : 4996)

const int MAX_MENU = 100;
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
	users = nullptr;
	usersCount = 0;

	booksToRead = nullptr;
	booksToReadCount = 0;
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
	for (int i = 0; i < usersCount; i++)
	{
		if (strcmp(users[i].getName(), username))
		{
			if (strcmp(users[i].getPassword(), password))
			{
				std::cout << "Welcome, " << username << "!" << std::endl;
				return true;
			}
		}
	}

	std::cout << "There is no user with such username or password. Try again!" << std::endl;
}

void Kindle::logOut() const
{
	std::cout << "Goodbye!" << std::endl;
}

void Kindle::addUser(char* username, char* password, size_t count) const
{
	users[count].setUsername(username);
	users[count].setPassword(password);
	users[count].setReadBooksCount(0);
	users[count].setWritenBooksCount(0);
	users[count].setReadBooks(nullptr);
	users[count].setWritenBooks(nullptr);
}

User Kindle::getUser(char* username, char* password) const
{
	for (int i = 0; i < usersCount; i++)
	{
		if (strcmp(users[i].getName(), username))
		{
			if (strcmp(users[i].getPassword(), password))
			{
				return users[i];
			}
		}
	}
}

void Kindle::setBooksToRead(Book* books)
{
	this->booksToRead = books;
}

void Kindle::setUser(User user,size_t currentUser)
{
	this->users[currentUser] = user;
}

void Kindle::setBook(const Book& book, size_t currentBook)
{
	this->booksToRead[currentBook] = book;
}

User Kindle::getUserByCount(size_t num) const
{
	return users[num];
}

void Kindle::setUsersCount(size_t count)
{
	this->usersCount = count;
}

void Kindle::setBooksToReadCount(size_t count)
{
	this->booksToReadCount = count;
}

size_t Kindle::getUsersCount() const
{
	return this->usersCount;
}

Book Kindle::getBook(char* bookName)
{
	for (int i = 0; i < booksToReadCount; i++)
	{
		if (strcmp(bookName, booksToRead[i].getBookName()))
		{
			return booksToRead[i];
		}
	}
}

void Kindle::addBook(char* bookName, char* authorName, size_t pagesCount, Page* pages)
{
	booksToReadCount++;
	booksToRead[booksToReadCount].setBookName(bookName);
	booksToRead[booksToReadCount].setAuthorName(authorName);
	booksToRead[booksToReadCount].setPagesCount(pagesCount);
	booksToRead[booksToReadCount].setPages(pages);
	booksToRead[booksToReadCount].setCommentsCount(0);
	booksToRead[booksToReadCount].setComments(nullptr);
	booksToRead[booksToReadCount].setRatings(nullptr);
	booksToRead[booksToReadCount].setRatingsCount(0);
}
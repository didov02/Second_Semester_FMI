#include <fstream>
#include "FillKindle.h"

void GetReadBooksFileName(char*& fileName, char* username)
{
	strcat(fileName, username);
	strcat(fileName, "'s read books");
}

void GetWritenBooksFileName(char*& fileName, char* username)
{
	strcat(fileName, username);
	strcat(fileName, "'s writen books");
}

void Fill(char* fileName, User& currentUser, char* mode, Kindle& kindle)
{
	std::ifstream file(fileName);

	size_t count;
	file >> count;

	if (strcmp(mode, "read"))
	{
		currentUser.setReadBooksCount(count);
	}
	else if (strcmp(mode, "write"))
	{
		currentUser.setWritenBooksCount(count);
	}
	else if (strcmp(mode, "booksToRead"))
	{
		kindle.setBooksToReadCount(count);
	}
	
	for (int j = 0; j < count; j++)
	{
		char* bookName = new char[MAX_SYMBOL];
		file.getline(bookName, MAX_SYMBOL);

		char* authorName = new char[MAX_SYMBOL];
		file.getline(authorName, MAX_SYMBOL);

		char* bookRatingsFileName = new char[MAX_SYMBOL];
		strcat(bookRatingsFileName, bookName);
		strcat(bookRatingsFileName, "_Ratings");

		std::ifstream ratingsFile(bookRatingsFileName);

		size_t ratingsCount;
		ratingsFile >> ratingsCount;
		Rating* ratings = new Rating[ratingsCount];

		for (int p = 0; p < ratingsCount; p++)
		{
			char* personName = new char[MAX_SYMBOL];
			ratingsFile.getline(personName, MAX_SYMBOL);
			ratings[p].setName(personName);
			delete[] personName;

			size_t rating;
			ratingsFile >> rating;
			ratings[p].setRating(rating);
		}

		ratingsFile.close();
		delete[] bookRatingsFileName;

		char* bookPagesFileName = new char[MAX_SYMBOL];
		strcat(bookPagesFileName, bookName);
		strcat(bookPagesFileName, "_Pages");

		std::ifstream pagesFile(bookPagesFileName);

		size_t pagesCount;
		pagesFile >> pagesCount;
		Page* pages = new Page[pagesCount];

		for (int p = 0; p < pagesCount; p++)
		{
			size_t page;
			pagesFile >> page;
			pages[p].setPage(page);

			char* pageContent = new char[MAX_SYMBOL];
			pagesFile.getline(pageContent, MAX_SYMBOL);
			pages[p].setContent(pageContent);

			delete[] pageContent;
		}

		pagesFile.close();
		delete[] bookPagesFileName;

		char* bookCommentsFileName = new char[MAX_SYMBOL];
		strcat(bookCommentsFileName, bookName);
		strcat(bookCommentsFileName, "_Comments");

		std::ifstream commentsFile(bookCommentsFileName);

		size_t commentsCount;
		commentsFile >> commentsCount;
		Comment* comments = new Comment[commentsCount];

		for (int p = 0; p < commentsCount; p++)
		{
			char* commentContent = new char[MAX_SYMBOL];
			commentsFile.getline(commentContent, MAX_SYMBOL);
			comments[p].setContent(commentContent);

			delete[] commentContent;

			char* commentAuthor = new char[MAX_SYMBOL];
			commentsFile.getline(commentAuthor, MAX_SYMBOL);
			comments[p].setAuthor(commentAuthor);

			delete[] commentAuthor;
		}

		commentsFile.close();
		delete[] bookCommentsFileName;

		if (strcmp(mode, "read"))
		{
			currentUser.addReadBook(bookName, authorName, ratings, ratingsCount, pagesCount, commentsCount, pages, comments, j);
		}
		else if (strcmp(mode, "write"))
		{
			currentUser.addWritenBook(bookName, authorName, ratings, ratingsCount, pagesCount, commentsCount, pages, comments, j);
		}
		else if (strcmp(mode, "booksToRead"))
		{
			Book tempBook;
			tempBook.setBookName(bookName);
			tempBook.setAuthorName(authorName);
			tempBook.setCommentsCount(commentsCount);
			tempBook.setComments(comments);
			tempBook.setPagesCount(pagesCount);
			tempBook.setPages(pages);
			tempBook.setRatingsCount(ratingsCount);
			tempBook.setRatings(ratings);

			kindle.setBook(tempBook, j);
		}

		delete[] bookName;
		delete[] authorName;
	}
	file.close();
}

void FillKindleUsers(Kindle& kindle)
{
	std::ifstream file("users.txt");
	size_t usersCount;
	file >> usersCount;
	kindle.setUsersCount(usersCount);

	for (int i = 0; i < usersCount; i++)
	{
		char* username = new char[MAX_SYMBOL];
		file.getline(username, MAX_SYMBOL);

		char* password = new char[MAX_SYMBOL];
		file.getline(password, MAX_SYMBOL);

		kindle.addUser(username, password, i);

		delete[] username;
		delete[] password;
	}

	file.close();

	for (int i = 0; i < kindle.getUsersCount(); i++)
	{
		User currentUser = kindle.getUserByCount(i);

		char* readBooksFileName = new char[MAX_SYMBOL];
		GetReadBooksFileName(readBooksFileName, currentUser.getName());
		char mode[MAX_SYMBOL] = { "read" };
		Fill(readBooksFileName, currentUser, mode, kindle);

		delete[] readBooksFileName;

		char* writenBooksFileName = new char[MAX_SYMBOL];
		GetWritenBooksFileName(writenBooksFileName, currentUser.getName());
		char otherMode[MAX_SYMBOL] = { "write" };
		Fill(writenBooksFileName, currentUser, otherMode, kindle);
		
		delete[] writenBooksFileName;

		kindle.setUser(currentUser, i);
	}
	
	char fileName[MAX_SYMBOL] = { "books.txt" };
	char mode[MAX_SYMBOL] = { "booksToRead" };
	User tempUser;
	Fill(fileName, tempUser, mode, kindle);
}
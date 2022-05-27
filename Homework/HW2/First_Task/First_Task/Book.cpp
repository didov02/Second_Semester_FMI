#include "Book.h"


void CopyComments(Comment* comments1, Comment* comments2, size_t size)
{
	for (int i = 0; i < size; i++)
	{
		comments1[i] = comments2[i];
	}
}

void CopyPages(Page* pages1, Page* pages2, size_t size)
{
	for (int i = 0; i < size; i++)
	{
		pages1[i] = pages2[i];
	}
}

void CopyRatings(Rating* rating1, Rating* rating2, size_t size)
{
	for (int i = 0; i < size; i++)
	{
		rating1[i] = rating2[i];
	}
}


void Book::free()
{
	delete[] bookName;
	delete[] authorName;
	delete[] pages;
	delete[] comments;
	delete[] ratings;
}

void Book::copy(const Book& other)
{
	bookName = new char[strlen(other.bookName) + 1];
	strcpy(bookName, other.bookName);

	authorName = new char[strlen(other.authorName) + 1];
	strcpy(authorName, other.authorName);

	ratingsCount = other.ratingsCount;

	comments = new Comment[other.commentsCount];
	CopyComments(comments, other.comments, other.commentsCount);

	commentsCount = other.commentsCount;

	pages = new Page[other.pagesCount];
	CopyPages(pages, other.pages, other.pagesCount);

	pagesCount = other.pagesCount;

	ratings = new Rating[other.ratingsCount];
	CopyRatings(ratings, other.ratings, other.ratingsCount);

}

Book::Book()
{
	bookName = new char[1];
	bookName[0] = '\0';

	authorName = new char[1];
	authorName[0] = '\0';

	ratings = nullptr;
	ratingsCount = 0;

	pages = nullptr;
	pagesCount = 0;

	comments = nullptr;
	commentsCount = 0;
}

Book::Book(char* bookName, char* authorName, Rating* raitings, size_t ratingsCount, Page* pages, size_t pagesCount, Comment* comments,
	size_t commentsCount, size_t capacity)
{
	this->bookName = new char[strlen(bookName) + 1];
	strcpy(this->bookName, bookName);

	this->authorName = new char[strlen(authorName) + 1];
	strcpy(this->authorName, authorName);

	this->ratingsCount = ratingsCount;

	this->pagesCount = pagesCount;

	this->commentsCount = commentsCount;

	this->comments = new Comment[commentsCount];
	CopyComments(this->comments, comments, commentsCount);

	this->pages = new Page[pagesCount];
	CopyPages(this->pages, pages, pagesCount);

	this->ratings = new Rating[ratingsCount];
	CopyRatings(this->ratings, ratings, ratingsCount);
	
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

void Book::setBookName(char* bookName)
{
	this->bookName = bookName;
}

void Book::setAuthorName(char* authorName)
{
	this->authorName = authorName;
}

void Book::setRatingsCount(size_t ratingsCount)
{
	this->ratingsCount = ratingsCount;
}

void Book::setPagesCount(size_t pagesCount)
{
	this->pagesCount = pagesCount;
}

void Book::setCommentsCount(size_t commentsCount)
{
	this->commentsCount = commentsCount;
}

void Book::setPages(Page* pages)
{
	this->pages = pages;
}
void Book::setComments(Comment* comments)
{
	this->comments = comments;
}

const char* Book::getBookName() const
{
	return bookName;
}

Page Book::getPage(size_t pageNum) const
{
	for (int i = 0; i < pagesCount; i++)
	{
		if (i == pageNum)
		{
			return pages[i];
		}
	}
}

void Book::setComment(Comment comment)
{
	this->comments[commentsCount++] = comment;
}

size_t Book::getCommentsCount() const
{
	return commentsCount;
}

void Book::printComments() const
{
	for (int i = 0; i < commentsCount; i++)
	{
		std::cout << comments[i].getContent() <<" by "<<comments[i].getAuthor()<< std::endl;
	}
}

double Book::calculateWholeRating() const
{
	double sum = 0;
	for (int i = 0; i < ratingsCount; i++)
	{
		sum += ratings[i].getRating();
	}

	sum /= ratingsCount;

	return sum;
}

void Book::setRating(Rating rating)
{
	this->ratings[ratingsCount] = rating;
	this->ratingsCount++;
}

void Book::setRatings(Rating* ratings)
{
	this->ratings = ratings;
}

size_t Book::getRatingsCount() const
{
	return ratingsCount;
}

Rating* Book::getRatings() const
{
	return ratings;
}

void Book::changeRating(char* username, size_t newRating)
{
	for (int i = 0; i < ratingsCount; i++)
	{
		if (strcmp(ratings[i].getPersonsName(), username))
		{
			ratings[i].setRating(newRating);
		}
	}
}


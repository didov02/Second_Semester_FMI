#pragma once
#include "Page.h"
#include "Rating.h"
#include "Comment.h"
#include <iostream>



class Book
{
private:
	char* bookName;
	char* authorName;
	Rating* ratings;
	size_t ratingsCount;
	size_t pagesCount;
	size_t commentsCount;
	Page* pages;
	Comment* comments;
public:
	Book();
	Book(char*, char*,Rating*, size_t, Page*, size_t, Comment*, size_t, size_t);
	Book(const Book&);
	Book& operator=(const Book&);
	~Book();

	void setBookName(char*);
	void setAuthorName(char*);
	void setRatingsCount(size_t);
	void setPagesCount(size_t);
	void setCommentsCount(size_t);
	void setPages(Page*);
	void setComments(Comment*);
	void setComment(Comment);
	void setRating(Rating);
	void setRatings(Rating*);

	Page getPage(size_t) const;
	const char* getBookName() const;
	size_t getCommentsCount() const;
	void printComments() const;
	double calculateWholeRating() const;
	size_t getRatingsCount() const;
	Rating* getRatings() const;

	void changeRating(char*, size_t);

private:
	void copy(const Book&);
	void free();
};


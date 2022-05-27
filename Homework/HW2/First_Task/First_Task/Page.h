#pragma once

#include <cstring>

#pragma warning (disable : 4996)
class Page
{
private:
	size_t page;
	char* content;
public:
	Page();
	Page(size_t, char*);
	Page(const Page& other);
	Page& operator=(const Page&);
	~Page();

	const char* getPageContent() const;
	size_t getPage() const;

	void setPage(size_t);
	void setContent(char*);
private:
	void copy(const Page&);
	void free();
};


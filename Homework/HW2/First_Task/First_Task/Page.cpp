#include "Page.h"

void Page::copy(const Page& other)
{
	page = other.page;

	content = new char[strlen(other.content) + 1];
	strcpy(content, other.content);
}

void Page::free()
{
	delete[] content;
}

Page::Page()
{
	page = 0;
	content = new char[1];
	content[0] = '\0';
}

Page::Page(size_t otherPage, char* content)
{
	this->page = otherPage;

	this->content = new char[strlen(content) + 1];
	strcpy(this->content, content);
}

Page::Page(const Page& other)
{
	copy(other);
}

Page& Page::operator=(const Page& other)
{
	if (this != &other)
	{
		page = 0;
		copy(other);
	}

	return *this;
}

Page::~Page()
{
	free();
}

const char* Page::getPageContent() const
{
	return content;
}

size_t Page::getPage() const
{
	return page;
}

void Page::setPage(size_t page)
{
	this->page = page;
}

void Page::setContent(char* content)
{
	delete[] this->content;
	this->content = new char[strlen(content) + 1];
	strcpy(this->content, content);
}

#include "Page.h"
#include <cstring>

#pragma warning (disable : 4996)

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
	page = otherPage;

	content = new char[1];
	content[0] = '\0';
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

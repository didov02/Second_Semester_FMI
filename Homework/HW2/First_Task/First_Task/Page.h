#pragma once
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
private:
	void copy(const Page&);
	void free();
};


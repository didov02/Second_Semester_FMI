#pragma once
class Comment
{
private:
	char* content;
	char* author;
public:
	Comment();
	Comment(char*, char*);
	Comment(const Comment&);
	Comment& operator=(const Comment&);
	~Comment();

	char* getContent() const;
	char* getAuthor() const;

	void setContent(char*);
	void setAuthor(char*);
private:
	void copy(const Comment&);
	void free();
};


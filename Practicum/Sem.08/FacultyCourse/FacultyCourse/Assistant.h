#pragma once

class Assistant
{
private:
	char* assistantName;
public:
	Assistant();
	Assistant(const char*);
	Assistant(const Assistant&);
	Assistant& operator=(const Assistant&);
	~Assistant();

	const char* getName() const;
private:
	void copy(const Assistant&);
	void free();
};


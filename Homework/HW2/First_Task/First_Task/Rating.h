#pragma once

#include <cstring>

#pragma warning (disable : 4996)
class Rating
{
private:
	char* personWhoRates;
	size_t rating;
public:
	Rating();
	Rating(char*, size_t);
	Rating(const Rating&);
	Rating& operator=(const Rating&);
	~Rating();

	const char* getPersonsName() const;
	size_t getRating() const;
	
	void setName(char*);
	void setRating(size_t);

private:
	void copy(const Rating&);
	void free();
};


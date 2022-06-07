#pragma once
#include <iostream>
#include <cstring>

#pragma warning (disable:4996)

enum Type
{
	CAR,
	MOTORCYCLE,
	BOAT,
	UNKNOWN
};

class Garage
{
protected:
	Type t;
private:
	char* color;
	size_t maxSpeed;
	size_t yearCreated;
public:
	Garage();
	Garage(char*, size_t, size_t);
	Garage(const Garage&);
	Garage& operator=(const Garage&);
	virtual ~Garage();

	void setColor(char*);
	void setMaxSpeed(size_t);
	void setYear(size_t);

	const char* getColor() const;
	size_t getMaxSpeed() const;
	size_t getYearCreated() const;

	virtual Garage* clone() const = 0;
	virtual Type getType() const = 0;
private:
	void copy(const Garage&);
	void free();
};


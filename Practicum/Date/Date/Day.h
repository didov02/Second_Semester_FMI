#pragma once

class Day
{
private:
	unsigned int day;
	unsigned int month;
	unsigned int year;

public:
	
	//Big 4
	Day();

	Day(unsigned int, unsigned int, unsigned int);

	Day(const Day&);

	Day& operator = (const Day&);

	~Day();

	//Mutators
	void setDay(unsigned int);
	void setMonth(unsigned int);
	void setYear(unsigned int);

	//Accessors
	unsigned int getDay() const;
	unsigned int getMonth() const;
	unsigned int getYear() const;

	//Methods
	void addToDate(unsigned int);
	void removeFromDate(unsigned int);
	bool isLeapYear() const;
	unsigned int daysToChristmas() const;
	unsigned int daysLeft() const;
	unsigned int daysToData(const Day&) const;
	bool isAfterCurrentDay(const Day&) const;
	void calculateDaysInDate(unsigned int); 
	unsigned int calculateWholeDateInDays() const;

private:
	void copy(const Day&);
};


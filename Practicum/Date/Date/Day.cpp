#include <iostream>
#include "Functions.h"

void Day::copy(const Day& currentDay)
{
	day = currentDay.day;
	month = currentDay.month;
	year = currentDay.year;
}

Day::Day()
{
	day = 1;
	month = 1;
	year = 2000;
}

Day::Day(unsigned int day, unsigned int month, unsigned int year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}

Day::Day(const Day& day)
{
	copy(day);
}

Day& Day::operator=(const Day& day)
{
	if (this != &day)
	{
		copy(day);
	}

	return *this;
}

void Day::setDay(unsigned int day)
{
	this->day = day;
}

void Day::setMonth(unsigned int month)
{
	this->month = month;
}

void Day::setYear(unsigned int year)
{
	this->year = year;
}

unsigned int Day::getDay() const
{
	return day;
}

unsigned int Day::getMonth() const
{
	return month;
}

unsigned int Day::getYear() const
{
	return year;
}

unsigned int Day:: calculateWholeDateInDays() const
{
	unsigned int currentDay = this->getDay();
	unsigned int currentMonth = this->getMonth();
	unsigned int currentYear = this->getYear();

	unsigned int counterOfLeapYears = 0;

	unsigned int yearsInDays = CalculateYear(currentYear, counterOfLeapYears);

	unsigned int monthsInDays = CalculateMonth(currentMonth, currentYear);

	return yearsInDays + monthsInDays + currentDay;
}

void Day::calculateDaysInDate(unsigned int wholeDateInDays)
{
	unsigned int newYear = GetYear(wholeDateInDays);

	unsigned int newMonth = GetMonth(wholeDateInDays, newYear);

	this->setYear(newYear);
	this->setMonth(newMonth);
	this->setDay(wholeDateInDays);
}

void Day::addToDate(unsigned int newDays)
{
	int newDateInDays = calculateWholeDateInDays() + newDays;
	this->calculateDaysInDate(newDateInDays);
}

void Day::removeFromDate(unsigned int newDays)
{
	int newDateInDays = calculateWholeDateInDays() - newDays;
	this->calculateDaysInDate(newDateInDays);
}

bool Day::isLeapYear() const
{
	return isCurrentYearLeap(this->year);
}

unsigned int Day::daysToChristmas() const
{
	unsigned int currentYear = this->year;
	unsigned int ChristmasMonth = 12;
	unsigned int ChristmasDay = 25;

	unsigned int daysToChristmas = 0;

	if (this->day >= ChristmasDay)//if we are after current year's christmas
	{
		daysToChristmas += MONTH_WITH_THIRTY_ONE_DAYS - this->day;
		if (isCurrentYearLeap(currentYear))
		{
			daysToChristmas += LEAP_YEAR - 6;//because 31-25 = 6
		}
		else
		{
			daysToChristmas += NORMAL_YEAR - 6;
		}
	}
	else
	{
		if (this->month == ChristmasMonth)
		{
			daysToChristmas += ChristmasDay - this->day;
		}
		else
		{
			unsigned int month = this->month;
			for (int i = month; i < ChristmasMonth; i++)
			{
				if (i == FEBRUARY)
				{
					if (isCurrentYearLeap(currentYear))
						daysToChristmas += LEAP_FEBRUARY;

					daysToChristmas += NORMAL_FEBRUARY;
				}
				else if (HasThirtyOneDays(i))
				{
					daysToChristmas += MONTH_WITH_THIRTY_ONE_DAYS;
				}
				else
				{
					daysToChristmas += MONTH_WITH_THIRTY_DAYS;
				}
			}
		}
	}

	return daysToChristmas;
}

unsigned int Day::daysLeft() const
{
	unsigned int daysLeft = 0;

	unsigned int month = this->month;
	unsigned int year = this->year;
	unsigned int day = this->day;

	FillToTheEndOfTheYear(day, month, year, daysLeft);

	return daysLeft;
}

unsigned int Day::daysToData(const Day& askedDay) const
{
	unsigned int daysLeft = 0;

	if (askedDay.year < this->year)
	{
		std::cout << "Couldn't be calculated!" << std::endl;
		return 0;
	}
	else if (askedDay.year == this->year)
	{
		if (askedDay.month < this->month)
		{
			std::cout << "Couldn't be calculated!" << std::endl;
			return 0;
		}
		else
		{
			if (askedDay.day >= this->day)
			{
				int currentMonth = this->month;
				for (int i = currentMonth; i < askedDay.month; i++)
				{
					if (i == FEBRUARY)
					{
						if (isCurrentYearLeap(this->year))
							daysLeft += LEAP_FEBRUARY;

						daysLeft += NORMAL_FEBRUARY;
					}
					else if (HasThirtyOneDays(i))
					{
						daysLeft += MONTH_WITH_THIRTY_ONE_DAYS;
					}
					else
					{
						daysLeft += MONTH_WITH_THIRTY_DAYS;
					}
				}

				daysLeft += askedDay.day - this->day;
			}
			else
			{
				std::cout << "Couldn't be calculated!" << std::endl;
				return 0;
			}
		}
	}
	else
	{
		unsigned int month = this->month;
		unsigned int year = this->year;
		unsigned int day = this->day;

		FillToTheEndOfTheYear(day, month, year, daysLeft);

		for (int i = year + 1; i < askedDay.year; i++)
		{
			if (isCurrentYearLeap(i))
			{
				daysLeft += LEAP_YEAR;
			}

			daysLeft += NORMAL_YEAR;
		}

		for (int i = 1; i < askedDay.month; i++)
		{
			if (i == FEBRUARY)
			{
				if (isCurrentYearLeap(this->year))
					daysLeft += LEAP_FEBRUARY;

				daysLeft += NORMAL_FEBRUARY;
			}
			else if (HasThirtyOneDays(i))
			{
				daysLeft += MONTH_WITH_THIRTY_ONE_DAYS;
			}
			else
			{
				daysLeft += MONTH_WITH_THIRTY_DAYS;
			}
		}

		daysLeft += askedDay.day;
	}

	return daysLeft;
}

bool Day::isAfterCurrentDay(const Day& askedDay) const
{
	if (askedDay.year < this->year)
	{
		return false;
	}
	else if (askedDay.month < this->month)
	{
		return false;
	}
	else if (askedDay.day < this->day)
	{
		return false;
	}
	else
	{
		return true;
	}
}



#include "Functions.h"

bool HasThirtyOneDays(unsigned int month)
{
	for (int i = 0; i < ThirtyOneDaysMonths; i++)
	{
		if (ThirthyOneDays[i] == month)
		{
			return true;
		}
	}

	return false;
}

bool HasThirtyDays(unsigned int month)
{
	for (int i = 0; i < ThirtyDaysMonths; i++)
	{
		if (ThirtyDays[i] == month)
		{
			return true;
		}
	}

	return false;
}

int GetLeapYears(unsigned int year)
{
	unsigned int leapYears = 0;

	for (int i = STARTING_YEAR; i < year; i++)
	{
		if (i % IS_LEAP_YEAR == 0)
		{
			leapYears++;
		}
	}

	return leapYears;
}

int CalculateMonth(unsigned int month, unsigned int year)
{
	unsigned int monthsInDays = 0;

	bool isYearLeap = false;
	
	if (year % IS_LEAP_YEAR == 0)
		isYearLeap = true;

	for (int i = STARTING_MONTH; i < month; i++)
	{
		if (HasThirtyOneDays(i))
		{
			monthsInDays += MONTH_WITH_THIRTY_ONE_DAYS;
		}
		else if (i == FEBRUARY)
		{
			if (isYearLeap)
				monthsInDays += LEAP_FEBRUARY;

			monthsInDays += NORMAL_FEBRUARY;
		}
		else
		{
			monthsInDays += MONTH_WITH_THIRTY_DAYS;
		}
	}

	return monthsInDays;
}

int CalculateYear(unsigned int year, unsigned int& leapYears)
{
	int years = 0;
	unsigned int yearsInDays = 0;

	for (int i = STARTING_YEAR; i < year; i++)
	{
		if (i % IS_LEAP_YEAR == 0)
		{
			leapYears++;
		}
		
		years++;
	}

	for (int i = 0; i < leapYears; i++)
	{
		yearsInDays += LEAP_YEAR;
	}

	for (int i = 0; i < years - leapYears; i++)
	{
		yearsInDays += NORMAL_YEAR;
	}

	return yearsInDays;
}

int GetYear(unsigned int& wholeDateInDays)
{
	unsigned int year = STARTING_YEAR;

	if (wholeDateInDays < LEAP_YEAR)
	{
		return year;
	}

	while (true)
	{
		if (year % IS_LEAP_YEAR == 0)
		{
			if (wholeDateInDays - LEAP_YEAR < 0)
			{
				break;
			}

			wholeDateInDays -= LEAP_YEAR;
		}
		else
		{
			if (wholeDateInDays - NORMAL_YEAR < 0)
			{
				break;
			}

			wholeDateInDays -= NORMAL_YEAR;
		}

		year++;
	}

	return year;
}

int GetMonth(unsigned int& wholeDateInDays, unsigned int currentYear)
{
	unsigned int month = STARTING_MONTH;
	
	if (wholeDateInDays < MONTH_WITH_THIRTY_ONE_DAYS)
	{
		return month;
	}

	bool isYearLeap = false;

	if (currentYear % IS_LEAP_YEAR == 0)
		isYearLeap = true;

	while (true)
	{
		if (HasThirtyOneDays(month))
		{
			if (wholeDateInDays - MONTH_WITH_THIRTY_ONE_DAYS < 0)
			{
				break;
			}

			wholeDateInDays -= MONTH_WITH_THIRTY_ONE_DAYS;
		}
		else if (HasThirtyDays(month))
		{
			if (wholeDateInDays - MONTH_WITH_THIRTY_DAYS < 0)
			{
				break;
			}

			wholeDateInDays -= MONTH_WITH_THIRTY_DAYS;
		}
		else if (month == FEBRUARY)
		{
			if (isYearLeap)
			{
				if (wholeDateInDays - LEAP_FEBRUARY < 0)
				{
					break;
				}

				wholeDateInDays -= LEAP_FEBRUARY;
			}
			else
			{
				if (wholeDateInDays - NORMAL_FEBRUARY < 0)
				{
					break;
				}

				wholeDateInDays -= NORMAL_FEBRUARY;
			}
		}

		month++;
	}
	
	return month;
}

bool isCurrentYearLeap(unsigned int year)
{
	if (year % IS_LEAP_YEAR == 0)
	{
		return true;
	}

	return false;
}

void FillToTheEndOfTheYear(unsigned int day, unsigned int month, unsigned int year, unsigned int& days)
{
	if (month == FEBRUARY)
	{
		if (isCurrentYearLeap(year))
			days += LEAP_FEBRUARY - day;

		days += NORMAL_FEBRUARY;
	}
	else if (HasThirtyOneDays(month))
	{
		days += MONTH_WITH_THIRTY_ONE_DAYS - day;
	}
	else
	{
		days += MONTH_WITH_THIRTY_DAYS - day;
	}

	for (int i = month + 1; i < 13; i++)
	{
		if (i == FEBRUARY)
		{
			if (isCurrentYearLeap(year))
				days += LEAP_FEBRUARY;

			days += NORMAL_FEBRUARY;
		}
		else if (HasThirtyOneDays(i))
		{
			days += MONTH_WITH_THIRTY_ONE_DAYS;
		}
		else
		{
			days += MONTH_WITH_THIRTY_DAYS;
		}
	}
}

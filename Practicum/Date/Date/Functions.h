#pragma once
#include "Day.h"
#include "Constants.h"

bool HasThirtyOneDays(unsigned int month);

bool HasThirtyDays(unsigned int month);

int GetLeapYears(unsigned int year);

int CalculateMonth(unsigned int month, unsigned int year);

int CalculateYear(unsigned int year, unsigned int& leapYears);

int GetYear(unsigned int& wholeDateInDays);

int GetMonth(unsigned int& wholeDateInDays, unsigned int currentYear);

bool isCurrentYearLeap(unsigned int year);

void FillToTheEndOfTheYear(unsigned int day, unsigned int month, unsigned int year, unsigned int& days);



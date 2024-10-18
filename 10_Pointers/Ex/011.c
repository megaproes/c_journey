#include <stdbool.h>

struct date
{
	int month;
	int day;
	int year;
};
void dateUpdate(struct date *today)
{
	int numberOfDays(struct date d);

	if (today->day != numberOfDays(*today))
	{
		today->day += 1; // Increment day
	}
	else if (today->month == 12)
	{ // End of year
		today->day = 1;
		today->month = 1;
		today->year += 1;
	}
	else
	{ // End of month
		today->day = 1;
		today->month += 1;
	}
}

// Function to find the number of days in a month
int numberOfDays(struct date d)
{
	int days;
	bool isLeapYear(struct date d);
	const int daysPerMonth[12] =
	    {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (isLeapYear(d) && d.month == 2)
		days = 29;
	else
		days = daysPerMonth[d.month - 1];
	return days;
}
// Function to determine if it's a leap year
bool isLeapYear(struct date d)
{
	bool leapYearFlag;
	if ((d.year % 4 == 0 && d.year % 100 != 0) ||
	    d.year % 400 == 0)
		leapYearFlag = true; // It's a leap year
	else
		leapYearFlag = false; // Not a leap year
	return leapYearFlag;
}
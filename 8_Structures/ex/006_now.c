// Program to determine tomorrow's date
#include <stdio.h>
#include <stdbool.h>
struct date
{
	int month;
	int day;
	int year;
};
// Function to calculate tomorrow's date
struct date dateUpdate(struct date today)
{
	struct date tomorrow;
	int numberOfDays(struct date d);

	if (today.day != numberOfDays(today))
		tomorrow = (struct date){.day = today.day + 1, .month = today.month, .year = today.year};
	else if (today.month == 12)
		tomorrow = (struct date){.day = 1, .month = 1, .year = today.year + 1};
	else
		tomorrow = (struct date){.day = 1, .month = today.month + 1, .year = today.year};

	return tomorrow;
}
// Function to find the number of days in a month
int numberOfDays(struct date d)
{
	int days;
	bool isLeapYear(struct date d);
	const int daysPerMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
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
	if ((d.year % 4 == 0 && d.year % 100 != 0) || d.year % 400 == 0)
		leapYearFlag = true; // It's a leap year
	else
		leapYearFlag = false; // Not a leap year
	return leapYearFlag;
}
int main(void)
{
	struct date dateUpdate(struct date today);
	struct date thisDay, nextDay;

	printf("Enter today's date (mm dd yyyy): ");
	scanf("%i%i%i", &thisDay.month, &thisDay.day, &thisDay.year);

	nextDay = dateUpdate(thisDay);

	printf("Tomorrow's date is %i / %i / %.2i.\n ", nextDay.month, nextDay.day, nextDay.year % 100);
	return 0;
}
#include <stdio.h>
#include <stdbool.h>

// Structures for time, date, and dateAndTime
struct time {
	int hour;
	int minutes;
	int seconds;
};

struct date {
	int month;
	int day;
	int year;
};

struct dateAndTime {
	struct date sdate;
	struct time stime;
};

// Function to calculate tomorrow's date
struct date dateUpdate(struct date today)
{
	struct date tomorrow;
	int numberOfDays(struct date d);
	if (today.day != numberOfDays(today))
	{
		tomorrow.day = today.day + 1;
		tomorrow.month = today.month;
		tomorrow.year = today.year;
	}
	else if (today.month == 12)
	{ // end of year
		tomorrow.day = 1;
		tomorrow.month = 1;
		tomorrow.year = today.year + 1;
	}
	else
	{ // end of month
		tomorrow.day = 1;
		tomorrow.month = today.month + 1;
		tomorrow.year = today.year;
	}
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

// Function to check if a year is a leap year
bool isLeapYear(struct date d)
{
	bool leapYearFlag;

	if ((d.year % 4 == 0 && d.year % 100 != 0) || d.year % 400 == 0)
		leapYearFlag = true;
	else
		leapYearFlag = false;

	return leapYearFlag;
}

// Function to update the time by one second
struct time timeUpdate(struct time now)
{
	now.seconds++;

	if (now.seconds == 60)
	{
		now.seconds = 0;
		now.minutes++;
	}

	if (now.minutes == 60)
	{
		now.minutes = 0;
		now.hour++;
	}

	if (now.hour == 24)
	{
		now.hour = 0; // Midnight
	}

	return now;
}

// Function to update both time and date if necessary (clockKeeper)
struct dateAndTime clockKeeper(struct dateAndTime dt)
{
	// Update the time first
	dt.stime = timeUpdate(dt.stime);

	// If the time is now midnight, update the date
	if (dt.stime.hour == 0 && dt.stime.minutes == 0 && dt.stime.seconds == 0)
	{
		dt.sdate = dateUpdate(dt.sdate);
	}

	// Return the updated dateAndTime structure
	return dt;
}

int main()
{
	// Example of using the clockKeeper function

	struct dateAndTime dt = {{12, 31, 2023}, {23, 59, 59}};
	dt = clockKeeper(dt);

	printf("Updated Date: %02d/%02d/%04d\n", dt.sdate.month, dt.sdate.day, dt.sdate.year);
	printf("Updated Time: %02d:%02d:%02d\n", dt.stime.hour, dt.stime.minutes, dt.stime.seconds);

	return 0;
}

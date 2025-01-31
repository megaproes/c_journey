#include <stdio.h>
#include <stdlib.h>

struct date
{
	int month;
	int day;
	int year;
} today, tomorrow; // Memory allocated for both variables
struct
{
	int id; // 4 bytes
	struct
	{
		int month; // 4 bytes
		int day;	 // 4 bytes
		double year;	 // 8 bytes
	} birthdate;	 // 16 bytes (nested struct)
} person;

int main()
{
	// Initialize today and tomorrow
	today.month = 1;
	today.day = 27;
	today.year = 2025;

	tomorrow.month = 1;
	tomorrow.day = 28;
	tomorrow.year = 2025;

	// Anonymous struct
	struct
	{
		int hours;
		int minutes;
		int seconds;
	} currentTime; // Variable created from an anonymous struct

	currentTime.hours = 12;
	currentTime.minutes = 30;
	currentTime.seconds = 45;

	printf("Today: %d/%d/%d\n", today.month, today.day, today.year);
	printf("Tomorrow: %d/%d/%d\n", tomorrow.month, tomorrow.day, tomorrow.year);
	printf("Current Time: %02d:%02d:%02d\n", currentTime.hours, currentTime.minutes, currentTime.seconds);
	printf("%i\n", sizeof(person)); 
	return 0;
}

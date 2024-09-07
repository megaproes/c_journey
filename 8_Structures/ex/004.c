#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Define the date structure
struct date
{
    int month;
    int day;
    int year;
};

// Helper function to adjust the year based on the month (to handle January and February)
int f(int year, int month)
{
    return month <= 2 ? year - 1 : year;
}

// Helper function to adjust the month for the formula (to handle January and February)
int g(int month)
{
    return month <= 2 ? month + 13 : month + 1;
}

// Function to compute the value of N for a given date
int N(struct date d1)
{
    return 1461 * f(d1.year, d1.month) / 4 + 153 * g(d1.month) / 5 + d1.day;
}

// Function to map the number (0-6) to the corresponding day of the week
const char* get_day_of_week(int day_num)
{
    const char* days_of_week[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    return days_of_week[day_num];
}

int main()
{
    struct date date1;

    // Input the date
    printf("Enter the date (YEAR:MONTH:DAY): ");
    scanf("%d:%d:%d", &date1.year, &date1.month, &date1.day);

    // Compute N for the given date
    int n_value = N(date1);

    // Subtract 621,049 from the result
    int adjusted_value = n_value - 621049;

    // Take the result modulo 7 to get the day of the week (0-6)
    int day_of_week = adjusted_value % 7;

    // Output the corresponding day of the week in English
    printf("The date falls on a: %s\n", get_day_of_week(day_of_week));

    return 0;
}

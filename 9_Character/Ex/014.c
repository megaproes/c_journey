#include <string.h>
#include <stdlib.h>
char *intToStr(int value)
{
	int is_negative = 0;
	int len = 0;
	int temp = value;

	// Handle negative value
	if (value < 0)
	{
		is_negative = 1;
		value = -value; // Convert to positive for easy manipulation
	}

	// Count the number of digits in the value
	do
	{
		len++;
		temp /= 10;
	} while (temp != 0);

	// Add space for the negative sign if necessary
	len += is_negative;

	// Allocate memory for the result (plus one for the null terminator)
	char *result = malloc(len + 1);

	result[len] = '\0'; // Null-terminate the string

	// Fill the string from the end to the start
	for (int i = len - 1; i >= is_negative; i--)
	{
		result[i] = (value % 10) + '0'; // Get the last digit and convert to char
		value /= 10;				  // Remove the last digit
	}

	// Add the negative sign if necessary
	if (is_negative)
	{
		result[0] = '-';
	}

	return result;
}
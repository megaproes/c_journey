#include <stdio.h>

int strToInt(const char string[])
{
	int i = 0, intValue, result = 0, is_negative = 0;

	// Check if the first character is a minus sign
	if (string[0] == '-')
	{
		is_negative = 1;
		i = 1; // Start processing the number after the minus sign
	}

	// Process the string until a non-digit character is found
	for (; string[i] >= '0' && string[i] <= '9'; ++i)
	{
		intValue = string[i] - '0';
		result = result * 10 + intValue;
	}

	// Return negative result if is_negative is set
	if (is_negative)
		return result * -1;

	return result;
}

int main(void)
{
	// Test cases
	printf("%i\n", strToInt("-2"));	   // Should print -2
	printf("%i\n", strToInt("100") + 25); // Should print 125
	printf("%i\n", strToInt("13x5"));	   // Should print 13 (stops at 'x')

	return 0;
}

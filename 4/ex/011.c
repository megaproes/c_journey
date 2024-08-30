#include <stdio.h>

int main()
{
	int integer, sum = 0, original_integer;
	printf("Enter the integer: ");
	scanf("%i", &integer);
	printf("\n");

	original_integer = integer; // Store the original integer for final output

	printf("The sum of the digits of %d is: ", original_integer);

	while (integer != 0)
	{
		int int_mod = integer % 10;
		sum += int_mod;

		if (integer / 10 != 0) // If this is not the last digit
			printf("%i + ", int_mod);
		else
			printf("%i", int_mod); // No + after the last digit

		integer /= 10;
	}
	printf(" = %i\n", sum);
	return 0;
}

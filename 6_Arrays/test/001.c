#include <stdio.h>

int main(void)
{
	const char baseDigits[16] = {
	    '0', '1', '2', '3', '4', '5', '6', '7',
	    '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

	int convertedNumber[64];
	long int numberToConvert;
	int nextDigit, base, index = 0;

	// Get the number and the base
	printf("Number to be converted? ");
	scanf("%ld", &numberToConvert);

	printf("Base? ");
	scanf("%i", &base);

	// Convert to the indicated base
	do
	{
		convertedNumber[index] = numberToConvert % base;
		numberToConvert = numberToConvert / base;
		++index; // Move to the next position
	} while (numberToConvert != 0);

	// Display the results in reverse order
	printf("Converted number = ");
	for (int i = index - 1; i >= 0; --i)
	{
		nextDigit = convertedNumber[i];
		printf("%c", baseDigits[nextDigit]);
	}
	printf("\n");

	return 0;
}

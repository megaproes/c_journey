#include <stdio.h>

void printBinary(int n)
{
	// Assuming we're dealing with 32-bit integers
	for (int i = 31; i >= 0; i--)
	{
		int bit = (n >> i) & 1; // Shift right by i bits and get the last bit
		printf("%d", bit);

		// Print a space after every 4 bits
		if (i % 4 == 0 && i != 0)
		{
			printf(" ");
		}
	}
}

int main()
{
	int w1 = 10;
	printf("%d in binary is: ", w1);
	printBinary(w1); 
	
	printf("\n%d & 0001 is:\t ", w1);
	printBinary(w1 & 0b0001);
	
	printf("\n%d & 0010 is:\t ", w1);
	printBinary(w1 & 0b0110);
	
	
	printf("\n");

	return 0;
}

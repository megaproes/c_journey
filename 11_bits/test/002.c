#include <stdio.h>

// Function to rotate an unsigned int left or right
unsigned int rotate(unsigned int value, int n)
{
	unsigned int result, bits;
	int bit_size = sizeof(value) * 8; // Modern way to get number of bits in an unsigned int (typically 32)

	// Ensure the shift count is within a valid range
	if (n > 0)
	{
		n = n % bit_size; // Left rotate
	}
	else
	{
		n = -(-n % bit_size); // Right rotate
	}

	if (n == 0)
	{
		result = value; // No rotation needed if n is zero
	}
	else if (n > 0)
	{
		// Left rotate
		bits = value >> (bit_size - n); // Get the leftmost bits that will wrap around
		result = (value << n) | bits;	  // Shift left and OR with wrapped bits
	}
	else
	{
		// Right rotate
		n = -n;					  // Convert to positive for right rotation
		bits = value << (bit_size - n); // Get the rightmost bits that will wrap around
		result = (value >> n) | bits;	  // Shift right and OR with wrapped bits
	}

	return result;
}
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

int main(void)
{
	unsigned int w1 = 0xabcdef00, w2 = 0xffff1122;
	printBinary(0xabcdef00);
	printf("\n\n");
	
	// Test cases
	printf("Rotate w1 left by 8: \n");	   // Expected: cdef00ab
	printBinary(rotate(w1, 8));
	printf("\n\n");
	
	printf("Rotate w1 right by 10: \n");	   
	printBinary(rotate(w1, -10));
	printf("\n\n");
	
	
	// printf("Rotate w1 right by 16: 0x%x\n", rotate(w1, -16)); // Expected: ef00abcd
	// printf("Rotate w2 left by 4: 0x%x\n", rotate(w2, 4));	   // Expected: fff1122f
	// printf("Rotate w2 right by 2: 0x%x\n", rotate(w2, -2));   // Expected: bfffc448

	return 0;
}

#include <stdio.h>
void printBinary(unsigned int n)
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
	unsigned int packed_data = 0; // Initialize packed_data

	// Setting 'type' field to 7
	packed_data |= 7 << 18;
	printf("Packed data after setting type to 7: \n");
	printBinary(packed_data);
	
	// Extracting 'type' from packed_data
	unsigned int type_value = (packed_data >> 18) & 0xff;
	printf("\nExtracted type value: %u\n", type_value);

	// Resetting 'type' field to 42 (clearing and then setting)
	packed_data &= ~(0xff << 18);	    // Clear the 'type' field
	packed_data |= (42 & 0xff) << 18; // Set 'type' to 42
	printf("\n\nPacked data after setting type to 42: \n");
	printBinary(packed_data);

	// Extracting the new 'type' value
	type_value = (packed_data >> 18) & 0xff;
	printf("Extracted type value: %u\n", type_value);

	unsigned int packed_data2 = 0;
	packed_data2 |= (0 << 16) | (1 << 17) | (0 << 18);

	printf("\n%u\n", packed_data2 >> 16 & 1);
	printf("\n%u\n", packed_data2 >> 17 & 1);
	printf("\n%u\n", packed_data2 >> 18 & 1);

	return 0;
}

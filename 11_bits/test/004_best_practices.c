#include <stdio.h>

// Define bit masks and positions for readability
#define F1_MASK 0x1
#define F1_POS 16
#define TYPE_MASK 0xff
#define TYPE_POS 18

unsigned int set_f1(unsigned int data, unsigned int f1_value)
{
	data &= ~(F1_MASK << F1_POS);			// Clear f1 field
	data |= (f1_value & F1_MASK) << F1_POS; // Set f1 field
	return data;
}

unsigned int set_type(unsigned int data, unsigned int type_value)
{
	data &= ~(TYPE_MASK << TYPE_POS);			 // Clear type field
	data |= (type_value & TYPE_MASK) << TYPE_POS; // Set type field
	return data;
}

int main()
{
	unsigned int packed_data = 0;

	// Set f1 and type values
	packed_data = set_f1(packed_data, 1);
	packed_data = set_type(packed_data, 200); // Overflow handling built-in

	// Extract values
	unsigned int f1 = (packed_data >> F1_POS) & F1_MASK;
	unsigned int type = (packed_data >> TYPE_POS) & TYPE_MASK;

	printf("f1: %u, type: %u\n", f1, type); // Outputs f1: 1, type: 200

	return 0;
}

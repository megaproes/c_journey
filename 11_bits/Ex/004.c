// Program to illustrate rotation of integers
#include <stdio.h>
unsigned int rotate(unsigned int value, int n);
int main(void)
{
	unsigned int w1 = 0xabcdef00u, w2 = 0xffff1122u;
	printf("%x\n", rotate(w1, 8));
	printf("%x\n", rotate(w1, -16));
	printf("%x\n", rotate(w2, 4));
	printf("%x\n", rotate(w2, -2));
	printf("%x\n", rotate(w1, 0));
	printf("%x\n", rotate(w1, 44));
	return 0;
}

int int_size()
{
	unsigned int full = ~0;
	short bits = 0;
	while (full)
	{
		full >>= 2;
		bits += 2;
	}
	return bits;
}

// Function to rotate an unsigned int left or right
unsigned int rotate(unsigned int value, int n)
{
	unsigned int result, bits;
	int bit_size = int_size();
	// scale down the shift count to a defined range
	if (n > 0)
		n = n % bit_size;
	else
		n = -(-n % bit_size);
	
	if (n == 0)
		result = value;
	else if (n > 0)
	{ // left rotate
		bits = value >> (bit_size - n);
		result = value << n | bits;
	}
	else
	{ // right rotate
		n = -n;
		bits = value << (bit_size - n);
		result = value >> n | bits;
	}
	return result;
}
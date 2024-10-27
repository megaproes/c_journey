#include <stdio.h>
int bit_test(unsigned int number, unsigned int bit)
{
	unsigned int value = (number >> (31 - bit)) & 0xff;
	return (value == 0) ? 0 : 1;
}
unsigned bit_set(unsigned int number, unsigned int bit)
{
	return number | (1 << (31 - bit));
}

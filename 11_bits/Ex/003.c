#include <stdio.h>

void int_size()
{
	unsigned int full = ~0;
	short bits = 0;
	while (full) {
		full >>= 2;
		bits += 2;
	}
	printf("%i\n", bits);
	
}

int main(int argc, char const *argv[])
{
	int_size();
	printf("\n%li\n%li\n", sizeof(int), sizeof(unsigned int));
	return 0;
}

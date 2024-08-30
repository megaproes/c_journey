#include <stdio.h>

int main(int argc, char const *argv[])
{
	for (int i = 5; i <= 50; i += 5)
	{
		int triangular_number = i * (i + 1) / 2;
		printf("%2i \t%2i\n", i, triangular_number);
	}

	return 0;
}

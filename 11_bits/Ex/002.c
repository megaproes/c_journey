#include <stdio.h>
#include <stdbool.h>

// Function to determine if the system performs an arithmetic right shift
bool isArithmetic(signed int num)
{
	return (num >> 1) < 0; // If still negative, it's an arithmetic shift
}

int main(int argc, char const *argv[])
{
	printf("The system performs arithmetic shift: %i\n", isArithmetic(-100));
	return 0;
}

#include <stdio.h>

void modifyArrayPointer(int * array)
{
	printf("Address before increment: %p\n", array);
	++array; // Increment the copied pointer
	printf("Address after increment:  %p\n", array);
}

int main(void)
{
	int values[3] = {1, 2, 3};
	int *ptr = values; // Pointer to the first element of values

	printf("Original address:        %p\n", ptr);

	modifyArrayPointer(ptr);

	printf("Address in main after function: %p\n", ptr); // Still the same!
	return 0;
}

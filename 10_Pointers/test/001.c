#include <stdio.h>

void modifyArrayPointer(int *array)
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

	const char *textPtr = "A much, much longer string that takes up more memory.";
	textPtr = "A new string!";

	const char *textPtr1 = "A much, much longer string that takes up more memory.";
	const char *textPtr2 = "A much, much longer string that takes up more memory.";

	if (textPtr1 == textPtr2)
	{
		printf("\n\nSame memory location!\n");
	}
	else
	{
		printf("Different memory locations!\n");
	}

	return 0;
}

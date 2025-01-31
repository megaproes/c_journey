#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *getLocalString()
{
	char localStr[] = "Temporary String"; // Local array
	return localStr;				   // Unsafe: pointer becomes invalid
}

void safeStringFunction()
{
	char *str = (char *)malloc(20 * sizeof(char));
	if (!str)
	{
		printf("Memory allocation failed!\n");
		return;
	}
	strcpy(str, "Safe Dynamic String");
	printf("Safe string: %s\n", str);
	free(str);  // Free memory
	str = NULL; // Avoid dangling pointer
}

int main()
{
	// Dangling pointer example
	char *str = getLocalString();
	printf("Dangling pointer: %s\n", str); // May print garbage or crash

	// Buffer overflow example
	char buffer[10];
	strcpy(buffer, "Short");
	printf("Buffer before overflow: %s\n", buffer);
	strcpy(buffer, "This is way too long!"); // Overflow: undefined behavior
	printf("Buffer after overflow: %s\n", buffer);

	// Safe dynamic allocation example
	safeStringFunction();

	return 0;
}

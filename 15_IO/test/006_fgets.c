#include <stdio.h>

int main()
{
	FILE *file = fopen("example.txt", "r");
	char buffer[100]; // Buffer to store a line

	if (!file)
	{
		perror("Error opening file");
		return 1;
	}

	while (fgets(buffer, sizeof(buffer), file))
	{						   // Reads one full line at a time
		printf("Line: %s", buffer); // Output includes \n
		//rewind(file);
	}

	fclose(file);
	return 0;
}

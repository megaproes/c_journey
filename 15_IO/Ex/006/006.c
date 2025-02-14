#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	FILE *in = fopen("file.txt", "r");
	if (in == NULL)
	{
		perror("Error opening input file");
		exit(1);
	}

	char choice = '\0', buffer[1024];
	int i = 0;

	while (1) // Infinite loop until we explicitly break
	{
		if (fgets(buffer, sizeof(buffer), in))
		{
			printf("%s", buffer);
			i++;
		}
		else
		{
			break; // Stop reading if EOF is reached
		}

		if (i == 20)
		{
			i = 0;
			printf("Type 'q' to quit or any other key to continue: ");

			choice = getchar(); // Read user input

			// Clear any extra characters in the buffer (like newline)
			while (getchar() != '\n')
				;

			if (choice == 'q')
			{
				break;
			}
		}
	}

	fclose(in);
	return 0;
}

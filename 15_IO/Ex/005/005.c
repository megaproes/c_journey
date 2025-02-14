#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void handle_input(int *m, int *n, FILE **f_ptr, int argc, const char *argv[])
{
	char in_file[256] = {0};
	char buffer[256] = {0};

	if (argc >= 2)
	{
		strncpy(in_file, argv[1], sizeof(in_file) - 1);
		in_file[sizeof(in_file) - 1] = '\0';
	}
	else
	{
		printf("Enter input file name: ");
		if (scanf("%255s", in_file) != 1)
		{
			perror("Error reading file name");
			exit(1);
		}
	}

	*f_ptr = fopen(in_file, "r");
	if (*f_ptr == NULL)
	{
		perror("Error opening input file");
		exit(1);
	}

	if (argc >= 3)
	{
		strncpy(buffer, argv[2], sizeof(buffer) - 1);
		buffer[sizeof(buffer) - 1] = '\0';
	}
	else
	{
		printf("Enter column range (m:n, m-n, m n): ");
		if (fgets(buffer, sizeof(buffer), stdin) == NULL)
		{
			fprintf(stderr, "Error reading range\n");
			exit(1);
		}
		buffer[strcspn(buffer, "\n")] = '\0';
	}

	_Bool cond =
	    (sscanf(buffer, "%d%*[ :-]%d", m, n) == 2) ||
	    (sscanf(buffer, "%d %d", m, n) == 2);
	printf("Debug: [%s]\n", buffer);

	if (!cond)
	{
		fprintf(stderr, "Error parsing characters\n");
		exit(1);
	}
	else if (*m > *n)
	{
		fprintf(stderr, "Error: m > n\n");
		exit(1);
	}
}

void handle_output(const int *m, const int *n, FILE *f_ptr)
{
	char buffer[1024] = {0};

	while (fgets(buffer, sizeof(buffer), f_ptr))
	{
		// If m is beyond the effective line length (excluding '\n'), print empty line
		// Subtract 1 for the newline if present
		if (*m > (int)strlen(buffer) - 1)
		{
			printf("(empty line)\n");
			continue;
		}

		// Use strcspn() to handle or strip the newline
		size_t line_length = strcspn(buffer, "\n");
		int printed = 0;
		// Print chars from m to n (inclusive), but not beyond line_length
		for (size_t i = *m; i <= (size_t)*n && i <= line_length; i++)
			putc(buffer[i - 1], stdout);

		putc('\n', stdout);
	}
}

int main(int argc, const char *argv[])
{
	int m = 0, n = 0;
	FILE *file_ptr = NULL;

	// Get user input / parse command-line args
	handle_input(&m, &n, &file_ptr, argc, argv);

	// Output the specified columns
	handle_output(&m, &n, file_ptr);

	// Close the file to avoid resource leaks
	fclose(file_ptr);

	return 0;
}

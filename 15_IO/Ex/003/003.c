#include <stdio.h>
#include <ctype.h>	// for toupper()
#include <stdlib.h> // for exit()

int main(void)
{
	char inName[64], outName[64];
	FILE *in, *out;
	int c;

	// Get file names from user
	printf("Enter name of file to be copied: ");
	if (scanf("%63s", inName) != 1)
	{
		fprintf(stderr, "Error reading input filename.\n");
		return 1;
	}

	printf("Enter name of output file: ");
	if (scanf("%63s", outName) != 1)
	{
		fprintf(stderr, "Error reading output filename.\n");
		return 1;
	}
	
	// Open input file
	in = fopen(inName, "r");
	if (in == NULL)
	{
		perror("Error opening input file");
		return 1;
	}

	// Open output file
	out = fopen(outName, "w");
	if (out == NULL)
	{
		perror("Error opening output file");
		fclose(in); // Close input file before exiting
		return 2;
	}

	// Copy in to out, converting lowercase to uppercase
	while ((c = getc(in)) != EOF)
	{
		putc(toupper(c), out);
	}

	// Close files
	fclose(in);
	fclose(out);

	printf("File has been copied successfully.\n");

	return 0;
}

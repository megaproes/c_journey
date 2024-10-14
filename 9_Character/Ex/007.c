#include <string.h>

// Function to insert string 'str[]' into 'source[]' at position 'pos'
void insertString(char source[], char str[], int pos)
{
	if (str[0] == '\0' || str == "" || pos < 0)
		return;

	int lenSource = strlen(source); // Length of the source string
	int lenStr = strlen(str);	  // Length of the string to be inserted

	// If the insertion position is beyond the end of the source string, append at the end
	if (pos > lenSource)
	{
		pos = lenSource;
	}

	// Shift characters in source[] to the right to make room for str[]
	for (int i = lenSource; i >= pos; i--)
	{
		source[i + lenStr] = source[i]; // Shift characters right
	}

	// Insert str[] into the correct position in source[]
	for (int i = 0; i < lenStr; i++)
	{
		source[pos + i] = str[i];
	}
}

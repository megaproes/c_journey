#include <string.h>
#include "007.c"
#include "006.c"
#include "005.c"

void replaceString(char source[], char str1[], char str2[])
{
	// Ensure valid inputs
	if (source == NULL || str1 == NULL || str2 == NULL)
		return;

	// Find the index of str1 in source
	int index = findString(source, str1);
	if (index != -1)
	{
		// Remove the found substring str1 from source
		removeString(source, index, strlen(str1));
		// Insert the replacement string str2 into the source
		insertString(source, str2, index);
	}
}

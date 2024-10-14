#include <string.h>

void removeString(char string[], int start_index, int k)
{
	int str_length = strlen(string);

	// Ensure valid inputs and prevent out-of-bounds access
	if (start_index < 0 || start_index >= str_length || k <= 0)
		return;

	// Ensure 'k' does not exceed the remaining length of the string
	if (start_index + k > str_length)
		k = str_length - start_index;

	// Shift the remaining part of the string left, overwriting the removed part
	for (int i = start_index; i + k < str_length; i++)
	{
		string[i] = string[k + i];
	}

	// Null-terminate the string at the new length
	string[str_length - k] = '\0';
}
void removeString_old(char string[], int start_index, int k)
{
	int str_length = strlen(string);
	if (start_index < 0 || k < 0 || string[0] == '\0' || str_length <= start_index)
		return;

	char temp[1024] = {0};
	int i, j;
	for (i = 0, j = 0; i < str_length; i++)
	{
		if (i == start_index)
		{
			i += k - 1;
			continue;
		}
		temp[j++] = string[i];
	}
	temp[i] = '\0';
	for (i = 0; temp[i] != '\0'; i++)
		string[i] = temp[i];

	string[i] = '\0';
}
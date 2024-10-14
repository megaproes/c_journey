#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
int countWords(const char string[]);
void readLine(char buffer[]);

void readLine(char buffer[])
{
	char character;
	int i = 0;
	do
	{
		character = getchar();
		buffer[i] = character;
		++i;
	} while (character != '\n');
	buffer[i - 1] = '\0';
}
int countWords(const char string[])
{
	int i, wordCount = 0;
	bool lookingForWord = true;
	for (i = 0; string[i] != '\0'; ++i)
	{
		bool is_separated = string[i] == '\'' || string[i] == '.' || string[i] == ',';
		if (isalpha(string[i]) || isdigit(string[i]) || is_separated || strchr("\'.,", string[i]) != NULL)
		{
			if (lookingForWord)
			{
				++wordCount;
				lookingForWord = false;
			}
		}
		else
			lookingForWord = true;
	}
	return wordCount;
}
int main(void)
{
	char text[81];
	int totalWords = 0;
	bool endOfText = false;

	printf("Type in your text.\n");
	printf("When you are done, press 'RETURN'.\n\n");

	while (!endOfText)
	{
		readLine(text);
		if (text[0] == '\0')
			endOfText = true;
		else
			totalWords += countWords(text);
	}

	printf("\nThere are %i words in the above text.\n", totalWords);
	return 0;
}
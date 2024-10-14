#include <stdio.h>
#include <stdbool.h>
int countWords(const char string[]);
bool alphabetic(const char c);
int countWords(const char string[]);
bool isDigit(const char ch);
bool alphabetic(const char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return true;
	else
		return false; // or simplier all above as return isalpha(c) != 0;
}
bool isDigit(const char ch)
{
	return ch >= '0' && ch <= '9';
}
int countWords(const char string[])
{
	int i, wordCount = 0;
	bool lookingForWord = true;
	for (i = 0; string[i] != '\0'; ++i)
	{
		bool is_separated = string[i] == '\'' || string[i] == '.' || string[i] == ',';

		if (alphabetic(string[i]) || isDigit(string[i]) || is_separated)
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
	const char text1[] = "Well, here goes.";
	const char text2[] = "And here we go... again.";
	const char text3[] = "It's an example!";
	const char text4[] = "It's a 1,234.56 example.";

	printf("%s - \twords = %i\n", text1, countWords(text1));
	printf("%s - \twords = %i\n", text2, countWords(text2));
	printf("%s - \twords = %i\n", text3, countWords(text3));
	printf("%s - \twords = %i\n", text4, countWords(text4));
	return 0;
}
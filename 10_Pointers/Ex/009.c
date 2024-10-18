void readLine(char *buffer)
{
	char character;
	int i = 0;
	do
	{
		character = getchar();
		*(buffer + i) = character;
		++i;
	} while (character != '\n');
	*(buffer + i - 1) = '\0';
}
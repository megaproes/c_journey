#include <stdio.h>
#include <ctype.h>

// Function to demonstrate isupper()
void showcase_isupper()
{
	char test_chars[] = {'A', 'Z', 'M', 'a', 'z', '1', '!', ' '};
	int num_chars = sizeof(test_chars) / sizeof(test_chars[0]);

	printf("\nTesting isupper():\n");
	for (int i = 0; i < num_chars; i++)
	{
		printf("isupper('%c') = %d\n", test_chars[i], isupper(test_chars[i]));
	}
}

// Function to demonstrate isalpha()
void showcase_isalpha()
{
	char test_chars[] = {'A', 'Z', 'm', 'z', '1', '!', ' '};
	int num_chars = sizeof(test_chars) / sizeof(test_chars[0]);

	printf("\nTesting isalpha():\n");
	for (int i = 0; i < num_chars; i++)
	{
		printf("isalpha('%c') = %d\n", test_chars[i], isalpha(test_chars[i]));
	}
}

// Function to demonstrate isdigit()
void showcase_isdigit()
{
	char test_chars[] = {'0', '5', '9', 'a', 'Z', '!', ' '};
	int num_chars = sizeof(test_chars) / sizeof(test_chars[0]);

	printf("\nTesting isdigit():\n");
	for (int i = 0; i < num_chars; i++)
	{
		printf("isdigit('%c') = %d\n", test_chars[i], isdigit(test_chars[i]));
	}
}

int main()
{
	printf("=== Demonstrating <ctype.h> functions ===\n");

	showcase_isupper();
	showcase_isalpha();
	showcase_isdigit();

	return 0;
}

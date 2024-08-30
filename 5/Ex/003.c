#include <stdio.h>

int main(int argc, char const *argv[])
{
	int num1, num2;

	// Prompt the user for input
	printf("Enter two integers separated by a space: ");
	scanf("%d %d", &num1, &num2);

	if (num2 == 0)
	{
		printf("Error: Division by zero is undefined.\n");
	}
	else
	{
		float result = (float)num1 / num2;
		printf("%i / %i = %.3f \n", num1, num2, result);
	}

	return 0;
}

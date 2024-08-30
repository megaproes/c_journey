#include <stdio.h>

int main()
{
	float number, accumulator = 0;
	char operator;

	printf("Enter the expression 'number operator' to start calculating:\n");

	while (1)
	{
		scanf("%f %c", &number, &operator);

		switch (operator)
		{
		case '+':
			accumulator += number;
			break;
		case '-':
			accumulator -= number;
			break;
		case '*':
			accumulator *= number;
			break;
		case '/':
			if (number == 0)
			{
				printf("Error: Division by zero is undefined.\n");
				continue;
			}
			accumulator /= number;
			break;
		case 'S':
			accumulator = number;
			break;
		case 'E':
			printf("= %.6f\n", accumulator);
			printf("End of calculations.\n");
			return 0;
		default:
			printf("Error: Unknown operator '%c'. Please enter a valid operator.\n", operator);
			continue;
		}

		printf("= %.6f\n", accumulator);
	}

	return 0;
}

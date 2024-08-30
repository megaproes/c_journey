#include <stdio.h>

int main(int argc, char const *argv[])
{
	int a, b;
	printf("Put two numbers with space: ");
	scanf("%i %i", &a, &b);

	printf("\n%i / %i = %f", a, b, (float)a / b);
	a % b == 0 ? printf(", so '%i' evenly divides '%i'\n", a, b) : printf(", so '%i' do NOT evenly divides '%i'\n", a, b);
	return 0;
}

// Idiomatic
int main() {
    int num1, num2;

    // Prompt the user for input
    printf("Enter two integers separated by a space: ");
    scanf("%d %d", &num1, &num2);

    // Check for division by zero
    if (num2 == 0) {
        printf("Error: Division by zero is undefined.\n");
    } else {
        // Calculate the result of the division
        float division_result = (float)num1 / num2;

        // Check if num1 is evenly divisible by num2
        if (num1 % num2 == 0) {
            printf("\n%d is evenly divisible by %d. (Result: %.2f)\n", num1, num2, division_result);
        } else {
            printf("\n%d is NOT evenly divisible by %d. (Result: %.2f)\n", num1, num2, division_result);
        }
    }

    return 0;
}
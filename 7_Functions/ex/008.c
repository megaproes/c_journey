#include <stdio.h>
float absoluteValue(float x)
{
	if (x < 0)
		x = -x;
	return (x);
}
// Function to compute the square root of a number
float squareRoot(float x, float epsilon)
{
	float guess = 1.0;
	while (absoluteValue((guess * guess / x) - 1) >= epsilon)
	{
		guess = (x / guess + guess) / 2.0;
	}
	return guess;
}
void calc_quadaratic_eq(int a, int b, int c)
{
	float discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
	{
		printf("Roots are imaginary\n");
		return;
	}
	float root1, root2;
	root1 = (-b + squareRoot(discriminant, .00001)) / (2 * a);
	root2 = (-b - squareRoot(discriminant, .00001)) / (2 * a);
	printf("root1 = %.3f, root2 = %.3f\n", root1, root2);
}
int main(int argc, char const *argv[])
{
	int a, b, c;

	printf("Put 'a', 'b' and 'c' separated by space to proceed: ");
	scanf("%i %i %i", &a, &b, &c);

	calc_quadaratic_eq(a, b, c);
	return 0;
}

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
	while (absoluteValue(guess * guess - x) >= epsilon){
		printf("guess = %f\n", guess);
		guess = (x / guess + guess) / 2.0;
	}
	printf("guess = %f\n", guess);
	return guess;
}
int main(void)
{
	float epsilon = .00001;
	printf("squareRoot (2.0) = %f\n", squareRoot(2.0, epsilon));
	printf("squareRoot (144.0) = %f\n", squareRoot(144.0, epsilon));
	printf("squareRoot (17.5) = %f\n", squareRoot(17.5, epsilon));
	return 0;
}
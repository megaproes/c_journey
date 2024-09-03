#include <stdio.h>
#include <stdlib.h>
int gcd(int a, int b)
{
	while (b != 0)
	{
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}
int lcm(int a, int b)
{
	return abs(a * b) / (gcd(a, b));
}
int main(int argc, char const *argv[])
{
	printf("gcd = %i\n", gcd(170, 950));
	printf("lcd = %i\n", lcm(170, 950));
	return 0;
}

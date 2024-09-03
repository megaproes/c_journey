#include <stdio.h>
#include <stdbool.h>
#include <math.h>
int is_prime(int number) {
	if(number <= 1) return false;
	if(number == 2) return true;
	if(number % 2 == 0) return false;
	
	int sqrt_n = (int)sqrt(number);
	for (int i = 3; i <= sqrt_n; i+=2)
		if(number%i == 0)
			return false;
	
	return true;
}
int main(int argc, char const *argv[])
{
	int num = 29;
	printf("%i is prime? -- %i\n", num, is_prime(num));
	return 0;
}

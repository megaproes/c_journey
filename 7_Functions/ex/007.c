#include <stdio.h>

long int x_to_the_n(int x, int n)
{
	if (n == 0)
		return 1;
	return x * x_to_the_n(x, n - 1);
}
long int x_to_the_n_iterative(int x, int n)
{
    long int result = 1;
    while (n > 0) {
        result *= x;
        n--;
    }
    return result;
}

int main(int argc, char const *argv[])
{	
	printf("%li \n", x_to_the_n(10, 3));
	return 0;
}

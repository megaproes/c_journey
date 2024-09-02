#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
	const int N = 100000;
	int *P = (int*)calloc(N + 1, sizeof(int));
	for (int i = 2; i <= N; i++)
	{
		if (P[i] == 0)
			printf("%i ", i);
		for (int j = i; j * i <= N; j++)
			P[i * j] = 1;
		
	}
	printf("\n");
	free(P);
	return 0;
}

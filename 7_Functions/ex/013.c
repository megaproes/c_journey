#include <stdio.h>

void sort(int a[], int n, char order)
{
	int i, j, temp;
	for (i = 0; i < n - 1; ++i)
	{
		for (j = i + 1; j < n; ++j)
		{
			if ((order == 'A' && a[i] > a[j]) || (order == 'D' && a[i] < a[j]))
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}

int main(void)
{
	int i;
		int array[16] = {34, -5, 6, 0, 12, 100, 56, 22,
					44, -3, -9, 12, 17, 22, 6, 11};

	printf("The array before the sort:\n");
	for (i = 0; i < 16; ++i)
		printf("%i ", array[i]);

	// Sorting in ascending order
	sort(array, 16, 'A');
	printf("\n\nThe array after ascending sort:\n");
	for (i = 0; i < 16; ++i)
		printf("%i ", array[i]);

	// Sorting in descending order
	sort(array, 16, 'D');
	printf("\n\nThe array after descending sort:\n");
	for (i = 0; i < 16; ++i)
		printf("%i ", array[i]);

	printf("\n");
	return 0;
}

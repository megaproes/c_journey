#include <stdio.h>
// 11:
#pragma region
int array[] = {1, 5, 10};
int arraySum(int size)
{
	int result = 0;
	for (int i = 0; i < size; i++)
		result += array[i];
	return result;
}
#pragma endregion
// 12:
#pragma region
int matrix1[4][5] = {{1, 5, 2, 56, 91}, {99, 28, 17, 7, 1}, {89, 64, 71, 63, 8}, {1, 2, 3, 4, 5}};
int matrix2[5][4] = {{0}};
void transposeMatrix(int in_matrix[4][5], int out_matrix[5][4])
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 5; j++)
			out_matrix[j][i] = in_matrix[i][j];
}

void printMatrix(int n, int m, int matrix[n][m])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%4i ", matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
#pragma endregion
// 13:
int array2[16] = {34, -5, 6, 0, 12, 100, 56, 22,
			  44, -3, -9, 12, 17, 22, 6, 11};
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

int main(int argc, char const *argv[])
{
	{ // 11

		printf("sum is %i\n", arraySum(3));
	}
	{ // 12
		transposeMatrix(matrix1, matrix2);
		printMatrix(4, 5, matrix1);
		printMatrix(5, 4, matrix2);
		printf("\n");
	}
	{ // 13
		sort(array2, 16, 'A');
		printf("\n\nThe array after ascending sort:\n");
		for (int i = 0; i < 16; ++i)
			printf("%i ", array2[i]);
	}
	return 0;
}

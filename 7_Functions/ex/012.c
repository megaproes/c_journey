#include <stdio.h>

void transposeMatrix(int in_matrix[4][5], int out_matrix[5][4])
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 5; j++)
			out_matrix[j][i] = in_matrix[i][j];
}

void transposeGeneral(int rows, int columns, int in_matrix[rows][columns], int out_matrix[columns][rows])
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
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

int main(int argc, char const *argv[])
{
	// a:
	{
		int matrix1[4][5] = {{1, 5, 2, 56, 91}, {99, 28, 17, 7, 1}, {89, 64, 71, 63, 8}, {1, 2, 3, 4, 5}};
		int matrix2[5][4] = {{0}};
		transposeMatrix(matrix1, matrix2);
		printMatrix(4, 5, matrix1);
		printMatrix(5, 4, matrix2);
		printf("\n");
	}
	
	// b:
	{
		int matrix1[4][5] = {{1, 5, 2, 56, 91}, {99, 28, 17, 7, 1}, {89, 64, 71, 63, 8}, {1, 2, 3, 4, 5}};
		int matrix2[5][4] = {{0}};
		transposeGeneral(4, 5, matrix1, matrix2);
		printMatrix(4, 5, matrix1);
		printMatrix(5, 4, matrix2);
		printf("\n");
	}
	return 0;
}

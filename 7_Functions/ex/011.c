#include <stdio.h>

int arraySum(int arr[], int size)
{
	int result = 0;
	for (int i = 0; i < size; i++)
		result += arr[i];
	return result;
}

int main(int argc, char const *argv[])
{
	int array[] = {1, 5, 10};
	printf("sum is %i\n", arraySum(array, 3));
	return 0;
}

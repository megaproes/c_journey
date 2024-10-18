void sort(int *array, int n)
{
	int i, j, temp;
	for (i = 0; i < n - 1; ++i)
		for (j = i + 1; j < n; ++j)
			if (array[i] > array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
}
void sort2(int *array, int n)
{
	int *i_ptr, *j_ptr, temp;

	// Loop through the array using pointer arithmetic
	for (i_ptr = array; i_ptr < array + n - 1; ++i_ptr)
	{
		for (j_ptr = i_ptr + 1; j_ptr < array + n; ++j_ptr)
		{
			if (*i_ptr > *j_ptr)
			{
				temp = *i_ptr;
				*i_ptr = *j_ptr;
				*j_ptr = temp;
			}
		}
	}
}

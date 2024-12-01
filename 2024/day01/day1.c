#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void	sort(int *arr, size_t n)
{
	size_t	i;
	int		temp;
	bool	sorted;

	do
	{
		i = 0;
		sorted = true;
		while (i+1 < n)
		{
			if (arr[i] > arr[i+1])
			{
				temp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = temp;
				sorted = false;
			}
			++i;
		}
	}
	while (!sorted);
}

int	main(void)
{
	int		sum_p1 = 0, sum_p2 = 0, d1, d2, repeated;
	int		*arr1 = NULL, *arr2 = NULL;
	size_t	arr_size = 0, arr_i = 0, arr_i1 = 0, arr_i2 = 0;

	while (EOF != fscanf(stdin, "%d   %d\n", &d1, &d2))
	{
		++arr_size;
		arr1 = realloc(arr1, arr_size * sizeof(int));
		arr2 = realloc(arr2, arr_size * sizeof(int));
		arr1[arr_size-1] = d1;
		arr2[arr_size-1] = d2;
	}
	sort(arr1, arr_size);
	sort(arr2, arr_size);
	while (arr_i++ < arr_size)
		sum_p1 += abs(arr1[arr_i-1] - arr2[arr_i-1]);
	while (arr_i1 < arr_size)
	{
		repeated = 0;
		arr_i2 = 0;
		while (arr_i2 < arr_size)
			if (arr1[arr_i1] == arr2[arr_i2++])
				++repeated;
		sum_p2 += arr1[arr_i1] * repeated;
		++arr_i1;
	}
	free(arr1);
	free(arr2);
	printf("Part one result: %d\n", sum_p1);
	printf("Part two result: %d\n", sum_p2);
}

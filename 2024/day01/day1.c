#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

void	sort(int *arr, size_t n)
{
	size_t	i = 0;
	int		temp;
	bool	sorted;

	do
	{
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
	int		sum = 0, d1, d2;
	int		*arr1 = NULL, *arr2 = NULL;
	size_t	arr_size = 0;

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
	while (arr_size--)
		sum += abs(arr1[arr_size] - arr2[arr_size]);
	free(arr1);
	free(arr2);
	printf("%d\n", sum);
}

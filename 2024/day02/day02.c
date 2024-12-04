#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define UP true
#define DOWN false
//		if (arr[arr_i] == arr[arr_i+1])
//			continue ;

void	safety_check(int *arr, size_t arr_size, bool *safe)
{
	size_t	arr_i = 0;
	bool	trend;

	if (arr[arr_i] < arr[arr_i+1])
		trend = UP;
	else
		trend = DOWN;
	*safe = true;
	while (++arr_i < arr_size)
	{
		if ((abs(arr[arr_i-1] - arr[arr_i]) <= 3)
			&& (arr[arr_i-1] != arr[arr_i])
			&& (trend?(arr[arr_i-1] < arr[arr_i]):(arr[arr_i-1] > arr[arr_i])))
			continue ;
		else
		{
			*safe = false;
			break ;
		}
	}
}

int	main(void)
{
	int		num;
	int		*arr = NULL, *arr2 = NULL;
	int		safe_sum_p1 = 0, safe_sum_p2 = 0;
	char	*tok = NULL;
	char	*line = NULL;
	size_t	n = 0, arr_size, arr_i, arr_i2, arr_i_neglect;
	bool	safe;

	while (EOF != getline(&line, &n, stdin))
	{
		tok = strtok(line, " ");
		arr_size = 0;
		while (tok)
		{
			num = atoi(tok);
			++arr_size;
			arr = realloc(arr, arr_size * sizeof(int));
			arr[arr_size-1] = num;
			tok = strtok(NULL, " ");
		}
		safety_check(arr, arr_size, &safe);
		if (safe)
		{
			++safe_sum_p1;
			continue ;
		}
		arr2 = realloc(arr2, (arr_size-1) * sizeof(int));
		arr_i_neglect = 0;
		while (arr_i_neglect < arr_size)
		{
			arr_i = 0;
			arr_i2 = 0;
			while (arr_i < arr_size)
			{
				if (arr_i_neglect != arr_i)
					arr2[arr_i2++] = arr[arr_i];
				++arr_i;
			}
			++arr_i_neglect;
			safety_check(arr2, arr_size, &safe);
			if (safe)
			{
				++safe_sum_p2;
				break ;
			}
		}
	}
	free(arr);
	free(arr2);
	free(line);
	printf("Part one, number of safe reports: %d\n", safe_sum_p1);
	printf("Part two, number of safe reports: %d\n", safe_sum_p1+safe_sum_p2);
}

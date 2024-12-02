#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define UP true
#define DOWN false

int	main(void)
{
	int		num;
	int		*arr = NULL;
	int		safe_sum = 0;
	char	*tok = NULL;
	char	*line = NULL;
	size_t	n = 0, arr_size = 0, arr_i;
	bool	safe, trend;

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
		arr_i = 0;
		if (arr[arr_i] == arr[arr_i+1])
			continue ;
		if (arr[arr_i] < arr[arr_i+1])
			trend = UP;
		else
			trend = DOWN;
		safe = true;
		while (arr_i++ < arr_size)
		{
			if ((abs(arr[arr_i-1] - arr[arr_i]) <= 3)
				&& (trend?(arr[arr_i-1] < arr[arr_i]):(arr[arr_i-1] > arr[arr_i])))
				continue ;
			else
			{
				safe = false;
				break ;
			}
		}
		if (safe)
			++safe_sum;
	}
	free(arr);
	arr = NULL;
	free(line);
	n = 0;
	printf("Part one, number of safe reports: %d\n", safe_sum);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(void)
{
	char		*line = NULL;
	size_t		n = 0;
	FILE		*input = fopen("./input.txt", "r");
	size_t		len;
	size_t		i;
	int			digits, sum = 0;
	const char	*nums[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	int			num_i;

	while (-1 != getline(&line, &n, input))
	{
		len = strlen(line)-1;
		i = 0;
		while (line[i])
		{
			num_i = 0;
			if ('1'<=line[i] && line[i]<='9')
			{
				digits = 10 * (line[i] - '0');
				break ;
			}
			else while (num_i < 9)
			{
				if (!strncmp(line+i, nums[num_i], 5))
				{
					digits = 10 * (num_i+1);
					break ;
				}
				num_i++;
			}
			i++;
		}
		while (len >= 0)
		{
			num_i = 0;
			if ('1'<=line[len] && line[len]<='9')
			{
				digits += line[len] - '0';
				break ;
			}
			else while (num_i < 9)
			{
				if (!strncmp(line+len, nums[num_i], 5))
				{
					digits += num_i+1;
					break ;
				}
				num_i++;
			}
			len--;
		}
		sum += digits;
	}
	printf("Sum of all calibration values: %d\n", sum);
	fclose(input);
	free(line);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(void)
{
	char	*line = NULL;
	size_t	n = 0;
	FILE	*input = fopen("input.txt", "r");
	int		prev_n;
	int		sum = 0;
	size_t	i = 0;
	size_t	len;

	getline(&line, &n, input);
	while (line[i])
	{
		if ((line[i] == line[i+1]) || !line[i+1] && line[i] == line[0]) // why does it not add the last number???
			sum += line[i] - '0';
		i++;
	}
	printf("Captcha result for part 1: %d\n", sum);
	sum = 0;
	i = 0;
	len = strlen(line);
	while (i < len/2)
	{
		if (line[i] == line[i+len/2])
			sum += 2*(line[i] - '0');
		i++;
	}
	printf("Captcha result for part 2: %d\n", sum);
	fclose(input);
	free(line);
}

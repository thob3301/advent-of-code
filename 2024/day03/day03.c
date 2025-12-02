#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

//bool	is_valid_mul(char *text)
//{
//

int	main(void)
{
	int		mul1, mul2, result = 0;
	char	*line = NULL;
	size_t	n = 0;
	size_t	line_i;
	char	*text;

	while (EOF != getline(&line, &n, stdin))
	{
		line_i = 0;
		while (line[line_i])
		{
			text = strstr(&line[line_i], "mul(");
			line_i += text - line + 4;
//			if (!is_valid_mul(text))
//			{
//				line_i += text - line + 1;
//				continue ;
//			}
			mul1 = atoi(&line[line_i]);
			line_i += floor(log10(abs(mul1)) + 1);
			if (line[line_i] && line[line_i] != ',')
				continue ;
			mul2 = atoi(&line[line_i]);
			line_i += floor(log10(abs(mul2)) + 1);
			if (line[line_i] && line[line_i] != ')')
				continue ;
			result += mul1 * mul2;
		}
	}
	free(line);
	printf("Part one, mul() sums: %d\n", result);
}

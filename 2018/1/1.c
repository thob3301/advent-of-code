#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	FILE	*input = fopen("input.txt", "r");
	char	sign;
	int		freq;
	int		sum = 0;

	while (-1 != fscanf(input, "%c%d\n", &sign, &freq))
	{
		if (sign == '-')
			freq = -freq;
		sum += freq;
	}
	fclose(input);
	printf("Frquency sum: %d\n", sum);
}

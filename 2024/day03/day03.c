#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int		mul1, mul2, result = 0;

	while (EOF != fscanf(stdin, "mul(%d,%d)", &mul1, &mul2))
		result += mul1 * mul2;
	printf("Part one, mul() sums: %d\n", result);
}

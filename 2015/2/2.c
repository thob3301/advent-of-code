#include <stdio.h>

int	main(void)
{
	FILE	*input = fopen("./input.txt", "r");
	int		l, w, h;
	int		paper = 0;
	int		ribbon = 0;

	while (EOF != fscanf(input, "%dx%dx%d\n", &l, &w, &h))
	{
		paper +=
		2*l*w+2*w*h+2*l*h + ((l*w<w*h?l*w:w*h)<l*h?(l*w<w*h?l*w:w*h):l*h);
		ribbon +=
		((2*l+2*w<2*w+2*h?2*l+2*w:2*w+2*h)<2*l+2*h?(2*l+2*w<2*w+2*h?2*l+2*w:2*w+2*h):2*l+2*h) + l*w*h;
	}
	printf("Square feet of paper: %d\n", paper);
	printf("Feet of ribbon: %d\n", ribbon);
	fclose(input);
}

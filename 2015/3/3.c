#include <stdio.h>
#include <stdlib.h>		

struct grid
{
	int	x;
	int	y;
};

void	tracesteps(size_t i, int *houses, struct grid location, char *line)
{
	size_t		j = 0;
	struct grid	traceback = {0, 0};

	if (location.x == 0 && location.y == 0)
		return ;
	while (i > j)
	{
		if (line[j] == '^')
			traceback.y++;
		else if (line[j] == 'v')
			traceback.y--;
		else if (line[j] == '>')
			traceback.x++;
		else if (line[j] == '<')
			traceback.x--;
		if (traceback.x == location.x && traceback.y == location.y)
			return ;
		j++;
	}
	(*houses)++;
}

int	main(void)
{
	struct grid	location = {0, 0};
	FILE		*input = fopen("./input.txt", "r");
	char		*line = NULL;
	size_t		n = 0;
	size_t		i = 0;
	int			houses = 1;

	getline(&line, &n, input);
	while (line[i])
	{
		if (line[i] == '^')
			location.y++;
		else if (line[i] == 'v')
			location.y--;
		else if (line[i] == '>')
			location.x++;
		else if (line[i] == '<')
			location.x--;
		tracesteps(i, &houses, location, line);
		i++;
	}
	printf("Number of houses with at least one present: %d\n", houses);
	fclose(input);
	free(line);
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int	main(void)
{
	char	*line = NULL;
	int		steps = 0;
	size_t	n = 0;
	FILE	*input = fopen("./input.txt", "r");
	int		steps_til_basement = 0;
	bool	basement_reached = false;
	int		floor = 0;

	getline(&line, &n, input);
	while (line[steps])
	{
		if (line[steps] == '(')
			floor++;
		else if (line[steps] == ')')
			floor--;
		if (!basement_reached && floor == -1)
		{
			steps_til_basement = steps;
			basement_reached = true;
		}
		steps++;
	}
	free(line);
	fclose(input);
	fprintf(stdout, "Ended at floor %d\n", floor);
	fprintf(stdout,  "Entered basement at %d steps\n" ,steps_til_basement+1);
}

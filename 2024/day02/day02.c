int	main(void)
{
	int		safe = 0, num;
	char	tok = NULL;
	char	*line = NULL;
	size_t	n = 0;

	while (EOF != getline(&line, &n, stdin))
	{
		tok = strtok(line, " ");
		while (tok)
		{
			num = atoi(tok);
			tok = strtok(NULL, " ");

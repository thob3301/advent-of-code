int	main(void)
{
	int		safe = 0, num;
	int		*arr = NULL;
	char	tok = NULL;
	char	*line = NULL;
	size_t	n = 0, arr_size;

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

	}
}

int count_lines_map(char *str_body_map)
{
	int	i;
	int lines_counter;

	i = 0;
	lines_counter = 0;
	while (str_body_map[i])
	{
		if (str_body_map[i] == '\n')
			lines_counter++;
		i++;
	}
	return (lines_counter);
}
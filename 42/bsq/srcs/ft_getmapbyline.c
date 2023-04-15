char	*get_map_by_line(char *str_map_body, int line_number)
{
	char	*str_map_by_line;
	int		i;
	int count_line;

	i = 0;
	count_line = 0;
	str_map_by_line = str_map_body;
	while (str_map_by_line[i] != '\0')
	{
		if (str_map_by_line[i] == '\n')
			count_line++;
		if (count_line == line_number)
			break ;
		i++;
	}
	if (count_line > 0)
		i++;
	return (&str_map_by_line[i]);
}
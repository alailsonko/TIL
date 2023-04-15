int	get_width_size(char *str_body_map)
{
	int	i;

	i = 0;
	while (str_body_map[i] != '\n')
		i++;
	return (i);
}
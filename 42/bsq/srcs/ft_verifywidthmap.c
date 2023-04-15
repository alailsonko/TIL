#include "ft_app.h"

int verify_width_map(char *str_body_map, struct s_map_dict *map_dict)
{
	int		i, lines_counter, first_line_width_counter, curr_line_width_counter;
	char	*str_body;

	i = 0;
	lines_counter = 0;
	str_body = str_body_map;
	first_line_width_counter = get_width_size(str_body_map);
	(*map_dict).width_size = first_line_width_counter;
	curr_line_width_counter = 0;
	while (str_body[i])
	{
		if ((str_body[i] != '\n' && lines_counter > 0))
			curr_line_width_counter++;
		else if (str_body[i] == '\n')
		{
			if ((curr_line_width_counter != first_line_width_counter) && lines_counter > 0)
				return (0);
			lines_counter++;
			curr_line_width_counter = 0;
		}
		i++;
	}
	return (1);
}
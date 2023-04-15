#include "ft_app.h"

int	verify_body_map_lines(char *str_body_map, struct s_map_dict *map_dict)
{
	if ((*map_dict).line_size != count_lines_map(str_body_map))
		return (0);
	return (1);
}
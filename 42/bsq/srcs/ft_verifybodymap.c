#include "ft_app.h"

int	verify_body_map(char *str_body_map, struct s_map_dict *map_dict)
{
	if (!verify_body_map_char(str_body_map, map_dict))
		return (0);
	if (!verify_body_map_lines(str_body_map, map_dict))
		return (0);
	if (!verify_width_map(str_body_map, map_dict))
		return (0);
	return (1);
}
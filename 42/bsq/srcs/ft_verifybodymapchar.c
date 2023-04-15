#include "ft_app.h"

int	verify_body_map_char(char *str_body_map, struct s_map_dict *map_dict)
{
	int	i;

	i = 0;
	while (str_body_map[i] != '\0')
	{
		if (str_body_map[i] != (*map_dict).char_empty && str_body_map[i] != (*map_dict).char_full && str_body_map[i] != (*map_dict).char_obstacle && str_body_map[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}
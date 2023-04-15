#include "ft_app.h"

int	verify_map_2(char *str_map, struct s_map_dict *map_dict)
{
	char	*str_header;
	char	*str_body;

	str_header = get_header_map(str_map);
	str_body = get_body_map(str_map);
	if (!verify_header_map(str_header, map_dict))
	{
		free((*map_dict).str_map);
		free(str_header);
		return (0);
	}
	if (!verify_body_map(str_body, map_dict))
	{
		free((*map_dict).str_map);
		free(str_header);
		return (0);
	}
	free(str_header);
	return (1);
}
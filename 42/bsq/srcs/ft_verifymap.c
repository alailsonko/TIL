#include "ft_app.h"

int	verify_map(char *argv, struct s_map_dict *map_dict)
{
	char	*str_map;
	int		buf_size;

	buf_size = ft_size_file(argv);
	if (!buf_size)
		return (0);
	str_map = malloc(sizeof(char) * (buf_size + 1));
	if (!get_map(argv, str_map, buf_size))
		return (0);
	(*map_dict).str_map = str_map;
	if (!verify_map_2(str_map, map_dict))
		return (0);
	return (1);
}
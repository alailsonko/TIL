#include "ft_app.h"

char	*read_map(char *map_filename, char *str_line, int size)
{
	int	map;
	char	str[size];

	map = open(map_filename, O_RDONLY, 0);
	read(map, &str, size);
	close(map);
	return (ft_strncpy(str_line, str, size));
}
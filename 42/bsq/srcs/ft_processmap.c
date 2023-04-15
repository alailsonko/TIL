#include "ft_app.h"

int	process_map(char *filename)
{
	struct s_map_dict *map_dict;
	int		i;

	map_dict = malloc(sizeof(struct s_map_dict));
	if (verify_map(filename, map_dict))
	{
		solve_map(map_dict);
		i = 0;
		while ((*map_dict).str_map[i] != '\0' )
		{
			write(1, &(*map_dict).str_map[i], 1);
			i++;
		}
		write(1, "\n", 1);
		free((*map_dict).str_map);
		free(map_dict);
		return (1);
	}
	write(1, "map error\n", 10);
	free(map_dict);
	return (0);
}
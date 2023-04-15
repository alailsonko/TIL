#include "ft_app.h"

int	solve_map(struct s_map_dict *map_dict)
{
	int		**str_map_body_matrix;
	int i;

	i = 0;
	str_map_body_matrix = get_matrix_map(map_dict);

	while (i < (*map_dict).line_size)
	{
		free(str_map_body_matrix[i]);
		i++;
	}
	free(str_map_body_matrix);
	return (1);
}
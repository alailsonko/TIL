#include "ft_app.h"

int **parse_map_to_matrix(char *str_map_body, struct s_map_dict *map_dict)
{
	int		**map_body_matrix;
	char	*self_str_map_body;
	int		i;
	int		j;

	i = 0;
	j = 0;
	map_body_matrix = malloc(sizeof(int *) * ((*map_dict).line_size + 1));
	while (i < (*map_dict).line_size)
	{
		map_body_matrix[i] = malloc(sizeof(int) * ((*map_dict).width_size));
		self_str_map_body = get_map_by_line(str_map_body, i);
		while (j < (*map_dict).width_size)
		{
			map_body_matrix[i][j] = self_str_map_body[j] - '0';
			j++;
		}
		j = 0;
		i++;
	}
	map_body_matrix[i] = NULL;
	return (map_body_matrix);
}
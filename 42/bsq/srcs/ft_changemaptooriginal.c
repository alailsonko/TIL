#include "ft_app.h"

int	**change_map_to_original(int **map_body_matrix, struct s_map_dict *map_dict)
{
	int		**self_map_body_matrix;
	char	*self_map_body_matrix_char;
	int	i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	self_map_body_matrix = map_body_matrix;
	self_map_body_matrix_char = get_body_map((*map_dict).str_map);
	while (i < (*map_dict).line_size)
	{
		j = 0;
		while (j < (*map_dict).width_size)
		{
			if (self_map_body_matrix[i][j] == -1)
				self_map_body_matrix_char[k] = (*map_dict).char_full;
			else if (self_map_body_matrix[i][j] == 0)
				self_map_body_matrix_char[k] = (*map_dict).char_obstacle;
			else if (self_map_body_matrix[i][j] != '\n')
				self_map_body_matrix_char[k] = (*map_dict).char_empty;
			j++;
			k++;
		}
		k++;
		i++;
	}
	return (self_map_body_matrix);
}
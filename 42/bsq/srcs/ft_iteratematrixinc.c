#include "ft_app.h"

int	**iterate_matrix_inc(int **map_body_matrix, struct s_map_dict *map_dict)
{
	int	**self_map_body_matrix;
	int	i;
	int j;
	int counter;

	i = 0;
	j = 0;
	counter = 1;
    self_map_body_matrix = map_body_matrix;
	while (i < (*map_dict).line_size)
	{
		while (j < (*map_dict).width_size)
		{
			if (self_map_body_matrix[i][j] == 1)
			{
				self_map_body_matrix[i][j] = counter;
				counter++;
			}
			else if (self_map_body_matrix[i][j] == 0)
			{
				counter = 1;
			}
			j++;
		}
		j = 0;
		counter = 1;
		i++;
	}
	return (self_map_body_matrix);
}
#include "ft_app.h"

int	**get_matrix_map(struct s_map_dict *map_dict)
{
	char	*str_map_body_bin;
	int		**str_map_body_matrix;

	str_map_body_bin = change_map_bin(map_dict);
	str_map_body_matrix = parse_map_to_matrix(str_map_body_bin, map_dict);
	str_map_body_matrix = set_biggest_square(str_map_body_matrix, map_dict);
	str_map_body_matrix = change_map_to_original(str_map_body_matrix, map_dict);
	free(str_map_body_bin);
	return (str_map_body_matrix);
}
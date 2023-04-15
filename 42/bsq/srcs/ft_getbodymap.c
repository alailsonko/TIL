#include "ft_app.h"

char	*get_body_map(char *str_map)
{
	int	buf_header_size;

	buf_header_size = ft_str_len_index(str_map, '\n');
	return (&str_map[buf_header_size + 1]);
}
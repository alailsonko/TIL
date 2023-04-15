#include "ft_app.h"

char	*get_header_map(char *str_map)
{
	char	*str_header;
	int		buf_header_size;

	buf_header_size = ft_str_len_index(str_map, '\n');
	str_header = malloc(sizeof(char) * (buf_header_size + 1));
	ft_strncpy(str_header, str_map, buf_header_size);
	return (str_header);
}
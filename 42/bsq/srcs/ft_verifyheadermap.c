#include "ft_app.h"

int	verify_header_map(char	*str_header, struct s_map_dict *map_dict)
{
	int		str_i_len_header;
	int		len_size_nbr;
	int		err;
	char	*nbr_str;

	str_i_len_header = ft_strlen(str_header);
	(*map_dict).char_full = str_header[str_i_len_header - 1];
	(*map_dict).char_obstacle = str_header[str_i_len_header - 2];
	(*map_dict).char_empty = str_header[str_i_len_header - 3];
	len_size_nbr = str_i_len_header - 3;
	if (len_size_nbr <= 0)
		return (0);
	nbr_str = malloc(sizeof(char) * (len_size_nbr + 1));
	ft_strncpy(nbr_str, str_header, len_size_nbr);
	err = is_numeric(nbr_str);
	if (!err)
	{
		free(nbr_str);
		return (0);
	}
	(*map_dict).line_size = ft_atoi(nbr_str);
	free(nbr_str);
	return (1);
}
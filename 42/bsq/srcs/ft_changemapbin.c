#include "ft_app.h"

char	*change_map_bin(struct s_map_dict *map_dict)
{
	int		i;
	char	*str_map_body_bin;
	char	*str_map_body;

	i = 0;
	str_map_body = get_body_map((*map_dict).str_map);
	str_map_body_bin = malloc(sizeof(char) * (ft_strlen(str_map_body) + 1));
	while (str_map_body[i] != '\0')
	{
		if (str_map_body[i] == (*map_dict).char_empty)
			str_map_body_bin[i] = '1';
		else if (str_map_body[i] == (*map_dict).char_obstacle)
			str_map_body_bin[i] = '0';
		else
			str_map_body_bin[i] = str_map_body[i];
		i++;
	}
	str_map_body_bin[i] = '\0';
	return (str_map_body_bin);
}
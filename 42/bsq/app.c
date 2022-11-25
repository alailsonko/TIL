/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalailson3 <aalailson3@fake.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 15:54:18 by aalailson3        #+#    #+#             */
/*   Updated: 2022/11/25 17:06:21 by aalailson3       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

struct s_map_dict
{
	int		line_size;
	int		width_size;
	char	char_obstacle;
	char	char_full;
	char	char_empty;
	char	*str_map;
};

int	ft_size_file(char *argv)
{
	int size;
	char buf;
	int fd;

	size = 0;
	fd = open(argv, O_RDONLY);
	while (read(fd, &buf, 1) && fd != -1)
		size++;
	close(fd);
	return (size);
}

char	*ft_strncpy(char *dest, char *src, int size)
{
	int	i;
	char *src_i;

	i = 0;
	src_i = src;
	while (i < size && src_i[i] != '\0')
	{
		dest[i] = src_i[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;
	char *src_i;

	i = 0;
	src_i = src;
	while (src_i[i] != '\0')
	{
		dest[i] = src_i[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*read_map(char *map_filename, char *str_line, int size)
{
	int	map;
	char	str[size];

	map = open(map_filename, O_RDONLY, 0);
	read(map, &str, size);
	close(map);
	return (ft_strncpy(str_line, str, size));
}

int	ft_str_len_index(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
		i++;
	return (i);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*get_header_map(char *str_map)
{
	char	*str_header;
	int		buf_header_size;

	buf_header_size = ft_str_len_index(str_map, '\n');
	str_header = malloc(sizeof(char) * (buf_header_size + 1));
	ft_strncpy(str_header, str_map, buf_header_size);
	return (str_header);
}

int	is_numeric(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int     absolute_value(int nbr)
{
    if (nbr < 0)
        return (-nbr);
    return (nbr);
}

int     get_len(int nbr)
{
    int len = 0;
    if (nbr <= 0)
        ++len;
    while (nbr != 0)
    {
        ++len;
        nbr = nbr / 10;
    }
    return (len);
}

char    *ft_itoa(int nbr)
{
    char *result;
    int len;

    len = get_len(nbr);
    result = malloc(sizeof(char) * (len + 1));
    result[len] = '\0';

    if (nbr < 0)
        result[0] = '-';
    else if (nbr == 0)
        result[0] = '0';

    while (nbr != 0)
    {
        --len;
        result[len] = absolute_value(nbr % 10) + '0';
        nbr = nbr / 10;
    }
    return (result);
}

int	ft_atoi(char *str_nbr)
{
	int	res;
	int	i;
	int	signal;

	i = 0;
	signal = 1;
	res = 0;
	if (str_nbr[i] == '-')
	{
		signal = signal * -1;
		i++;
	}
	if (str_nbr[i] == '+')
		i++;
	while (str_nbr[i] != '\0')
	{
		res = res * 10 + (str_nbr[i] - '0');
		i++;
	}
	return (res * signal);
}

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

int	get_map(char *filename, char *str_map, int buf_size)
{
	read_map(filename, str_map, buf_size);
	return (1);
}

char	*get_body_map(char *str_map)
{
	int	buf_header_size;

	buf_header_size = ft_str_len_index(str_map, '\n');
	return (&str_map[buf_header_size + 1]);
}

int	verify_body_map_char(char *str_body_map, struct s_map_dict *map_dict)
{
	int	i;

	i = 0;
	while (str_body_map[i] != '\0')
	{
		if (str_body_map[i] != (*map_dict).char_empty && str_body_map[i] != (*map_dict).char_full && str_body_map[i] != (*map_dict).char_obstacle && str_body_map[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int count_lines_map(char *str_body_map)
{
	int	i;
	int lines_counter;

	i = 0;
	lines_counter = 0;
	while (str_body_map[i])
	{
		if (str_body_map[i] == '\n')
			lines_counter++;
		i++;
	}
	return (lines_counter);
}

int	get_width_size(char *str_body_map)
{
	int	i;

	i = 0;
	while (str_body_map[i] != '\n')
		i++;
	return (i);
}

int verify_width_map(char *str_body_map, struct s_map_dict *map_dict)
{
	int		i, lines_counter, first_line_width_counter, curr_line_width_counter;
	char	*str_body;

	i = 0;
	lines_counter = 0;
	str_body = str_body_map;
	first_line_width_counter = get_width_size(str_body_map);
	(*map_dict).width_size = first_line_width_counter;
	curr_line_width_counter = 0;
	while (str_body[i])
	{
		if ((str_body[i] != '\n' && lines_counter > 0))
			curr_line_width_counter++;
		else if (str_body[i] == '\n')
		{
			if ((curr_line_width_counter != first_line_width_counter) && lines_counter > 0)
				return (0);
			lines_counter++;
			curr_line_width_counter = 0;
		}
		i++;
	}
	return (1);
}

int	verify_body_map_lines(char *str_body_map, struct s_map_dict *map_dict)
{
	if ((*map_dict).line_size != count_lines_map(str_body_map))
		return (0);
	return (1);
}

int	verify_body_map(char *str_body_map, struct s_map_dict *map_dict)
{
	if (!verify_body_map_char(str_body_map, map_dict))
		return (0);
	if (!verify_body_map_lines(str_body_map, map_dict))
		return (0);
	if (!verify_width_map(str_body_map, map_dict))
		return (0);
	return (1);
}

int	verify_map_2(char *str_map, struct s_map_dict *map_dict)
{
	char	*str_header;
	char	*str_body;

	str_header = get_header_map(str_map);
	str_body = get_body_map(str_map);
	if (!verify_header_map(str_header, map_dict))
	{
		free((*map_dict).str_map);
		free(str_header);
		return (0);
	}
	if (!verify_body_map(str_body, map_dict))
	{
		free((*map_dict).str_map);
		free(str_header);
		return (0);
	}
	free(str_header);
	return (1);
}

int	verify_map(char *argv, struct s_map_dict *map_dict)
{
	char	*str_map;
	int		buf_size;

	buf_size = ft_size_file(argv);
	if (!buf_size)
		return (0);
	str_map = malloc(sizeof(char) * (buf_size + 1));
	if (!get_map(argv, str_map, buf_size))
		return (0);
	(*map_dict).str_map = str_map;
	if (!verify_map_2(str_map, map_dict))
		return (0);
	return (1);
}

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

char	*get_map_by_line(char *str_map_body, int line_number)
{
	char	*str_map_by_line;
	int		i;
	int count_line;

	i = 0;
	count_line = 0;
	str_map_by_line = str_map_body;
	while (str_map_by_line[i] != '\0')
	{
		if (str_map_by_line[i] == '\n')
			count_line++;
		if (count_line == line_number)
			break ;
		i++;
	}
	if (count_line > 0)
		i++;
	return (&str_map_by_line[i]);
}

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

int min_of_3(int a, int b, int c)
{
    int m = a;
    if (m > b)
        m = b;
    if (m > c)
        m = c;
    return m;
}

int **set_biggest_square(int **M, struct s_map_dict *map_dict)
{
    int i, j;
    int **S;
    int max_of_s, max_i, max_j;

	S = M;
	i = 1;
	while (i < (*map_dict).line_size)
	{
		j = 1;
		while (j < (*map_dict).width_size)
		{
            if (M[i][j] == 1)
                S[i][j] = min_of_3(S[i][j - 1], S[i - 1][j], S[i - 1][j - 1]) + 1;
            else
                S[i][j] = 0;
			j++;
		}
		i++;
	}
    max_of_s = S[0][0];
    max_i = 0;
    max_j = 0;
	i = 1;
	while (i < (*map_dict).line_size)
	{
		j = 1;
		while (j < (*map_dict).width_size)
		{
            if (max_of_s < S[i][j]) {
                max_of_s = S[i][j];
                max_i = i;
                max_j = j;
            }
			j++;
		}
		i++;
	}
	i = max_i;
	while (i > max_i - max_of_s)
	{
		j = max_j;
		while (j > max_j - max_of_s)
		{
            M[i][j] = -1;
			j--;
		}
		i--;
	}
	return (S);
}

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

int	app(int argc, char *argv[])
{
	int	i;

	if (argc > 1)
	{
		i = 1;
		while (i < argc)
		{
			process_map(argv[i]);
			i++;
		}
	}
	return (0);
}

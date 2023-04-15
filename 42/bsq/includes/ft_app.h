
#ifndef FT_APP
#define FT_APP

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

char	*read_map(char *map_filename, char *str_line, int size);
int     absolute_value(int nbr);
int	app(int argc, char *argv[]);
int	ft_atoi(char *str_nbr);
char	*change_map_bin(struct s_map_dict *map_dict);
int	**change_map_to_original(int **map_body_matrix, struct s_map_dict *map_dict);
int count_lines_map(char *str_body_map);
char	*get_body_map(char *str_map);
char	*get_header_map(char *str_map);
int     get_len(int nbr);
int	get_map(char *filename, char *str_map, int buf_size);
char	*get_map_by_line(char *str_map_body, int line_number);
int	**get_matrix_map(struct s_map_dict *map_dict);
int	get_width_size(char *str_body_map);
int	is_numeric(char *str);
int	**iterate_matrix_inc(int **map_body_matrix, struct s_map_dict *map_dict);
char    *ft_itoa(int nbr);
int **parse_map_to_matrix(char *str_map_body, struct s_map_dict *map_dict);
int	process_map(char *filename);
char	*read_map(char *map_filename, char *str_line, int size);
int **set_biggest_square(int **M, struct s_map_dict *map_dict);
int	ft_size_file(char *filename);
int	solve_map(struct s_map_dict *map_dict);
char	*ft_strcpy(char *dest, char *src);
int	ft_strlen(char *str);
int	ft_str_len_index(char *str, char c);
char	*ft_strncpy(char *dest, char *src, int size);
int	verify_body_map(char *str_body_map, struct s_map_dict *map_dict);
int	verify_body_map_char(char *str_body_map, struct s_map_dict *map_dict);
int	verify_body_map_lines(char *str_body_map, struct s_map_dict *map_dict);
int	verify_header_map(char	*str_header, struct s_map_dict *map_dict);
int	verify_map(char *argv, struct s_map_dict *map_dict);
int	verify_map_2(char *str_map, struct s_map_dict *map_dict);
int verify_width_map(char *str_body_map, struct s_map_dict *map_dict);

#endif
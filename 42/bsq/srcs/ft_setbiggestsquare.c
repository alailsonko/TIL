#include "ft_app.h"

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
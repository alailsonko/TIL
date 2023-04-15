#include "ft_app.h"

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
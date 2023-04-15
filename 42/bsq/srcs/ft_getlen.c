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
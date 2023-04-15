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
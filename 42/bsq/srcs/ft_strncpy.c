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

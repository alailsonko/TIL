
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

char	*ft_strncat(char *dest, char *src, unsigned int n)
{
	unsigned	int	i;
	unsigned	int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j] && j < n)
		dest[i++] = src[j++];
	dest[i] = '\0';
	return (dest);
}
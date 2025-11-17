#include "../push_swap.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int	len1;
	int	len2;
	char	*res;
	int	i;
	int	j;

	i = 0;
	j = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	res = malloc(len1 + len2 + 2);
	len2 = ft_strlen(s2);
	if (!res)
		return (NULL);
	while (i < len1)
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = ' ';
	while (j < len2)
		res[i++] = s2[j++];
	res[i] = '\0';
	free(s1);
	return (res);
}

char **join_n_split(char *argv[])
{
	int		i;
	char	**final;
	char	*joined;

	i = 1;
	while (argv[i])
	{
		joined = ft_strjoin(argv[i - 1], argv[i]);
		i++;
	}
	final = split_num(joined, ' ');
	free(joined);
	return (final);
}

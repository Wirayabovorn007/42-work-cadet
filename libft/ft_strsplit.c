#include <stdlib.h>

int	countWords(char const *s, char delimiter)
{
	int	i;
	int	newW;

	newW = 0;
	i = 0;
	while (*s)
	{
		if (*s == delimiter)
			newW = 0;
		else
		{
			if (!newW)
			{
				newW = 1;
				i++;
			}
		}
		s++;
	}
	return (i);
}

char	*word_dup(char const *str, int len)
{
	int	i;
	char *dup = malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**arr;
	const char	*temp;
	int		words;
	int	i;
	int	len;

	if (!s)
		return (NULL);
	i = 0;
	words = countWords(s, c);
	arr = malloc(sizeof(char *) * (words + 1));
	if (!arr)
		return NULL;
	while (i < words)
	{
		while (*s == c)
			s++;
		len = 0;
		temp  = s;
		while (*s && !(*s == c))
		{
			s++;
			len++;
		}
		arr[i] = word_dup(temp, len);
		if (!arr[i])
		{
			while (i > 0)
				free(arr[--i]);
			free(arr);
			return (NULL);
		}
		i++;
	}
	arr[i] = NULL;
	return (arr);
}

// #include <stdio.h>
// int main(){
// 	char **arr = ft_strsplit("***d*3232*oioo_", '*');
// 	int i = -1;
// 	while (arr[++i]) printf("%s\n", arr[i]);
// }
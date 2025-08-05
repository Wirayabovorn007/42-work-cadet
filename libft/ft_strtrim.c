#include <stdlib.h>

int	ft_strlen(char const *c)
{
	int	i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}

int	is_whitespace(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

char	*ft_strtrim(char const *s)
{
	int	start;
	int	end;
	int	i;
	char	*trim;

	if (!s)
		return NULL;
	start = 0;
	while (is_whitespace(s[start]))
		start++;
	end = ft_strlen(s) - 1;
	while (end > start && is_whitespace(s[end]))
		end--;
	trim = (char *)malloc(end - start + 2);
	if (!trim)
		return NULL;
	i = 0;
	while (start <= end)
		trim[i++] = s[start++];
	trim[i] = '\0';
	return (trim);
}
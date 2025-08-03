#include <stdlib.h>

int	ft_strlen(char *c)
{
	int	i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result;
	unsigned int	i;

	if (!s || !f)
		return NULL;
	result = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!result)
		return NULL;
	i = 0;
	while (s[i])
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return result;
}
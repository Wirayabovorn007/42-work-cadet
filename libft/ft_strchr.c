#include <stddef.h>

char *ft_strchar(char *str, char searchC)
{
	while (*str)
	{
		if (*str == searchC)
			return (str);
		str++;
	}
	if (searchC == '\0')
		return str;
	return (NULL);
}
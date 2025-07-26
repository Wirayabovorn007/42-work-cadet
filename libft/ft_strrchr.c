#include <stddef.h>

char	*ft_strrchr(char *str, char searchC)
{
	char *last = NULL;

	while (*str)
	{
		if (*str == searchC)
			last = str;
		str++;
	}
	if (searchC == '\0')
		return NULL;
	return last;
}
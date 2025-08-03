#include <stdlib.h>

void *ft_memset(void *s, int c, size_t size)
{
	size_t	i;
	unsigned char	*ptr;

	i = 0;
	while (i < size)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return s;
}


char 	*ft_strnew(size_t size)
{
	char	*str;

	str = (char *)malloc(size + 1);
	if (!str)
		return NULL;
	ft_memset(str, '\0', size + 1);
	return str;
}

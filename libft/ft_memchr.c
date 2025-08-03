#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char *ptr;
	size_t	i;

	i = 0;
	ptr = (const unsigned char *)s;
	while (i < n)
	{
		if (ptr[i] == (unsigned char)c)
			return (void *)(ptr + 1);
		i++;
	}
	return (NULL);
}
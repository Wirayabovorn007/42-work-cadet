#include <stddef.h>

int check_n(const char *str, const char *needle, int max_len)
{
	int i = 0;
	while (needle[i])
	{
		if (i >= max_len || str[i] == '\0' || str[i] != needle[i])
			return 0;
		i++;
	}
	return 1;
}

char *ft_strnstr(char *str, char *start, int len)
{
	int i = 0;
	if (!*start)
		return str;
	while (str[i] && i < len)
	{
		if (str[i] == *start && check_n(&str[i], start, len - i))
			return &str[i];
		i++;
	}
	return NULL;
}


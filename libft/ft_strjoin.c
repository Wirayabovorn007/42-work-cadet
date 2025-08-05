#include <stdlib.h>

int	ft_strlen(char const *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	char	*ptr;

	if (!s1 || !s2)
		return NULL;
	res = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
		return NULL;
	ptr = res;
	while (*s1)
		*ptr++ = *s1++;
	while (*s2)
		*ptr++ = *s2++;
	*ptr = '\0';
	return (res);
}

// #include <stdio.h>

// int main(){
// 	char *joined = ft_strjoin("C", ".dev");
// 	if ( joined){
// 		printf("%s\n", joined);
// 		free(joined);
// 	}
// }
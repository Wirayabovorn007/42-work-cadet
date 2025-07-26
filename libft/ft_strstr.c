#include <stddef.h>

int check(char *str, char *start)
{
	int	i;

	i = 0;
	while (start[i])
	{
		if ((str[i] != start[i]) || str[i] == '\0')
			return (0);
		i++;
	}
	return (1);
}


char *ft_strstr(char *str, char *start)
{
	if (!*start)
		return str;
	while (*str)
	{
		if (*str == *start && check(str, start))
			return (str);
		str++;
	}
	return (NULL);
}

// #include <stdio.h>
// int main(){
// 	char myStr[] = "The rain in Spain falls mainly on the plains";
// char *myPtr = ft_strstr(myStr, "ain");
// if (myPtr != NULL) {
//   printf("%s", myPtr);
// }
// }
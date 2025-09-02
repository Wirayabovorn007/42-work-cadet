/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiraya <wiraya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 14:41:27 by wiraya            #+#    #+#             */
/*   Updated: 2025/08/10 14:42:20 by wiraya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	check(char *str, char *start)
{
	int	i;

	i = 0;
	while (start[i])
	{
		if ((str[i] != start[i]))
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strstr(char *str, char *start)
{
	if (!*start)
		return (str);
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiboonpr <wiboonpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 13:15:14 by wiboonpr          #+#    #+#             */
/*   Updated: 2025/09/05 22:33:35 by wiboonpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	len_s;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (start >= len_s)
		len = 0;
	if (len_s - start < len)
		len = len_s - start;
	substr = (char *)malloc(len + 1);
	if (!substr)
		return (NULL);
	i = -1;
	while (++i < len)
		substr[i] = s[start + i];
	substr[len] = '\0';
	return (substr);
}

// #include <stdio.h>
// int main()
// {
// 	char s[]= "Wiraya";
// 	printf("%s", strncpy(s,s + 2,1));
// 	char *s2 = ft_substr(s, 2, 1);
// 	if (s2){
// 		printf("%s\n", s2);
// 		free(s2);
// 	}
// 	return 0;
// }

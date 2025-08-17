/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiraya <wiraya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 15:04:19 by wiraya            #+#    #+#             */
/*   Updated: 2025/08/17 13:34:00 by wiraya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_strlen(char const *x)
{
	int	i;

	i = 0;
	while (x[i])
		i++;
	return (i);
}

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	i;
	unsigned int	len_s;

	len_s = ft_strlen(s);
	if (!s || start > len_s)
		return (NULL);
	if (start + len > len_s)
		return (NULL);
	substr = (char *)malloc(len + 1);
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[len] = '\0';
	return (substr);
}

// #include <stdio.h>
// int main()
// {
// 	char s[]= "Wiraya";
// 	char *s2 = ft_strsub(s, 2, 4);
// 	if (s2){
// 		printf("%s\n", s2);
// 		free(s2);
// 	}
// 	return 0;
// }

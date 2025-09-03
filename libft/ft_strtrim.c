/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiraya <wiraya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 15:05:48 by wiraya            #+#    #+#             */
/*   Updated: 2025/09/03 21:42:27 by wiraya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	const char	*r1;
	const char	*r2;
	size_t		i;
	char		*res;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	r1 = s1;
	r2 = ft_strchr(s1, '\0');
	while (r2 > r1 && ft_strchr(set, *(r2 - 1)))
		r2--;
	i = r2 - r1;
	if (i == 0)
		return (ft_strdup(""));
	res = malloc(sizeof(char) * (i + 1));
	if (!res)
		return (NULL);
	ft_strlcpy(res, r1, (i + 1));
	return (res);
}

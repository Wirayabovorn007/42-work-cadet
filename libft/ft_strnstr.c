/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiraya <wiraya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 14:42:38 by wiraya            #+#    #+#             */
/*   Updated: 2025/09/03 21:41:29 by wiraya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_n(const char *str, const char *needle, size_t max_len)
{
	size_t i = 0;

	while (needle[i])
	{
		if (i >= max_len || str[i] == '\0' || str[i] != needle[i])
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i = 0;

	if (!*needle)
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		if (haystack[i] == *needle && check_n(&haystack[i], needle, len - i))
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}

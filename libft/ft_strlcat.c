/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiraya <wiraya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 14:37:40 by wiraya            #+#    #+#             */
/*   Updated: 2025/08/10 14:38:14 by wiraya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_strlen(char *c)
{
	int	i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}

int	ft_strlcat(char *dst, char *src, int size)
{
	int	i;
	int	dst_len;
	int	src_len;

	i = 0;
	src_len = ft_strlen(src);
	while (dst_len < size && dst[dst_len])
		dst_len++;
	if (dst_len == size)
		return (size + src_len);
	while (src[i] && dst_len + 1 < size - 1)
	{
		dst[dst_len + 1] = src[i];
		i++;
	}
	dst[dst_len + 1] = '\0';
	return (dst_len + src_len);
}

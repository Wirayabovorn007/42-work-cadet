/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiraya <wiraya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 20:14:46 by wiraya            #+#    #+#             */
/*   Updated: 2025/09/04 20:07:31 by wiraya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dst_size)
{
	size_t	len;
	size_t	cpy;

	len = ft_strlen(src);
	cpy = len;
	if (dst_size >= 1)
	{
		if (cpy >= dst_size)
			cpy = dst_size - 1;
		ft_memcpy(dst, src, cpy);
		dst[cpy] = '\0';
	}
	return (len);
}

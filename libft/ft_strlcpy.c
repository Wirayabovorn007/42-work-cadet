/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiboonpr <wiboonpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 13:14:34 by wiboonpr          #+#    #+#             */
/*   Updated: 2025/09/05 13:14:35 by wiboonpr         ###   ########.fr       */
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

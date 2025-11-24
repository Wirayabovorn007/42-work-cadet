/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiboonpr <wiboonpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:11:14 by wiboonpr          #+#    #+#             */
/*   Updated: 2025/11/24 14:11:15 by wiboonpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*ptr;
	char	*dup;

	dup = (char *)malloc(ft_strlen(src) + 1);
	if (!dup)
		return (NULL);
	ptr = dup;
	while (*src)
	{
		*ptr = *src;
		ptr++;
		src++;
	}
	*ptr = '\0';
	return (dup);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		len1;
	int		len2;
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	res = malloc(len1 + len2 + 2);
	len2 = ft_strlen(s2);
	if (!res)
		return (NULL);
	while (i < len1)
	{
		res[i] = s1[i];
		i++;
	}
	res[i++] = ' ';
	while (j < len2)
		res[i++] = s2[j++];
	res[i] = '\0';
	return (res);
}

char	**join_n_split(char *argv[])
{
	int		i;
	char	**final;
	char	*joined;
	char	*temp_join;

	if (!argv[1])
		return (NULL);
	joined = ft_strdup(argv[1]);
	if (!joined)
		return (NULL);
	i = 1;
	while (argv[++i])
	{
		temp_join = ft_strjoin(joined, argv[i]);
		if (!temp_join)
		{
			free(joined);
			return (NULL);
		}
		free(joined);
		joined = temp_join;
	}
	final = split_num(joined, ' ');
	free(joined);
	return (final);
}

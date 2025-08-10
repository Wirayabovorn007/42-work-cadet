/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiraya <wiraya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 15:05:48 by wiraya            #+#    #+#             */
/*   Updated: 2025/08/10 15:06:37 by wiraya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_strlen(char const *c)
{
	int	i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}

static int	is_whitespace(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

char	*ft_strtrim(char const *s)
{
	int		start;
	int		end;
	int		i;
	char	*trim;

	if (!s)
		return (NULL);
	start = 0;
	while (is_whitespace(s[start]))
		start++;
	end = ft_strlen(s) - 1;
	while (end > start && is_whitespace(s[end]))
		end--;
	trim = (char *)malloc(end - start + 2);
	if (!trim)
		return (NULL);
	i = 0;
	while (start <= end)
		trim[i++] = s[start++];
	trim[i] = '\0';
	return (trim);
}

// #include <stdio.h>
// int main(){
// 	char str[] = "   Iwraya  ";
// 	printf("%s", ft_strtrim(str));
// }
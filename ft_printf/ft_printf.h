/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiboonpr <wiboonpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 12:58:28 by wiboonpr          #+#    #+#             */
/*   Updated: 2025/10/07 14:32:23 by wiboonpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h> 

int		ft_printf(const char *format, ...);
int		ft_putchar(char c);
int		handle_x(va_list args, const char x);
int		handle_p(va_list args);
int		handle_string(char *str);
int		handle_int(va_list args);
int		handle_unsinged_int(va_list args);
int		handle_i(va_list args);

#endif
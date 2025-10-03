#ifndef FTPRINTF_H
# define FTPRINTF_H
# include <stdarg.h>
# include <unistd.h> 


int		ft_strlen(char *c);
void	handle_x(va_list args, const char x);
void	handle_p(va_list args);
void	handle_char(va_list args);
void	handle_string(va_list args);
void	handle_int(va_list args);
void	handle_unsinged_int(va_list args);
void	handle_i(va_list args);

#endif
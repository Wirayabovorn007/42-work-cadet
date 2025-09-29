#ifndef FTPRINTF_H
# define FTPRINTF_H
# include <stdarg.h>
# include <unistd.h> 

void	handle_char(va_list args);
void	handle_string(va_list args);
void	handle_int(va_list args);
void	handle_unsinged_int(va_list args);

#endif
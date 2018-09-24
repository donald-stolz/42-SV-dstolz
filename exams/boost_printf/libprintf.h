#ifndef LIBPRINTF_H
# define LIBPRINTF_H

#include <stdarg.h>
#include <unistd.h>

typedef unsigned long t_ul;

int ft_printf(char *format, ...);
int ft_lookup(va_list arg, char c);
int ft_putchar(char c);
char ft_tochar(int num);
int ft_puts(char *s);
int ft_printitoa(t_ul value, int base);
int ft_putptr(t_ul value);

#endif

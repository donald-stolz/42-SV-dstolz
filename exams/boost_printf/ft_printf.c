#include "libprintf.h"

int ft_printf(char *format, ...)
{
	va_list	arg;

	unsigned int i;

	i = 0;

	va_start(arg, format);
	while(*format)
	{
		if(*format == '%')
			i += ft_lookup(arg, *++format);
		else
			i += ft_putchar(*format);
		format++;
	}
	va_end(arg);
	return(i);
}

int	ft_lookup(va_list arg, char c)
{
	int i;
	int n;

	i = 0;
	switch (c) {
		case 's': return (ft_puts(va_arg(arg, char *)));
		case 'c': return (ft_putchar(va_arg(arg, int)));
		case 'i':
		case 'd':
				  n = va_arg(arg, int);
				  i = n > 0 ? 0 : ft_putchar('-');
				  return (ft_printitoa((t_ul)(n > 0 ? n : -n), 10) + i);
		case 'p': return (ft_putptr((t_ul)va_arg(arg, void *)));
		case 'o': return (ft_printitoa((t_ul)va_arg(arg, unsigned int), 8));
		case 'u': return (ft_printitoa((t_ul)va_arg(arg, unsigned int), 10));
		case 'x': return (ft_printitoa((t_ul)va_arg(arg, unsigned int), 16));
		case '%': return (ft_putchar('%'));
	}
	return 0;
}

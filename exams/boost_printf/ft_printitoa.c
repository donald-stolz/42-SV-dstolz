#include "libprintf.h"

int	ft_printitoa(t_ul value, int base)
{
	int i;

	i = 0;
	if (value > 0)
	{
		i = ft_printitoa(value/base, base);
		i += ft_putchar(ft_tochar(value%base));
	}
	return (i);
}

int	ft_putptr(t_ul value)
{
	int i;

	i = ft_puts("0x");
	i += ft_printitoa(value, 16);
	return (i);
}

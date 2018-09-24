#include "libprintf.h"

int	ft_putchar(char c)
{
	return write(1, &c, 1);
}

char ft_tochar(int num)
{
	if(num >= 0 && num <= 9)
		return ((char)(num + '0'));
	else
		return ((char)(num - 10 + 'a'));
}

int ft_puts(char *s)
{
	int i;

	i = 0;
	while(*s)
		i += ft_putchar(*s++);
	return (i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_printf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstolz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 09:01:20 by dstolz            #+#    #+#             */
/*   Updated: 2018/09/30 09:01:22 by dstolz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/b_printf.h"

int	b_printf(const char *restrict format, ...)
{
	va_list	arg;
	int		i;

	i = 0;
	va_start(arg, format);
	while (*format)
	{
		if (*format == '%')
			i += ft_lookup(arg, *++format);
		else
			i += ft_putchar(*format);
		format++;
	}
	va_end(arg);
	return (i);
}

int	ft_lookup(va_list arg, char c)
{
	if (c == 's')
		return (ft_puts(va_arg(arg, char *)));
	else if (c == 'c')
		return (ft_putchar(va_arg(arg, int)));
	else if (c == 'i' || c == 'd')
		return (ft_puts(ft_itoa((long long)va_arg(arg, int), 10)));
	else if (c == 'p')
		return (ft_putptr(arg));
	else if (c == 'o')
		return (ft_puts(ft_itoa((long long)va_arg(arg, unsigned int), 8)));
	else if (c == 'u')
		return (ft_puts(ft_itoa((long long)va_arg(arg, unsigned int), 10)));
	else if (c == 'x')
		return (ft_puts(ft_itoa((long long)va_arg(arg, unsigned int), 16)));
	else if (c == '%')
		return (ft_putchar('%'));
	else
		return (0);
}

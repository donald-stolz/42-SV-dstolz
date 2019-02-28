/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_printf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstolz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 09:01:20 by dstolz            #+#    #+#             */
/*   Updated: 2019/01/20 11:56:12 by dstolz           ###   ########.fr       */
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
			i += b_lookup(arg, *++format);
		else
			i += b_putchar(*format);
		format++;
	}
	va_end(arg);
	return (i);
}

int	b_lookup(va_list arg, char c)
{
	char	*tmp;
	int		count;

	if (c == 's')
		return (b_puts(va_arg(arg, char *)));
	else if (c == 'c')
		return (b_putchar(va_arg(arg, int)));
	else if (c == '%')
		return (b_putchar('%'));
	else if (c == 'p')
		return (b_putptr(arg));
	else if (c == 'i' || c == 'd')
		tmp = b_itoa((long long)va_arg(arg, int), 10);
	else if (c == 'o')
		tmp = b_itoa((long long)va_arg(arg, unsigned int), 8);
	else if (c == 'u')
		tmp = b_itoa((long long)va_arg(arg, unsigned int), 10);
	else if (c == 'x')
		tmp = b_itoa((long long)va_arg(arg, unsigned int), 16);
	else
		return (0);
	count = b_puts(tmp);
	free(tmp);
	return (count);
}

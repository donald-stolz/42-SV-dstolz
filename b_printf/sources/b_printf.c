/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_printf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstolz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 15:42:45 by dstolz            #+#    #+#             */
/*   Updated: 2018/09/24 11:01:10 by dstolz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	b_printf(char *format, ...)
{
	char	*traverse;
	va_list	arg;
	int		i;

	i = 0;
	traverse = format;
	va_start(arg, format);
	while (*(traverse))
	{
		if (*traverse == '%')
		{
			traverse++;
			i += ft_searchflags(*traverse, arg);
		}
		else
			i += ft_putchar(*traverse);
		traverse++;
	}
	va_end(arg);
	return (i);
}

int	ft_searchflags(char option, va_list arg)
{
	int i;

	i = 0;
	while (i < 9)
	{
		if (g_flag_table[i].c == option)
			return (g_flag_table[i].func(arg));
		i++;
	}
	if (option == '%')
		return (ft_putchar('%'));
	return (0);
}

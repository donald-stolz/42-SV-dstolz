/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstolz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 09:57:06 by dstolz            #+#    #+#             */
/*   Updated: 2018/09/19 14:27:42 by dstolz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libprintf.h"
#include <stdio.h>

int	ft_puts(char *s)
{
	t_uint i;

	i = 0;
	while (*(s + i))
		i += ft_putchar(*(s + i));
	return (i);
}

int	ft_putstr(va_list arg)
{
	return (ft_puts(va_arg(arg, char *)));
}

int	ft_putarg(va_list arg)
{
	return (ft_putchar(va_arg(arg, int)));
}

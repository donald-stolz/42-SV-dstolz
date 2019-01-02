/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstolz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 09:57:06 by dstolz            #+#    #+#             */
/*   Updated: 2018/09/25 18:45:15 by dstolz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/b_printf.h"

int	b_puts(char *s)
{
	int i;

	i = 0;
	if (s == NULL)
		return (b_puts("(null)"));
	while (*(s + i))
		i++;
	write(1, s, i);
	return (i);
}

int	b_putarg(va_list arg)
{
	return (b_putchar(va_arg(arg, int)));
}

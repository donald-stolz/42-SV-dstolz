/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_puts.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstolz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 11:57:14 by dstolz            #+#    #+#             */
/*   Updated: 2019/01/20 11:57:19 by dstolz           ###   ########.fr       */
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printltoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstolz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 09:31:42 by dstolz            #+#    #+#             */
/*   Updated: 2018/09/19 14:27:51 by dstolz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	ft_printltoa(t_long value, int base)
{
	int i;

	i = 0;
	if (value > 0)
	{
		i = ft_printltoa((value / base), base);
		i += ft_putchar(ft_tochar(value % base));
	}
	return (i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printuitoa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstolz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 18:52:17 by dstolz            #+#    #+#             */
/*   Updated: 2018/09/18 13:10:12 by dstolz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libprintf.h"

int	ft_printuitoa(t_uint value, int base)
{
	int i;

	i = 0;
	if (value > 0)
	{
		i = ft_printuitoa((value / base), base);
		i += ft_putchar(ft_tochar(value % base));
	}
	return (i);
}

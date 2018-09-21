/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printitoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstolz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 10:49:25 by dstolz            #+#    #+#             */
/*   Updated: 2018/09/18 12:58:53 by dstolz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libprintf.h"

int	ft_printitoa(int value, int base)
{
	int i;

	i = 0;
	if (value < 0)
	{
		i++;
		ft_putchar('-');
	}
	return (i + ft_printuitoa(ABS(value), base));
}

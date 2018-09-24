/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numdigits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstolz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 14:25:18 by dstolz            #+#    #+#             */
/*   Updated: 2018/09/24 13:31:51 by dstolz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	ft_numdigits(int value, int base)
{
	int digits;

	digits = 0;
	if (value <= 0)
	{
		value = -value;
		digits++;
	}
	while (value)
	{
		value /= base;
		digits++;
	}
	return (digits);
}

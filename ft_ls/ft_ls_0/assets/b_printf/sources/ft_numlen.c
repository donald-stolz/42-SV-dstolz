/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstolz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 09:53:44 by dstolz            #+#    #+#             */
/*   Updated: 2018/09/30 09:53:46 by dstolz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/b_printf.h"

int	ft_numlen(long long n, int base)
{
	int	digits;

	digits = 0;
	if (n <= 0)
	{
		n = -n;
		digits++;
	}
	while (n)
	{
		n /= base;
		digits++;
	}
	return (digits);
}

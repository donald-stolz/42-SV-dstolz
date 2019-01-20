/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_numlen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstolz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 11:56:02 by dstolz            #+#    #+#             */
/*   Updated: 2019/01/20 11:56:05 by dstolz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/b_printf.h"

int	b_numlen(long long n, int base)
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

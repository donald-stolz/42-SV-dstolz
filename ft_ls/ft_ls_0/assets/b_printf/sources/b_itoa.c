/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_itoa.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstolz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 11:55:39 by dstolz            #+#    #+#             */
/*   Updated: 2019/01/20 11:55:46 by dstolz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/b_printf.h"

char	*b_itoa(long long value, int base)
{
	char	*str;
	int		sign;
	int		i;

	i = 0;
	sign = value < 0 ? -1 : 0;
	str = (char *)malloc((sizeof(*str) * b_numlen(value, base)) + 1);
	value = value < 0 ? -value : value;
	if (str == NULL)
		return (NULL);
	if (value == 0)
	{
		*(str + i++) = '0';
		*(str + i) = '\0';
	}
	while (value != 0)
	{
		*(str + i++) = b_tochar(value % base);
		value = value / base;
	}
	if (sign)
		*(str + i++) = '-';
	*(str + i) = '\0';
	b_strrev(str);
	return (str);
}

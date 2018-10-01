/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstolz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 09:46:00 by dstolz            #+#    #+#             */
/*   Updated: 2018/09/30 09:46:03 by dstolz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_itoa(int n)
{
	int			i;
	int			sign;
	char		*str;
	long long	value;

	i = 0;
	sign = n < 0 ? -1 : 0;
	str = (char *)malloc(sizeof(char) * ft_numlen(n, 10) + 1);
	value = ABS(n);
	if (str == NULL)
		return (NULL);
	if (value == 0)
	{
		*(str + i++) = '0';
		*(str + i) = '\0';
	}
	while (value != 0)
	{
		*(str + i++) = value % 10 + '0';
		value = value / 10;
	}
	if (sign)
		*(str + i++) = '-';
	*(str + i) = '\0';
	ft_strrev(str);
	return (str);
}

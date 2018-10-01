/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstolz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 12:01:18 by dstolz            #+#    #+#             */
/*   Updated: 2018/09/30 12:01:40 by dstolz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

char    *ft_itoa(long long value, int base)
{
    char    *str;
    int     sign;
    int     i;

    i = 0;
    sign = 0;
    str = (char *)malloc( (sizeof(*str) * ft_numlen(value, base)) + 1);
    if (str == NULL)
        return (NULL);
    if (value == 0)
    {
        *(str + i++) = '0';
        *(str + i) = '\0';
    }
    if (value < 0)
    {
        sign = -1;
        value = -value;   
    }
    while (value != 0)
    {
        *(str + i++) = ft_tochar(value % base);
        value = value/base;
    }
    if (sign)
        *(str + i++) = '-';
    *(str + i) = '\0';
    ft_strrev(str);
    return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstolz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 11:21:55 by dstolz            #+#    #+#             */
/*   Updated: 2018/09/19 14:27:00 by dstolz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	ft_putptr(va_list arg)
{
	int i;

	i = ft_puts("0x");
	i += ft_puts(ft_itoa((long long)va_arg(arg, void *), 16));
	return (i);
}

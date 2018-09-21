/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstolz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 15:18:05 by dstolz            #+#    #+#             */
/*   Updated: 2018/09/19 14:23:32 by dstolz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libprintf.h"

int	ft_putnbr(va_list arg)
{
	return (ft_printitoa(va_arg(arg, int), 10));
}

int	ft_putoct(va_list arg)
{
	return (ft_printuitoa(va_arg(arg, unsigned int), 8));
}

int	ft_putunbr(va_list arg)
{
	return (ft_printuitoa(va_arg(arg, unsigned int), 10));
}

int	ft_puthex(va_list arg)
{
	return (ft_printuitoa(va_arg(arg, unsigned int), 16));
}

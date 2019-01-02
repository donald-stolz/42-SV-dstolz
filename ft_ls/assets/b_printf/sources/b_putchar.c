/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstolz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 08:33:02 by dstolz            #+#    #+#             */
/*   Updated: 2018/09/24 13:22:24 by dstolz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/b_printf.h"

int		b_putchar(char c)
{
	return ((int)write(1, &c, 1));
}

char	b_tochar(int num)
{
	if (num >= 0 && num <= 9)
		return ((char)(num + '0'));
	else
		return ((char)(num - 10 + 'a'));
}

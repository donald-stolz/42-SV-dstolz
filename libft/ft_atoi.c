/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstolz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 14:00:48 by dstolz            #+#    #+#             */
/*   Updated: 2018/09/27 17:08:08 by dstolz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	size_t	i;
	int		num;
	int		sign;

	i = 0;
	num = 0;
	sign = 1;
	if (*(str + i) == '\e' || *(str + i) == '\0')
		return (0);
	while (*(str + i) == '\n' || *(str + i) == '\t' || *(str + i) == '\r' ||
			*(str + i) == '\v' || *(str + i) == '\f' || *(str + i) == ' ')
		i++;
	if (*(str + i) == '-')
		sign = -1;
	if (*(str + i) == '-' || *(str + i) == '+')
		i++;
	while (*(str + i) && ft_isdigit(*(str + i)))
		num = (num * 10) + (*(str + i++) - '0');
	while (ft_isdigit(*(str + i)))
		i--;
	return (num * sign);
}

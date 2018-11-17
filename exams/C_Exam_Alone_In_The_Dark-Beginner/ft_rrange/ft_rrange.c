/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 11:57:55 by exam              #+#    #+#             */
/*   Updated: 2018/09/21 12:32:08 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int ft_diff(int a, int b);
int *ft_rrange(int start, int end);

int ft_diff(int a, int b)
{
	a = a - b;
	return ( a > 0 ? a : -a);
}

int *ft_rrange(int start, int end)
{
	int *ptr;
	int temp;
	int i;

	ptr = (int *)malloc(sizeof(int) * ft_diff(start, end));
	if (ft_diff(start, end) == 0)
	{
		*(ptr) = end;
		return ptr;
	}
	i = 0;
	temp = end;
	if (end > start)
		while (temp != (start - 1))
			*(ptr + i++) = temp--;
	else
		while (temp != (start + 1))
			*(ptr + i++) = temp++;
	return (ptr);
}

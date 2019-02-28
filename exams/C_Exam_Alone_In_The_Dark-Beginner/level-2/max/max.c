/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 09:25:28 by exam              #+#    #+#             */
/*   Updated: 2018/09/21 09:54:53 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	max(int* tab, unsigned int len);

int	max(int* tab, unsigned int len)
{
	int big;
	unsigned int i;

	i = 0;
	if ((void *)tab == NULL || len == 0)
		return 0;
	big = *(tab + i);
	while (i < len)
	{
		if (*(tab + i) > big)
			big = *(tab + i);
		i++;
	}
	return (big);
}

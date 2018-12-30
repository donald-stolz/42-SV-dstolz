/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstolz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 13:24:15 by dstolz            #+#    #+#             */
/*   Updated: 2018/11/14 13:24:17 by dstolz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fillit.h"

// Requires adding 'pos' & 'placed' to struct
// ToDo: Use goto
int solve_map(t_et *p, int size, uint16_t *map)
{
	int i;

	i = 0;
SOLVE:
	while (i > -1)
	{
		if ((p + i)->id == '0')
			return (1);
		// if ((p + i)->placed)
		// {

		// }
		// else
		// {
		(p + i)->pos = ((p + i)->last ? ((p + i)->last->x + (p + i)->last->y * size) : 0);
		// }
		(p + i)->y = (p + i)->pos / size;
		while ((p + i)->y <= size - (p + i)->height)
		{
			(p + i)->x = ((p + i)->y == (p + i)->pos / size ? (p + i)->pos % size : 0);
			while ((p + i)->x <= size - (p + i)->width)
			{
				if (CHECK((map + (p + i)->y), ((p + i)->value >> (p + i)->x)))
				{
					TOGGLE((map + (p + i)->y), ((p + i)->value >> (p + i)->x));
					(p + i)->placed = 1;
					goto SOLVE;
				}
				(p + i)->x++;
			}
			(p + i)->y++;
		}
		(p + i)->x = 0;
		(p + i)->y = 0;
		i--;
		TOGGLE((map + (p + i)->y), ((p + i)->value >> (p + i)->x));
		(p + i)->placed = 0;
		(p + i)->pos = ((p + i)->x + (p + i)->y * size) + 1;
	}
	return (0);
}

int solve(uint16_t *map, t_et *pieces, const int count)
{
	int size;

	size = 2;
	while (size * size < count * 4)
		++size;
	while (!(solve_map(pieces, size, map) && size <= 16))
	{
		ft_bzero(map, sizeof(uint16_t) * 16);
		++size;
	}
	return (size == 17 ? 0 : size);
}

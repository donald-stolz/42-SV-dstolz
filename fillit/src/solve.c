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

int solve_map(t_et *piece, int size, uint16_t *map)
{
	int pos;

	if (piece->id == 0)
		return (1);
	pos = (piece->last ? (piece->last->x + piece->last->y * size) : 0);
	piece->y = pos / size;
	while (piece->y <= size - piece->height)
	{
		piece->x = (piece->y == pos / size ? pos % size : 0);
		while (piece->x <= size - piece->width)
		{
			if (CHECK((map + piece->y), (piece->value >> piece->x)))
			{
				TOGGLE((map + piece->y), (piece->value >> piece->x));
				if (solve_map(piece + 1, size, map))
					return (1);
				TOGGLE((map + piece->y), (piece->value >> piece->x));
			}
			piece->x++;
		}
		piece->y++;
	}
	piece->x = 0;
	piece->y = 0;
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

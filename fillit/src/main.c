/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstolz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 11:18:03 by dstolz            #+#    #+#             */
/*   Updated: 2018/11/04 11:18:05 by dstolz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "..inc/libft.h"

char		*create_empty_map(int size)
{
	char	*str;
	int		x;
	int		y;

	str = ft_strnew((size + 1) * size);
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			str[y * (size + 1) + x] = '.';
			x++;
		}
		str[y * (size + 1) + x] = '\n';
		y++;
	}
	return (str);
}

void		solution_print(t_et *p, int count, int size)
{
	char	*str;
	int		x;
	int		y;

	str = create_empty_map(size);
	while (count > 0)
	{
		y = 0;
		while (y < p->height)
		{
			x = 0;
			while (x < p->width)
			{
				if ((p->value >> (16 * (y + 1) - 1 - x)) & 1)
					str[(p->y + y) * (size + 1) + x + p->x] = p->id;
				x++;
			}
			y++;
		}
		t++;
		count--;
	}
	ft_putstr(str);
	ft_strdel(&str);
}

int main(int argc, char **argv)
{
	t_et		pieces[MAX_TETRI + 1];
	uint16_t	map[16];
	int			count;
	// int			size;

	if (argc != 2)
		FAIL("usage: ./fillit [file_path]");
	if ((count = read_file(open(argv[1], O_RDONLY), pieces)))
		FAIL("Invalid board");
	solve(map, pieces, count);
	/**
	 * 0. Check args for errors
	 * 1. Read map into list
	 * 2. Solve map
	 * 3. Print map
	 * 4. Free map & list
	 * int		main(int argc, char **argv)

	if (argc != 2)
		return (end("usage: ./fillit [valid input file]"));
	ft_bzero(tetri, sizeof(t_et) * (MAX_PIECES + 1));
	if ((count = read_file(open(argv[1], O_RDONLY), tetri)) == 0)
		return (end("error"));
	ft_bzero(map, sizeof(unint16_t) * 16);
	if ((size = solve(tetri, count, map)) == 0)
		return (end("error"));
	solution_print(tetri, count, size);
	return (0);
}
	 **/
}

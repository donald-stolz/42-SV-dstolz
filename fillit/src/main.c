/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstolz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 11:18:03 by dstolz            #+#    #+#             */
/*   Updated: 2018/11/28 19:59:21 by dstolz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
		p++;
		count--;
	}
	ft_putstr(str);
	ft_strdel(&str);
}

inline int	fail(void)
{
	ft_putendl("error");
	return (1);
}

int			main(int argc, char **argv)
{
	t_et		pieces[MAX_PIECES + 1];
	uint16_t	map[16];
	int			count;
	int			size;

	if (argc != 2)
		return (fail());
	ft_bzero(pieces, sizeof(t_et) * (MAX_PIECES + 1));
	if (!(count = read_file(open(argv[1], O_RDONLY), pieces)))
		return (fail());
	ft_bzero(map, sizeof(uint16_t) * 16);
	if (!(size = solve(map, pieces, count)))
		return (fail());
	solution_print(pieces, count, size);
	return (0);
}

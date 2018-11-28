/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstolz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 12:26:22 by dstolz            #+#    #+#             */
/*   Updated: 2018/11/13 12:26:25 by dstolz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	min_max_calc(const char *buf, char *m)
{
	int		i;

	i = 0;
	m[0] = 3;
	m[1] = 0;
	m[2] = 3;
	m[3] = 0;
	while (i < 20)
	{
		if (buf[i] == '#')
		{
			if (i % 5 < m[0])
				m[0] = i % 5;
			if (i % 5 > m[1])
				m[1] = i % 5;
			if (i / 5 < m[2])
				m[2] = i / 5;
			if (i / 5 > m[3])
				m[3] = i / 5;
		}
		i++;
	}
}

t_et	set_piece(const char *buf, const char curr_id)
{
	t_et	tetromino;
	char	m[4];
	int		x;
	int		y;

	min_max_calc(buf, m);
	tetromino.width = m[1] - m[0] + 1;
	tetromino.height = m[3] - m[2] + 1;
	tetromino.id = curr_id;
	tetromino.value = 0;
	tetromino.last = NULL;
	y = 0;
	while (y < tetromino.height)
	{
		x = 0;
		while (x < tetromino.width)
		{
			if (buf[(m[0] + x) + (m[2] + y) * 5] == '#')
				tetromino.value |= (1L << (16 * (y + 1) - 1 - x));
			++x;
		}
		y++;
	}
	return (tetromino);
}

int		check_surround(char *buf)
{
	int	connects;
	int i;

	i = 0;
	connects = 0;
	while (i < 20)
	{
		if (buf[i] == '#')
		{
			if ((i + 1) < 20 && buf[i + 1] == '#')
				++connects;
			if ((i - 1) >= 0 && buf[i - 1] == '#')
				++connects;
			if ((i + 5) < 20 && buf[i + 5] == '#')
				++connects;
			if ((i - 5) >= 0 && buf[i - 5] == '#')
				++connects;
		}
		++i;
	}
	return (connects == 6 || connects == 8);
}

int		check_chars(char *buf, int count)
{
	int i;
	int hash;

	i = 0;
	hash = 0;
	while (i < 20)
	{
		if (i % 5 < 4)
		{
			if (buf[i] != '.' && buf[i] != '#')
				return (0);
			if (buf[i] == '#' && ++hash > 4)
				return (0);
		}
		else if (buf[i] != '\n')
			return (0);
		i++;
	}
	if (count == 21 && buf[20] != '\n')
		return (0);
	if (!check_surround(buf))
		return (0);
	return (1);
}

int		read_file(const int fd, t_et *pieces)
{
	char	buf[22];
	int		count;
	char	curr_id;
	int		i;
	int		c;

	i = 0;
	curr_id = 'A';
	while ((count = read(fd, buf, 21)) >= 20)
	{
		if (!check_chars(buf, count))
			return (0);
		pieces[i] = set_piece(buf, curr_id++);
		c = i - 1;
		while (c >= 0)
		{
			if (pieces[c].value == pieces[i].value)
				pieces[i].last = pieces + c;
			c--;
		}
		i++;
		if (count == 20)
			buf[20] = '\0';
	}
	return ((count != 0 || buf[20] != '\0') ? 0 : (curr_id - 'A'));
}

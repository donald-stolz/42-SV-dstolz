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

#include "../inc/fillit.h"

int	check_surround(char *buf)
{
	int	connects;
	int i;

	i = 0;
	connects = 0;
	while (i < 20)
	{
		if (buf[i] == '#')
		{
			((i + 1) < 20 && buf[i + 1] == '#') ? ++connects : NULL;
			((i - 1) >= 0 && buf[i - 1] == '#') ? ++connects : NULL;
			((i + 5) < 20 && buf[i + 5] == '#') ? ++connects : NULL;
			((i - 5) >= 0 && buf[i - 5] == '#') ? ++connects : NULL;			
		}
		++i;
	}
	return (connects == 6 || connects == 8);
}

int	check_chars(char *buf, int count)
{
	int i;
	int hash;

	i = 0;
	hash = 0;
	while (i < 20)
	{
		if (i % 5 < 4)
		{
			if (buf[i] != '.' || buf[i] != '#')
				return (0);
			if (buf[i] == '#' && ++hash > 4)
				return (0);
		}
		else if (buf[i] != '\n')
			return (0);
		i++;
	}
	if (buf[i] != '\n')
		return (0);
	if (!check_surround(buf))
		return (0);
	return (1);
}

int	read_file(const int fd, t_tetromino *peice)
{
	char	buf[22];
	int		count;
	char	curr_id;
	int	    i;
	int		c;

	i = 0;
	curr_id = 'A';
	while ((count = read(fd, buf, 21)) >= 21)
	{
		check_chars(buf, count);
		peice[i] = set_peice(buf, curr_id++);
		c = i - 1;
		while (c >= 0)
		{
			if (peice[c].value == peice[i].value)
				peice[i].last = peice + c;
			c--;
		}
		i++;
	}
	return ((count != 0) ? 0 : (curr_id - 'A'));
}


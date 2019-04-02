/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utility.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstolz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 13:29:40 by dstolz            #+#    #+#             */
/*   Updated: 2019/03/29 13:29:44 by dstolz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

static char	*ft_parse_old(char *dir_time)
{
	char	*res;
	int		i;

	i = -1;
	res = (char *)malloc(11);
	while (i++ < 6)
		*(res + i) = *(dir_time + (4 + i));
	while (i < 11)
	{
		*(res + i) = *(dir_time + (13 + i));
		i++;
	}
	*(res + i) = '\0';
	return (res);
}

static char	*ft_parse_recent(char *dir_time)
{
	char	*res;
	int		i;

	i = -1;
	res = (char *)malloc(12);
	while (i++ < 11)
		*(res + i) = *(dir_time + (4 + i));
	*(res + i) = '\0';
	return (res);
}

char		*ft_parse_time(struct timespec m_time)
{
	static time_t	now;
	char			*dir_time;

	now = time(NULL);
	dir_time = ctime(&m_time.tv_sec);
	if (m_time.tv_sec + SIXMONTHS > now && m_time.tv_sec < now + SIXMONTHS)
		return (ft_parse_recent(dir_time));
	else
		return (ft_parse_old(dir_time));
}

void		ft_print_dir(t_dir *dir, t_bool l_op)
{
	if (l_op)
		ft_print_l(dir);
	else
		b_printf("%s", dir->path);
	if (dir->next)
		write(1, "\n\n", 2);
}

void		ft_print_header(t_dir *dir, t_bool root)
{
	if (root)
		b_printf("%s:\n", dir->name);
	else
		b_printf("%s:\n", dir->path);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_displaydir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstolz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 09:47:58 by dstolz            #+#    #+#             */
/*   Updated: 2018/10/04 09:48:02 by dstolz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/b_ls.h"

char	*ft_parsetime(char *m_time)
{
	char	*new;
	int		i;

	i = 0;
	new = (char *)malloc(13);
	while (i < 12)
	{
		*(new + i) = *(m_time + (4 + i));
		i++;
	}
	*(new + i) = '\0';
	return (new);
}

void	ft_displayl(t_dir *dir)
{
	char *m_time;

	while (dir)
	{
		m_time = ft_parsetime(ctime(&dir->mtime));
		printf("%s %3d %s %s %5lld %s %s\n", dir->permissions, dir->links,
				dir->owner, dir->group, dir->size, m_time, dir->name);
		free(m_time);
		dir = dir->next;
	}
}

void	ft_displaydir(t_dirlist *dir, t_opt *options)
{
	t_dir	*nav;

	nav = dir->head;
	if (options->l_op)
	{
		printf("total %zu\n", dir->total);
		return (ft_displayl(nav));
	}
	while (nav)
	{
		printf("%-15s", nav->name);
		nav = nav->next;
	}
	free(nav);
}

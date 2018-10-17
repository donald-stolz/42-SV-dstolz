/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortdir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstolz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 09:32:02 by dstolz            #+#    #+#             */
/*   Updated: 2018/10/04 09:32:04 by dstolz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/b_ls.h"

void	ft_swapdata(t_dir *dir1, t_dir *dir2)
{
	t_dir tmp;

	tmp = *dir1;
	dir1->permissions = dir2->permissions;
	dir1->links = dir2->links;
	dir1->owner = dir2->owner;
	dir1->group = dir2->group;
	dir1->size = dir2->size;
	dir1->mtime = dir2->mtime;
	dir1->name = dir2->name;
	dir2->permissions = tmp.permissions;
	dir2->links = tmp.links;
	dir2->owner = tmp.owner;
	dir2->group = tmp.group;
	dir2->size = tmp.size;
	dir2->mtime = tmp.mtime;
	dir2->name = tmp.name;
}

t_dir	*ft_revlist(t_dir *dir)
{
	t_dir	*current;
	t_dir	*prev;
	t_dir	*next;

	current = dir;
	prev = NULL;
	next = NULL;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	dir = prev;
	return (dir);
}

void	ft_sortmtime(t_dir *dir)
{
	t_dir *nav;
	t_dir *sort;

	sort = dir;
	while (sort != NULL)
	{
		nav = sort;
		while (nav != NULL)
		{
			if (nav->mtime > sort->mtime)
				ft_swapdata(sort, nav);
			nav = nav->next;
		}
		sort = sort->next;
	}
}

void	ft_sortlex(t_dir *dir)
{
	t_dir *nav;
	t_dir *sort;

	sort = dir;
	while (sort)
	{
		nav = sort;
		while (nav)
		{
			if (ft_strcmp(nav->name, sort->name) < 0)
				ft_swapdata(sort, nav);
			nav = nav->next;
		}
		sort = sort->next;
	}
}

t_dir	*ft_sortdir(t_dir *dir, t_opt *options)
{
	if (options->t_op)
		ft_sortmtime(dir);
	else
		ft_sortlex(dir);
	if (options->r_op)
		dir = ft_revlist(dir);
	return (dir);
}

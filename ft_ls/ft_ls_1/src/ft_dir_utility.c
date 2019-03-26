/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dir_utility.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstolz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 09:27:47 by dstolz            #+#    #+#             */
/*   Updated: 2019/03/22 09:27:51 by dstolz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

t_dir	*ft_add_dir(char *name, t_dir *curr, char *path, t_opt *opts)
{
	t_dir	*tail;

	tail = ft_get_tail(curr);
	tail->next = ft_new_dir(name, path, opts);
	tail->next->previous = tail;
	return (tail);
}

t_dir	*ft_new_dir(char *name, char *path, t_opt *opts)
{
	t_dir	*dir;

	dir = malloc(sizeof(t_dir));
	dir->name = name;
	dir->path = path;
	dir->previous = NULL;
	dir->next = NULL;
	dir->children = NULL;
	ft_get_dir_info(dir, opts);
	return (dir);
}

t_dir	*ft_get_head(t_dir *curr)
{
	while (curr && curr->previous)
		curr = curr->previous;
	return (curr);
}

t_dir	*ft_get_tail(t_dir *curr)
{
	while (curr && curr->next)
		curr = curr->next;
	return (curr);
}

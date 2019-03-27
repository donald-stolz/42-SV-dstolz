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

t_dir	*ft_new_dir(char *name, char *path, t_opt *opts)
{
	t_dir	*dir;

	dir = malloc(sizeof(t_dir));
	dir->name = name;
	dir->path = path;
	dir->next = NULL;
	dir->children = NULL;
	ft_get_dir_info(dir, opts);
	return (dir);
}

t_dir	*ft_get_tail(t_dir *curr)
{
	while (curr && curr->next)
		curr = curr->next;
	return (curr);
}

void ft_push(t_dir **curr, t_dir *new)
{
	new->next = *curr;
	*curr = new;
}

void ft_rev_list(t_dir **dir)
{
	t_dir *current;
	t_dir *prev;
	t_dir *next;

	current = *dir;
	prev = NULL;
	next = NULL;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*dir = prev;
}
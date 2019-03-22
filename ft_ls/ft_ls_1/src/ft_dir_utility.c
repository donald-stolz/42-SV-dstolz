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

t_dir *ft_get_dir_info(t_dir *dir, t_opt *opts)
{
	// TODO:
}

t_dir *ft_new_dir(char *name, t_opt *opts)
{
	t_dir *dir;

	dir = malloc(sizeof(t_dir));
	//	TODO: Check if name needs to be malloced
	dir->name = name;
	dir->previous = NULL;
	dir->next = NULL;
	dir->children = NULL;
	ft_get_dir_info(dir, opts);
	return (dir);
}

t_dir *ft_add_dir(t_dir curr, char *name, t_opt *opts)
{
	t_dir tail;

	tail = ft_get_tail(curr);
	tail->next = ft_new_dir(name, opts);
	tail->next->previous = tail;
	return (tail);
}

t_dir *ft_get_head(t_dir *curr)
{
	while (curr && curr->previous)
		curr = curr->next;
	return (curr);
}

t_dir *ft_get_tail(t_dir *curr)
{
	while (curr && curr->next)
		curr = curr->next;
	return (curr);
}

// void ft_make_head(t_dir *curr)
// {
// 	t_dir *temp;

// 	temp = curr;
// 	curr->previous->next = curr->next;
// 	curr->next->previous = curr->previous;
// 	while (curr && curr->previous)
// 		curr = curr->next;
// 	temp->previous = NULL;
// 	curr->previous = temp;
// 	temp->next = curr;
// }

// void ft_make_tail(t_dir *curr)
// {
// 	t_dir *temp;
// 	temp = curr;
// 	curr->previous->next = curr->next;
// 	curr->next->previous = curr->previous;
// 	while (curr && curr->next)
// 		curr = curr->next;
// 	temp->next = NULL;
// 	curr->next = temp;
// 	temp->previous = curr;
// }
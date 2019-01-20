/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freestructs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstolz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 20:57:08 by dstolz            #+#    #+#             */
/*   Updated: 2018/10/10 20:57:10 by dstolz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void		ft_freelist(t_dir *dir)
{
	t_dir *curr;

	curr = dir;
	while (curr)
	{
		curr = dir->next;
		free(dir->permissions);
		free(dir->name);
		free(dir);
		dir = NULL;
		dir = curr;
	}
}

t_dirlist	*ft_nextfree(t_dirlist *directory)
{
	t_dirlist	*next;

	next = directory->next;
	ft_freelist(directory->head);
	free(directory->name);
	free(directory);
	directory = NULL;
	return (next);
}

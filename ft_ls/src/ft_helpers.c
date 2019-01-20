/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstolz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 12:38:11 by dstolz            #+#    #+#             */
/*   Updated: 2019/01/20 12:38:34 by dstolz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

t_dirlist	*ft_revnames(t_dirlist *names)
{
	t_dirlist *current;
	t_dirlist *prev;
	t_dirlist *next;

	current = names;
	prev = NULL;
	next = NULL;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	names = prev;
	return (names);
}

int			ft_isdir(const char *path)
{
	struct stat statbuf;

	if (lstat(path, &statbuf) != 0)
		return (0);
	return (S_ISDIR(statbuf.st_mode) && !S_ISLNK(statbuf.st_mode));
}

t_dirlist	*ft_lsttail(t_dirlist *head)
{
	while (head->next)
		head = head->next;
	return (head);
}

t_dirlist	*ft_newdir(char *name)
{
	t_dirlist *new;

	new = malloc(sizeof(struct s_dirlist));
	new->name = name;
	new->head = NULL;
	new->total = 0;
	new->next = NULL;
	return (new);
}

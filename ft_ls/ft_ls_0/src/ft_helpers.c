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

t_args	*ft_revargs(t_args *names)
{
	t_args *current;
	t_args *prev;
	t_args *next;

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

char *ft_checkname(char *str)
{
	int i;
	char c;

	i = ft_strlen(str);
	c = *(str + (i - 1));
	str = c == '/' ? ft_strdup(str) : ft_strjoin(str, "/");
	return (str);
}

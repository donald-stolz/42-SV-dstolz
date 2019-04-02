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

char	*ft_parse_path(char *name, char *path)
{
	char	*tmp;
	char	*result;
	int		len;

	if (name[0] == '/')
		return (ft_strdup(name));
	len = ft_strlen(path);
	if (path[len - 1] != '/')
	{
		tmp = ft_strjoin(path, "/");
		result = ft_strjoin(tmp, name);
		ft_strdel(&tmp);
	}
	else
		result = ft_strjoin(path, name);
	return (result);
}

t_dir	*ft_new_dir(char *name, char *path, t_opt *opts, size_t *total)
{
	t_dir	*dir;

	dir = (t_dir *)malloc(sizeof(t_dir));
	dir->name = name;
	dir->path = path;
	dir->total = 0;
	dir->next = NULL;
	dir->children = NULL;
	ft_get_dir_info(dir, opts, total);
	return (dir);
}

t_dir	*ft_get_tail(t_dir *curr)
{
	while (curr && curr->next)
		curr = curr->next;
	return (curr);
}

void	ft_push(t_dir **curr, t_dir *new)
{
	new->next = *curr;
	*curr = new;
}

void	ft_rev_list(t_dir **dir)
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

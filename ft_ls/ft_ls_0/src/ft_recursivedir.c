/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursivedir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstolz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/01 19:44:54 by dstolz            #+#    #+#             */
/*   Updated: 2019/01/01 19:44:58 by dstolz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

char		*ft_relpath(char *curr_dir, char *next_dir)
{
	char	*relpath;
	int		len;

	len = ft_strlen((const char *)curr_dir);
	len += ft_strlen((const char *)next_dir);
	relpath = ft_strnew(len + 3);
	ft_strcat(relpath, curr_dir);
	if (curr_dir[ft_strlen(curr_dir) - 1] != '/')
		ft_strcat(relpath, "/");
	ft_strcat(relpath, next_dir);
	return (relpath);
}

t_dirlist	*ft_recursivedir(char *dir_name, t_bool a_op)
{
	DIR				*dirstream;
	struct dirent	*curr;
	t_dirlist		*result;
	char			*n_name;

	result = ft_newdir(dir_name);
	dirstream = opendir(dir_name);
	if (dirstream == NULL)
	{
		b_printf("ft_ls: %s: No such file or directory\n", dir_name);
		return (NULL);
	}
	while ((curr = readdir(dirstream)) != NULL)
	{
		if ((!ft_strchr(curr->d_name, '.') || a_op) &&
			(ft_strcmp(curr->d_name, ".") && ft_strcmp(curr->d_name, "..")))
		{
			n_name = ft_relpath(dir_name, curr->d_name);
			if (ft_isdir(n_name))
			{
				ft_strcat(n_name, "/");
				ft_lsttail(result)->next = ft_recursivedir(n_name, a_op);
			}
		}
	}
	return (result);
}

t_dirlist	*ft_sortparentlex(t_dirlist *dir)
{
	t_dirlist	*sort;
	t_dirlist	*curr;
	char		*swap;

	sort = dir;
	while (sort)
	{
		curr = sort;
		while (curr)
		{
			if (ft_strcmp(curr->name, sort->name) < 0)
			{
				swap = curr->name;
				curr->name = sort->name;
				sort->name = swap;
			}
			curr = curr->next;
		}
		sort = sort->next;
	}
	return (dir);
}

t_dirlist	*ft_getchildren(t_dirlist *list, t_opt *options)
{
	t_dirlist *result;

	result = ft_recursivedir(list->name, options->a_op);
	list = list->next;
	while (list)
	{
		ft_lsttail(result)->next = ft_recursivedir(list->name, options->a_op);
		list = list->next;
	}
	if (!options->t_op)
		result->next = ft_sortparentlex(result->next);
	return (result);
}

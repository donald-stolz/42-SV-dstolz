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

// Should most of these functions be static?
int			ft_isdir(const char *path)
{
	// need to accomodate -a option (pass from previos functions)
	struct stat statbuf;
	if (stat(path, &statbuf) != 0)
		return 0;
	return S_ISDIR(statbuf.st_mode);
}

t_dirlist	*ft_lsttail(t_dirlist *head)
{
	while (head->next){
		head = head->next;
	}
	return (head);
}

t_dirlist	*ft_newdir(char *name)
{
	t_dirlist *new;
	new = malloc(sizeof(struct s_dirlist));
	// Do I need to dup or simply assign
	new->name = ft_strdup((const char *)name);
	new->head = NULL;
	new->total = 0;
	new->next = NULL;
	return (new);
}

char *ft_relpath(char *curr_dir, char *next_dir)
{
	char *relpath;
	int len;

	len = ft_strlen((const char*)curr_dir);
	len += ft_strlen((const char *)next_dir);
	relpath = ft_strnew(len + 2);
	ft_strcat(relpath, curr_dir);
	if (curr_dir[ft_strlen(curr_dir) - 1] != '/') 
		ft_strcat(relpath, "/");
	ft_strcat(relpath, next_dir);
	return (relpath);
}

/*
 * While parent has childern
 * 		if child == directory
 * 			parent[tail]->next = ft_recursivedir(child)
 * 		next child
 */
t_dirlist	*ft_recursivedir(char *dir_name)
{
	DIR		*dirstream;
	struct	dirent *curr;
	t_dirlist *result;
	char	*n_name;

	result = ft_newdir(dir_name);
	dirstream = opendir(dir_name);
	if (dirstream == NULL)
	{
		b_printf("ft_ls: %s: No such file or directory\n", dir_name);
		return (NULL);
	}
	while ((curr = readdir(dirstream)) != NULL )
	{
		if (ft_strcmp(curr->d_name, ".") && ft_strcmp(curr->d_name, ".."))
		{
			n_name = ft_relpath(dir_name, curr->d_name);
			if (ft_isdir(n_name))
				ft_lsttail(result)->next = ft_recursivedir(n_name);
		}
	}
	return (result);
}

t_dirlist	*ft_getchildren(t_dirlist *list)
{
	t_dirlist *result;

	result = ft_recursivedir(list->name);
	list = list->next; // Watch for leaks
	while (list)
	{
		ft_lsttail(result)->next = ft_recursivedir(list->name);
		list = list->next;
	}
	return (result);
}
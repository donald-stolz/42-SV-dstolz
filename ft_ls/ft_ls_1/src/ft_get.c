/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstolz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 09:35:16 by dstolz            #+#    #+#             */
/*   Updated: 2019/03/19 09:35:19 by dstolz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

//TODO: Error file?
static t_dir *ft_nofile(char *name)
{
	b_printf("ft_ls: %s: No such file or directory\n", name);
	return (NULL);
}
/*
 * 0. Start with head of list
 * 1. Send to name dirstream
 * 2. Get file names, check is_dir and a_op
 * 3. Create t_dir list of children
 * 4. Return list of children
 */
t_dir	*ft_set_children(char *p_name, t_opt *opts)
{
	DIR				*dirstream;
	struct dirent	*curr;
	t_dir			*result;
	char			*name;

	result = NULL;
	dirstream = opendir(p_name);
	if (dirstream == NULL)
		return *ft_nofile(p_name);
	while((curr = readdir(dirstream)) != NULL)
	{
		name = curr->d_name;
		if (A_OP(name, opts->a_op))
		{
			result = result ? ft_add_dir(result, name, opts)
							: ft_new_dir(name, opts);
		}
		result->path = NULL;
	}
	result = ft_get_head(result);
	return (result);
}

t_dir	*ft_set_children_rec(char *p_name, t_opt *opts)
{
	DIR				*dirstream;
	struct dirent	*curr;
	t_dir			*result;
	char			*name;
	char			*nxt_path;

	result = NULL;
	dirstream = opendir(p_name);
	if (dirstream)
		return *ft_nofile(p_name);
	while((curr = readdir(dirstream)))
	{
		name = curr->d_name;
		if (A_OP(name, opts->a_op) && (ft_strcmp(name, ".") 
			&& ft_strcmp(name, ".."))
		{
			result = result ? ft_add_dir(result, name, opts) 
							: ft_new_dir(name, opts);
			result->path = ft_strjoin(p_name, "/");
			if(result->is_dir)
			{
				nxt_path = ft_strjoin(result->path, name);
				result->children = ft_set_children_rec(nxt_path, opts);
				ft_strdel(nxt_path);
			}
		}
	}
	result = ft_get_head(result);
	return (result);
}

void ft_get_children(t_opt *opts, t_dir *p)
{
	while(p)
	{
		if(!p->is_dir)
			p->children = NULL;
		else if (opts->rec_op)
			p->children = ft_set_children_rec(p->name, opts);
		else
			p->children = ft_set_children(p->name, opts);
		p = p->next;
	}
}
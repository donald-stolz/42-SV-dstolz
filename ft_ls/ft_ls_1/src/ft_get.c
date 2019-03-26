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

static t_dir	*ft_nofile(char *name)
{
	b_printf("ft_ls: %s: No such file or directory\n", name);
	return (NULL);
}

static t_dir	*ft_set_children(char *p_name, t_opt *opts)
{
	DIR				*dirstream;
	struct dirent	*curr;
	t_dir			*result;
	char			*name;
	char			*path;

	result = NULL;
	dirstream = opendir(p_name);
	if (dirstream == NULL)
		return ft_nofile(p_name);
	while((curr = readdir(dirstream)) != NULL)
	{
		name = ft_strdup(curr->d_name);
		if (A_OP(name, opts->a_op))
		{
			path = ft_strjoin(p_name, "/");
			if (result)
				result = ft_add_dir(name, result, ft_strjoin(path, name), opts);
			else
				result = ft_new_dir(name, ft_strjoin(path, name), opts);
			ft_strdel(&path);
		}
		result->path = NULL;
	}
	result = ft_get_head(result);
	return (result);
}

static t_dir	*ft_set_children_rec(char *p_name, t_opt *opts)
{
	DIR				*dirstream;
	struct dirent	*curr;
	t_dir			*result;
	char			*name;
	char			*path;

	result = NULL;
	dirstream = opendir(p_name);
	if (dirstream)
		return ft_nofile(p_name);
	while((curr = readdir(dirstream)))
	{
		name = ft_strdup(curr->d_name);
		if (A_OP(name, opts->a_op) && (ft_strcmp(name, ".") && ft_strcmp(name, "..")))
		{
			path = ft_strjoin(p_name, "/");
			result = result ? ft_add_dir(name, result, 
								ft_strjoin(path, name), opts)
							: ft_new_dir(name, ft_strjoin(path, name), opts);
			ft_strdel(&path);
			if(result->is_dir)
				result->children = ft_set_children_rec(result->path, opts);
		}
	}
	result = ft_get_head(result);
	return (result);
}

void			ft_get_children(t_opt *opts, t_dir *p)
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
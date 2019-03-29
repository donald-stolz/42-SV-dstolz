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

static t_dir	*ft_set_children(char *p_name, t_opt *opts, size_t *total)
{
	DIR				*dirstream;
	struct dirent	*curr;
	t_dir			*result;
	char			*name;
	char			*path;

	result = NULL;
	dirstream = opendir(p_name);
	if (dirstream == NULL)
		return (ft_nofile(p_name));
	while ((curr = readdir(dirstream)) != NULL)
	{
		name = ft_strdup(curr->d_name);
		if (A_OP(name, opts->a_op))
		{
			path = ft_parse_path(name, p_name);
			if (result != NULL)
				ft_push(&result, ft_new_dir(name, path, opts, total));
			else
				result = ft_new_dir(name, path, opts, total);
		}
	}
	return (result);
}

static t_dir	*ft_set_children_rec(char *p_name, t_opt *opts, size_t *total)
{
	DIR				*dirstream;
	struct dirent	*curr;
	t_dir			*res;
	char			*name;
	char			*path;

	res = NULL;
	dirstream = opendir(p_name);
	if (dirstream)
		return (ft_nofile(p_name));
	while ((curr = readdir(dirstream)))
	{
		name = ft_strdup(curr->d_name);
		if (A_OP(name, opts->a_op))
		{
			path = ft_parse_path(name, p_name);
			if (res != NULL)
				ft_push(&res, ft_new_dir(name, path, opts, total));
			else
				res = ft_new_dir(name, path, opts, total);
			if (res->is_dir && (ft_strcmp(name, ".") && ft_strcmp(name, "..")))
				res->children = ft_set_children_rec(res->path, opts, total);
		}
	}
	return (res);
}

void			ft_get_children(t_opt *opts, t_dir *p)
{
	while (p)
	{
		if (!p->is_dir)
			p->children = NULL;
		else if (opts->rec_op)
			p->children = ft_set_children_rec(p->path, opts, &p->total);
		else
			p->children = ft_set_children(p->path, opts, &p->total);
		p = p->next;
	}
}

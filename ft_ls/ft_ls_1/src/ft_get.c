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

static t_dir	*ft_get_child(char *p_name, t_opt *opts, size_t *total,
							DIR *dirstream)
{
	t_dir			*res;
	struct dirent	*curr;
	char			*name;
	char			*path;

	res = NULL;
	while ((curr = readdir(dirstream)))
	{
		if (A_OP(curr->d_name, opts->a_op))
		{
			name = ft_strdup(curr->d_name);
			path = ft_parse_path(name, p_name);
			if (res != NULL)
				ft_push(&res, ft_new_dir(name, path, opts, total));
			else
				res = ft_new_dir(name, path, opts, total);
			if (res->is_dir && opts->rec_op && (ft_strcmp(name, ".")
				&& ft_strcmp(name, "..")))
				res->children = ft_set_children(res->path, opts, &res->total);
		}
	}
	return (res);
}

t_dir			*ft_set_children(char *p_name, t_opt *opts, size_t *total)
{
	DIR		*dirstream;
	t_dir	*res;

	res = NULL;
	dirstream = opendir(p_name);
	if (dirstream == NULL)
		return (ft_nofile(p_name));
	res = ft_get_child(p_name, opts, total, dirstream);
	closedir(dirstream);
	return (res);
}

void			ft_get_children(t_opt *opts, t_dir *p)
{
	while (p)
	{
		if (!p->is_dir)
			p->children = NULL;
		p->children = ft_set_children(p->path, opts, &p->total);
		p = p->next;
	}
}

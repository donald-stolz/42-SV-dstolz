/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstolz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 18:19:48 by dstolz            #+#    #+#             */
/*   Updated: 2019/03/22 18:19:51 by dstolz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

static void	ft_print_l(t_dir *dir)
{
	char *dir_time;

	dir_time = ft_parse_time(ctime(&dir->m_time.tv_sec));
	b_printf("%s %d %s %s %d %s %s\n", dir->permissions, dir->links,
				dir->owner, dir->group, dir->size, dir_time, dir->name);
	ft_strdel(&dir_time);
}

static void	ft_print_children_l(t_dir *p)
{
	t_dir	*nav;

	nav = p->children;
	b_printf("total %d\n", p->total);
	while (nav)
	{
		ft_print_l(nav);
		nav = nav->next;
	}
}

static void	ft_print_children(t_dir *children)
{
	while (children)
	{
		b_printf("%s    ", children->name);
		children = children->next;
	}
}

// FIXME:
void		ft_print_ls(t_opt *opts, t_dir *p, t_bool root)
{
	while (p)
	{
		if (p->next || (opts->rec_op && p->is_dir))
			ft_print_path(p->path);
		else if (root)
		{
			if (opts->l_op)
				ft_print_l(p);
			else if (p->next)
				b_printf("%s\n", p->name);
		}
		if (p->children)
		{
			if (opts->l_op)
				ft_print_children_l(p);
			else
				ft_print_children(p->children);
			if (opts->rec_op)
				ft_print_ls(opts, p->children, false);
		}
		p = p->next;
	}
}

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

void	ft_print_l(t_dir *dir)
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

void		ft_print_ls(t_opt *opts, t_dir *p, t_bool root)
{
	t_bool mult;

	mult = p->next ? true : false;
	while (p)
	{
		if (p->is_dir)
		{
			if (!root || mult)
				ft_print_header(p, root);
			if (opts->l_op && p->children != NULL)
				ft_print_children_l(p);
			else
				ft_print_children(p->children);
			if (opts->rec_op && p->children != NULL)
			{
				write(1, "\n\n", 2);
				ft_print_ls(opts, p->children, false);
			}
		}
		else if (root)
			ft_print_dir(p, opts->l_op);
		p = p->next;
	}
}

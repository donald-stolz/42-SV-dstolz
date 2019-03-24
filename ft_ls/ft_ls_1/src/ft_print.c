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

static char	*ft_parse_time(char *dir_time)
{
	char *new;
	int i;

	i = 0;
	new = (char *)malloc(13);
	while (i < 12)
	{
		*(new + i) = *(dir_time + (4 + i));
		i++;
	}
	*(new + i) = '\0';
	return (new);
}

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

	*nav = p->children;
	b_printf("total %d\n", p->total);
	while (nav)
	{
		ft_print_l(nav);
		nav = nav->next;
	}
}

static void	ft_print_children(t_dir *children)
{
	while(children)
	{
		b_printf("%s	", children->name);
		children = children->next;
	}
}

static void	ft_print_path(char *path)
{
	path[ft_strlen((const char *)path) - 1] = ":";
	b_printf("\n%s\n", path);
}

void		ft_print_ls(t_opt *opts, t_dir *p, t_bool root)
{
	p = ft_get_head(p);
	while(p)
	{
		if ((p->next || p->previous) || (opts->rec_op && p->is_dir))
			ft_print_path(p->path);
		else if (root)
		{
			if (opts->l_op)
				ft_print_l(p);
			else
				ft_print_name(p->name);
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

/*
 * 0. (Check if arg is single parent && -R) or if multiple
 * 	-	Add t_bool to arguments
 *  -	Check if is_dir; false -> simply print name & \n (Careful w/ -l)
 *  - true don't display dir->path
 *  - false display dir->path w/ ':'
 * 1. Check if l_op; 
 * 		- true-> print total then -l children
 * 		- Else iterate through and print children
 * 2. Check -R
 * 		- true -> ft_print_ls children
 * 		- false -> next parent
 */
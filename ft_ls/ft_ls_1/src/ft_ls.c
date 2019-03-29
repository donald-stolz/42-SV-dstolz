/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstolz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 08:13:22 by dstolz            #+#    #+#             */
/*   Updated: 2019/03/19 08:13:25 by dstolz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

static void	ft_sort_children(t_opt *opts, t_dir *parents)
{
	while (parents)
	{
		ft_sort(opts, &parents->children);
		parents = parents->next;
	}
}

static void	ft_ls(t_opt *options, t_dir *parents)
{
	ft_get_children(options, parents);
	ft_sort_children(options, parents);
	ft_print_ls(options, parents, true);
}

int			main(int argc, const char **argv)
{
	t_opt	*options;
	t_dir	*parents;

	if (argc > 0)
	{
		options = ft_get_flags(argv);
		parents = ft_get_args((char **)argv, options);
		ft_sort(options, &parents);
		ft_ls(options, parents);
		// ft_free_opts(&options);
		// ft_free_dirs(&parents);
	}
	return (0);
}

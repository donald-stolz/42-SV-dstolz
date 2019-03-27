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

int		main(int argc, const char **argv)
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

/*	1. Parse args
 *		- Get directory args into linked arglist
 *		- If sort options, sort parents first
 * 	2. Call ft_ls on list of args(Parent directory(ies)) with option flags
 * 	3. First check for -R option
 * 		- Update directory list with children
 * 	4. Sort children
 * 	5. Print elements
 * 	6. Return to main
 *  7. Free structures
 */
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstolz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 09:36:15 by dstolz            #+#    #+#             */
/*   Updated: 2019/03/19 09:36:18 by dstolz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

static t_opt	*ft_new_flags(void)
{
	t_opt *new;

	new = malloc(sizeof(t_opt));
	new->l_op = false;
	new->a_op = false;
	new->r_op = false;
	new->t_op = false;
	new->rec_op = false;
	return (new);
}

t_opt			*ft_get_flags(const char **argv)
{
	size_t i;
	t_opt *result;

	result = ft_new_flags();
		i = 1;
	while (argv[i] && *(*(argv + i) + 0) == '-')
	{
		//FIXME: Needs to check full string of flags, not just index 1
		if (ft_strchr("lartR", argv[i][1]))
		{
			result->l_op = ft_strchr(argv[i], 'l') ? true : result->l_op;
			result->a_op = ft_strchr(argv[i], 'a') ? true : result->a_op;
			result->r_op = ft_strchr(argv[i], 'r') ? true : result->r_op;
			result->t_op = ft_strchr(argv[i], 't') ? true : result->t_op;
			result->rec_op = ft_strchr(argv[i], 'R') ? true : result->rec_op;
			i++;
		}
		else
		{
			ft_putstr("ft_ls: illegal option -- - \n");
			exit(1);
		}
	}
	return (result);
}

t_dir			*ft_get_args(char **argv, t_opt *opts)
{
	size_t i;
	t_dir *curr;

	i = 1;
	while (argv[i] && *(*(argv + i) + 0) == '-')
		i++;
	if (argv[i])
	{
		curr = ft_new_dir(ft_strdup(argv[i]), argv[i], opts);
		i++;
		while (argv[i])
		{
			curr = ft_add_dir(ft_strdup(argv[i]), curr, argv[i], opts);
			i++;
		}
		curr = ft_get_head(curr);
	}
	else
		curr = ft_new_dir(ft_strdup("./"), ft_strdup("./"),opts);
	return curr;
}
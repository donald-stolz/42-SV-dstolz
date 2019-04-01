/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstolz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 11:13:43 by dstolz            #+#    #+#             */
/*   Updated: 2019/03/24 11:13:44 by dstolz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void		ft_free_opts(t_opt **opts)
{
	free(*opts);
	*opts = NULL;
}

void		ft_free_dirs(t_dir **dir)
{
	t_dir *cur;
	t_dir *next;

	cur = *dir;
	while (cur != NULL)
	{
		if (cur->children != NULL)
			ft_free_dirs(&cur->children);
		next = cur->next;
		ft_strdel(&cur->name);
		ft_strdel(&cur->path);
		ft_strdel(&cur->permissions);
		free(cur);
		cur = next;
	}
	*dir = NULL;
}

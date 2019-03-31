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

static void	ft_dir_del(t_dir **dir)
{
	if (*dir)
	{
		ft_strdel(&(*dir)->name);
		ft_strdel(&(*dir)->path);
		ft_strdel(&(*dir)->permissions);
		free(*dir);
		*dir = NULL;
	}
}

void		ft_free_dirs(t_dir **dir)
{
	t_dir **temp;

	while (*dir)
	{
		if ((*dir)->children)
			ft_free_dirs(&(*dir)->children);
		temp = &(*dir)->next;
		ft_dir_del(dir);
		dir = temp;
	}
}

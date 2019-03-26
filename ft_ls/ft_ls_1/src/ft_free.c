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

void	ft_free_opts(t_opt **opts)
{
	free(*opts);
	*opts = NULL;
}

static void ft_dir_del(t_dir *dir)
{
	if ((dir)->children)
		ft_free_dirs(&(dir)->children);
	if (dir)
	{
		ft_strdel(&(dir)->name);
		ft_strdel(&(dir)->path);
		ft_strdel(&(dir)->permissions);
		free(dir);
		dir = NULL;
	}
}

void	ft_free_dirs(t_dir **dir)
{
	t_dir *temp;

	temp = ft_get_head(*dir);
	while(temp->next)
	{	
		temp = temp->next;
		ft_dir_del(temp->previous);
	}
	ft_dir_del(temp);
}
	/* 
	 * 0. Get head of list
	 * 1. Send children to get freed
	 * 2. strdel name & path
	 * 3. Go to next
	 */

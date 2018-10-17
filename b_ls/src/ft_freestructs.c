/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freestructs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstolz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 20:57:08 by dstolz            #+#    #+#             */
/*   Updated: 2018/10/10 20:57:10 by dstolz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/b_ls.h"

void	ft_freelist(t_dir *dir)
{
	t_dir *curr;
	curr = dir;
	while (curr)
	{
		curr = dir->next;
		free(dir->permissions);
		free(dir);
		dir = curr;
	}
}

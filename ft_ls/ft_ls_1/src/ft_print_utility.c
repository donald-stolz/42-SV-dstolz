/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utility.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstolz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 13:29:40 by dstolz            #+#    #+#             */
/*   Updated: 2019/03/29 13:29:44 by dstolz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

char	*ft_parse_time(char *dir_time)
{
	char	*new;
	int		i;

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

void	ft_print_dir(t_dir *dir, t_bool l_op)
{
	if (l_op)
		b_printf("%s/%s", dir->path, dir->name);
	else
		ft_print_l(dir);
	if (dir->next)
		write(1, "\n\n", 2);
}

void	ft_print_header(t_dir *dir, t_bool root)
{
	if (root)
		b_printf("%s:\n", dir->name);
	else
		b_printf("%s:\n", dir->path);
}

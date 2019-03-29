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

void	ft_print_path(char *path)
{
	path[ft_strlen((const char *)path) - 1] = ':';
	b_printf("\n%s\n", path);
}

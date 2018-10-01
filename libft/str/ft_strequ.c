/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstolz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 17:44:18 by dstolz            #+#    #+#             */
/*   Updated: 2018/09/30 17:44:31 by dstolz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int ft_strequ(char const *s1, char const *s2)
{
	size_t i;

	i = 0;
    if (!s1 || !s2)
        return (0);
	while (*(s1 + i) && (*(s1 + i) == *(s2 + i)))
		i++;
	if (*((unsigned char *)s1 + i) - *((unsigned char *)s2 + i) != 0)
        return  (0);
    return (1);
}
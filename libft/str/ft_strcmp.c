/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstolz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 09:13:47 by dstolz            #+#    #+#             */
/*   Updated: 2018/09/17 18:58:41 by dstolz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t i;

	i = 0;
	while (*(s1 + i) && (*(s1 + i) == *(s2 + i)))
		i++;
	return (*((unsigned char *)s1 + i) - *((unsigned char *)s2 + i));
}

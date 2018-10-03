/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstolz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 17:46:11 by dstolz            #+#    #+#             */
/*   Updated: 2018/09/30 17:46:22 by dstolz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>

char    *ft_strtrim(char const *s)
{
	size_t	i;
	size_t	start;
	size_t	end;
	char		*str;

	i = 0;
	if (!s)
		return (NULL);
	while (*(s + i) <= ' ' && *(s + i))
        i++;
	start = i;
	while (*(s + i))
		i++;
	while (*(s + i) <= ' ' && i > start)
		i--;
	end = i;
	str = ft_strnew(end - start + 1);
	i = 0;
	if (!str)
		return (NULL);
	while (start <= end)
		*(str + i++) = *((char *)s + start++);
	str[i] = '\0';
	return (str);
}

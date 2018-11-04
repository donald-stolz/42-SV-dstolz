/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstolz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 17:45:40 by dstolz            #+#    #+#             */
/*   Updated: 2018/09/30 17:45:52 by dstolz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*str;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	MALLCHECK((str = ft_strnew(ft_strlen(s1) + ft_strlen(s2))));
	while (*s1)
		*(str + i++) = *s1++;
	while (*s2)
		*(str + i++) = *s2++;
	*(str + i) = '\0';
	return (str);
}

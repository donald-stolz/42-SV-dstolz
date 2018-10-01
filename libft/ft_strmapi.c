/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstolz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 15:47:41 by dstolz            #+#    #+#             */
/*   Updated: 2018/09/30 15:47:47 by dstolz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	size;
	char	*str;

	if (!s)
		return (NULL);
	i = 0;
	size = ft_strlen(s);
	str = (char *)malloc((size + 1) * sizeof(*str));
	if (str == NULL)
		return (NULL);
	while (i < size)
	{
		*(str + i) = f(i, *((char *)s + i));
		i++;
	}
	*(str + i) = '\0';
	return (str);
}

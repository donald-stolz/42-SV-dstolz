/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstolz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 15:47:28 by dstolz            #+#    #+#             */
/*   Updated: 2018/09/30 15:47:30 by dstolz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	size_t	size;
	char	*str;

	MALLCHECK(s);
	i = 0;
	size = ft_strlen(s);
	MALLCHECK((str = (char *)malloc((size + 1) * sizeof(*str))));
	while (i < size)
	{
		*(str + i) = f(*((char *)s + i));
		i++;
	}
	*(str + i) = '\0';
	return (str);
}

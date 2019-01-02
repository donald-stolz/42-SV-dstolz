/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstolz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 10:17:15 by dstolz            #+#    #+#             */
/*   Updated: 2018/09/27 18:21:40 by dstolz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*(haystack + i) == *(needle + i) && !*(haystack + i))
		return ((char *)haystack + i);
	while (*(haystack + i) && i < len)
	{
		j = i;
		while (*(haystack + j) == *(needle + (j - i))
				&& *(haystack + j) != '\0' && j < len)
			j++;
		if (*(needle + (j - i)) == '\0')
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}

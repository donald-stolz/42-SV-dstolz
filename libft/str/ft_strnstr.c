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
	size_t	k;
	size_t	check;

	i = 0;
	if (!ft_strlen(needle))
		return ((char *)haystack);
	while (*haystack + i && i < len)
	{
		if (*(haystack + i) == *needle)
		{
			j = 0;
			k = i;
			check = 1;
			while (*(needle + j))
				if (*(needle + j++) != *(haystack + k++))
					check = 0;
			if (check)
				return ((char *)haystack + i);
		}
		i++;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstolz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 10:17:15 by dstolz            #+#    #+#             */
/*   Updated: 2018/09/27 18:19:56 by dstolz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*(haystack + i) == *(needle + i) && *(haystack + i) == '\0')
		return ((char *)haystack + i);
	while (*(haystack + i))
	{
		j = i;
		while (*(haystack + j) == *(needle + (j - i))
			&& *(haystack + j) != '\0')
			j++;
		if (*(needle + (j - i)) == '\0')
		{
			return ((char *)haystack + i);
		}
		i++;
	}
	return (NULL);
}

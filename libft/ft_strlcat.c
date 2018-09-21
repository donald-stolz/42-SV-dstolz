/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstolz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 09:59:12 by dstolz            #+#    #+#             */
/*   Updated: 2018/09/20 10:53:49 by dstolz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t i;
	size_t j;

	i = 0;
	j = ft_strlen(dst);
	while (j < dstsize && *(src + i))
		*(dst + j++) = *((char *)src + i++);
	*(dst + j) = '\0';
	return (i);
}
